class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        for (int i = 0, n = words.size(); i < n;) {
            int j = i, len = 0;
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }
            std::string line = words[i];
            if (j == n || j == i + 1) { // Last line or single word
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += std::string(maxWidth - line.size(), ' ');
            } else {
                int spaces = (maxWidth - len) / (j - i - 1);
                int extra = (maxWidth - len) % (j - i - 1);
                for (int k = i + 1; k < j; k++) {
                    line += std::string(spaces + (k - i <= extra), ' ') + words[k];
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};