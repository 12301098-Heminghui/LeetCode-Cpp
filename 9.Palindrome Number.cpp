#include <cmath>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindromeV1(int x) {
        /*
         * 采用reverse integer的思想。
         * 将输入数字反转，比较反转后的值与输入值是否相等
         */
        if (x < 0){
            return false;
        }
        int n = x;
        int rev = 0;
        while(n != 0){
            if (rev > INT_MAX/10){
                return false;
            }
            rev = rev*10 + n%10;
            n = n/10;
        }
        if (rev == x) {
            return true;
        }else{
            return false;
        }
    }

    bool isPalindromeV2(int x){
        /**
         * 将int的类型，转成string类型
         * 比较string是否对称
         */
        if (x < 0){
            return false;
        }
        
        string str = to_string(x);
        int len = str.size();
        if (len == 1){
            return true;
        }
        int step = len/2;
        int index = 0;
        while(index < step){
            if (str[index] == str[len-1-index]){
                index++;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(int x) {
        /**
         * 对x进行反转（只需反转后半部分，这样也不需要考虑溢出的问题）
         * 比较反转到一半的值是否相同
         */
        if (x < 0 || (x != 0 && x%10==0)){
            return false;
        }
        int sum = 0;
        while(x > sum) {
            sum = sum*10 + x%10;
            x = x/10;
        }
        return (x==sum || x == sum/10);
    }
};