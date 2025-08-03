/*
 * Created By George on 5/1/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
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
    int computeMaxElement(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans) {
                ans = nums[i];
            }
        }
        return ans;
    }

    vector<int> computeMaxElementPositions(vector<int>& nums, int maxValue) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxValue) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    int binarySearchForGTE(vector<int>& nums, int target) {
        if (target > nums[nums.size() - 1]) {
            return -1;
        }

        int left = 0;
        int right = nums.size();
        int mid;
        int ans = -1;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    long long countSubarrays(vector<int>& nums, int k) {

        int maxValue = computeMaxElement(nums);
        vector<int> occurrences = computeMaxElementPositions(nums, maxValue);

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int correspondingOccurrenceIdx = binarySearchForGTE(occurrences, i);
            int kthBoundaryElement = correspondingOccurrenceIdx + k - 1;

            if (correspondingOccurrenceIdx >= occurrences.size() || kthBoundaryElement >= occurrences.size()) {
                continue;
            }

            ans += (int)nums.size() - occurrences[kthBoundaryElement];
        }

        return ans;

    }
};

int main() {
    /*
    1, 3, 4
    0 -> [3, 4]
    1 -> [3, 4]
    2 -> [4]
    3 -> [4]
    */

    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    Solution solution;

    cout << solution.countSubarrays(nums, k) << endl;

    return 0;
}