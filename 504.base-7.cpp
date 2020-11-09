/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (44.62%)
 * Total Accepted:    39K
 * Total Submissions: 87.4K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
class Solution {
public:
    string convertToBase7(int num) {
        bool bMinus = false;
        if (num < 0)
        {
            bMinus = true;
            num *= -1;
        }
        string rtn;
        int mod = 0;
        while(num >= 7){
            mod = num % 7;
            num = num / 7;
            rtn.insert(rtn.begin(), mod + '0');
        }
        rtn.insert(rtn.begin(), num + '0');
        if (bMinus)
        {
            rtn.insert(rtn.begin(), '-');
        }
        
        return rtn;
    }
};

