// https://leetcode-cn.com/problems/generate-parentheses/
// 给定一个数字，生成所有可能的并且有效的括号组合

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0){
            return res;
        }
        generate("", n, n, res);
        return res;
    }
void generate(string curr, int m, int n, vector<string>& res){

    if(n <= 0 && m <= 0){
        res.push_back(curr);
        return;
    }
    //此处需要添加m>0的限制条件，使得左括号用完后，就不能再继续拼接左括号了
    if(m > 0){
        generate(curr+"(", m-1, n, res);
    }
    if(m < n){
        //左括号少于右括号的时候，才能拼接右括号
        generate(curr+")", m, n-1, res);
    }
}
};