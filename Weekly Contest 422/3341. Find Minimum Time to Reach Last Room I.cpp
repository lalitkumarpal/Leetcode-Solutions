
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0});
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> visited;

        while (!pq.empty()) {
            auto top = pq.top();
            auto time = top[0];
            auto row = top[1];
            auto col = top[2];
            pq.pop();
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }
            for (auto& dir : directions) {
                int new_row = row + dir[0], new_col = col + dir[1];
                if (new_row >= 0 && new_row < rows && new_col >= 0 &&
                    new_col < cols && !visited.count({new_row, new_col})) {
                    pq.push({max(time, moveTime[new_row][new_col]) + 1, new_row,
                             new_col});
                    visited.insert({new_row, new_col});
                }
            }
        }
        return -1;
    }
};