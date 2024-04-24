class Solution {
    vector<int> bfs(int n, vector<vector<int>> &g, int s) {
        queue<int> q;
        vector<int> d(n, -1);
        q.push(s);
        d[s] = 0;
        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (auto x: g[cur]) {
                if (d[x] == -1) {
                    d[x] = d[cur] + 1;
                    q.push(x);
                }
            }
        }
        return d;
    }

    int getNodeAtMaxDist(vector<int> &dist) {
        int res = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] > dist[res]) res = i;
        }
        return res;
    }
public:
    /*
        find 2 ends on diamter of the tree now the nodes at distance D / 2  in (even length)
        and D / 2 || (D + 1) / 2 from both the ends will be the centroid of the tree.

        - 1 bfs to find node at max dist from random root.
        - do a bfs from that node again to find other end of the diameter.
        - do a bfs aging from end of the diameter to habe distance
        - now compare distance from both diametric ends
    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto v: edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> d1 = bfs(n, g, 0);
        int end1 = getNodeAtMaxDist(d1);
        vector<int> d2 = bfs(n, g, end1);
        int end2 = getNodeAtMaxDist(d2);
        d1 = bfs(n, g, end2);
        int D = *max_element(d1.begin(), d1.end());
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (D % 2 == 0) {
                if (d1[i] == d2[i] && d1[i] == D / 2) {
                    return vector<int> {i};
                }
            } else {
                if ((d1[i] == D / 2 && d2[i] == (D + 1) / 2) || (d2[i] == D / 2 && d1[i] == (D + 1) / 2)) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};