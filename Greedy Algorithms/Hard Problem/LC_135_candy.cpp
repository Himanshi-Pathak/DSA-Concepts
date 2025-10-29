#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int candies = 1;  // Start with 1 candy for the first child
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                // Increasing sequence: give more candies than previous child
                up++;
                peak = up;
                down = 0;
                candies += 1 + up;
            } else if (ratings[i] == ratings[i - 1]) {
                // Equal ratings: reset sequence, each gets 1 candy
                up = down = peak = 0;
                candies += 1;
            } else {
                // Decreasing sequence: handle downward slope after a peak
                up = 0;
                down++;
                // Adjust candies so that the peak child gets enough candies
                candies += 1 + down - (peak >= down ? 1 : 0);
            }
        }

        // Total candies distributed
        return candies;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}