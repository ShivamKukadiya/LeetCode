class Solution {
public:
    int ok(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 1;
        else {
            if (grid[i][j] == 1) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    sum += ok(i + 1, j, grid);
                    sum += ok(i, j + 1, grid);
                    sum += ok(i, j - 1, grid);
                    sum += ok(i - 1, j, grid);
                }
            }
        }
        return sum;
    }
};