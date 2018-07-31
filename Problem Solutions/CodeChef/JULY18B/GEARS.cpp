#include <bits/stdc++.h>
using namespace std;

// connections of gears as a graph in adjacency list form
vector <int> adj_list[100001];
bool visited[100001];

// Union-Find Disjoint Sets Library written in OOP manner,
class UnionFind {
private:
    vector <int> p, setSize, rank; 
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1); 
        rank.assign(N, 0);
        numSets = N; 
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i; 
    }
    int findSet(int i){ 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }
    bool isSameSet(int i, int j){ 
        return findSet(i) == findSet(j); 
    }
    void unionSet(int i, int j){ 
        numSets--; 
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]){
            p[y] = x; 
            setSize[x] += setSize[y];
        }
        else{ 
            p[x] = y; 
            setSize[y] += setSize[x];
            if(rank[x] == rank[y]) 
                rank[y]++; 
        } 
    }
    int parent(int i){
    	return p[i];
    }
};

int euclidGCD(long long a, long long b){
	if (b == 0){
		return a;
	}
	return euclidGCD(b, a % b);
}

bool directlyConnected(int x, int y){
	// check whether adjacency list of x contains y
	int adj_x = adj_list[x].size(), connected_to;
	for(int i = 0; i < adj_x; i ++){
		connected_to = adj_list[x][i];
		if(connected_to == y){
			return true;
		}
	}
	// since undirected graph, no need to check vice-versa
	return false;
}

int numDirectConnections(int x, int y, int c = 0){
	visited[x] = true;
	if(x == y){
		return c;
	}
	for(int i = 0; i < adj_list[x].size(); i ++){
		int next = adj_list[x][i];
		if(!visited[next]){
			int check = numDirectConnections(next, y, c + 1);
			if(check != -1){
				return check;
			}
		}
	}
	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int gears, queries;
	scanf("%d %d", &gears, &queries);

	vector <int> teeth(gears, 0);
	for (int gear = 0; gear < gears; gear ++){
		cin >> teeth[gear];
	}

	UnionFind UF(gears);
	// blocked gears
	set <int> blocked;

	int query_type, gear_x, gear_y, speed_of_gear_x, new_teeth;
	long long numerator, denominator;
	for (int query = 0; query < queries; query ++){
		scanf("%d", &query_type);

		// first set visited to false
		for(int j = 0; j < gears; j ++){
			visited[j] = false;
		}
		
		switch(query_type){
			case 1:
				scanf("%d %d", &gear_x, &new_teeth);
				// zero-based indexing
				gear_x --;
				teeth[gear_x] = new_teeth;
				break;
			case 2:
				scanf("%d %d", &gear_x, &gear_y);
				// zero-based indexing
				gear_x --;
				gear_y --;
				// if already connected
				// and leads to blockage
				// set speed = 0 for all as all blocked
				if (UF.isSameSet(gear_x, gear_y)){
					// check whether directly connected, if not, then results in a cycle, thus blockage
					if(!directlyConnected(gear_x, gear_y)){
						// set speed of all gears in the set to be zero
						// if the cycle formed will have an odd length
						// i.e. number of direct connections between x and y is even
						int connections = numDirectConnections(gear_x, gear_y);
						// printf("Connections: %d\n", connections);
						if (!(connections & 1)){
							int set_id = UF.findSet(gear_x);
							blocked.insert(set_id);
						}
					}
					else{
						;	// directly connected, nothing to do
					}
				}
				else{
					// if either of them is blocked, then after union both must be blocked
					if (blocked.count(UF.findSet(gear_x)) != 0){
						// add the other set to blocked sets
						int set_id = UF.findSet(gear_y);
						blocked.insert(set_id);
					}
					else if (blocked.count(UF.findSet(gear_y)) != 0){
						int set_id = UF.findSet(gear_x);
						blocked.insert(set_id);
					}
					else{
						// none of them is blocked
						UF.unionSet(gear_x, gear_y);
						adj_list[gear_x].push_back(gear_y);
						adj_list[gear_y].push_back(gear_x);
					}
				}
				break;
			case 3:
				scanf("%d %d %d", &gear_x, &gear_y, &speed_of_gear_x);
				// zero-based indexing
				gear_x --;
				gear_y --;
				// find speed of gear y
				// if already blocked
				if (blocked.count(UF.findSet(gear_x)) != 0){
					// speed_of_gear_y = 0;
					printf("0\n");
				}
				else if(UF.isSameSet(gear_x, gear_y)){
					// find the no. of direct connections between x and y
					int connections = numDirectConnections(gear_x, gear_y);	
					// printf("Connections: %d\n", connections);
					// if not connected, then speed is zero
					if (connections == 0){
						// speed_of_gear_y = 0;
						printf("0\n");
					}
					else{
						// if connections are odd, speed will be negative
						if(connections & 1){
							numerator = -1ll * speed_of_gear_x;
						}
						else{
							numerator = 1ll * speed_of_gear_x;
						}

						// numerator will be teeth[x]/gcd(teeth[x], teeth[y])
						// denominator will be teeth[y]/gcd(teeth[x], teeth[y])
						numerator *= teeth[gear_x];
						denominator = teeth[gear_y];
						long long gcd = euclidGCD(abs(numerator), denominator);
						numerator /= gcd;
						denominator /= gcd;

						// printf("Connections: %d\n", connections);
						printf("%lld/%lld\n", numerator, denominator);
					}
				}
				else{
					// no direct connection
					printf("0\n");
				}
				break;
		}
	}

	return 0;
}