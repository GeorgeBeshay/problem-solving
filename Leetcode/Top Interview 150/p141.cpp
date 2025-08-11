/*
 * Created By George on 8/3/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/linked-list-cycle/
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> is_visited;

        ListNode *temp_node = head;
        while (temp_node != nullptr && temp_node->next != nullptr) {

            if (is_visited[temp_node]) {
                return true;
            }

            is_visited[temp_node] = true;
            temp_node = temp_node->next;
        }

        return false;
    }
};

int main() {


    return 0;
}