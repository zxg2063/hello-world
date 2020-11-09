/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (1 >= nums.size())
        {
            return 0;
        }

        int iPos = 0;
        int iMaxPos = nums[iPos];
        if (iMaxPos >= nums.size()-1)
            return 1;
        int iStep = 1;
        int iMaxStepPos = nums[iPos];
        while (iPos <= iMaxStepPos)
        {
            if (iPos + nums[iPos] > iMaxPos)
            {
                iMaxPos = iPos + nums[iPos];
                if (iMaxPos >= nums.size()-1)
                    return ++iStep;
            }
            iPos++;
            if (iPos > iMaxStepPos)
            {
                iStep++;
                iMaxStepPos = iMaxPos;
            }
        }
        
        return 0;
    }
};
// @lc code=end

