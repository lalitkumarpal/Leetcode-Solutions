class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string last = "";
        for (auto& i : target) {
            for (int j = 0; j <= i - 'a'; j++) {
                last += (j + 'a');
                ans.push_back(last);
                last.pop_back();
            }
            last = ans.back();
        }
        return ans;
    }
};