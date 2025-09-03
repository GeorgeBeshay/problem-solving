/*
 * Created By George on 8/31/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/greatest-common-divisor-of-strings/
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
    string repeat(string base, int count) {
        string result;
        result.reserve(base.size() * count);

        for (int i = 0; i < count ; i++) {
            result += base;
        }

        return result;
    }
    string gcdOfStrings(string str1, string str2) {
        string shorterStr = str1.size() <= str2.size() ? str1 : str2;

        string ans;
        std::ostringstream currentSubstring;
        for (int i = 0; i < shorterStr.size(); i++) {
            // if the size of the current substring can't be repeated to create any of
            // both strings, then skip.
            currentSubstring << shorterStr[i];
            if (str1.size() % (i+1) != 0 || str2.size() % (i+1) != 0) {
                continue;
            }

            string tempCurrentSubstring = currentSubstring.str();
            if (
                repeat(tempCurrentSubstring, str1.size() / (i+1) ) == str1 &&
                repeat(tempCurrentSubstring, str2.size() / (i+1) ) == str2
                ) {
                ans = tempCurrentSubstring;
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}