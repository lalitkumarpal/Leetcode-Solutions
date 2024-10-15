class Solution {
public:
    long long minimumSteps(string s) {
        int i = 0;
        while (s[i] == '0') {
            i++;
        }
        long long ans = 0;
        for (int j = i; j < s.size(); j++) {
            if (s[j] == '0') {
                ans += (j - i);
                i++;
            }
        }
        return ans;
    }
};