class Solution {
public:
    int maxScore(int n, int k, const vector<vector<int>>& stayScore, const vector<vector<int>>& travelScore) {
        vector<vector<int>> memo(k, vector<int>(n, -1));
        int maxPoints = 0;
        for (int startCity = 0; startCity < n; ++startCity) {
            maxPoints = max(maxPoints, dfs(0, startCity, n, k, stayScore, travelScore, memo));
        }
        return maxPoints;
    }

private:
    int dfs(int day, int curr, int n, int k, const vector<vector<int>>& stayScore, 
             const vector<vector<int>>& travelScore, vector<vector<int>>& memo) {
        if (day == k) {
            return 0;
        }

        if (memo[day][curr] != -1) {
            return memo[day][curr];
        }

        int maxPoints = stayScore[day][curr] + dfs(day + 1, curr, n, k, stayScore, travelScore, memo);

        for (int dest = 0; dest < n; ++dest) {
            if (dest != curr) {
                maxPoints = max(maxPoints, travelScore[curr][dest] + dfs(day + 1, dest, n, k, stayScore, travelScore, memo));
            }
        }

        memo[day][curr] = maxPoints;
        return maxPoints;
    }
};
