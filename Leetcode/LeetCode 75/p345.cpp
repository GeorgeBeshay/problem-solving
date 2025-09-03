/*
 * Created By George on 9/3/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/reverse-vowels-of-a-string/
 * Problem Status:          Accepted.
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
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        map<char, bool> vowels = {
            {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
            {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}
        };

        while (left < right) {
            if (vowels[s[left]]) {
                while (!vowels[s[right]]) right--;
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                right--;
            }
            left++;
        }

        return s;
    }
};

int main() {


    return 0;
}