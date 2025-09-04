/*
 * Created By George on 9/4/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/find-the-highest-altitude/
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

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        vector<int> alts(gain.size() + 1);
        alts[0] = 0;

        int ans = 0;
        int prefix = 0;
        for (int i = 0; i < gain.size(); i++) {
            prefix += gain[i];
            alts[i+1] = prefix;
            ans = max(ans, prefix);
        }

        return ans;
    }
};

int main() {


    return 0;
}