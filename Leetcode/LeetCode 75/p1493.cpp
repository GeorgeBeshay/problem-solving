/*
 * Created By George on 9/4/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
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
    int longestSubarray(vector<int>& nums) {

        int ans = 0;
        int start = 0;
        int zeroPos = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                start = zeroPos + 1;
                zeroPos = i;
            }
            ans = max(ans, i - start);
        }


        return ans;
    }
};

int main() {


    return 0;
}