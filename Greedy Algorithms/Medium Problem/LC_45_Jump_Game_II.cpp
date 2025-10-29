#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump = 0, currEnd = 0, count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            // Track the farthest index reachable from current range
            maxJump = max(maxJump, i + nums[i]);

            // When we reach the end of the current jump range,
            // it means we must make another jump
            if (i == currEnd) {
                count++;            // Increment jump count
                currEnd = maxJump;  // Update the range for the next jump
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << sol.jump(nums) << endl;
    return 0;
}
