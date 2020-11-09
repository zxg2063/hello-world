/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution {
public:
    int chroseCheck(vector<int>& interval, vector<int>& newInterval) {
        //1--
        //interval    :[  ]
        //newInterval :      [  ]
        //2--
        //interval    :[      ]
        //newInterval :  [  ]
        //3--
        //interval    :[      ]
        //newInterval :  [      ]
        //4--
        //interval    :   [ ]
        //newInterval :[      ]
        //5--
        //interval    :   [      ]
        //newInterval :[      ]
        //6--
        //interval    :      [  ]
        //newInterval :[  ]
        return 0;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //0-合并intervals中元素，1-合并newInterval元素
        int iMergeType = 1;
        int iPos = 0;
        int iPosNew = 0;
        while (true)
        {
            if (1 == iMergeType)
            {
            }
            else
            {
                /* code */
            }
            
        }
        
        return intervals;
    }
};

