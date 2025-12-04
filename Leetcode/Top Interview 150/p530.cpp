/*
* Created By George on 12/3/2025.
*/

/*
 * Problem Link:        https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return MAX_INT;
        }
        int temp1 = getMinimumDifference(root->right);
        int temp2 = getMinimumDifference(root->left);
        int temp3 = min(abs(root->val - getMaxInSubTree(root->left)), abs(root->val - getMinInSubTree(root->right)));

        return min(min(temp1, temp2), temp3);
    }

    int getMaxInSubTree(TreeNode* root) {
        if (root == nullptr) {
            return MAX_INT;
        }
        if (root->right != nullptr) {
            return getMaxInSubTree(root->right);
        }
        return root->val;
    }

    int getMinInSubTree(TreeNode* root) {
        if (root == nullptr) {
            return MAX_INT;
        }
        if (root->left != nullptr) {
            return getMinInSubTree(root->left);
        }
        return root->val;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(3);


    Solution solution;
    cout << solution.getMinimumDifference(root) << endl;

    delete root;

    return 0;
}