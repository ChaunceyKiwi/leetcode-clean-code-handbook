/* O(n) runtime, O(1) space */

class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    
    bool isSameCharacter(char c1, char c2) {
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 - 'A' + 'a';
        }
        
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 - 'A' + 'a';
        }
        
        return c1 == c2;
    }
    
    
    bool isPalindrome(string s) {
        int L = 0;
        int R = (int)s.size() - 1;
        
        while (L < R) {
            while (!isCharacter(s[L]) && L < R) {
                L++;
            } 
            
            while (!isCharacter(s[R]) && L < R) {
                R--;
            }
                        
            if (!isSameCharacter(s[L], s[R])) {
                return false;
            }
                        
            L++;
            R--;
        }
        
        return true;
    }
};