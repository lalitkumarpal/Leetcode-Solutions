class Solution {
public:
    bool check(int first, int second, vector<int>& nums, int k) {
        int first_check = nums[first];
        int second_check = nums[second];
        for (int i = 0; i < k - 1; i++) {
            if (nums[first] >= nums[first + 1] ||
                nums[second] >= nums[second + 1]) {
                return false;
            }
            first++;
            second++;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) {
            return true;
        }
        int n = nums.size();
        for (int i = 0; i < n - 2 * k + 1; i++) {
            if (check(i, i + k, nums, k) == true) {
                return true;
            }
        }
        return false;
    }
};