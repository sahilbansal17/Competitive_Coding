class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int current = 1, index = 0;
        vector <int> res(num_people, 0);
        while (candies) {
            if (current <= candies) {
                res[index] += current;
                candies -= current;
            } else {
                res[index] += candies;
                candies = 0;
            }
            index ++;
            index %= num_people;
            current ++;
        }
        return res;
    }
};