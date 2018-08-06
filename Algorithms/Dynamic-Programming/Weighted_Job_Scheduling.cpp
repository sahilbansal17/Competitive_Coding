/*
  https://github.com/sahilbansal17/Competitive_Coding/

  Name: Anil Khatri (@imkaka)
  Email-Id: anil.soccer.khatri@gmail.com

*/

// Weighted Job Scheduling => It is the variation of Activity Selection Problem .(https://github.com/sahilbansal17/Competitive_Coding/Algorithms/Greedy/Activity_Selection.cpp)
// In this we have another factor in addition to Start Time and Finish Time.
//               * Profit/Weight associated
// So we have to find the non overlapping maximum Profit jobs.

// we can not solve this Problem via Greedy technique but it can we solved by Dynamic Programming.
// we will discuss DP solution to solve above Problem.

//Solution Idea:
/*         1. Sort the jobs according to Finish time
           2. Recursive Procedure:
                  maxProfit(jobs[],N):
                    a. if N==1:
                          return jobs[0]
                    b. Return max Of:
                            1. Maximum profit by excluding current job MaximumProfit(jobs[], N-1)
                            2. Maximum profit by including the current job.

          The idea is to find the latest job before the current job that doesn't conflict with current job 'arr[n-1]'.
          Once we find such a job, we recur for all jobs till that job and add profit of current job to result.

          The Above Recursive Solution result in Overlapping Subproblems and here the DP come 
          to evaluate a sub-problem only once and store in table and use it if required later.


  Example:              |Job|Start Time|Finish Time| Profit|
                        
                        |A  |     1    |    2      |  60   |
                        |B  |     3    |    6      |  90   |
                        |C  |     2    |    100    |  400  |

          Solution (Recursive): 
                               
                         {A,B}        =>  60+90 = 150
                      A/      
                       \{A}/ {A,C}    =>  60+400 = 460   <= Max Profit (Result)
                           \ {A}      =>  60


*/ 


#include <iostream>
#include <algorithm>
using namespace std;
 

struct Job
{
    int start, finish, profit;
};
 
// To sort via finish time
bool compare(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
 
// A Binary Search based function to find the latest job
// that doesn't conflict with current
// job.  "last" is index of the current job.  This function
// returns -1 if all jobs before last conflict with it.
int bSearch(Job jobs[], int last)
{
    
    int low = 0, high = last - 1;
 
   
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[last].start)
        {
            if (jobs[mid + 1].finish <= jobs[last].start)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }
 
    return -1;
}
 

// Find max profit possible from given array of jobs
int MaxProfit(Job jobs[], int n)
{
    // Sort jobs according to finish time
    sort(jobs, jobs+n, compare);
 
    // Create an array to store solutions of subproblems.  DP[i]
    int *DP = new int[n];
    DP[0] = jobs[0].profit;
 
    
    for (int i=1; i<n; i++)
    {
        // Find profit including the current job
        int inclProf = jobs[i].profit;
        int l = bSearch(jobs, i);
        if (l != -1)
            inclProf += DP[l];
 
        // Store maximum of including and excluding
        DP[i] = max(inclProf, DP[i-1]);
    }
 
    // Store result and free dynamic memory allocated for DP[]
    int result = DP[n-1];
    delete[] DP;
 
    return result;
}
 

int main()
{
   cout << "Please Enter the No of Jobs: ";
   int n;
   cin >> n;

    Job jobs[n];
    cout<< "Enter the Start time, Finish Time & Profit with space in between:"<< endl;

    for(int i=0;i<n;i++){
      cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
    } 
    
    cout << "The Maximum profit is : " << MaxProfit(jobs, n);
    return 0;
}

// Time Complexity =>  O(N log N)  => We iterate the jobs only one time because we are storing the subproblems
//                                    Result O(N) and O(Log N) for Binary Search.
//                                    Overall O(N Log N)
// Space Complexity => O(N)       => Storing Jobs






