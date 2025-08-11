/*
 * Created By George on 8/4/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/pascals-triangle/
 * Problem Status:      Accepted.
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

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = {{1}};

        for (int i = 1; i < numRows; i++) {
            vector<int> newRow = {1};
            for (int j = 1; j <= i - 1; j++) {
                newRow.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            }
            newRow.push_back(1);
            triangle.push_back(newRow);
        }

        return triangle;
    }
};

int main() {


    return 0;
}