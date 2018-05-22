/* O(n) runtime, O(1) space */
/* The key idea is to update start index */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mapping;
        int maxLen = 0;
        int startIndex = 0;
        
        for (int i = 0; i < (int)s.size(); i++) {
            /* If the char has repeated */
            if (mapping.count(s[i]) > 0 && mapping.at(s[i]) >= startIndex) {
                startIndex = mapping.at(s[i]) + 1;
            }
            
            maxLen = max(maxLen, i - startIndex + 1);
            
            /* Update hash table*/
            if (mapping.count(s[i]) == 0) {
                mapping.insert(pair<char, int>(s[i], i));
            } else {
                mapping.at(s[i]) = i;
            }            
        }
        
        return maxLen;
    }
};