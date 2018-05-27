class Solution {
public:
    map<int, string> mapping = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };

    int findNearestNum(int val) {
        if (val >= 1000) {
            return 1000;
        } else if (val >= 900) {
            return 900;
        } else if (val >= 500) {
            return 500;
        } else if (val >= 400) {
            return 400;
        } else if (val >= 100) {
            return 100;
        } else if (val >= 90) {
            return 90;
        } else if (val >= 50) {
            return 50;
        } else if (val >= 40) {
            return 40;
        } else if (val >= 10) {
            return 10;
        } else if (val >= 9) {
            return 9;
        } else if (val >= 5) {
            return 5;
        } else if (val >= 4) {
            return 4;
        } else if (val >= 1) {
            return 1;
        }
    }

    string intToRoman(int num) {
        string res = "";
        while (num > 0) {
            int nearestNum = findNearestNum(num);
            res += mapping.at(nearestNum);
            num -= nearestNum;
        }

        return res;
    }
};
