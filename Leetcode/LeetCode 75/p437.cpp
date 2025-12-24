/*
 * Created By George on 12/24/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/path-sum-iii/
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
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> tempNums;
        return recursivePathSum(root, targetSum, tempNums);
    }

    int recursivePathSum(TreeNode* root, int targetSum, vector<int>& currentNums) {
        if (root == nullptr) return 0;

        int ans = 0;

        long long tempSum = 0;
        for (auto it = currentNums.rbegin(); it != currentNums.rend(); it++) {
            tempSum += (long long) *it;
            if (root->val + tempSum == targetSum) {
                ans++;
            }
        }

        if (root->val == targetSum) {
            ans++;
        }

        currentNums.push_back(root->val);
        if (root->left != nullptr) {
            ans += recursivePathSum(root->left, targetSum, currentNums);
        }
        if (root->right != nullptr) {
            ans += recursivePathSum(root->right, targetSum, currentNums);
        }
        currentNums.pop_back();

        return ans;
    }
};

int main() {
    return 0;
}
