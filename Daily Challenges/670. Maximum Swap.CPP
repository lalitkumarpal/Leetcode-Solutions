class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int index = -1;
            char last = s[i];
            for (int j = n - 1; j > i; j--) {
                if (s[j] > last) {
                    index = j;
                    last = s[j];
                }
            }
            if (index != -1) {
                swap(s[i], s[index]);
                break;
            }
        }
        return stoi(s);
    }
};