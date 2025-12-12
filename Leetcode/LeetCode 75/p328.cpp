/*
 * Created By George on 12/12/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* evenList = head;
        ListNode* oddList = head->next;
        ListNode* tempEven = evenList;
        ListNode* tempOdd = oddList;

        ListNode* tempNode = oddList->next;
        int tempIdx = 0;
        while (tempNode != nullptr) {
            if (tempIdx % 2 == 0) {
                tempEven->next = tempNode;
                tempEven = tempEven->next;
            } else {
                tempOdd->next = tempNode;
                tempOdd = tempOdd->next;
            }
            tempNode = tempNode->next;
            tempIdx++;
        }
        tempOdd->next = nullptr;
        tempEven->next = oddList;

        return evenList;
    }
};

int main() {

    Solution solution;

    auto *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* newList = solution.oddEvenList(head);

    ListNode* temp = newList;
    while (temp != nullptr) {
        cout << temp->val << endl;
        temp = temp->next;
    }

    return 0;
}
