/*
 * Created By George on 12/20/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/leaf-similar-trees/
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;

        traverse(root1, leafs1);
        traverse(root2, leafs2);

        if (leafs1.size() != leafs2.size()) return false;

        for (int i = 0; i < leafs1.size(); i++) {
            if (leafs1[i] != leafs2[i]) return false;
        }

        return true;
    }

    void traverse(TreeNode* node, vector<int>& leafs) {
        if (node == nullptr) return;

        if (node->left != nullptr || node->right != nullptr) {
            traverse(node->left, leafs);
            traverse(node->right, leafs);
        } else {
            leafs.push_back(node->val);
        }
    }
};

int main() {
    return 0;
}
