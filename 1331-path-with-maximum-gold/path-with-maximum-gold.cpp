class Solution {
public:
    int getMaximumGold_helper(vector<vector<int>>& grid, int k, int n) {
        if ( k == grid.size() || k == -1 || n == grid.front().size() || n == -1 ||  grid[k][n] == 0 )
            return 0;

        int g = grid[k][n];
        grid[k][n] = 0;

        int r = getMaximumGold_helper(grid,k - 1,n);
        r = max(r,getMaximumGold_helper(grid,k + 1,n));
        r = max(r,getMaximumGold_helper(grid,k,n-1));
        r = max(r,getMaximumGold_helper(grid,k,n+1));
        grid[k][n] = g;
        return r + g;
    }

    bool getMaximumGold_check(vector<vector<int>>& grid, int k, int n) {
        if (grid[k][n] == 0) 
            return false;     
        return
             k == grid.size() - 1 || grid[k +1][n] == 0 
             || k == 0 ||  grid[k -1][n] == 0
             || n == grid.front().size() - 1 || grid[k][n + 1] == 0 
             || n == 0 || grid[k][n - 1] == 0; 
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int r = 0;
        int s = 0;
        for (int i = 0; i != grid.size(); ++i)
            for (int j = 0; j != grid.front().size(); ++j)
            {
                if (getMaximumGold_check(grid, i,j))
                  r = max(r,getMaximumGold_helper(grid,i,j));
                  s += grid[i][j];
            }
        
        return r == 0 ? s : r;
    }
};