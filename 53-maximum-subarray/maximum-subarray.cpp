class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_so_far = nums[0];
        int curr_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_max = std::max(nums[i], curr_max + nums[i]);
            max_so_far = std::max(max_so_far, curr_max);
        }
        return max_so_far;
    }
};