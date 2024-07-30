class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    ans += (row[i] - 1) * (col[j] - 1);
                }
            }
        }
        return ans;
    }
};