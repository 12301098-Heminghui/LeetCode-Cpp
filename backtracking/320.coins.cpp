
// https://leetcode-cn.com/problems/coin-change/
// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。



// 回溯法：时间超出限制

class Solution {
static bool compare(int a, int b){
    return a >b;
}
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), compare); //降序排列
        int minVal = INT_MAX;
        int currPath = 0;
        helper(coins, amount, 0, minVal, currPath);
        if(minVal == INT_MAX){
            return -1;
        }
        return minVal;
    }
void helper(vector<int>& coins, int amount, int start, int& minPath, int& currPath){
    if(amount == 0){
        minPath = min(currPath, minPath);
        return;
    }
    if(amount < 0){
        return;
    }
    for(int i = start; i < coins.size(); i++){
        currPath = currPath+1;
        helper(coins, amount-coins[i], i, minPath, currPath);
        currPath--;
    }
}
};


// 改进一：先计算出每个硬币用几次，然后去找凑齐余额的硬币路径
// 还是超出时间限制

class Solution {
static bool compare(int a, int b){
    return a >b;
}
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), compare); //降序排列
        int currPath = 0;
        return helper(coins, amount, 0);

    }
int helper(vector<int>& coins, int amount, int start){
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return -1;
    }
    //cout <<"amount=" << amount << ",start=" << start << endl;
    if(start < coins.size()){
        int minCost = INT_MAX;
        int maxVal = amount/coins[start]; // coins[i] 最多出现的次数
        for(int j=0; j <= maxVal; j++){
            if(amount-j*coins[start] >= 0){
                int res = helper(coins, amount-j*coins[start], start+1);
                if(res != -1){
                    minCost = min(minCost, res + j);
                }
            }
        }
        if(minCost==INT_MAX){
            return -1;
        }else{
            return minCost;
        }
    }
    return -1;
}
};


// 动态规划：accept
// 思路：自下而上的思想。
// 定义 F(i)F(i) 为组成金额 ii 所需最少的硬币数量，
// 假设在计算 F(i)之前，我们已经计算出 F(0)-F(i-1)F(0)−F(i−1) 的答案。 
// 则 F(i)对应的转移方程应为 F(i) = min(F(i-cj)) + 1 （假设最后一枚硬币是cj）

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
