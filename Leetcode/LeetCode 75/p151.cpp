/*
 * Created By George on 8/31/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/reverse-words-in-a-string/
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
    string reverseWords(string s) {
        vector<string> strings;

        ostringstream builder;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            while (s[i] != ' ') {
                builder << s[i++];
                if (i >= s.size()) {
                    break;
                }
            }
            strings.push_back(builder.str());
            builder.str("");
            builder.clear();
        }

        for (string s : strings) {
            cout << s << endl;
        }

        builder.str("");
        builder.clear();
        for (int i = strings.size() - 1; i >= 0; i--) {
            builder << strings[i];
            if (i != 0) {
                builder << " ";
            }
        }

        return builder.str();
    }
};

int main() {


    return 0;
}