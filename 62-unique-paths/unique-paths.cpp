class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i = 1; i < m; i++) {
            int res = 1;

            for (int j = 1; j < n; j++) {
                dp[j] += res;
                res = dp[j];
            }
        }
        return dp[n - 1];
    }
};