class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(candidates.begin(), candidates.end());
        findCombinations(candidates, target, 0, current, result);
        return result;
    }
private:
    void findCombinations(std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};