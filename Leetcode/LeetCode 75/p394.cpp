

/*
 * Created By George on 12/9/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/decode-string/
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
    string decodeString(string s) {
        stack<char> tempS;

        for (char c: s) {
            if (c != ']') {
                tempS.push(c);
                continue;
            }

            string substring;
            while (tempS.top() != '[') {
                substring += tempS.top();
                tempS.pop();
            }
            reverse(substring.begin(), substring.end());
            tempS.pop();

            string repeatString;
            while (tempS.top() >= '0' && tempS.top() <= '9') {
                repeatString += tempS.top();
                tempS.pop();
                if (tempS.empty()) {
                    break;
                }
            }
            reverse(repeatString.begin(), repeatString.end());
            int count = stoi(repeatString);

            string tempAns;
            for (int i = 0; i < count; i++) {
                tempAns += substring;
            }
            for (char c2: tempAns) {
                tempS.push(c2);
            }
        }

        string ans;
        while (!tempS.empty()) {
            ans += tempS.top();
            tempS.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    Solution solution;
    cout << solution.decodeString("20[a]");

    return 0;
}
