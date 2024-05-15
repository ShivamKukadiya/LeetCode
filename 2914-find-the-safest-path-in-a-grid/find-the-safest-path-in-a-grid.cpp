class Solution {
public:
    void computeMinDistances(vector<vector<int>>& grid, vector<vector<int>> & dist, int n) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool> (n, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }

        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(dist[x][y] == -1) {
                    dist[x][y] = level;
                }

                int xMoves[] = {1,-1,0,0};
                int yMoves[] = {0,0,1,-1};

                for(int idx = 0; idx < 4; idx++) {
                    int newX = x + xMoves[idx];
                    int newY = y + yMoves[idx];

                    if(newX >= 0 && newX < n && newY >= 0 && newY < n) {
                        if(!visited[newX][newY]) {
                            visited[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }
            }
            level++;
        }
    }

    void dijkstra(vector<vector<int>> & dist, vector<vector<int>> & min_dist, int n) {
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({dist[0][0], {0, 0}});

        while(!pq.empty()) {
            int nodex = pq.top().second.first;
            int nodey = pq.top().second.second;
            int dis = pq.top().first;

            pq.pop();

            int xMoves[] = {1,-1,0,0};
            int yMoves[] = {0,0,1,-1};

            for(int idx = 0; idx < 4; idx++) {
                int newX = nodex + xMoves[idx];
                int newY = nodey + yMoves[idx];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n) {
                    int w = dist[newX][newY];
                    if(min(dis, w) > min_dist[newX][newY])  {
                        min_dist[newX][newY] = min(dis, w);
                        pq.push({min_dist[newX][newY], {newX, newY}});
                    }
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<vector<int>> dist(n, vector<int> (n, -1));
        computeMinDistances(grid, dist, n);

        vector<vector<int>> min_dist(n, vector<int> (n, 0));
        dijkstra(dist, min_dist, n);

        return min_dist[n - 1][n - 1];
    }
};