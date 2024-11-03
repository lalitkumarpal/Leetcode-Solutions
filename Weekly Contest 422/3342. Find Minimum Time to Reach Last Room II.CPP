
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0, 0});

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> time_to_reach(rows, vector<int>(cols, INT_MAX));
        time_to_reach[0][0] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = top[0];
            int row = top[1];
            int col = top[2];
            int moves = top[3];

            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            for (auto& dir : directions) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];
                int move_time = 1;
                if (moves % 2 == 1) {
                    move_time = 2;
                }
                if (new_row >= 0 && new_row < rows && new_col >= 0 &&
                    new_col < cols) {
                    int time_to_move = max(time, moveTime[new_row][new_col]) +
                                       move_time;
                    if (time_to_move < time_to_reach[new_row][new_col]) {
                        time_to_reach[new_row][new_col] = time_to_move;
                        pq.push({time_to_move, new_row, new_col, moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};
