#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	scanf("%s",str);
	int ascii[26]={0};
	int y = strlen(str);
	for(int i=0;i<y;i++)
	{
		int x;
		x = str[i];
		int j;
		j= (char)x-'a';
		ascii[j]++;
	}
	int count=0;
	for(int i=0;i<26;i++)
	{
		if(ascii[i] !=0)
			count++;
	}
	if(count%2==0)
		printf("CHAT WITH HER!");
	else
		printf("IGNORE HIM!");
	return 0;
}
