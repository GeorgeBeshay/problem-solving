
/*
 * Created By George on 1/21/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * Problem Status:      Accepted.
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
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;

        map<int, vector<int>> edges;
        map<int, vector<bool>> isEdgeInOppDir;
        map<int, bool> visitedNodes;

        for (auto& connection: connections) {
            int source = connection[0];
            int destination = connection[1];

            edges[source].push_back(destination);
            isEdgeInOppDir[source].push_back(false);

            edges[destination].push_back(source);
            isEdgeInOppDir[destination].push_back(true);
        }

        queue<int> nodesToVisit;
        nodesToVisit.push(0);
        visitedNodes[0] = true;

        while (!nodesToVisit.empty()) {

            int n = nodesToVisit.front();
            nodesToVisit.pop();

            for (int i = 0; i < edges[n].size(); i++) {
                if (visitedNodes[edges[n][i]]) continue;

                visitedNodes[edges[n][i]] = true;
                nodesToVisit.push(edges[n][i]);
                if (!isEdgeInOppDir[n][i]) ans++;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
