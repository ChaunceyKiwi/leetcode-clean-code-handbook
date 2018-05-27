/* This solution can only deal with positive numbers */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};

        for (int i = 0; i < nums.size(); i++) {
            int bit_index = 0;
            while (nums[i] > 0) {
                count[bit_index++] += nums[i] % 2;
                nums[i] = nums[i] >> 1;
            }
        }

        for (int i = 0; i < 32; i++) {
            count[i] = count[i] % 3;
        }

        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += count[i] * pow(2, i);
        }

        return res;
    }
};
