#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	char s_c[200010], t_c[200010];
	scanf("%s\n%s", s_c, t_c);

	string s, t;
	s = s_c;
	t = t_c;

	int len_s = s.length();
	int len_t = t.length();

	int last_s = len_s - 1;
	int last_t = len_t - 1;
	while(last_s >= 0 && last_t >= 0){
		if(t[last_t] != s[last_s]){
			break;
		}
		else{
			last_t --;
			last_s --;
		}
	}

	int res = 2 + last_s + last_t;
	printf("%d", res);

	return 0;
}