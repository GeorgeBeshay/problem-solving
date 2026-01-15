/*
 * Created By George on 1/15/2026.
 */

/*
 * Problem Link:        https://leetcode.com/problems/search-in-a-binary-search-tree/
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

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;

        TreeNode* n1 = searchBST(root->left, val);
        TreeNode* n2 = searchBST(root->right, val);

        if (n1 != nullptr)
            return n1;
        return n2;
    }
};

int main() {
    return 0;
}
