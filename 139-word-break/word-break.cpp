class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (std::string word : wordDict) {
                if (i >= word.length() && s.substr(i - word.length(), word.length()) == word) {
                    dp[i] = dp[i] || dp[i - word.length()];
                }
            }
        }
        return dp[s.length()];
    }
};