/* Two iterations solution */
/* O(n) time, O(1) space */
class Solution {
public:
    int mapping[128] = {0};

    int getNumberOfDistinctCharacter() {
        int res = 0;
        for (int i = 0; i < 128; i++) {
            if (mapping[i] != 0) {
                res++;
            }
        }

        return res;
    }

    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start_index = 0;
        int max_len = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            mapping[s[i]]++;

            while (getNumberOfDistinctCharacter() > 2 && start_index < s.size()) {
                mapping[s[start_index]]--;
                start_index++;
            }

            max_len = max(max_len, i - start_index + 1);
        }

        return max_len;
    }
};
