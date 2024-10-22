// sorting based


class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            long long level_sum = 0;
            for (int i = 0; i< sz; i++) {
                auto node = q.front();
                q.pop();
                level_sum += node->val;
                if (node->left) {
                    q.push({node->left});
                }
                if (node->right) {
                    q.push({node->right});
                }
            }
            level_sums.push_back(level_sum);
        }
        sort(level_sums.begin(), level_sums.end());
        int n = level_sums.size();
        if (n < k) {
            return -1;
        }
        return level_sums[n - k];
    }
};

// Min heap based


class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> level_sums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            long long level_sum = 0;
            for (int i = 0; i< sz; i++) {
                auto node = q.front();
                q.pop();
                level_sum += node->val;
                if (node->left) {
                    q.push({node->left});
                }
                if (node->right) {
                    q.push({node->right});
                }
            }
            if(level_sums.size()<k){
                level_sums.push(level_sum);
            }else if(level_sum>level_sums.top()){
                level_sums.pop();
                level_sums.push(level_sum);
            }
            
        }
        int n = level_sums.size();
        if (n < k) {
            return -1;
        }
        return level_sums.top();
    }
};