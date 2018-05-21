/* O(n) runtime, O(1) space */
/* this solution require the string to be well-formatted */
/* The input string does not contain leading or trailing spaces and
 * the words are always separated by a single space */

class Solution {
public:
  void reverseWordsInRange(string &s, int start, int end) {
    while (start <= end) {
      swap(s[start], s[end]);
      start++;
      end--;
    }
  }

  void reverseWords(string &s) {
    int len = (int)s.size();
    int i = len - 1;
    int j = len - 1;

    reverseWordsInRange(s, 0, len-1);

    while (i >= 0) {
      if (s[i] == ' ') {
        j = i - 1;
      }

      else if (i == 0 || s[i-1] == ' ') {
        reverseWordsInRange(s, i, j);
      }

      i--;
    }
  }
};