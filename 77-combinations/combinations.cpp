class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        combineHelper(result, combination, 1, n, k);
        return result;
    }

private:
    void combineHelper(std::vector<std::vector<int>>& result, std::vector<int>& combination, int start, int n, int k) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= n - k + 1; ++i) {
            combination.push_back(i);
            combineHelper(result, combination, i + 1, n, k - 1);
            combination.pop_back();
        }
    }
};