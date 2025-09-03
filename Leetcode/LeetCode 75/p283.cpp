/*
 * Created By George on 9/3/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/move-zeroes/
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
    void moveZeroes(vector<int>& nums) {

        int left1 = 0;
        int left2 = 1;

        while (left1 < left2 && left2 < nums.size()) {
            if (nums[left1] != 0) {
                left1++;
                left2++;
                continue;
            }
            if (nums[left2] == 0) {
                left2++;
                continue;
            }
            nums[left1] = nums[left2];
            nums[left2] = 0;
            left1++;
            left2++;
        }

    }
};

int main() {


    return 0;
}