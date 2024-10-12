class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    unordered_set<int> st;
    int solve(int i, int j, string& s, string& pattern) {
        if (i == n) {
            if (j == m) {
                return 0;
            }
            return -1e7;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = solve(i + 1, j, s, pattern);
        if (st.find(i) != st.end()) {
            ans = max(ans, 1 + solve(i + 1, j, s, pattern));
        }
        if (s[i] == pattern[j]) {
            ans = max(ans, solve(i + 1, j + 1, s, pattern));
        }
        return dp[i][j] = ans;
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        n = source.size();
        m = pattern.size();
        dp.resize(n, vector<int>(m+1, -1));
        for (auto& i : targetIndices) {
            st.insert(i);
        }
        return solve(0, 0, source, pattern);
    }
};