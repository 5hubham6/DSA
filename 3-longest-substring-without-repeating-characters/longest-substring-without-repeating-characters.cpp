class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charMap;
        int left = 0, right = 0, maxLength = 0;
        while (right < s.length()) {
            if (charMap.find(s[right]) != charMap.end()) {
                left = std::max(left, charMap[s[right]] + 1);
            }
            charMap[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};