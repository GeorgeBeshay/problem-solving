/*
 * Created By George on 12/8/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/removing-stars-from-a-string/
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int> > vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

class Solution {
public:
    string removeStars(string s) {
        bool shouldBeEscaped[s.size()];
        string ans;

        int tempStarCount = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                shouldBeEscaped[i] = true;
                tempStarCount++;
            } else {
                if (tempStarCount > 0) {
                    shouldBeEscaped[i] = true;
                    tempStarCount--;
                } else {
                    shouldBeEscaped[i] = false;
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (shouldBeEscaped[i]) continue;
            ans += s[i];
        }

        return ans;
    }
};

int main() {
    return 0;
}
