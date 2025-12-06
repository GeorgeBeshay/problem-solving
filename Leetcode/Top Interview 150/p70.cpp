/*
 * Created By George on 12/5/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/climbing-stairs/
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
    int climbStairs(int n) {
        map<int, int> memo;
        return recursiveClimbStairs(n, memo);
    }

    int recursiveClimbStairs(int n, map<int, int>& memo) {
        if (n == 0 || n == 1) return 1;

        if (memo.count(n) > 0) {
            return memo[n];
        }
        memo[n] = recursiveClimbStairs(n-1, memo) + recursiveClimbStairs(n-2, memo);

        return memo[n];
    }
};

int main() {


    return 0;
}