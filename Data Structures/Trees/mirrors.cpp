/* The following program checks whether or not two n-ary trees are
 * mirror reflections of each other. An n-ary tree is a tree, each of whose
 * nodes has a maximum of n children.
 *
 * All nodes of the first tree and their children and parents are stored
 * in a stack and the other in a queue.
 * Elements are popped and dequeued one by one to check for mirror property.
 */

#include <bits/stdc++.h>
using namespace std;

bool isMirror(int e, int *p1, int *c1, int *p2, int *c2){
    vector < stack<int> > t1 (e + 1);
    vector < queue<int> > t2 (e + 1);

    int i;

    for(i = 0; i < e; i ++)
        t1[p1[i]].push(c1[i]);

    for(i = 0; i < e; i ++)
        t2[p2[i]].push(c2[i]);

    for (i = 1; i < t1.size(); i ++) {
        stack <int>& s = t1[i];
        queue <int>& q = t2[i];

        while (!s.empty() && !q.empty()) {
            if (s.top() != q.front())
                return false;
            s.pop();
            q.pop();
        }
        if (!s.empty() || !q.empty())
            return false;
    }
    return true;
}

int main(){
    int n,e;
    cout << "Enter the number of nodes" << endl;
    cin>>n;

    cout << "Enter the number edges" << endl;
    cin>>e;

    cout << "Please enter the trees edge wise, in the form - 'parent' 'child' " << endl;
    cout << "Each new child will be placed to the right of the siblings" << endl;

    cout << "Enter the first tree" << endl;

    int i;
    int p1[e], c1[e];

    for(i = 0; i < e; i ++){
        cin >> p1[i] >> c1[i];
    }

    int p2[e], c2[e];

    for(i = 0; i < e; i ++){
        cin >> p2[i] >> c2[i];
    }

    if( isMirror(e, p1, c1, p2, c2) )
        cout << "Mirror" << endl;

    else
        cout << "Not mirror" << endl;
}

/* Both time and space complexity of this program is O(e) where e is the number of
 * edges in each of the trees.
 */
