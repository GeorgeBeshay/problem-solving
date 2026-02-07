/*
 * Created By George on 2/7/2026.
 */

/*
 * Problem Link:            https://leetcode.com/problems/rotting-oranges/
 * Problem Status:          Accepted.
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
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> nextMinuteGrid(grid);
        int ans = 0;
        bool changesHappened =  true;

        while (changesHappened) {
            changesHappened = false;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 0 || grid[i][j] == 1) continue;

                    if (i < grid.size() - 1 && grid[i+1][j] == 1) {
                        nextMinuteGrid[i+1][j] = 2;
                        changesHappened = true;
                    }
                    if (j < grid[0].size() - 1 && grid[i][j+1] == 1) {
                        nextMinuteGrid[i][j+1] = 2;
                        changesHappened = true;
                    }
                    if (i > 0 && grid[i-1][j] == 1) {
                        nextMinuteGrid[i-1][j] = 2;
                        changesHappened = true;
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        nextMinuteGrid[i][j-1] = 2;
                        changesHappened = true;
                    }
                }
            }
            if (changesHappened) ans++;
            grid = nextMinuteGrid;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
