#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Downloads/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int test_cases;
	scanf("%d", &test_cases);

	int no_of_attractions, no_of_attractions_per_visit;
	long long no_of_visits;

	vector <string> attractions;
	string attraction;
	char attr[51];
	for(int case_no = 1; case_no <= test_cases; case_no ++){
		scanf("%d %d %lld", &no_of_attractions, &no_of_attractions_per_visit, &no_of_visits);

		for(int attraction_no = 0; attraction_no < no_of_attractions; attraction_no ++){
			scanf("%s", attr);
			attraction = attr;
			attractions.push_back(attraction);
		}
	
		printf("Case #%d: ", case_no);
		int starting_index_of_current_visit = (1ll * (no_of_visits - 1) * no_of_attractions_per_visit) % (no_of_attractions);
		int ending_index_of_current_visit = (starting_index_of_current_visit + no_of_attractions_per_visit - 1) % no_of_attractions;

		int start = starting_index_of_current_visit;
		int end = ending_index_of_current_visit;
		if(end > start){
			for(int i = start; i <= end; i ++){
				printf("%s ", attractions[i].c_str());
			}
		}
		else if(end < start){
			for(int i = 0; i <= end; i ++){
				printf("%s ", attractions[i].c_str());
			}
			for(int i = start; i < no_of_attractions; i ++){
				printf("%s ", attractions[i].c_str());
			}
		}
		else{
			printf("%s ", attractions[start].c_str());
		}
		printf("\n");

		attractions.clear();
	}

	return 0;
}