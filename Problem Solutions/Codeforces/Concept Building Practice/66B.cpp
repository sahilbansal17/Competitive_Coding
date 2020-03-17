#include<bits/stdc++.h>
using namespace std;

int main () {

    int num_sections;
    cin >> num_sections;

    vector<int> heights(num_sections);
    for (auto &height: heights) {
        cin >> height;
    }

    vector<int> non_decreasing_ending_here(num_sections, 1);
    vector<int> non_decreasing_starting_here(num_sections, 1);

    // non_decreasing_ending_here[0] = 1 always
    for (int section = 1; section < num_sections; ++section) {
        if (heights[section] >= heights[section - 1]) {
            non_decreasing_ending_here[section] = non_decreasing_ending_here[section - 1] + 1;
        }
    }

    // non_decreasing_starting_here[num_sections - 1] = 1 always
    for (int section = num_sections - 2; section >= 0; --section) {
        if (heights[section] >= heights[section + 1]) {
            non_decreasing_starting_here[section] = non_decreasing_starting_here[section + 1] + 1;
        }
    }

    int optimal_section = 1;
    int max_watered_sections = 1;
    for (int section = 0; section < num_sections; ++section) {
        // subtract 1 so as not to count the section being watered twice
        if (-1 + non_decreasing_ending_here[section] + non_decreasing_starting_here[section] > max_watered_sections) {
            max_watered_sections = -1 + non_decreasing_ending_here[section] + non_decreasing_starting_here[section];
            optimal_section = section;
        }
    }

    // print the maximum watered sections for artificial watering the optimal_section
    cout << max_watered_sections << endl;
    return 0;
}