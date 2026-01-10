

/*
 * Created By George on 1/10/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<bool> v = {false, false};
        return findRecursive(root, p, q, v);
    }

    TreeNode* findRecursive(TreeNode* root, TreeNode* p, TreeNode* q, vector<bool>& found) {
        if (root == nullptr) return nullptr;

        vector<bool> before(found);

        TreeNode* temp1 = findRecursive(root->left, p, q, found);
        if (temp1 != nullptr) return temp1;

        TreeNode* temp2 = findRecursive(root->right, p, q, found);
        if (temp2 != nullptr) return temp2;

        if (root->val == q->val) {
            found[0] = true;
            if (found[0] && found[1] && !before[1]) return root;
        }
        if (root->val == p->val) {
            found[1] = true;
            if (found[0] && found[1] && !before[0]) return root;
        }

        if (found[0] && found[1] && !before[0] && !before[1]) return root;

        return nullptr;
    }
};

int main() {
    return 0;
}
