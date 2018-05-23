class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string res = "";

        for (int i = 0; i < 2 * s.size() - 1; i++) {
            int L = 0, R = 0, len = 0;

            if (i % 2 == 0) {
                L = i / 2 - 1;
                R = i / 2 + 1;
                len = 1;
            } else {
                L = (i - 1) / 2;
                R = (i + 1) / 2;
                len = 0;
            }

            while ((L >= 0) && (R <= s.size() - 1) && s[L] == s[R]) {
                len += 2;
                L--;
                R++;
            }

            if (len > maxLen) {
                maxLen = len;
                res = s.substr(L + 1, R - L - 1);
            }
        }

        return res;
    }
};
