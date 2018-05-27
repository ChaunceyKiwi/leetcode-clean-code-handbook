class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        x *= sign;
        int res = 0;
        int INT_MAX_DIV10 = INT_MAX / 10;

        while (x > 0) {
            int digit = x % 10;

            if (res > INT_MAX_DIV10) {
                return 0;
            }

            res = res * 10 + digit;
            x /= 10;
        }

        return sign * res;
    }
};
