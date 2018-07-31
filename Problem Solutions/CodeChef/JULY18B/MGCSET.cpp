#include <bits/stdc++.h>
using namespace std;

int main(){

	int total_cases, size_of_sequence, divisibility_factor;
	scanf("%d", &total_cases);
	
	// store the count of elements which are divisible by the factor provided
	int count_of_elements_divisible = 0, element, ans;
	for(int case_no = 0; case_no < total_cases; case_no ++){
		scanf("%d %d", &size_of_sequence, &divisibility_factor);

		for(int sequence_element_index = 0; sequence_element_index < size_of_sequence; sequence_element_index ++){
			scanf("%d", &element);
			if(element % divisibility_factor == 0){
				count_of_elements_divisible ++;
			}
		}

		// the answer is simply the no. of non-empty sequences that can be formed
		// using all the elements which are divisible by the factor provided
		ans = pow(2, count_of_elements_divisible) - 1;
		printf("%d\n", ans);
		
		// re-initialize with ZERO
		count_of_elements_divisible = 0;
	} 

	return 0;
}