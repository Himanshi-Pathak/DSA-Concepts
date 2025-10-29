#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays so we can assign the smallest possible cookie
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;

        // Use two pointers to iterate through children and cookies
        while (i < g.size() && j < s.size()) {
            // If the current cookie can satisfy the child's greed
            if (g[i] <= s[j]) {
                count++;  // Child is content
                i++;      // Move to the next child
                j++;      // Move to the next cookie
            } else {
                // Current cookie too small, try a bigger one
                j++;
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> g = {1, 2, 3};   // Greed factors of children
    vector<int> s = {1, 1};      // Sizes of cookies

    int result = sol.findContentChildren(g, s);
    cout << "Number of content children: " << result << endl;

    return 0;
}
