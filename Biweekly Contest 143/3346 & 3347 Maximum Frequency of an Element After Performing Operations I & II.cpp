class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        unordered_map<long long, int> freq,diff;
        int max_freq = 0;
        set<long long > st; 
        for (auto i : nums) {

            int mini = i - k;
            int maxi = i + k+1;

            if (mini < 0) {
                mini = 0;
            }
            diff[mini]++;
            diff[maxi]--;
            freq[i]++;
            st.insert(mini);
            st.insert(maxi);
            st.insert(i);
            max_freq = max(max_freq, freq[i]);
            
        }

        int ans = 0;
        int curr = 0;
        for (auto i:st) {
            curr += diff[i];
            ans = max(ans, min(curr, freq[i] + numOperations));
        }

        return min(ans, max_freq + numOperations);
    }
};