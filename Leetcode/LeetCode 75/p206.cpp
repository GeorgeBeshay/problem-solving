/*
 * Created By George on 12/13/2025.
 */

/*
 * Problem Link:            https://leetcode.com/problems/reverse-linked-list/
 * Problem Status:          Accepted.
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


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        const ListNode* temp = head;
        ListNode* newList = nullptr;

        while(temp != nullptr) {
            if (newList == nullptr) {
                newList = new ListNode(temp->val);
            } else {
                newList = new ListNode(temp->val, newList);
            }
            temp = temp->next;
        }

        return newList;
    }
};

int main() {
    return 0;
}
