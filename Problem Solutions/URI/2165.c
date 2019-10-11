#include <stdio.h>
#include <string.h>

int main(){
	char tweet[600];
	
	gets(tweet);
	if(strlen(tweet) <= 140)
		printf("TWEET\n");
	else
		printf("MUTE\n");


}
