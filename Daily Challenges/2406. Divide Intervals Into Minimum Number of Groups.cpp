# O(nlogn)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const auto& interval : intervals) {
            int interval_start = interval[0];
            int interval_end = interval[1];

            if (!minHeap.empty() && minHeap.top() < interval_start) {
                minHeap.pop();  
            }
            minHeap.push(interval_end);
        }

        return minHeap.size();
    }
};

# O(n+max_element)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (vector<int> interval : intervals) {
            mn = min(mn, interval[0]);
            mx = max(mx, interval[1]);
        }

        vector<int> diff(mx + 2, 0);
        for (auto interval : intervals) {
            diff[interval[0]]++;
            diff[interval[1] + 1]--;
        }

        int overlap_intervals = 0;
        int groups = 0;
        for (int i = mn; i <= mx; i++) {
            overlap_intervals += diff[i];
            groups =
                max(groups, overlap_intervals);
        }

        return groups;
    }
};