#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s2.size() + 1, vector<int>(s1.size() + 1, 0));
    for (int i = 1; i <= s1.size(); i++)
        dp[0][i] = i;
    for (int i = 1; i < s2.size() + 1; i++)
        dp[i][0] = i;
    for (int i = 1; i < s2.size() + 1; i++) {
        for (int j = 1; j <= s1.size(); j++) {
            bool v = s1[j - 1] != s2[i - 1];
            if (s1[j - 1] != s2[i - 1])
                dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            else {
                dp[i][j] = min({dp[i - 1][j - 1] , dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
    }
    cout << dp[s2.size()][s1.size()];
}