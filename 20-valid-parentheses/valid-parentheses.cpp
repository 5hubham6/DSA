class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if ((c == ')' && st.top() == '(') ||
                    (c == ']' && st.top() == '[') ||
                    (c == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};