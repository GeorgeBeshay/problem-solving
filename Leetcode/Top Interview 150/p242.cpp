/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/valid-anagram/
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
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        map<char, int> letters_count;

        for (char c: s) {
            letters_count[c]++;
        }

        for (char c: t) {
            if (letters_count[c] == 0) {
                return false;
            }

            letters_count[c]--;
        }

        return true;
    }
};

int main() {


    return 0;
}