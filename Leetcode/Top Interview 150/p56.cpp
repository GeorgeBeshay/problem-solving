/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/merge-intervals/
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> new_intervals;

        // sort the intervals based on the start_i element.
        sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        int begin_idx = 0;
        int end_idx = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > intervals[end_idx][1]) {
                new_intervals.push_back(
                    {
                        intervals[begin_idx][0],
                        max(intervals[end_idx][1], intervals[begin_idx][1])
                    }
                );
                begin_idx = i;
                end_idx = i;
                continue;
            }

            end_idx = intervals[i][1] >= intervals[end_idx][1] ? i : end_idx;
        }
        new_intervals.push_back(
            {
                intervals[begin_idx][0],
                max(intervals[end_idx][1], intervals[begin_idx][1])
            }
        );

        return new_intervals;
    }
};

int main() {


    return 0;
}