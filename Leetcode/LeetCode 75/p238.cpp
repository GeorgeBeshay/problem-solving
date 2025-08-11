/*
 * Created By George on 8/5/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/product-of-array-except-self/
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        map<int, bool> zero_indices;

        int total_product = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_indices[i] = true;
                continue;
            }
            total_product *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zero_indices.empty()) {
                ans[i] = total_product / nums[i];
            } else if (zero_indices.count(i) == 0) {
                ans[i] = zero_indices.size() > 0 ? 0 : total_product / nums[i];
            } else {
                ans[i] = zero_indices.size() > 1 ? 0 : total_product;
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}