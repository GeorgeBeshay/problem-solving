/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/two-sum/
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
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> numToIdxMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            if (numToIdxMap.count(target - nums[i]) != 0) {
                result = {i, numToIdxMap[target - nums[i]]};
            }

            // this will override the previous occurrence of the same number.
            // but that's okay.
            numToIdxMap[nums[i]] = i;
        }

        return result;
    }
};

int main() {


    return 0;
}