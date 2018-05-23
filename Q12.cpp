class Solution {
public:
    string getRange(long int L, long int R) {
        if ((L == R) || (L + 1 ==  R)) {
            return "";
        }

        string res = to_string(L + 1);

        if (R - L > 2) {
            res += ("->" + to_string(R - 1));
        }

        return res;
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<long int> long_nums;

        for (int i = 0; i < nums.size(); i++) {
            long_nums.push_back(nums[i]);
        }

        long int long_lower = lower;
        long int long_upper = upper;
        long_nums.insert(long_nums.begin(), long_lower - 1);
        long_nums.insert(long_nums.end(), long_upper + 1);

        vector<string> res;
        for (int i = 0; i < long_nums.size() - 1; i++) {
            string range = getRange(long_nums[i], long_nums[i+1]);

            if (range.size() > 0) {
                res.push_back(range);
            }
        }

        return res;
    }
};
