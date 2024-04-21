class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        
        // BFS to find if there's a path from source to destination
        queue<int> bfsQueue;
        unordered_set<int> visited;
        
        bfsQueue.push(source);
        visited.insert(source);
        
        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            bfsQueue.pop();
            
            if (current == destination)
                return true;
            
            for (int neighbor : adjacencyList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    bfsQueue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        
        return false;
    }
};