/*
 * Created By George on 1/15/2026.
 */
 
 /*
  * Problem Link:       https://leetcode.com/problems/delete-node-in-a-bst/
  * Problem Status:     Accepted.
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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* node = findNode(root, key);
        if (node == nullptr) return root;

        if (node->right != nullptr) {
            TreeNode* leftMostParent = findLeftMost(node->right);
            if (leftMostParent == nullptr) {
                node->val = node->right->val;
                node->right = node->right->right;
            } else {
                node->val = leftMostParent->left->val;
                leftMostParent->left = leftMostParent->left->right;
            }
        } else if (node->left != nullptr) {
            TreeNode* rightMostParent = findRightMost(node->left);
            if (rightMostParent == nullptr) {
                node->val = node->left->val;
                node->left = node->left->left;
            } else {
                node->val = rightMostParent->right->val;
                rightMostParent->right = rightMostParent->right->left;
            }
        } else {
            TreeNode* parentNode = findParent(root, key);
            if (parentNode == nullptr) return nullptr;
            if (parentNode->left != nullptr && parentNode->left->val == key) {
                parentNode->left = nullptr;
            } else {
                parentNode->right = nullptr;
            }
        }

        return root;

    }

    TreeNode* findParent(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr && root->left->val == key) return root;
        if (root->right != nullptr && root->right->val == key) return root;

        TreeNode* n1 = findParent(root->left, key);
        TreeNode* n2 = findParent(root->right, key);

        if (n1 != nullptr) return n1;
        return n2;
    }

    TreeNode* findNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) return root;

        TreeNode* n1 = findNode(root->left, key);
        TreeNode* n2 = findNode(root->right, key);

        if (n1 != nullptr) return n1;
        return n2;
    }

    TreeNode* findLeftMost(TreeNode* root) {
        if (root->left == nullptr) return nullptr;

        TreeNode* n = findLeftMost(root->left);
        if (n == nullptr) return root;

        return n;
    }

    TreeNode* findRightMost(TreeNode* root) {
        if (root->right == nullptr) return nullptr;

        TreeNode* n = findRightMost(root->right);
        if (n == nullptr) return root;

        return n;
    }
};

int main(){
    
    
        
    return 0;
}