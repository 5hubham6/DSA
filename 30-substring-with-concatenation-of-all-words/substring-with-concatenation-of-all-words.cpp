#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        std::unordered_map<std::string, int> wordCount;
        for (const std::string& word : words) {
            wordCount[word]++;
        }

        int wordLen = words[0].length();
        int totalLen = wordLen * words.size();

        for (int i = 0; i < wordLen; ++i) { // Start from different offsets
            std::unordered_map<std::string, int> seen;
            int count = 0, left = i;

            for (int j = i; j <= (int)s.length() - wordLen; j += wordLen) {
                std::string word = s.substr(j, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordCount[word]) {
                        std::string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == words.size()) {
                        result.push_back(left);
                        std::string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};