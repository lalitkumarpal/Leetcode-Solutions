/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    int solve(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == right) {
            int totalNodes = 1 + 2 * left;
            ans.push_back(totalNodes);
            return totalNodes;
        }

        return -1;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);

        if (ans.size() < k) {
            return -1;
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans[k - 1];
    }
};
