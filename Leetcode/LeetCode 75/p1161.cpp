/*
 * Created By George on 1/14/2026.
 */
 
 /*
  * Problem Link:       https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> levels;
        vector<vector<int>> tree;

        q.push(root);
        levels.push(1);

        while (!q.empty())
            recursiveBfs(q, levels, tree);

        map<int, int> sums;

        int tempLevel = 1;
        for (const auto& v: tree) {
            int tempSum = 0;
            for (const auto& num: v) {
                tempSum += num;
            }
            if (sums.count(tempSum) > 0) continue;
            sums[tempSum] = tempLevel++;
        }

        return sums.rbegin()->second;
    }

    void recursiveBfs(queue<TreeNode*>& nodesToVisit, queue<int>& levels, vector<vector<int>>& tree) {

        TreeNode* node = nodesToVisit.front();
        nodesToVisit.pop();
        const int level = levels.front();
        levels.pop();

        if (node == nullptr) return;

        nodesToVisit.push(node->left);
        levels.push(level + 1);
        nodesToVisit.push(node->right);
        levels.push(level + 1);

        if (tree.size() < level) {
            const vector<int> v;
            tree.push_back(v);
        }
        tree[level - 1].push_back(node->val);
    }
};

int main(){
    
    Solution solution;
    auto* root = new TreeNode(
        1,
        new TreeNode(7, new TreeNode(7), new TreeNode(-8)),
        new TreeNode(0)
    );
    const int ans = solution.maxLevelSum(root);
    cout << ans << endl;

    delete root;
        
    return 0;
}