/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (13.84%)
 * Total Accepted:    116.9K
 * Total Submissions: 844K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */
class Solution {
public:
    bool isNumber(string s) {
        //先清除行首行尾空格
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        
        if (s.empty())
        {
            return false;
        }

        int iPos = s.find_first_of('e');
        if (-1 == iPos)
        {
            //没有指数，直接校验数字
            return checkBaseNum(s);
        }

        return checkBaseNum(s.substr(0, iPos)) && checkPowerNum(s.substr(iPos + 1));
    }
    bool checkBaseNum(string base) {
        if (base.empty())
        {
            return false;
        }
        int iPos = 0;
        if (base[iPos] == '-' || base[iPos] == '+')
        {
            iPos++;
        }
        bool bDecimal = false;
        int iDecimalNum = 0;
        int iIntNum = 0;
        for (; iPos < base.size(); iPos++)
        {
            if (base[iPos] == '.')
            {
                if (bDecimal)
                    return false;
                bDecimal = true;
                continue;
            }
            if (bDecimal)
                iDecimalNum++;
            else
                iIntNum++;
                
            if (base[iPos] < '0' || base[iPos] > '9') {
                return false;
            }
        }
        if (0 == iIntNum && 0 == iDecimalNum)
            return false;
        return true;
    }
    bool checkPowerNum(string power) {
        if (0 == power.length())
        {
            return false;
        }
        int iPos = 0;
        if (power[iPos] == '-' || power[iPos] == '+')
        {
            iPos++;
        }
        int iIntNum = 0;
        for (; iPos < power.size(); iPos++)
        {
            if (power[iPos] < '0' || power[iPos] > '9') {
                return false;
            }
            iIntNum++;
        }
        if (0 == iIntNum)
            return false;
        
        return true;
    }
};

