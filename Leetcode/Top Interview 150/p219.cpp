/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/contains-duplicate-ii/
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> numToIdxMap;

        for (int i = 0; i < nums.size(); i++) {
            if (numToIdxMap.count(nums[i]) == 0) {
                numToIdxMap[nums[i]] = i;
                continue;
            }

            if (i - numToIdxMap[nums[i]] <= k) {
                return true;
            }

            numToIdxMap[nums[i]] = i;
        }

        return false;
    }
};

int main() {


    return 0;
}