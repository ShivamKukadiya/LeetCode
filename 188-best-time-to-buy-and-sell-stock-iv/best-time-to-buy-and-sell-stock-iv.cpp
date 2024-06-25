class Solution {
public:

    int func(vector<vector<vector<int>>>& dp, vector<int>& v, int ind, bool flg, int cnt) {
        int n = v.size();
        if (ind == n || cnt == 0) return 0;
        if (dp[ind][flg][cnt] != -1) return dp[ind][flg][cnt];

        int ans = 0;

        if (flg) {
            int take = -v[ind] + func(dp, v, ind + 1, 0, cnt);
            int ntake = func(dp, v, ind + 1, 1, cnt);
            ans = max(take, ntake);
        } else {
            int take = v[ind] + func(dp, v, ind + 1, 1, cnt - 1);
            int ntake = func(dp, v, ind + 1, 0, cnt);
            ans = max(take, ntake);
        }

        return dp[ind][flg][cnt] = ans;
    }

    int maxProfit(int k,vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return func(dp, v, 0, 1, k);
    }
};