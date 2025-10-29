#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;  // Tracks the farthest reachable index

        for (int i = 0; i < nums.size(); i++) {
            // If current index is beyond the farthest reachable point, we’re stuck
            if (i > maxJump) return false;

            // Update the farthest index we can reach from this position
            maxJump = max(maxJump, i + nums[i]);

            // Early exit: if we can reach or go beyond the last index
            if (maxJump >= nums.size() - 1) return true;
        }

        // If we finish the loop, it means we can reach the end
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << (sol.canJump(nums) ? "Can reach end" : "Cannot reach end") << endl;
    return 0;
}