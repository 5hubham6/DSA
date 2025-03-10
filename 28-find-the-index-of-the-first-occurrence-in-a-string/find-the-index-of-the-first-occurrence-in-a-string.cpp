class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }

        for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i) {
            bool found = true;
            for (int j = 0; j < (int)needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
};