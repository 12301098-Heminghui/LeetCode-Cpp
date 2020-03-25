
// 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        long long one = 0;
        long long two = 1;
        long long fibN = 0;
        for(int i=2; i <=n; i++){
            fibN = (one + two)%1000000007;
            one = two;
            two = fibN;
        }
        return fibN;
    }
};