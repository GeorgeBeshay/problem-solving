/*
 * Created By George on 9/3/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/container-with-most-water/
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
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            ans = max (
                ans,
                (right - left) * min(height[left], height[right])
            );

            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}