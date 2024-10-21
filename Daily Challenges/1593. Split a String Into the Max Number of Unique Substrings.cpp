class Solution {
public:
    unordered_set<string> unique_susbtrings;
    int n;
    int solve(int i, string s) {
        if (i >= n) {
            return 0;
        }

        string temp = "";
        int count = 0;
        for (int j = i; j < n; j++) {
            temp += s[j];
            if (unique_susbtrings.find(temp) == unique_susbtrings.end()) {
                unique_susbtrings.insert(temp);
                count = max(count, 1 + solve(j + 1, s));
                unique_susbtrings.erase(temp);
            }
        }
        return count;
    }
    int maxUniqueSplit(string s) {
        n = s.size();
        return solve(0, s);
    }
};