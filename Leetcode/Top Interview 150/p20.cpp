/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/valid-parentheses/
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

    bool isOpeningBrackets(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    bool doMatch(char opening, char closing) {
        switch (opening) {
            case '(':
                return closing == ')';
            case '{':
                return closing == '}';
            case '[':
                return closing == ']';
            default:
                return false;
        }

        return false;
    }

    bool isValid(string s) {
        stack<char> temp_stack;

        for(char c: s) {
            if (isOpeningBrackets(c)) {
                temp_stack.push(c);

            } else {

                if (temp_stack.empty()) {
                    return false;
                }

                char prev_c = temp_stack.top();
                temp_stack.pop();

                if (!doMatch(prev_c, c)) {
                    return false;
                }
            }
        }

        if (temp_stack.empty()) {
            return true;
        }
        return false;
    }
};

int main() {


    return 0;
}