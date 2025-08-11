/*
 * Created By George on 8/11/2025.
 */

/*
 * Problem Link:    https://leetcode.com/problems/range-product-queries-of-powers/
 * Problem Status:  Accepted.
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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> powers;
        vector<int> answers(queries.size());
        int mod = (int)pow(10, 9) + 7;

        while (n > 0) {
            int exp = (int)log2(n); // take the maximum exponent smaller than log2.
            int temp_power = pow(2, exp);
            powers.push_back(temp_power);
            n -= temp_power;
        }

        for (int i = 0; i < queries.size(); i++) {
            int lower = powers.size() - queries[i][1] - 1;
            int upper = powers.size() - queries[i][0] - 1;
            answers[i] = 1;
            for (int j = lower; j <= upper; j++) {
                answers[i] = ((long)answers[i] * (long)powers[j]) % mod;
            }
        }

        return answers;
    }
};

int main() {


    return 0;
}