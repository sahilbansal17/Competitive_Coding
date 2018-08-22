/*
  https://github.com/sahilbansal17/Competitive_Coding/

  Name: Anil Khatri (@imkaka)
  Email-Id: anil.soccer.khatri@gmail.com

*/

// Activity Selection Problem => One  has given N activities with their start (Si) and finish (Fi) times.
//  Select the maximum number of activities that can be performed by a single person, 
//  assuming that a person can only work on a single activity at a time.

// It is the first example when we talk about Greedy Algorithms.and it is also asked a lot in CP.

// The idea is to select the the activity with least finish time (Fi) among the remaining Activities and start time (Si) is
// more than or equal to finish time of previously selected activity , This is our Greedy Choice.

// For that we can sort the Activities according to finish time (Fi).and Select as stated above.

#include<iostream>
#include<algorithm>

using namespace std;

// a activity have start time and finish time

struct Activity
{
   int start,finish;

};

// A function which is used sorting Activity according to Finish time

bool compareFinish (Activity a1, Activity a2)
{
  return(a1.finish < a2.finish);
}

// Return Max Activities which can be done as per Condition

void MaxActivities(Activity activity[],int N)
{

  // Sort Activities according to finish time
  sort(activity,activity+N,compareFinish);
  
  int count =1;
  // First one is always selected
  int j = 0;
  cout << "The Selected Activities:\n";
  cout << "("<<activity[j].start << ", " << activity[j].finish << "), ";

  for( int i=1 ; i<N ;i++)
  {
    // Activity's start time is greater than or equal to finish time of previously selected  one then select it.
    if(activity[i].start >= activity[j].finish)
    {
      cout << "("<< activity[i].start << ", " << activity[i].finish << "), ";
      count ++;

      j = i;
    }
  }
  
  cout << "\n Total Selected Activities : "<< count<<endl;
    
}
 
// driver program to test above function
int main()
{
    int N;
    cout << "Enter Total no of Activity: ";
    cin >> N;
    Activity act[N];
    // Input Finish time and Finish time as 12 10 and Press Enter for next Activity Input
    cout<< "Input Activities first Start time than Finish time with space in b/w: ";
    for (int i=0 ; i < N; i++)
    {
      cin >> act[i].start >> act[i].finish;
    }
    
    // Function call
    MaxActivities(act,N);

    return 0;
}

// Time Complexity => O(Nlog(N))    => Complexity for Sorting.
// Space Complexity => O(N) 
