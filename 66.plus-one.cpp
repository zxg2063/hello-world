/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.76%)
 * Total Accepted:    359.8K
 * Total Submissions: 882.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size()-1;
        int iAdd = 0;
        for(; i >= 0; i--)
        {
            int tmp = digits[i] + 1;
            if (10 > tmp) {
                digits[i] = tmp;
                return digits;
            }
            /*else
            {
                digits[i] = tmp%10;
                iAdd = 1;
            }*/
            digits[i] = tmp%10;
        }

        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
