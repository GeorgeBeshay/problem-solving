/*
 * Created By George on 8/4/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/string-compression/
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

    char extractLastDigitAndUpdateNumber(int* num) {
        int ans = *num % 10;
        *num = *num / 10;
        return '0' + ans;
    }

    int updateCharsArray(vector<char>& chars, int current_idx, char last_char, int temp_count) {
        chars[current_idx++] = last_char;
        if (temp_count > 1) {
            stack<char> temp_num_stack;
            while (temp_count > 0) {
                temp_num_stack.push(
                    extractLastDigitAndUpdateNumber(&temp_count)
                );
            }
            while (!temp_num_stack.empty()) {
                chars[current_idx++] = temp_num_stack.top();
                temp_num_stack.pop();
            }
        }

        return current_idx;
    }

    int compress(vector<char>& chars) {
        if (chars.empty()) {
            return 0;
        }

        int current_idx = 0;

        char last_char = chars[0];
        int temp_count = 1;
        for (int i = 1; i < chars.size(); i++) {

            if (chars[i] == last_char) {
                temp_count++;
                continue;
            }

            current_idx = updateCharsArray(chars, current_idx, last_char, temp_count);
            last_char = chars[i];
            temp_count = 1;
        }
        current_idx = updateCharsArray(chars, current_idx, last_char, temp_count);

        return current_idx;
    }
};

int main() {


    return 0;
}