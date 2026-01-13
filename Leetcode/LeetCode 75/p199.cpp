/*
 * Created By George on 1/13/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        vector<vector<int>> tree;
        queue<TreeNode*> nodesToVisit;
        queue<int> nodeLevels;
        nodesToVisit.push(root);
        nodeLevels.push(0);

        while (!nodesToVisit.empty())
            recursiveSideViewBfs(tree, nodesToVisit, nodeLevels);

        for (auto& v: tree) {
            ans.push_back(v[v.size() - 1]);
        }

        return ans;
    }

    void recursiveSideViewBfs(vector<vector<int>>& tree, queue<TreeNode*>& nodesToVisit, queue<int>& nodeLevels) {

        const TreeNode* root = nodesToVisit.front();
        nodesToVisit.pop();
        const int level = nodeLevels.front();
        nodeLevels.pop();
        if (root == nullptr) return;

        if (tree.size() <= level) {
            const vector<int> v;
            tree.push_back(v);
        }

        tree[level].push_back(root->val);
        nodesToVisit.push(root->left);
        nodesToVisit.push(root->right);
        nodeLevels.push(level + 1);
        nodeLevels.push(level + 1);
    }
};

int main() {

    Solution solution;

    TreeNode* root = new TreeNode(
        1,
        new TreeNode(2, nullptr, new TreeNode(5)),
        new TreeNode(3, nullptr, new TreeNode(4))
    );

    vector<int> ans = solution.rightSideView(root);
    for (auto& i: ans) cout << i << endl;

    delete root;

    return 0;
}
