class Solution {
public:
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, 1, -1, 0};

    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis) {
          queue<pair<pair<int, int>,int>> q;
        int n = mat.size();
        int m = mat[0].size();
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ( mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }

            // queue<pair<pair>>
        }
        
        while (!q.empty()) {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int len=q.front().second;
                q.pop();
                mat[row][col]=len;
                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 1) {
                           vis[nr][nc] = 1;
                            q.push({{nr, nc},len+1});
                        }
                    }
                }
            }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
       bfs(mat,vis);
        return mat;
    }
};