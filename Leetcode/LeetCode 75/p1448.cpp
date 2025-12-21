/*
 * Created By George on 12/21/2025.
 */

/*
 * Problem Link:        https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
#define MIN_INT numeric_limits<int>::min()

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return recursiveGoodNodes(root, MIN_INT);
    }

    int recursiveGoodNodes(TreeNode* root, int currentMax) {
        int tempCount = 0;
        if (root->val >= currentMax) {
            tempCount++;
        }

        currentMax = max(currentMax, root->val);
        if (root->left != nullptr) {
            tempCount += recursiveGoodNodes(root->left, currentMax);
        }
        if (root->right != nullptr) {
            tempCount += recursiveGoodNodes(root->right, currentMax);
        }

        return tempCount;
    }
};

int main() {
    return 0;
}
