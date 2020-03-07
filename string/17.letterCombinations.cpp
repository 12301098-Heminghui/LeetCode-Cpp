// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// 电话号码的组合。给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合

// 递归的思想。找到递归的结束条件。

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> myMap = {{'2',"abc"},
                                  {'3',"def"},
                                  {'4',"ghi"},
                                  {'5',"jkl"},
                                  {'6',"mno"},
                                  {'7',"pqrs"},
                                  {'8',"tuv"},
                                  {'9',"wxyz"}};
        
        vector<string> strs;
        vector<string> res;
        if(digits.empty()){
            return res;
        }
        for(int i = 0; i < digits.size(); i++){
            strs.push_back(myMap[digits[i]]);
        }
        recursion(strs, 0, "", res);
        return res;
    }
void recursion(vector<string> vec, int index, string res, vector<string>& res_vec){
    if(index >= vec.size()){
        res_vec.push_back(res);
        return;
    }
    string str = vec[index];
    for(int i = 0; i < str.size(); i++){
        recursion(vec, index+1, res+str[i], res_vec);
    }
}
};