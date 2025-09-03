/*
 * Created By George on 8/31/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());

        int maxCandies = 0;
        for (int tempCandy: candies) {
            if (tempCandy > maxCandies) {
                maxCandies = tempCandy;
            }
        }

        for (int i = 0; i < candies.size(); i++) {
            ans[i] = ((candies[i] + extraCandies) >= maxCandies);
        }

        return ans;
    }
};

int main() {


    return 0;
}