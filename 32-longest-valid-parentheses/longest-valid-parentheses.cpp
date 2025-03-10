#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        st.push(-1); // Initialize with -1 to handle cases starting with ')'
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // If stack is empty, push current index as new start
                } else {
                    maxLen = std::max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};