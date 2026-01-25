/*
 * Created By George on 1/25/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/evaluate-division/
 * Problem Status:      Accepted
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int> > vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(queries.size());

        map<string, vector<string>> edges;
        map<pair<string, string>, double> edgesWeights;
        set<string> variablesAppeared;

        // process the graph
        for (int i = 0; i < equations.size(); i++) {
            auto& eq = equations[i];
            auto& val = values[i];

            pair<string, string> forwardEdge = {eq[0], eq[1]};
            pair<string, string> backwardEdge = {eq[1], eq[0]};

            edges[eq[0]].push_back(eq[1]);
            edgesWeights[forwardEdge] = val;

            edges[eq[1]].push_back(eq[0]);
            edgesWeights[backwardEdge] = 1.0 / val;

            variablesAppeared.insert(eq[0]);
            variablesAppeared.insert(eq[1]);
        }

        // resolve the queries
        int queryIdx = 0;
        for (auto& q: queries) {
            if (variablesAppeared.count(q[0]) == 0 || variablesAppeared.count(q[1]) == 0) {
                ans[queryIdx++] = -1.0;
                continue;
            }

            ans[queryIdx++] = dfsTraverse(
                q[0], q[1], edges, edgesWeights
            );
        }

        return ans;
    }

    double dfsTraverse(
        const string& src,
        const string& dest,
        const map<string, vector<string>>& edges,
        const map<pair<string, string>, double>& edgesWeights
    ) {
        stack<string> nodesToVisit;
        set<string> visitedNodes;
        stack<double> traversalCost;

        nodesToVisit.push(src);
        visitedNodes.insert(src);
        traversalCost.push(1.0);

        while (!nodesToVisit.empty()) {
            string node = nodesToVisit.top();
            nodesToVisit.pop();
            const double currentCost = traversalCost.top();
            traversalCost.pop();

            if (node == dest) return currentCost;

            for (int neighborIdx = 0; neighborIdx < edges.at(node).size(); neighborIdx++) {

                string neighbor = edges.at(node)[neighborIdx];

                if (visitedNodes.count(neighbor) > 0) continue;

                pair<string, string> edge = {node, neighbor};
                double tempCost = currentCost * edgesWeights.at(edge);
                nodesToVisit.push(neighbor);
                traversalCost.push(tempCost);
                visitedNodes.insert(neighbor);
            }
        }

        return -1.0;
    }
};

int main() {
    return 0;
}
