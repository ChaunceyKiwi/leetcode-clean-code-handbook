class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                char_stack.push(s[i]);
            } else {
                if (char_stack.empty()) {
                    return false;
                }

                char stack_top = char_stack.top();
                char_stack.pop();

                if (s[i] == ')' && stack_top == '(') {
                    continue;
                }

                if (s[i] == '}' && stack_top == '{') {
                    continue;
                }

                if (s[i] == ']' && stack_top == '[') {
                    continue;
                }

                return false;
            }
        }

        return char_stack.empty();
    }
};
