/*
 * Created By George on 8/31/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/merge-strings-alternately/
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
    string mergeAlternately(string word1, string word2) {
        std::ostringstream builder;

        int p1 = 0;
        int p2 = 0;
        bool firstStringTurn = true;

        while (p1 < word1.size() && p2 < word2.size()) {
            if (firstStringTurn) {
                builder << word1[p1++];
            } else {
                builder << word2[p2++];
            }
            firstStringTurn = !firstStringTurn;
        }

        while (p1 < word1.size()) {
            builder << word1[p1++];
        }

        while (p2 < word2.size()) {
            builder << word2[p2++];
        }

        return builder.str();
    }
};

int main() {


    return 0;
}