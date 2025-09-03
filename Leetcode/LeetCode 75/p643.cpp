/*
 * Created By George on 9/3/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/maximum-average-subarray-i/
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
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = -pow(10, 5);
        double tempSum = 0;
        int left = 0;
        int right = k - 1;

        for (int i = 0; i < k; i++) {
            tempSum += nums[i];
        }

        maxAvg = max(maxAvg, tempSum / (double)k );
        while (right < nums.size() - 1) {
            tempSum -= nums[left];
            tempSum += nums[right + 1];
            maxAvg = max(maxAvg, tempSum / (double)k );
            left++;
            right++;
        }

        return maxAvg;
    }
};

int main() {


    return 0;
}