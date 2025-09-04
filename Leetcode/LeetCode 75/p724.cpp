/*
 * Created By George on 9/4/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/find-pivot-index/
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
    int pivotIndex(vector<int>& nums) {
        vector<int> leftPrefix(nums.size());
        vector<int> rightPrefix(nums.size());

        leftPrefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            leftPrefix[i] = leftPrefix[i-1] + nums[i];
        }

        rightPrefix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            rightPrefix[i] = rightPrefix[i+1] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && i < nums.size() - 1) {
                if (leftPrefix[i-1] == rightPrefix[i+1]) {
                    return i;
                }
            } else if (i == 0 && i < nums.size() - 1) {
                if (rightPrefix[i+1] == 0) {
                    return i;
                }
            } else if(i > 0 && i == nums.size() - 1) {
                if (leftPrefix[i-1] == 0) {
                    return i;
                }
            } else {
                return 0;
            }
        }

        return -1;
    }
};

int main() {


    return 0;
}