class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MODULO = 1e9 + 7;
        vector<long long> charCount(26, 0);

        for (char character : s) {
            charCount[character - 'a']++;
        }

        for (int transformation = 0; transformation < t; transformation++) {
            vector<long long> newCharCount(26, 0);

            for (int charIndex = 0; charIndex < 26; charIndex++) {
                if (charIndex == 25) {
                    newCharCount[0] =
                        (newCharCount[0] + charCount[charIndex]) % MODULO;
                    newCharCount[1] =
                        (newCharCount[1] + charCount[charIndex]) % MODULO;
                } else {
                    newCharCount[charIndex + 1] =
                        (newCharCount[charIndex + 1] + charCount[charIndex]) %
                        MODULO;
                }
            }
            charCount = newCharCount;
        }

        long long totalLength = 0;
        for (long long count : charCount) {
            totalLength = (totalLength + count) % MODULO;
        }

        return static_cast<int>(totalLength);
    }
};
