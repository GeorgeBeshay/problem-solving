/*
 * Created By George on 12/7/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/equal-row-and-column-pairs/
 * Problem Status:          Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

#define MIN_INT numeric_limits<int>::min()

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<vector<int>, int> rowsFreq;
        int ans = 0;


        for (vector<int>& v: grid) {
            rowsFreq[v]++;
        }

        for (int i = 0; i < grid[0].size(); i++) {
            vector<int> tempV(grid.size());
            for (int j = 0; j < grid.size(); j++) {
                tempV[j] = grid[j][i];
            }
            ans += rowsFreq[tempV];
        }

        return ans;
    }
};

int main() {

    map<vector<int>, int> m;

    vector<int> x {1, 2, 3};
    vector<int> y {1, 2, 3};

    m[x]++;
    m[y]++;

    cout << m[x] << endl;


    return 0;
}