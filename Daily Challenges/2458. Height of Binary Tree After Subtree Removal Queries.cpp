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
    unordered_map<int, int> heights;
    unordered_map<int, int> pre_compute_results;
    int height(TreeNode* root) {
        if (!root) {
            return -1;
        }
        if (heights.find(root->val) != heights.end()) {
            return heights[root->val];
        }
        int left_height = height(root->left);
        int right_height = height(root->right);

        return heights[root->val] = 1 + max(left_height, right_height);
    }
    void dfs(TreeNode* root, int curr_height, int max_height) {
        if (!root) {
            return;
        }
        pre_compute_results[root->val] = max_height;
        dfs(root->left, curr_height + 1,
            max(max_height, curr_height + 1 + height(root->right)));
        dfs(root->right, curr_height + 1,
            max(max_height, curr_height + 1 + height(root->left)));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        TreeNode* dummy = new TreeNode(-1);
        dfs(root, 0, 0);
        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(pre_compute_results[q]);
        }
        return ans;
    }
};