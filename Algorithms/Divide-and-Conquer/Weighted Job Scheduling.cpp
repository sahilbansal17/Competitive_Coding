#include <iostream>
#include <algorithm>
using namespace std;

struct Job{
    int start, finish, profit;
};

bool compareFinishTime(Job s1, Job s2){
    return (s2.finish > s1.finish);
}

int binarySearch(Job jobs[], int index){// to find the latest job (before current job) that doesn't conflict with current job.
    int low = 0, high = index - 1;         // index of current job
    while (low <= high){
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[index].start){
            if (jobs[mid + 1].finish <= jobs[index].start){
                low = mid + 1;
            }
            else{
                return mid;
            }
        }
        else{
            high = mid - 1;
        }
    }
    return -1;                         // returns -1 if all jobs before index conflict with it.
}

int findMaxProfit(Job array[], int n){
    int result, i, included, l;
    sort(array, array+n, compareFinishTime);    // Sorting jobs based on finish time
    int *profitTill = new int[n];
    profitTill[0] = array[0].profit;

    for(i=1; i<n; i++){
        included = array[i].profit;    // Find profit including the current job
        l = binarySearch(array, i);
        if (l != -1){
            included += profitTill[l];
        }
        profitTill[i] = max(included, profitTill[i-1]); // Store maximum of including and excluding
    }

    result = profitTill[n-1];      // Store result and free dynamic memory allocated for profitTill[]
    delete[] profitTill;

    return result;
}

int main(){
    Job array[] = {{1, 2, 150}, {5, 10, 80}, {3, 11, 20}, {2, 50, 300}};
    int n = sizeof(array)/sizeof(array[0]);
    cout << "Maximum profit obtained is " << findMaxProfit(array, n);
    return 0;
}
// The complexity of this algorithm is O(nLogn) as it uses Binary Search.