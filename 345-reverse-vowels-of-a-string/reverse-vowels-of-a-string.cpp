class Solution {
public:
    std::string reverseVowels(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        std::string vowels = "aeiouAEIOU";

        while (left < right) {
            if (vowels.find(s[left]) == std::string::npos) {
                left++;
            } else if (vowels.find(s[right]) == std::string::npos) {
                right--;
            } else {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};