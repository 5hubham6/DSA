class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complements;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
 
            auto it = complements.find(nums[i]);
            if (it != complements.end()) {
                return {it->second, i};
            }
       
            complements[complement] = i;
        }
        return  {};
    }
};
