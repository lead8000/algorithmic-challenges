#include "solution.h"

vector<int> topological_sort(int n, vector<vector<int>>& edges) {
    vector<Node> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(Node(i));
    }

    for (int i = 0, from, to; i < edges.size(); i++) {
        from = edges[i][0];
        to   = edges[i][1];

        nodes[to].inEdges.push_back(from);
        nodes[from].outEdges.push_back(to);
    }

    queue<Node*> q;
    for (int i = 0; i < n; i++) {
        if (nodes[i].inEdges.size() == 0) {
            q.push(&nodes[i]);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int value = q.front()->value;
        vector<int> *outEdges = &q.front()->outEdges;
        q.pop();

        for (auto to: *outEdges) {
            // remove the value on the other inEdges
            auto newEnd = remove(nodes[to].inEdges.begin(), nodes[to].inEdges.end(), value);
            nodes[to].inEdges.erase(newEnd, nodes[to].inEdges.end());

            if (nodes[to].inEdges.size() == 0) {
                q.push(&nodes[to]);
            }
        }
        result.push_back(value);
    }

    return result;
}

vector<vector<int>> Solution::getAncestors(int n, vector<vector<int>>& edges) {
    auto top_sort = topological_sort(n, edges);

    vector<vector<int>> inEdges(n);
    vector<vector<bool>> ancestors(n, vector<bool>(n, false));
    for (int i = 0, from, to; i < edges.size(); i++) {
        from = edges[i][0];
        to   = edges[i][1];

        inEdges[to].push_back(from);
        ancestors[to][from] = true;
    }

    for(auto x: top_sort) {
        for (int i = 0; i < inEdges[x].size(); i++) {
            // apply the OR operation
            transform(
                ancestors[inEdges[x][i]].begin(), ancestors[inEdges[x][i]].end(), // first vector 
                ancestors[x].begin(), // second vector
                ancestors[x].begin(), // result
                logical_or<bool>());  // operation
        }
    }

    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ancestors[i][j]) {
                result[i].push_back(j);
            }
        }
    }
    return result;
}
