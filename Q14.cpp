class Solution {
public:
    bool isOneInsertDistance(string s1, string s2) {
        int index1 = 0, index2 = 0;
        bool diff = false;

        while (index1 < s1.size() && index2 < s2.size()) {
            if (s1[index1] == s2[index2]) {
                index1++;
                index2++;
            } else {
                if (diff == true) {
                    return false;
                }
                index2++;
                diff = true;
            }
        }

        return (diff == true) || (index1 == s1.size());
    }

    bool isOneEditDistance(string s, string t) {
        /* Check one insert or one delete */
        if ((int)s.size() - (int)t.size() == 1) {
            return isOneInsertDistance(t, s);
        } else if ((int)t.size() - (int)s.size() == 1) {
            return isOneInsertDistance(s, t);
        }

        /* Check one modify */
        if (s.size() == t.size()) {
            bool diff = false;
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] != t[i]) {
                    if (diff == true) {
                        return false;
                    }
                    diff = true;
                }
            }
            return diff == true;
        }

        return false;
    }
};
