class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        permuteHelper(nums, 0, result);
        return result;
    }
private:
    void permuteHelper(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            permuteHelper(nums, start + 1, result);
            std::swap(nums[start], nums[i]);
        }
    }
};