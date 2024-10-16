class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        string ans;
        while (true) {
            auto front = pq.top();
            pq.pop();
            auto ch = front.second;
            auto count = front.first;
            if (ans.size() < 2) {
                if (count > 0) {
                    ans += ch;
                    count--;
                    pq.push({count, ch});
                    continue;
                }
                

            } else {
                int n = ans.size();
                if (count > 0) {
                    if (ans[n - 1] == ch && ans[n - 2] == ch) {
                        auto second_front = pq.top();
                        pq.pop();
                        pq.push({count, ch});
                        auto second_ch = second_front.second;
                        auto second_count = second_front.first;
                        if (second_count > 0) {
                            ans += second_ch;
                            second_count--;
                            pq.push({second_count, second_ch});
                            continue;
                        }

                    } else {
                        ans += ch;
                        count--;
                        pq.push({count, ch});
                        continue;
                    }
                }
            }
            break;
        }
        return ans;
    }
};