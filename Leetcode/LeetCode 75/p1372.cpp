/*
 * Created By George on 12/29/2025.
 */
 
 /*
  * Problem Link:           https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
  * Problem Status:         Accepted.
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
    int longestZigZag(TreeNode* root) {
        return max(visit(root->left, false, 1), visit(root->right, true, 1));
    }

    int visit(TreeNode* root, bool isLeft, int prevLength) {
        if (root == nullptr) return prevLength - 1;
        return max(
            isLeft ? visit(root->left, false, prevLength + 1) : visit(root->right, true, prevLength + 1),
            isLeft ? visit(root->right, true, 1) : visit(root->left, false, 1)
        );
    }
};

int main(){
    
    
        
    return 0;
}