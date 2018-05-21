/* Brute-force: O(n^2) time, O(1) space */
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i++) {
            int j;
            for (j = 0; j < needle.size(); j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) {
                return i;
            }
        }
        
        return -1;
    }
};