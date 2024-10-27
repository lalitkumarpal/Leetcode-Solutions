class Solution {
public:
    long long gcd_of_array(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), nums[0], gcd<int, int>);
    }

    static long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long lcm_of_array(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 1LL, Solution::lcm);
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return static_cast<long long>(nums[0]) * nums[0];
        }

        long long overall_gcd = gcd_of_array(nums);
        long long overall_lcm = lcm_of_array(nums);
        
        long long max_score = overall_gcd * overall_lcm;

        for (int i = 0; i < n; ++i) {
            vector<int> new_nums(nums.begin(), nums.end());
            new_nums.erase(new_nums.begin() + i);

            long long gcd_without_i = gcd_of_array(new_nums);
            long long lcm_without_i = lcm_of_array(new_nums);

            long long factor_score = gcd_without_i * lcm_without_i;

            max_score = max(max_score, factor_score);
        }

        return max_score;
    }
};


