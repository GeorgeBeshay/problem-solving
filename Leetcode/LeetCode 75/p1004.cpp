/*
 * Created By George on 9/4/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/max-consecutive-ones-iii/
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
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int tempK = k;

        int left = 0;
        int right = 0;

        while (left <= right && right < nums.size()) {
            if (nums[right] != 0) {
                right++;
                ans = max(ans, right - left);
            } else {
                if (tempK > 0) {
                    tempK--;
                    right++;
                    ans = max(ans, right - left);
                } else {
                    if (right == left) {
                        left++;
                        right++;
                    } else {
                        if (nums[left] == 0) {
                            tempK++;
                        }
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}