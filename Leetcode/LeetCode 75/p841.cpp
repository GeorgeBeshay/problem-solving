/*
 * Created By George on 1/17/2026.
 */
 
 /*
  * Problem Link:           https://leetcode.com/problems/keys-and-rooms/
  * Problem Status:         Accepted.
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int, bool> visited;
        int visitedCount = 0;
        stack<int> canVisit;
        canVisit.push(0);

        while (!canVisit.empty()) {

            int nextNode = canVisit.top();
            canVisit.pop();
            visitedCount++;
            visited[nextNode] = true;

            for (const auto& possibleNode: rooms[nextNode]) {
                if (!visited[possibleNode]) canVisit.push(possibleNode);
            }

        }

        if (visitedCount >= rooms.size()) return true;
        return false;
    }
};

int main(){

    Solution sol;

    vector<vector<int>> v;
    veci v1 = {1};
    veci v2 = {1};
    v.push_back(v1);
    v.push_back(v2);

    cout << sol.canVisitAllRooms(v);
    
        
    return 0;
}