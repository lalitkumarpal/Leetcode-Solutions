# Brute Force

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for (int i = 0; i < n; i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        vector<int> chairs(1e5 + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1e5 + 1; j++) {
                if (times[i][0] >= chairs[j]) {
                    chairs[j] = times[i][1];
                    if (times[i][2] == targetFriend) {
                        return j;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};

# optimized

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;

        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], i});
            events.push_back({times[i][1], -1*i});
        }

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> available_chairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            occupied_chairs;

        for (int i = 0; i < n; i++)
            available_chairs.push(i);

        for (auto& event : events) {
            auto time = event.first;
            auto friend_index = event.second;

            while (!occupied_chairs.empty() &&
                   occupied_chairs.top().first <= time) {
                available_chairs.push(occupied_chairs.top().second);
                occupied_chairs.pop();
            }

            if (friend_index >= 0) {
                auto chair = available_chairs.top();
                available_chairs.pop();
                if (friend_index == targetFriend)
                    return chair;
                occupied_chairs.push({times[friend_index][1], chair});
            }
        }

        return -1;
    }
};