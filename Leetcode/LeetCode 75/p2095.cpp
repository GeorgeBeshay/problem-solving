/*
 * Created By George on 12/12/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;

        ListNode* tempNode = head;
        while (tempNode != nullptr) {
            n++;
            tempNode = tempNode->next;
        }

        if (n == 1) return nullptr;

        int targetNodeIdx = max(0, (int)floor(n / 2) - 1);

        int tempIdx = 0;
        tempNode = head;
        while (tempIdx != targetNodeIdx) {
            tempIdx++;
            tempNode = tempNode->next;
        }

        tempNode->next = tempNode->next->next;

        return head;
    }
};

int main() {
    return 0;
}
