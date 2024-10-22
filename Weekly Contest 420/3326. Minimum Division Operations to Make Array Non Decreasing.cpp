class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] < nums[i - 1]) {
                nums[i - 1] = get_max_proper_divisor(nums[i], nums[i - 1]);
                if (nums[i - 1] == -1) {
                    return -1;
                }
                ans++;
            }
        }
        return ans;
    }

    int get_max_proper_divisor(int n1, int n2) {
        for (int i = 2; i <=n1; i++) {
            if (n2 % i == 0)
                return i;
        }
        return -1;
    }
};