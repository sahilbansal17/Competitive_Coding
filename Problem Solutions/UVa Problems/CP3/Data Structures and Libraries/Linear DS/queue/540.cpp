#include <bits/stdc++.h>
using namespace std;

int main () {

    int num_teams;
    cin >> num_teams;
    int id = 1;
    while (num_teams != 0) {
        cout << "Scenario #" << id << endl;
        ++id;

        map<int, int> element_to_team, present;
        for (int team_id = 1; team_id <= num_teams; ++team_id) {
            int num_elements;
            cin >> num_elements;

            int element;
            for (int element_id = 1; element_id <= num_elements; ++element_id) {
                cin >> element;
                element_to_team[element] = team_id;
            }
        }

        queue<int> team_queue;
        queue<int> team[num_teams + 1];

        string query;
        cin >> query;
        int x;
        while (query != "STOP") {
            if (query == "ENQUEUE") {
                cin >> x;
                int element_team = element_to_team[x];
                // if team not present in the queue
                if (!present[element_team]) {
                    team_queue.push(element_team);
                    // mark the team as present
                    present[element_team] = 1;
                }
                // push to individual team queue
                team[element_team].push(x);
            } else if (query == "DEQUEUE") {
                // get front team in the team queue
                int front_team = team_queue.front();

                // team queue size = 1, remove from team_queue
                if (team[front_team].size() == 1) {
                    team_queue.pop();
                    // mark team as not present
                    present[front_team] = false;
                }

                // get the element at the front for the team
                x = team[front_team].front();
                cout << x << endl;
                // remove from the queue
                team[front_team].pop();
            }
            cin >> query;
        }

        cin >> num_teams;
        cout << endl;
    }
    return 0;
}