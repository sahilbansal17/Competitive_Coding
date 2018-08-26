/* Solution taken from PraveenDhinwa's submission on codeforces */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > split(vector<int> a)
{
      vector<vector<int> > ans;
      vector<int> temp;

      for (int i = 0; i < a.size(); i++)
      {
            if (a[i] == 0)
            {
                  if (temp.size() != 0)
                        ans.push_back(temp);
                  temp.clear();
            }
            else
                  temp.push_back(a[i]);
      }
      if (temp.size() != 0)
            ans.push_back(temp);

      return ans;
}

int solve(vector<int> a)
{
      if (a.size() == 0)
            return 0;

      int pos = 0, mn = (int) 1e9 + 5;
      for (int i = 0; i < a.size(); i++)
      {
            if (a[i] < mn)
            {
                  mn = a[i];
                  pos = i;
            }
      }

      int ans = a.size();
      int cnt = mn;
      for (int i = 0; i < a.size(); i++)
            a[i] -= mn;

      vector<vector<int> > v = split(a);
      for (int i = 0; i < v.size(); i++)
            cnt += solve(v[i]);

      ans = min(ans, cnt);
      return ans;
}

int main()
{
      int n;
      cin >> n;
      
      vector<int> a;
      
      for (int i = 0; i < n; i++)
      {
            int t;
            cin >> t;
            a.push_back(t);
      }

      cout << solve(a) << endl;

      return 0;
}