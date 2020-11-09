/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (41.75%)
 * Total Accepted:    86.4K
 * Total Submissions: 206.8K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (1 == nums.size() && nums[0] == k) {
            return 1;
        }
        
        int begin = 0;
        int end = 1;
        int rtn = 0;
        int iSum = 0;
        while (end < nums.size())
        {
            
        }

        return rtn;
    }
};

