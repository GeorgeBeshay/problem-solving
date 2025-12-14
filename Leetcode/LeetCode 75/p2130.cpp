/*
 * Created By George on 12/14/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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
    int pairSum(ListNode* head) {
        ListNode* newHead = head;

        ListNode* temp = head->next;
        while (temp != nullptr) {
            newHead = new ListNode(temp->val, newHead);
            temp = temp->next;
        }

        int maxVal = 0;
        ListNode* temp2 = newHead;
        temp = head;

        while (temp != nullptr) {
            maxVal = max(maxVal, temp->val + temp2->val);
            temp = temp->next;
            temp2 = temp2->next;
        }

        return maxVal;
    }
};

int main() {
    return 0;
}
