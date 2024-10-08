class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long mx = *max_element(nums.begin(), nums.end());
        vector<long long> gcd_count(mx + 1, 0);
        for (auto num : nums) {
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    if (i == num / i) {
                        gcd_count[i]++;
                    } else {
                        gcd_count[i]++;
                        gcd_count[num / i]++;
                    }
                }
            }
        }
        for (long long num = mx; num >= 1; num--) {
            long long count = gcd_count[num];

            gcd_count[num] = (count * (count - 1)) / 2;
            for (int mult = 2 * num; mult <= mx; mult += num) {
                gcd_count[num] -= gcd_count[mult];
            }
        }

        for (int i = 1; i <= mx; i++) {
            gcd_count[i] = gcd_count[i] + gcd_count[i - 1];
        }
        vector<int> ans;
        for (auto& query : queries) {
            query++;
            long long a =
                lower_bound(gcd_count.begin(), gcd_count.end(), query) -
                gcd_count.begin();
            ans.push_back(a);
        }
        return ans;
    }
};