class Solution {
public:
    map<string, int> mapping = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };

    int romanToInt(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size()) {
                string dual_key = s.substr(i, 2);
                if (mapping.count(dual_key) > 0) {
                    res += mapping.at(dual_key);
                    i++;
                    continue;
                }
            }

            res += mapping.at(s.substr(i, 1));
        }

        return res;
    }
};
