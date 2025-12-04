/*
 * Created By George on 11/30/2025.
 */

/*
 * Problem Link:    https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/merge-and-sort-intervals/
 * Problem Status:  Accepted.
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

vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
    vector<vector<int>> merged;

    if (intervals.empty()) {
        return merged;
    }

    sort(intervals.begin(), intervals.end(), [](vector<int> i1, vector<int> i2){
        return i1[0] < i2[0];
    });

    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {

        if (intervals[i][0] <= currentEnd) {
            currentEnd = max(currentEnd, intervals[i][1]);
            continue;
        }

        merged.push_back({currentStart, currentEnd});
        currentStart = intervals[i][0];
        currentEnd = intervals[i][1];
    }
    merged.push_back({currentStart, currentEnd});

    return merged;
}

int main() {


    return 0;
}