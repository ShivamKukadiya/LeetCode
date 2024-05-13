class Solution {
public:
    void flipBitsRow(int row, vector<vector<int>>& grid){
        int n = grid[0].size();

        for(int i = 0; i < n; i++){
            grid[row][i] = (grid[row][i] == 1) ? 0 : 1;
        }
    }

    void flipBitsCol(int col, vector<vector<int>>& grid){
        int m = grid.size();

        for(int i = 0; i < m; i++){
            grid[i][col] = (grid[i][col] == 1) ? 0 : 1;
        }
    }

    int calculateAns(vector<vector<int>>& grid, int m, int n){
        int ans = 0;
        for(int i = 0; i < m; i++){
            int tempAns = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    tempAns += pow(2, n - j - 1);
                }
            }
            ans += tempAns;
        }
        return ans;
    }

    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Flipping the row if first digit is 0
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                flipBitsRow(i, grid);
            }
        }

        // Flipping the column if column his having more 0's than 1's
        for(int i = 0; i < n; i++){
            int zeroes = 0;
            int ones = 0;
            for(int j = 0; j < m; j++){
                if(grid[j][i] == 0)
                    zeroes++;
                else
                    ones++;
            }
            if(zeroes > ones){
                flipBitsCol(i, grid);
            }
        }

        return calculateAns(grid, m, n);
    }
};