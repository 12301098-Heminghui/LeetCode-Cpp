// https://leetcode-cn.com/problems/consecutive-numbers-sum/
// 给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?

// 通过连续正整数的起终点来遍历，超时！！！
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        if(N <= 2){
            return 1;
        }
        int num = 1;
        int min = 1;
        int max = 1;
        int sum = 0;
        while(min <= N/2 + 1){
            //cout << "sum=" << sum<<endl;
            if(sum == N){
                num++;
                sum = 0;
                min++;
                max = min;
            }
            else if(sum < N){
                sum += max;
                max++;
            }else{
                sum = 0;
                min++;
                max = min;
            }
        }
        return num;
    }
};

// 利用等差数列求和公式
// 设从a开始，连续k个元素组成的序列和等于N,那么 N = (a+a+k-1)*k/2
// 对求和公式变换，a*k = N - (k-1)*k/2，能使得该式子成立的k都符合题目要求。
// 仔细分析一下k的取值范围：k >= 1 && (N-(k-1)*k/2) > 0。
// 所以对取值范围内的k进行遍历，找到满足a*k = N - (k-1)*k/2这个条件的k的数量

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int sum = 0;
        for(int k = 1; (k-1)*k/2 < N; k++){
            int tmp = N - (k-1)*k/2;
            if(tmp%k == 0){
                sum++;
            }
        }
        return sum;
    }
};