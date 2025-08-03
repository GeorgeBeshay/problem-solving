/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/happy-number/
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
    void split_digits(int n, vector<int>& digits) {
        int temp_mod = 10;

        while (n != 0) {
            digits.push_back(n % temp_mod);
            n /= temp_mod;
        }
    }

    long compute_sum_of_digit_squares(const vector<int>& digits) {
        long ans = 0;
        for (int digit: digits) {
            ans += digit * digit;
        }

        return ans;
    }

    bool isHappy(int n) {
        map<long, bool> occurrence_check;
        long current_n = n;

        while (current_n != 1) {
            if (occurrence_check.count(current_n) != 0) {
                return false;
            }

            occurrence_check[current_n] = true;
            vector<int> temp_digits;
            split_digits(current_n, temp_digits);
            current_n = compute_sum_of_digit_squares(temp_digits);
        }

        return true;
    }
};

int main() {


    return 0;
}