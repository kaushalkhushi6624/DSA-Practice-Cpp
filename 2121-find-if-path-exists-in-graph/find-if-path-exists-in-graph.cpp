class Solution {
public:
    bool dfs(int node, int destination,
             vector<vector<int>>& adj,
             vector<bool>& vis) {

        if (node == destination)
            return true;

        vis[node] = true;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, destination, adj, vis))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        return dfs(source, destination, adj, vis);
    }
};