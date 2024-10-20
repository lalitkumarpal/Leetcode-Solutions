class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();
        vector<int> freq(26, 0);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            freq.assign(26, 0);
            mx = 0;
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                mx = max(mx, freq[s[j] - 'a']);
                if (mx >= k) {
                    ans += (n - j);
                    break;
                }
            }
        }
        return ans;
    }
};