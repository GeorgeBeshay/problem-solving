/*
 * Created By George on 9/1/2025.
 */

/*
 * Problem Link:    https://leetcode.com/problems/can-place-flowers/
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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int alreadyPlanted = 0;
        int canBePlanted = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                alreadyPlanted++;
            } else {
                if (i > 0 && i < flowerbed.size() - 1) {
                    if (flowerbed[i-1] + flowerbed[i+1] == 0) {
                        canBePlanted++;
                        flowerbed[i] = 1;
                    }
                } else if (i > 0) {
                    if (flowerbed[i-1] == 0) {
                        canBePlanted++;
                        flowerbed[i] = 1;
                    }
                } else if (i < flowerbed.size() - 1) {
                    if (flowerbed[i+1] == 0) {
                        canBePlanted++;
                        flowerbed[i] = 1;
                    }
                } else {
                    // flowerbed size is 1
                    canBePlanted++;
                }
            }
        }

        return canBePlanted >= n;

    }
};

int main() {


    return 0;
}