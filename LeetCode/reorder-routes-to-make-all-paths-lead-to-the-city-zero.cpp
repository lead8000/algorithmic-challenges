class Solution {
private:
    int visitDfs(int node, vector<bool> &visitedNode, vector<vector<int>> &edges, vector<set<int>> &directedEdges) {
        int amountReverseEdges = 0;
        for(int i = 0; i < edges[node].size(); i++) {
            if (!visitedNode[edges[node][i]]) {
                visitedNode[edges[node][i]] = true;
                if (directedEdges[edges[node][i]].find(node) == directedEdges[edges[node][i]].end()) {
                    amountReverseEdges++;
                }
                amountReverseEdges += visitDfs(edges[node][i], visitedNode, edges, directedEdges);
            }
        }
        return amountReverseEdges;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n);
        vector<set<int>> directedEdges(n);

        for(int i = 0; i < connections.size(); i++) {
            int a = connections[i][0], b = connections[i][1];
            edges[a].push_back(b);
            edges[b].push_back(a);
            directedEdges[a].insert(b);
        }

        vector<bool> visitedNode(n);
        visitedNode[0]=true;

        return visitDfs(0, visitedNode, edges, directedEdges);
    }
};