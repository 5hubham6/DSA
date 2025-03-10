class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
            if (counts[num] > nums.size() / 2) {
                return num;
            }
        }
        return -1; // Should not reach here if majority element exists
    }
};