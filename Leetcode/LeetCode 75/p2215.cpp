/*
 * Created By George on 9/21/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/find-the-difference-of-two-arrays/
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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        map<int, bool> m1, m2;

        for (int num: nums1) {
            m1[num] = true;
        }
        for (int num: nums2) {
            m2[num] = true;
        }

        for (const auto& entry: m1) {
            if (m2.find(entry.first) == m2.end()) {
                answer[0].push_back(entry.first);
            }
        }
        for (const auto& entry: m2) {
            if (m1.find(entry.first) == m1.end()) {
                answer[1].push_back(entry.first);
            }
        }

        return answer;
    }
};

int main() {


    return 0;
}