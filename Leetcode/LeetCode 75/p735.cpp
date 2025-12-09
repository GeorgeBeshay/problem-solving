/*
 * Created By George on 12/9/2025.
 */
 
 /*
  * Problem Link:       https://leetcode.com/problems/asteroid-collision/
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int asteroid : asteroids) {
            s.push(asteroid);
            if (s.size() < 2) continue;

            bool shouldRepeat = false;

            do {
                int temp1 = s.top(); s.pop();
                int temp2 = s.top(); s.pop();
                shouldRepeat = false;

                if (!(isPositive(temp2) && !isPositive(temp1))) {
                    s.push(temp2);
                    s.push(temp1);
                    continue;
                }

                if (abs(temp1) == abs(temp2)) continue;

                if (abs(temp1) > abs(temp2)) {
                    s.push(temp1);
                } else {
                    s.push(temp2);
                }
                shouldRepeat = s.size() >= 2;

            } while (shouldRepeat);

        }

        vector<int> ans(s.size());
        while (!s.empty()) {
            ans[s.size()-1] = s.top();
            s.pop();
        }

        return ans;
    }

    static bool isPositive(int x) {
        return x > 0;
    }
};

int main(){
    
    vector<int> v = {10, 2, -5};
    Solution solution;
    solution.asteroidCollision(v);
        
    return 0;
}