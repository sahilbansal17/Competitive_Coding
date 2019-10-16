/*
	Problem Link: https://leetcode.com/problems/merge-intervals
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return intervals; //base condition
        
        vector<vector<int>> ans;
        vector<pair<int,int>> temp;

        for(int i=0;i<intervals.size();i++){
            temp.push_back({intervals[i][0],0}); //saving interval start along 0
            temp.push_back({intervals[i][1],1}); //saving interval end along 1
        }
        sort(temp.begin(), temp.end()); //sorting intervals based on time values
    
	//l,r - mantains the longest current range covered
        int l=abs(temp[temp.size()-1].first),r=0,cnt=0;
        
        for(int i=0;i<temp.size();i++){
            if(temp[i].second==0){ //case when a interval beginning occurs
                cnt++;
                l = min(l,temp[i].first);
            }
            else{ //case when a interval ends occurs
                cnt--;
                r = max(r,abs(temp[i].first));
            }
            
            if(cnt==0){ //when count becomes zero, we have a maximal interval
                vector<int> here;
                here.push_back(l); here.push_back(r); //pushing into a temperorary vector
                ans.push_back(here); //saving into answer
                l = abs(temp[temp.size()-1].first);
                r = 0;
            }
        }
        return ans;
    }
};
