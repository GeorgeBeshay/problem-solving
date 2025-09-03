/*
 * Created By George on 9/3/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
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
    int maxVowels(string s, int k) {
        map<char, bool> vowels = {
            {'a', true},
            {'e', true},
            {'i', true},
            {'o', true},
            {'u', true}
        };

        int tempCount = 0;

        for (int i = 0; i < k; i++) {
            tempCount += vowels[s[i]] ? 1 : 0;
        }
        int ans = tempCount;

        int left = 1;
        int right = k;
        while (right < s.size()) {
            tempCount -= vowels[s[left - 1]] ? 1 : 0;
            tempCount += vowels[s[right]] ? 1 : 0;
            ans = max(ans, tempCount);
            left++;
            right++;
        }

        return ans;
    }
};

int main() {


    return 0;
}