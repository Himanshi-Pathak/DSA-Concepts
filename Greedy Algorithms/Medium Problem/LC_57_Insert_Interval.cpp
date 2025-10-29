#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInte) {
        int i = 0, n = intervals.size();
        vector<vector<int>> ans;

        // Step 1: Add all intervals that come before the new interval (no overlap)
        while (i < n && intervals[i][1] < newInte[0]) {
            ans.emplace_back(intervals[i++]);
        }

        // Step 2: Merge all overlapping intervals with the new interval
        while (i < n && intervals[i][0] <= newInte[1]) {
            newInte[0] = min(newInte[0], intervals[i][0]);
            newInte[1] = max(newInte[1], intervals[i][1]);
            i++;
        }

        // Step 3: Add the merged interval
        ans.emplace_back(newInte);

        // Step 4: Add all remaining intervals (after the merged one)
        while (i < n) ans.emplace_back(intervals[i++]);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInte = {2,5};

    vector<vector<int>> result = sol.insert(intervals, newInte);

    cout << "After inserting new interval: ";
    for (auto& it : result) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;
    return 0;
}