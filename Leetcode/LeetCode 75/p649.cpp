/*
* Created By George on 12/10/2025.
 */

 /*
  * Problem Link:       https://leetcode.com/problems/dota2-senate/
  * Problem Status:     Accepted.
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
    string predictPartyVictory(string senate) {

        int direCount = 0, radiantCount = 0;
        queue<char> nextTurn;

        for (const char c: senate) {
            nextTurn.push(c);
        }

        while (!nextTurn.empty()) {
            if (nextTurn.size() == 1) {
                return nextTurn.front() == 'D' ? "Dire" : "Radiant";
            }
            if (direCount > senate.size()) {
                return "Dire";
            }
            if (radiantCount > senate.size()) {
                return "Radiant";
            }

            const char current = nextTurn.front(); nextTurn.pop();
            if (current == 'D') {
                if (radiantCount > 0) {
                    radiantCount--;
                } else {
                    direCount++;
                    nextTurn.push(current);
                }
            } else {
                if (direCount > 0) {
                    direCount--;
                } else {
                    radiantCount++;
                    nextTurn.push(current);
                }
            }
        }

        return "INVALID STATE";
    }
};

int main() {
    return 0;
}