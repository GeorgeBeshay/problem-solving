/*
 * Created By George on 11/24/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/surrounded-regions/
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
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                map<pair<int, int>, bool> visited;
                if (board[i][j] == 'O' && check(board, i, j, visited)){
                    zeroOut(board, i, j);
                }
            }
        }
    }

    bool check(
        vector<vector<char>>& board,
        int i,
        int j,
        map<pair<int, int>, bool>& visited
    ) {
        pair<int, int> pr = {i, j};
        if (visited[pr]) {
            return true;
        }

        visited[pr] = true;
        if (board[i][j] == 'X') return true;

        bool ans = true;

        if (
            (i == board.size() - 1) ||
            (j == board[0].size() - 1) ||
            i == 0 ||
            j == 0
            ) {
            ans = false;
        }

        if (i < board.size() - 1) {
            ans = ans && check(board, i+1, j, visited);
        }
        if (j < board[0].size() - 1) {
            ans = ans && check(board, i, j+1, visited);
        }
        if (i > 0) {
            ans = ans && check(board, i-1, j, visited);
        }
        if (j > 0) {
            ans = ans && check(board, i, j-1, visited);
        }

        return ans;
    }

    void zeroOut(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = 'X';
        } else {
            return;
        }

        if (i < board.size() - 1) {
            zeroOut(board, i+1, j);
        }
        if (i > 0) {
            zeroOut(board, i-1, j);
        }
        if (j < board[0].size() - 1) {
            zeroOut(board, i, j + 1);
        }
        if (j > 0) {
            zeroOut(board, i, j - 1);
        }

    }
};

int main() {

    Solution sol;

//    vector<vector<char>> v = {
//        {'X','X','X','X'},
//        {'X','O','O','X'},
//        {'X','X','O','X'},
//        {'X','O','X','X'}
//    };

    vector<vector<char>> v = {
        {'O','O','O'},
        {'O','O','O'},
        {'O','O','O'},
    };

    sol.solve(v);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}