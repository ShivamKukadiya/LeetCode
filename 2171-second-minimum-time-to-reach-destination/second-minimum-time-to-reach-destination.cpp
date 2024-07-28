#include <vector>
#include <queue>
#include <deque>
#include <array>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        deque<array<int, 2>> q;
        q.push_back({1, 0});
        
        vector<array<int, 2>> dist(n + 1, {INT_MAX, INT_MAX});
        dist[1][1] = 0;

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop_front();
            for (int v : g[u]) {
                if (d + 1 < dist[v][0]) {
                    dist[v][0] = d + 1;
                    q.push_back({v, d + 1});
                } else if (dist[v][0] < d + 1 && d + 1 < dist[v][1]) {
                    dist[v][1] = d + 1;
                    if (v == n) {
                        break;
                    }
                    q.push_back({v, d + 1});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < dist[n][1]; ++i) {
            ans += time;
            if (i < dist[n][1] - 1 && (ans / change) % 2 == 1) {
                ans = (ans + change) / change * change;
            }
        }
        return ans;
    }
};
