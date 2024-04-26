class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int j=0;j<n;j++){
          dp[0][j]=grid[0][j];        
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int mini=INT_MAX;
            for(int prevcol=0;prevcol<n;prevcol++){
                if(prevcol!=j)
                mini=min(mini,grid[i][j]+dp[i-1][prevcol]);
            }
            dp[i][j]=mini;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[n-1][i]);
    }
return ans;

    }
};