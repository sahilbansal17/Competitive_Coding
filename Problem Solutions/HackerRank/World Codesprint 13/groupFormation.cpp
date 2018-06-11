#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {
private:
    vector <int> p, rank, setSize; 
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
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
    int numDisjointSets(){ 
        return numSets; 
    }
    int sizeOfSet(int i){ 
        return setSize[findSet(i)]; 
    }
}; // source: CP3 by Steven Halim

// Complete the membersInTheLargestGroups function below.
void membersInTheLargestGroups(int n, int m, int a, int b, int f, int s, int t) {
    // Print the names of the students in all largest groups or determine if there are no valid groups.
    /*
        n : no of students
        m : requests containing students who want to be in the same group
        a : min no of students in a group 
        b : max no of students in a group
        f : max no of first grade students in a group
        s : max no of second grade students in a group 
        t : max no of third grade students in a group
    */
    
    string name, name1, name2;
    int grade, id1, id2, size1, size2, setId1, setId2, gNew1, gNew2, gNew3;
    int sizeByGrade[n + 1][3]; // n*3 grade size matrix 
    
     // find the size of largest group simultaneously while merging
    int maxSize = 0, currSize;
    
    unordered_map <string, int> studentId;
    // pair contains id and grade
    unordered_map <int, string> studentName;
    
    for(int i = 0; i < n ; i++){
        cin >> name >> grade;
        studentId[name] = i;
        sizeByGrade[i][0] = 0;
        sizeByGrade[i][1] = 0;
        sizeByGrade[i][2] = 0;
        sizeByGrade[i][grade - 1] = 1; // initially every student is in its own group
        studentName[i] = name;
    }
    
    UnionFind studentGroup(n);
    
    for(int i = 0 ; i < m ; i++){
        cin >> name1 >> name2;
        id1 = studentId[name1];
        id2 = studentId[name2];
        setId1 = studentGroup.findSet(id1);
        setId2 = studentGroup.findSet(id2);
        bool canJoin = 0;
        if(setId1 != setId2){
            size1 = studentGroup.sizeOfSet(id1);
            size2 = studentGroup.sizeOfSet(id2);
            // first check whether the size of combining groups can exceed max size possible
            if(size1 + size2 > b){
                continue;
                // move to next query
            }
            // resulting gradewise size of new set if allowed to merge 
            gNew1 = sizeByGrade[setId1][0] + sizeByGrade[setId2][0]; 
            gNew2 = sizeByGrade[setId1][1] + sizeByGrade[setId2][1]; 
            gNew3 = sizeByGrade[setId1][2] + sizeByGrade[setId2][2];
            // check whether gNew(i) < maxAllowed(i-th group)
            if(gNew1 <= f && gNew2 <= s && gNew3 <= t){
                canJoin = 1;
            }
        }
        if(canJoin){
            studentGroup.unionSet(id1, id2);
            
            // update maxSize appropriately, also should satisfy minSize constraint
            if(size1 + size2 >= maxSize && size1 + size2 >= a){
                maxSize = size1 + size2;
            }
            // find the resultant setId 
            setId1 = studentGroup.findSet(id1);
            // update the gradeWise size matrix
            sizeByGrade[setId1][0] = gNew1;
            sizeByGrade[setId1][1] = gNew2;
            sizeByGrade[setId1][2] = gNew3;
        }
    }
    
    // cout << "No of groups is: " << studentGroup.numDisjointSets();
    
    vector <int> maxGroupSetId;
    for(int i = 0 ; i < n ; i++){
        currSize = studentGroup.sizeOfSet(i);
        if(currSize == maxSize){
            int setID = studentGroup.findSet(i);
            maxGroupSetId.push_back(setID);
        }
    }
    if(maxSize == 0){
        cout << "no groups";
    }
    else{
        vector <string> largestGroup;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < maxGroupSetId.size() ; j ++){
                if(studentGroup.findSet(i) == maxGroupSetId[j]){
                    largestGroup.push_back(studentName[i]);
                    break;
                }   
            }
        }
        sort(largestGroup.begin(), largestGroup.end());
        for(int i = 0 ; i < largestGroup.size() ; i ++){
            cout << largestGroup[i] << "\n";
        }
    }
    
}
int main()
{
    string nmabfst_temp;
    getline(cin, nmabfst_temp);

    vector<string> nmabfst = split_string(nmabfst_temp);

    int n = stoi(nmabfst[0]);

    int m = stoi(nmabfst[1]);

    int a = stoi(nmabfst[2]);

    int b = stoi(nmabfst[3]);

    int f = stoi(nmabfst[4]);

    int s = stoi(nmabfst[5]);

    int t = stoi(nmabfst[6]);

    membersInTheLargestGroups(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
