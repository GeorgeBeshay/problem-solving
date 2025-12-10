/*
 * Created By George on 12/10/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/number-of-recent-calls/
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int> > vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

class RecentCounter {
private:
    queue<int> timestamps;

public:
    RecentCounter() {
    }

    int ping(int t) {
        timestamps.push(t);

        while (timestamps.front() < t - 3000) {
            timestamps.pop();
        }

        return timestamps.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    return 0;
}
