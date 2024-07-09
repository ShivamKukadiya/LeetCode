#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        return BFS(0, M);
    }
    
private:
    void BFSHelper(vector<vector<int>>& adj_mat, int sv, vector<bool>& visited) {
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        int v = adj_mat.size();
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (int i = 0; i < v; ++i) {
                if (adj_mat[front][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int BFS(int ans, vector<vector<int>>& adj_mat) {
        int v = adj_mat.size();
        vector<bool> visited(v, false);
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                ++ans;
                BFSHelper(adj_mat, i, visited);
            }
        }
        return ans;
    }
};
