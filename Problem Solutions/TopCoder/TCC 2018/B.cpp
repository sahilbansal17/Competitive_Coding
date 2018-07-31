#include <bits/stdc++.h>
using namespace std;

vector <int> primes;
bitset<10010> prime; 
void sieve(int upperbound) {          
  int total = upperbound + 1;                   
  prime.set();                                                 
  prime[0] = prime[1] = 0;                                     
  for (int i = 2; i <= total; i++){
  	if (prime[i]) {
  		for (int j = i * i; j <= total; j += i) prime[j] = 0; 
  		primes.push_back(i);
	}
  } 
}

bool isPrime(int N) {                 
  if (N <= 10000) return prime[N];                   
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                    
} 

set <int> mySet;
class EllysPrimesMatrix{
private:
	
	public:

	void solve(vector <string> matrix, int ct, int last, string s){
		if(ct == last + 1){
			if(isPrime(stoi(s))){
				// cout << s << "\n";
				mySet.insert(stoi(s));
			}
		}
		else{
			string current = matrix[ct];
			for(int i = 0; i < current.size(); i ++){
				solve(matrix, ct + 1, last, s + current[i]);
			}
		}
	}
	int getCount(vector <string> matrix){
		int score = 0;
		sieve(10000);
		int num = matrix.size();
		string last = matrix[num - 1], without_even;
		for(int i = 0; i < last.size(); i ++){
			if(last[i] != '2' && last[i] != '4' && last[i] != '6' && last[i] != '8' && last[i] != '0')
			without_even += last[i];
		}
		matrix[num - 1] = without_even;
		string s;
		solve(matrix, 0, num - 1, s);
		score = mySet.size();
		return score;
	}
};

int main(){

	EllysPrimesMatrix a;
	
	string s1 = "315509";
	string s2 = "712846";
	string s3 = "666371";
	string s4 = "123456";
	string s5 = "789012";
	string s6 = "059437";
	string s7 = "149573";
	vector <string> vs;
	vs.push_back(s1);
	vs.push_back(s2);
	vs.push_back(s3);
	vs.push_back(s4);
	vs.push_back(s5);
	vs.push_back(s6);
	vs.push_back(s7);
	cout << "\n" << a.getCount(vs) << "\n";
	// cout << pow(7, 7);
}