/*
    Longest Palindromic Subsequence (LPS)
    --------------------------------------
    Given a string s, find the length of the longest subsequence of s
    that is a palindrome.

    Example:
        Input:  s = "bbbab"
        Output: 4
        Explanation: "bbbb" is the longest palindromic subsequence.

    Time Complexity : O(n^2)
    Space Complexity: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(const string &s) {
    int n = s.size();
    if (n == 0) return 0;

    // dp[i][j] will store the length of LPS in s[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // every single character is a palindrome of length 1
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    // fill dp for substrings of length 2 to n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tests = {"bbbab", "cbbd", "agbdba", "racecar", ""};
    for (auto &s : tests) {
        cout << "Input: \"" << s << "\" → LPS length = "
             << longestPalindromicSubsequence(s) << "\n";
    }

    return 0;
}
