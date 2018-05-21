/* Trigger to add a word: a non-space char with the next char as space */
/* Trigger to add a space: when the result string is not empty */
/* Using two indices: substring from i to j will be extracted */
/* While iterating the string in reverse order, we keep track of a word's
 * begin and end position. When we are at the beginning of a word, we append it */
/* O(n) runtime, O(n) space */

class Solution {
public:
  void reverseWords(string &s) {
    int len = (int)s.size();
    string temp = "";
    string res = "";

    int i = len - 1;
    int j = len - 1;

    while (i >= 0) {
      if (s[i] == ' ') {
        j = i - 1;
      }

      else if (i == 0 || s[i-1] == ' ') {
        if (res.size() > 0) {
          res += " ";
        }
        res += s.substr(i, j-i+1);
      }

      i--;
    }

    s = res;
  }
};