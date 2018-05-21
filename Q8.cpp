class Solution {
public:
    int INT_MAX_Div10 = INT_MAX / 10;
    
    int pureMyAtoi(string str, int flag) {        
        int res = 0;
        for (int i = 0; i < (int)str.size(); i++) {
            int digit = str[i] - '0';
            if ((res > INT_MAX_Div10) || ((res == INT_MAX_Div10) && (digit >= 8))) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            res *= 10;
            res += digit;
        }
        
        return flag * res;
    }
    
    int myAtoi(string str) {
        /* Firstly, discard leading whitespace characters */
        int i = 0;
        while (i < (int)str.size() && str[i] == ' ') {
            i++;
        }
        
        /* Get sign */
        int flag = 1;
        if (str[i] == '+') {
            flag = 1;
            i++;
        } else if (str[i] == '-') {
            flag = -1;
            i++;
        } else if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        
        /* Drop additional characters */
        int j = i;
        while (str[j] >= '0' && str[j] <= '9') {
            j++;
        }
        
        string intPart = str.substr(i, j - i);
        return pureMyAtoi(intPart, flag);
    }
};