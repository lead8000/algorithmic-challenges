class Solution {
private:
    double visitDfs(string currNode, string targetNode, map<string,bool> &visitedNode, map<string, vector<pair<string, double>>> &adj) {
        if (targetNode == currNode && visitedNode[currNode]) {
            return 1;
        }
        
        double partialEquationVal = 0.0;
        for (int i = 0; i < adj[currNode].size(); i++) {
            string otherNode = adj[currNode][i].first;
            double value = adj[currNode][i].second;
            if (!visitedNode[otherNode]) {
                visitedNode[otherNode] = true;
                partialEquationVal = max(partialEquationVal, value * visitDfs(otherNode, targetNode, visitedNode, adj));
            }
        }
        return partialEquationVal;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < equations.size(); i++) {
            string X = equations[i][0], Y = equations[i][1];
            adj[X].push_back({Y, (double)values[i]});
            adj[Y].push_back({X, 1.0/(double)values[i]});
        }

        vector<double> results;

        for (auto equation: queries) {
            string X = equation[0], Y = equation[1];
            map<string,bool> visitedNode;
            double value = visitDfs(X, Y, visitedNode, adj);
            results.push_back(
                abs(value - 0.0) < 0.0001 ? -1 : value
            );
        }

        return results;
    }
};