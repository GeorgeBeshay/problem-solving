/*
 * Created By George on 10/4/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/unique-number-of-occurrences/
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
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> freq;
        for (int num: arr) {
            freq[num]++;
        }

        set<int> uniqueFreq;
        for (const auto& kv: freq) {
            uniqueFreq.insert(kv.second);
        }

        return freq.size() == uniqueFreq.size();
    }
};

int main() {


    return 0;
}