/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/summary-ranges/
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

    void updateRanges(vector<string>& existing_ranges, int begin, int end) {
        if (begin != end) {
            existing_ranges.push_back(to_string(begin) + "->" + to_string(end));
        } else {
            existing_ranges.push_back(to_string(begin));
        }
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        if (nums.empty()) {
            return ans;
        }

        int begin = nums[0];
        int end = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (end + 1)) {
                end = nums[i];
                continue;
            }

            updateRanges(ans, begin, end);
            begin = nums[i];
            end = nums[i];
        }
        updateRanges(ans, begin, end);

        return ans;
    }
};

int main() {


    return 0;
}