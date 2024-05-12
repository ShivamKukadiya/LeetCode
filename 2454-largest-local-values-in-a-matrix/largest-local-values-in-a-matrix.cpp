class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> vv;
        int n = grid.size();
        for (int i = 0; i < n - 2; i++) {
            vector<int>v;
            for(int j = 0 ; j < n - 2; j++){
                int maxi = 0;
                for(int l = i; l < i+3; l++){
                    for(int k = j ; k  < j+3; k++){
                        maxi = max(maxi,grid[l][k]);
                    }
                }
                v.push_back(maxi);
            }
            vv.push_back(v);
        }
        return vv;
    }
};