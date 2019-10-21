#include <stdio.h>
int main()
{
int n,a[101],b[101],i,j,flag=0,temp;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
scanf("%d",&b[i]);
for(i=0;i<n;i++)
{
while (a[i]>=0)
{
if (a[i]==b[i])
flag++;
if (a[i]==b[i]) break;
else
{
temp=a[i];
for(j=i;j<n;j++)
{
a[j]=a[j+1];
}
a[n-1]=temp;
flag++;
}
}
}
printf("%d",flag);
return 0;
}
