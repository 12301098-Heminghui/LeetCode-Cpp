// https://leetcode-cn.com/problems/string-to-integer-atoi/
// 字符串转成int数

class Solution {
public:
    int myAtoi(string str) {
        
        int flag= 1;//定义一个正负号的标志位
        bool start=false; //标识是否找到了起始位置(正负号或者数字)
        long result = 0;
        for(char s: str){
            if(s == ' ' && start==false){
                continue;
            }
            if(s == '-' && start==false){
                start=true;
                flag=-1;
                continue;
            }
            if(s == '+' && start==false){
                start=true;
                continue;
            }
            if(s >= '0' && s <= '9'){
                start=true;
                result = result*10 + flag*(s - '0');
                if(result > INT_MAX){
                    return INT_MAX;
                }
                if(result < INT_MIN){
                    return INT_MIN;
                }
            }else{
                break;
            }
        }
        return result;
    }
};