// https://leetcode-cn.com/problems/zigzag-conversion/submissions/

// 先将同一行的字符存为一个string。然后把每行的string拼接起来。
// 关键在于怎么把同一行的字符找到。
// 遍历输入的string时，字符所在的行在变化，但是这里的变化有一个规律，第0行的下一个移动方向都是向下，而最后一行的移动方向都是向上
// 因此，可以定义一个方向变量goDown标识是否往下走。如果goDown为TRUE，则currRow需要加1

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || numRows == 1){
            return s;
        }
        vector<string> rows(min(int(s.size()), numRows));
        int currRow = 0;
        bool goDown = false;
        for(char c: s){
            rows[currRow] += c;
            if(currRow == 0 || currRow == numRows-1){
                goDown = !goDown;
            }
            currRow += goDown? 1:-1;
        }
        string res;
        for(string row : rows){
            res += row;
        }
        return res;
    }
};
