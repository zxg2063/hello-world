/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    /*int candy(vector<int>& ratings) {
        if (1 >= ratings.size())
        {
            return ratings.size();
        }
        
        int iChildNum = ratings.size();
        //初始化每个孩子一个糖果
        vector<int> vecCandy(iChildNum, 1);

        //从第二个孩子开始检查，直到最后一个孩子
        for (int i = 1; i < iChildNum; i++)
        {
            //cout << "i=" << i << endl;
            if (ratings[i] > ratings[i-1])
            {
                vecCandy[i] = vecCandy[i-1]+1;
            }
            else if (ratings[i] < ratings[i-1] && 1 == vecCandy[i-1])
            {
                vecCandy[i-1]++;
                //需要往前校验
                for (int j = i-2; j >= 0; j--)
                {
                    //cout << "j=" << j << endl;
                    if ((ratings[j] > ratings[j+1] && vecCandy[j] > vecCandy[j+1])
                        || (ratings[j] < ratings[j+1] && vecCandy[j] < vecCandy[j+1])
                        || ratings[j] == ratings[j+1])
                    {
                        break;
                    }
                    else
                    {
                        vecCandy[j]++;
                    }
                }
                
            }
            
        }
        
        int iCandyNum = 0;
        for (size_t i = 0; i < iChildNum; i++)
        {
            //cout << vecCandy[i] << " ";
            iCandyNum += vecCandy[i];
        }

        return iCandyNum;
    }*/

    /*int candy(vector<int>& ratings) {
        if(ratings.size() == 0)return 0;
        
        int total = 1;
        int pre = 1;
        // 维护最近的波峰的位置和糖果数
        int bofenidx = 0;
        int bofenvalue = 1;
        for(int i = 1; i< ratings.size(); i++)
        {
            int tmp = ratings[i];
            //如果与前一个相等,则一个波结束,重置波峰
            if(tmp == ratings[i-1]){
                bofenidx = i;
                bofenvalue = 1;
                pre = 1;
                total +=pre;
            }else if(tmp > ratings[i-1])
            // 如果是上升序列,糖果数++,更新波峰
            {
                bofenidx = i;
                pre ++;
                bofenvalue = pre;
                total += pre;
            }else{
                // 如果是下降序列,
                // 如果前一个小孩糖果数>1,那么当前就是1
                if(pre > 1)
                {
                    pre = 1;
                    total += pre;
                }else
                {
                    // 如果前一个小孩为1
                    // 需要判断波峰的糖果数 是不是比间隔小孩数多,如果多,当前为1,间隔的都得加1
                    if(bofenvalue > i - bofenidx)
                    {
                        pre = 1;
                        total += i-bofenidx;
                    }else
                    // 如果波峰的糖果数比间隔数少,当前为1,间隔含波峰 都得加1,更新波峰的value
                    {
                        pre = 1;
                        total += i-bofenidx+1;
                        bofenvalue ++;
                    }
                }
            }

        }
        return total;
    }*/

    int candy(vector<int>& ratings) {
        if (0 == ratings.size())
        {
            return 0;
        }
        
        int iChildNum = ratings.size();
        //初始化每个孩子一个糖果
        vector<int> vecCandy(iChildNum, 1);

        for (int i = 1; i < iChildNum; i++)
        {
            if (ratings[i] > ratings[i-1])
            {
                vecCandy[i] = vecCandy[i-1] + 1;
            }
        }
        
        int iTotal = vecCandy[iChildNum-1];
        for (int i = iChildNum - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i+1] && vecCandy[i] <= vecCandy[i+1])
            {
                vecCandy[i] = vecCandy[i+1] + 1;
            }
            iTotal += vecCandy[i];
        }
        
        return iTotal;
    }
};
// @lc code=end

