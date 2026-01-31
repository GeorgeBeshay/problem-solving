/*
 * Created By George on 1/31/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> nodesToVisit;
        queue<int> pathCost;
        set<vector<int>> visited;

        nodesToVisit.push(entrance);
        pathCost.push(-1);
        visited.insert(entrance);

        while (!nodesToVisit.empty()) {
            vector<int> node = nodesToVisit.front();
            nodesToVisit.pop();
            int tempCost = pathCost.front() + 1;
            pathCost.pop();

            if (node != entrance) {
                if (
                    node[0] == 0 || node[0] == maze.size() - 1 ||
                    node[1] == 0 || node[1] == maze[0].size() - 1
                ) return tempCost == 0 ? -1 : tempCost;
            }
            vector<vector<int>> neighborNodes = getValidNeighbors(maze, node, visited);
            for (auto& v: neighborNodes) {
                nodesToVisit.push(v);
                visited.insert(v);
                pathCost.push(tempCost);
            }
        }

        return -1;
    }

private:
    vector<vector<int>> getValidNeighbors(vector<vector<char>>& maze, vector<int>& node, set<vector<int>>& visited) {
        vector<vector<int>> ans;

        if (node[0] > 0) {
            vector<int> v = {node[0] - 1, node[1]};
            if (visited.count(v) == 0 && maze[v[0]][v[1]] != '+') {
                ans.push_back(v);
            }
        }
        if (node[0] < maze.size() - 1) {
            vector<int> v = {node[0] + 1, node[1]};
            if (visited.count(v) == 0 && maze[v[0]][v[1]] != '+') {
                ans.push_back(v);
            }
        }
        if (node[1] > 0) {
            vector<int> v = {node[0], node[1] - 1};
            if (visited.count(v) == 0 && maze[v[0]][v[1]] != '+') {
                ans.push_back(v);
            }
        }
        if (node[1] < maze[0].size() - 1) {
            vector<int> v = {node[0], node[1] + 1};
            if (visited.count(v) == 0 && maze[v[0]][v[1]] != '+') {
                ans.push_back(v);
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<char>> maze = {
        {'+', '.', '+', '+', '+', '+', '+'},
        {'+', '.', '+', '.', '.', '.', '+'},
        {'+', '.', '+', '.', '+', '.', '+'},
        {'+', '.', '.', '.', '.', '.', '+'},
        {'+', '+', '+', '+', '.', '+', '.'}
    };
    vector<int> entrance = {0, 1};

    Solution solution;

    cout << solution.nearestExit(maze, entrance);

    return 0;
}
