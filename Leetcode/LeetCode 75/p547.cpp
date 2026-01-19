/*
 * Created By George on 1/19/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/number-of-provinces/
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size());

        for (int c1 = 0; c1 < isConnected.size(); c1++) {
            if (visited[c1]) continue;
            count++;
            explore(isConnected, visited, c1);
        }

        return count;
    }

    void explore(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        queue<int> toVisit;
        if (visited[node]) return;

        visited[node] = true;
        toVisit.push(node);

        while (!toVisit.empty()) {
            int beingVisited = toVisit.front();
            toVisit.pop();

            for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {

                if (!isConnected[beingVisited][neighbor]) continue;
                if (visited[neighbor]) continue;

                visited[neighbor] = true;
                toVisit.push(neighbor);
            }
        }
    }
};

int main() {
    return 0;
}
