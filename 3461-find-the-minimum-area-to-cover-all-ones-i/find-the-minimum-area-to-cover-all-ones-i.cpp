class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        int r = INT_MAX;
        int r1 = INT_MIN;
        int s = INT_MAX;
        int s1 =INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    r = min(r,i);
                    r1 = max(r1,i);
                    s = min(s,j);
                    s1 = max(s1,j); 
                }
            }
        }
        int res = r1 - r +1;
        int res1 = s1 - s +1;
        return res * res1;
    }
};