class Solution {
private:
    int dfs1(int node, vector<vector<int>>& graph, int parent, int dist) {
        int cnode = dist;
        for(auto& child : graph[node]) {
            if(child != parent) {
                cnode += dfs1(child, graph, node, dist+1);
            }
        }
        return cnode;
    }
    int dfs2(int node, vector<vector<int>>& graph, int parent, vector<int>& tchild) {
        for(auto& child : graph[node]) {
            if(child != parent) {
                tchild[node]+= dfs2(child, graph, node, tchild);
            }
        }
        return 1+tchild[node];
    }
    void dfs3(int node, vector<vector<int>>& graph, int parent, vector<int>& ans, vector<int>& tchild) {
        if(parent != -1) ans[node] = ans[parent] - tchild[node] + (graph.size() - tchild[node] - 2);
        for(auto& child : graph[node]) {
            if(child != parent) {
                dfs3(child, graph, node, ans, tchild);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int init = dfs1(0, graph, -1, 0);
        vector<int> ans(n, init);
        
        vector<int> tchild(n, 0);
        dfs2(0, graph, -1, tchild);

        dfs3(0, graph, -1, ans, tchild);

        return ans;
    }
};


/*

1. Root the tree at 0 and find distance using dfs
2. Find the total children attached to the current node
3. DFS again from root 0 and update the answer of each node
4. Update a node by, ans[node] = ans[parent] - children[node] + (children[parent] or edges from parent)-2(exclude the current and parent node)

*/