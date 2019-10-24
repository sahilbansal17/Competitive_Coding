#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t,k=0;
  scanf("%d",&t);
  while (t--)
  {
    k++;
    int n,m,flag=0;
    scanf("%d %d",&n,&m);
    vector <int>graph[n+1];
    for (int i=0; i<m; i++)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    int *list=(int*)calloc(n+1,sizeof(int));

    for (int i=0; i<=n; i++)
    list[i]=2;
    int *mark=(int *)calloc(n+1,sizeof(int));
    for (int i=1; i<=n; i++)
    {
      if (mark[i]==0)
      {
        queue <int> q;
        q.push(i);
        list[i]=1;
        while (q.size()!=0)
        {
          int temp=q.front();
          for (int j=0; j<graph[temp].size(); j++)
          {
            if (list[graph[temp][j]]==2)
              list[graph[temp][j]]=!list[temp];
            else if (list[graph[temp][j]]==list[temp])
            {
              flag=1;
              break;
            }
            if (mark[graph[temp][j]]==0)
              q.push(graph[temp][j]);
          }
          q.pop();
          mark[temp]=1;
          if (flag==1)
             break;
        }
      }
      if (flag==1)
        break;
    }

    printf("Scenario #%d:\n",k);
    if (flag==1)
    printf("Suspicious bugs found!\n");
    else
    printf("No suspicious bugs found!\n");
  }
  return 0;
}
