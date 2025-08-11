/*
 * Created By George on 8/4/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/increasing-triplet-subsequence/
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
    bool increasingTriplet(vector<int>& nums) {

        int lower_bound = MAX_INT;
        int upper_bound = MAX_INT;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= lower_bound) {
                lower_bound = nums[i];
            } else if (nums[i] <= upper_bound) {
                upper_bound = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {


    return 0;
}