class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start});
        vector<bool> visited(n);

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        while (!maxHeap.empty()) {
            double prob = maxHeap.top().first;
            int u = maxHeap.top().second;
            maxHeap.pop();

            if (u == end)
                return prob;

            if (visited[u])
                continue;

            visited[u] = true;

            for (const auto& neighbor : graph[u]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                if (!visited[nextNode]) {
                    maxHeap.push({prob * edgeProb, nextNode});
                }
            }
        }

        return 0.0;
    }
};
