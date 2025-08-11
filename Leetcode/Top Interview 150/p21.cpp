/*
 * Created By George on 8/4/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/merge-two-sorted-lists/
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

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* current_node = list1->val <= list2->val ? list1 : list2;
        ListNode* temp_list1 = list1->val <= list2->val ? list1->next : list1;
        ListNode* temp_list2 = list1->val <= list2->val ? list2 : list2->next;

        while (temp_list1 != nullptr && temp_list2 != nullptr) {
            if (temp_list1->val <= temp_list2->val) {
                current_node->next = temp_list1;
                temp_list1 = temp_list1->next;
            } else {
                current_node->next = temp_list2;
                temp_list2 = temp_list2->next;
            }
            current_node = current_node->next;
        }

        if (temp_list1 != nullptr) {
            current_node->next = temp_list1;
        } else if (temp_list2 != nullptr) {
            current_node->next = temp_list2;
        }

        return list1->val <= list2->val ? list1 : list2;
    }
};

int main() {


    return 0;
}