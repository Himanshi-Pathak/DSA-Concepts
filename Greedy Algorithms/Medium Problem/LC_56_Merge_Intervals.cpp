#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // Sort intervals by starting time to make merging easier
        sort(intervals.begin(), intervals.end());

        // Initialize 'prev' with the first interval
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the previous one, merge them
            if (intervals[i][0] <= prev[1]) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                // No overlap → push previous interval and move to the next
                ans.push_back(prev);
                prev = intervals[i];
            }
        }

        // Add the last merged interval
        ans.push_back(prev);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged intervals: ";
    for (auto& it : result) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;
    return 0;
}