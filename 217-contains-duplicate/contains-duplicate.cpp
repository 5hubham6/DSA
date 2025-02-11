/*
 * Approach:
 * - The solution first sorts the input array in ascending order using `sort()`.
 * - Then, it iterates through the sorted array and checks for consecutive equal elements.
 * - If a duplicate is found, the function immediately returns `true`; otherwise, it returns `false`.
 *
 * Complexity Analysis:
 * - Time Complexity: O(n log n) due to the sorting operation, followed by a single O(n) pass to check for duplicates.
 * - Space Complexity: O(1) additional space if sorting is done in-place; O(n) if external sorting space is required.
 *
 * Improvements:
 * - To achieve an optimal O(n) time complexity solution, use a hash set to track seen elements.
 * - This approach avoids the sorting step and provides constant time lookups, albeit with an O(n) space tradeoff.
 *
 * Example of a more efficient solution using unordered_set:
 *
 * bool containsDuplicate(vector<int>& nums) {
 *     unordered_set<int> seen;
 *     for (int num : nums) {
 *         if (seen.count(num)) return true;
 *         seen.insert(num);
 *     }
 *     return false;
 * }
 */


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        {
            for(int i = 1 ; i<nums.size();i++)
            {
                if(nums[i]==nums[i-1])
                {
                    return true;
                }
            }
            return false;
        }
        
    }
};
