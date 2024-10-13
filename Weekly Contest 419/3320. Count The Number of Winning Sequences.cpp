class Solution {
public:
    int ans = 0;
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int i, int score, int last, string& s) {
        if (i == s.size()) {
            if (score > 0) {
                return 1;
            }
            return 0;
        }
        if (dp[i][score + 1000][last + 1] != -1) {
            return dp[i][score + 1000][last + 1];
        }
        int curr = s[i] - 'A';
        int ways = 0;
        if (curr == 0) {
            if (last != 1) {
                ways += (solve(i + 1, score + 1, 1, s));
                ways %= mod;
            }
            if (last != 0) {
                ways += (solve(i + 1, score, 0, s));
                ways %= mod;
            }
            if (last != 2) {
                ways += (solve(i + 1, score - 1, 2, s));
                ways %= mod;
            }
        }
        if (curr == 1) {
            if (last != 2) {
                ways += (solve(i + 1, score + 1, 2, s));
                ways %= mod;
            }
            if (last != 1) {
                ways += (solve(i + 1, score, 1, s));
                ways %= mod;
            }
            if (last != 0) {
                ways += (solve(i + 1, score - 1, 0, s));
                ways %= mod;
            }
        }
        if (curr == 2) {
            if (last != 0) {
                ways += (solve(i + 1, score + 1, 0, s));
                ways %= mod;
            }
            if (last != 2) {
                ways += (solve(i + 1, score, 2, s));
                ways %= mod;
            }
            if (last != 1) {
                ways += (solve(i + 1, score - 1, 1, s));
                ways %= mod;
            }
        }
        return dp[i][score + 1000][last + 1] = ways;
    }

    int countWinningSequences(string s) {
        for (auto& i : s) {
            if (i == 'F') {
                i = 'A';
            }
            if (i == 'W') {
                i = 'B';
            }
            if (i == 'E') {
                i = 'C';
            }
        }
        dp.resize(s.size(),
                  vector<vector<int>>(s.size() + 1000, vector<int>(4, -1)));
        return solve(0, 0, -1, s);
    }
};