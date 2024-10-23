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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        queue<pair<TreeNode*, TreeNode*>> q;
        auto dummy = new TreeNode(-1);
        q.push({root, dummy});
        while (!q.empty()) {
            int sz = q.size();
            unordered_map<TreeNode*, TreeNode*> parents;
            unordered_map<TreeNode*, long long> sums;
            long long total_sum = 0;
            for (int i = 0; i < sz; i++) {
                auto node_pair = q.front();
                q.pop();
                auto node = node_pair.first;
                auto parent = node_pair.second;
                sums[parent] += node->val;
                total_sum += node->val;
                parents[node] = parent;
                if (node->left) {
                    q.push({node->left, node});
                }
                if (node->right) {
                    q.push({node->right, node});
                }
            }
            for (auto i : parents) {
                i.first->val = total_sum - sums[i.second];
            }
        }
        return root;
    }
};