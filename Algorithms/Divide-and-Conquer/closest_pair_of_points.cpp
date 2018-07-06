// C++ Program to Find Closest Pair of Points
// among the given set of points using
// Divide and Conquer Approach.

// Author: Pritam Negi.

#include <iostream>
#include <cfloat>
#include <cstdlib>
#include <cmath>
using namespace std;
 
// Declaration of structure
// for x any y coordinate of a point
struct Point
{
    int x, y;
};
 
// Function to sort array of points according to x coordinate
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// Function to sort array of points according to y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// Function to find the Euclidean distance between two set of points
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the smallest distance between two points
float small_dist(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
        }
    }
    return min;
}

// Function to find the distance beween the closest points of strip of given size
float stripClosest(Point strip[], int size, float d)
{
    float min = d;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
        {
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
        }
    }
    return min;
}

// Function that finds the smallest distance between points
// by dividing the points into left half and right half. 
float closestUtil(Point Px[], Point Py[], int n)
{
    // If number of points is less than equal to 3
    // then directly finding the closest pair of points
    if (n <= 3)
        return small_dist(Px, n);

    // Else we require to divide points into two halves
    int mid = n / 2;
    Point midPoint = Px[mid];
    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int li = 0, ri = 0;

    // Checking which points lie in left half
    // and which one in the right half of the midpoint
    // and storing them accodingly
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    // Finding smallest distance separately for
    // left half and right half.
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
    float d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
    }
    return min(d, stripClosest(strip, j, d));
}

// Function to store x and y coordinates into separate arrays
// Then sorting the Px array according to x coordinate
// and sorting the Py array according to y coordinate
float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];

    // Storing x and y coordinates in separate arrays
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    // Sorting the x and y coordinates
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    return closestUtil(Px, Py, n);
}

int main()
{
    int n;

    // Declaring an array to store x and y coordinates
    Point P[100100];

    // Taking input the number of points
    cout<< "Enter the number of points: ";
    cin>> n;

    // Taking input the x and y coordinates of n points
    cout<< "Enter the x any y coordinates of "<<n<<" points: "<< endl;
    for(int i = 0; i < n ; i++)
    {
        cin>>P[i].x>>P[i].y;
    }

    cout<< endl;

    // Printing the distance between closest pair of points.
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}

// Time Complexity: Let Time complexity of above algorithm be T(n). Let us assume that we use a O(n * log (n)) sorting algorithm.
// The above algorithm divides all points in two sets and recursively calls for two sets.
// After dividing, it finds the strip in O(n) time, sorts the strip in O(n * log (n)) time
// and finally finds the closest points in strip in O(n) time. So T(n) can expressed as follows
// T(n) = 2T(n/2) + O(n) + O(n * log (n)) + O(n)
// T(n) = 2T(n/2) + O(n * log (n))
// T(n) = T(n * log (n) * log (n))

