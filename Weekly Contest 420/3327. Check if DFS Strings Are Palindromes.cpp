
class Solution {
public:
    vector<int> manacherOdd(const string& s) {
        int n = s.size();

        string modifiedStr = "$" + s + "^";
        vector<int> p(n + 2);
        int leftBoundary = 1, rightBoundary = 1;

        for (int i = 1; i <= n; i++) {
            p[i] = max(
                0, min(rightBoundary - i, p[leftBoundary + rightBoundary - i]));
            while (modifiedStr[i - p[i]] == modifiedStr[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > rightBoundary) {
                leftBoundary = i - p[i];
                rightBoundary = i + p[i];
            }
        }

        return vector<int>(begin(p) + 1, end(p) - 1);
    }

    string transformString(const string& s) {
        int n = s.length();
        string transformedStr(2 * n + 1, '#');
        for (int i = 0; i < n; i++) {
            transformedStr[2 * i + 1] = s[i];
        }
        return transformedStr;
    }

    vector<bool> findAnswer(vector<int>& parent, const string& s) {
        int n = parent.size();
        vector<vector<int>> adjacencyList(n);

        for (int i = 1; i < n; i++) {
            adjacencyList[parent[i]].push_back(i);
        }

        vector<array<int, 3>> evenPalindromicInfo, oddPalindromicInfo;
        string dfsTraversalString(n, '0');
        int currentIndex = 0;

        function<void(int)> dfs = [&](int node) {
            int startIndex = currentIndex;

            for (int child : adjacencyList[node]) {
                dfs(child);
            }

            dfsTraversalString[currentIndex++] = s[node];

            int endIndex = currentIndex - 1;
            int length = endIndex - startIndex + 1;
            if ((length % 2) == 0) {
                int midIndex = (startIndex + endIndex) / 2;
                evenPalindromicInfo.push_back(
                    {2 * (midIndex + 1), length, node});
            } else {
                oddPalindromicInfo.push_back(
                    {(startIndex + endIndex) / 2, (length + 1) / 2, node});
            }
        };

        dfs(0);

        vector<bool> result(n, false);

        auto oddPalindromicLengths = manacherOdd(dfsTraversalString);

        auto evenPalindromicLengths =
            manacherOdd(transformString(dfsTraversalString));
        for (auto& info : oddPalindromicInfo) {
            if (oddPalindromicLengths[info[0]] >= info[1]) {
                result[info[2]] = true;
            }
        }

        for (auto& info : evenPalindromicInfo) {
            if (evenPalindromicLengths[info[0]] >= info[1]) {
                result[info[2]] = true;
            }
        }

        return result;
    }
};