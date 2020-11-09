/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (1 >= nums.size())
        {
            return true;
        }

        int iPos = 0;
        int iMaxPos = nums[iPos];
        if (iMaxPos >= nums.size()-1)
            return true;
        while (iPos <= iMaxPos)
        {
            if (iPos + nums[iPos] > iMaxPos)
            {
                iMaxPos = iPos + nums[iPos];
                if (iMaxPos >= nums.size()-1)
                    return true;
            }
            iPos++;
        }
        
        return false;
    }
};
// @lc code=end

