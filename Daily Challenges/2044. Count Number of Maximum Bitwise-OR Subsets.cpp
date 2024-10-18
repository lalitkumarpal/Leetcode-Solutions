// Recursive
class Solution {
public:
    int max_or = 0;

    int solve(int i, int curr_or, vector<int>& nums) {

        if (i >= nums.size()) {
            return curr_or==max_or;
        }

        int not_take = solve(i + 1, curr_or, nums);

        int take = solve(i + 1, curr_or | nums[i], nums);
        return take + not_take;

    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (auto& i : nums) {
            max_or |= i;
        }

        return solve(0, 0, nums); 

    }
};


// Recursive + memo

class Solution {
public:
    vector<vector<int>> dp;
    int max_or = 0;
    int solve(int i, int curr_or, vector<int>& nums) {
        if (i >= nums.size()) {
            return curr_or == max_or;
        }
        if (dp[i][curr_or] != -1) {
            return dp[i][curr_or];
        }
        int not_take = solve(i + 1, curr_or, nums);

        int take = solve(i + 1, curr_or | nums[i], nums);
        return dp[i][curr_or] = take + not_take;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (auto& i : nums) {
            max_or |= i;
        }

        dp.resize(nums.size(), vector<int>(max_or + 1, -1));
        return solve(0, 0, nums);
    }
};
