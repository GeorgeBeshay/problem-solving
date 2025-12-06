/*
 * Created By George on 12/6/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/determine-if-two-strings-are-close/
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
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        map<char, int> freq1, freq2;
        for (char c: word1) freq1[c]++;
        for (char c: word2) freq2[c]++;

        vector<char> charsToBeRemoved;
        for (auto &entry: freq1) {
            if (freq2.count(entry.first) == 0) return false;

            if (freq2[entry.first] == entry.second) charsToBeRemoved.push_back(entry.first);
        }

        for (auto &c: charsToBeRemoved) {
            freq1.erase(c);
            freq2.erase(c);
        }

        map<int, vector<char>> availableCharsOfSize;
        for (auto &entry: freq1) availableCharsOfSize[entry.second].push_back(entry.first);

        charsToBeRemoved.clear();
        for (auto &entry: freq2) {
            if (availableCharsOfSize[entry.second].empty()) return false;

            charsToBeRemoved.push_back(entry.first);
            availableCharsOfSize[entry.second].pop_back();
        }

        for (auto &c: charsToBeRemoved) freq2.erase(c);
        if (freq2.empty()) return true;

        return false;
    }
};

int main() {


    return 0;
}