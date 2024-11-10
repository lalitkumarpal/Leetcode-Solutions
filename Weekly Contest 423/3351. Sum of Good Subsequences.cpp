class Solution {
public:
    int mod = 1e9 + 7;

    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<long long, long long> cnt, sum;

        for (int i : nums) {
            cnt[i] += (cnt[i - 1] + cnt[i + 1] + 1) % mod;
            cnt[i] %= mod;
            sum[i] += (sum[i - 1] + sum[i + 1]) % mod;
            sum[i] %= mod;
            sum[i] += (cnt[i - 1] + cnt[i + 1] + 1) % mod * i % mod;
            sum[i] %= mod;
        }

        int ans = 0;
        for (auto& p : sum) {
            ans += p.second;
            ans %= mod;
        }

        return ans;
    }
};