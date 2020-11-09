/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.11%)
 * Total Accepted:    281K
 * Total Submissions: 736.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int maxlen = max(a.length(),b.length()) + 1;
        a.insert(a.begin(),maxlen-a.length(),'0');
        b.insert(b.begin(),maxlen-b.length(),'0');
        string rtn(maxlen, '0');
        char chAdd = '0';
        for (int iPos = 0;iPos<maxlen;++iPos)
        {
            switch (a[maxlen-iPos-1] + b[maxlen-iPos-1] + chAdd)
            {
                case '0'+'0'+'0':
                    rtn[maxlen-iPos-1] = '0';
                    chAdd = '0';
                    break;
                case '0'+'0'+'1':
                    rtn[maxlen-iPos-1] = '1';
                    chAdd = '0';
                    break;
                case '0'+'1'+'1':
                    rtn[maxlen-iPos-1] = '0';
                    chAdd = '1';
                    break;
                case '1'+'1'+'1':
                    rtn[maxlen-iPos-1] = '1';
                    chAdd = '1';
                    break;
                default:
                    cout << "xxxxx" << endl;
                    break;
            }
        }

        if ('0' == *rtn.begin())
        {
            rtn.erase(rtn.begin());
        }
        return rtn;
    }
};

