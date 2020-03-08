// https://leetcode-cn.com/problems/count-and-say/
// 从数字 1 开始，序列中的每一项都是对前一项的描述
// 1 被读作  "one 1"  ("一个一") , 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

// 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

class Solution {
public:
    string countAndSay(int n) {
        if(n < 1){
            return "";
        }
        vector<string> strVec;
        strVec.push_back("1");
        for(int i = 0; i < n-1; i++){
            string str = helper(strVec[i]);
            strVec.push_back(str);
        }
        return strVec[n-1];
    }
string helper(string str){
    string res = "";
    string last = string(1,str[0]);
    int cnt = 1;
    for(int i=1; i < str.size(); i++){
        if(string(1,str[i]) != last){
            res += to_string(cnt)+last;
            last = str[i];
            cnt = 1;
        }else{
            cnt += 1;
        }
    }
    res += to_string(cnt) + last;
    return res;
}
};


// 稍微改进，运行效率更高

class Solution {
public:
    string countAndSay(int n) {
        if(n < 1){
            return "";
        }
        string str = "1";
        for(int i = 1; i < n; i++){
            string tmp = helper(str);
            str = tmp;
        }
        return str;
    }
string helper(string str){
    string res = "";
    string last = string(1,str[0]);
    int cnt = 1;
    for(int i=1; i < str.size(); i++){
        if(string(1,str[i]) != last){
            res += to_string(cnt)+last;
            last = str[i];
            cnt = 1;
        }else{
            cnt += 1;
        }
    }
    res += to_string(cnt) + last;
    return res;
}
};