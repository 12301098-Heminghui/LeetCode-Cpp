//原题链接：
// https://leetcode-cn.com/problems/best-sequence-at-index-lcci/submissions/
// 叠罗汉节目，计算最多可叠多少人
/*
 * 
 *  输入：height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
    输出：6
    解释：从上往下数，叠罗汉最多能叠 6 层：(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
 **/

//思路: 1.先对身高进行升序排列(身高相等，再按体重升序排)
//      2.排序后的数组，从前往后遍历，身高一定是满足条件的，于是问题就变成了求解体重这一维度的最长递增子序列
//      3.动态规划问题(两层for训练的动态规划，超时)；
//      4.动态规划+二分查找可ac,时间复杂度O(NlogN)（参考链接:https://cloud.tencent.com/developer/article/1469560）
#include<vector>
using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
    return a.first==b.first ? a.second<=b.second : a.first<b.first;
}
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int cnt = height.size();
        vector<pair<int,int>> person_vec(cnt);
        for(int i = 0; i < cnt; i++){
            pair<int,int> p;
            p = make_pair(height[i],weight[i]);
            person_vec[i] = p;
        }
        //先按照身高升序，如果身高相等则按体重排序
        sort(person_vec.begin(), person_vec.end(),compare);

        //接下来，就是求体重的最长递增子序列
        vector<int> dp(cnt,1);//全初始化为1

        for(int i = 1; i < cnt; i++){
            for(int j = 0; j < i; j++){
                if(person_vec[i].second > person_vec[j].second){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        auto maxPosition = max_element(dp.begin(), dp.end());
        return *maxPosition;

    }
};


bool compare(pair<int,int>& a,pair<int,int>& b){
    return a.first==b.first ? a.second<=b.second : a.first<b.first;
}
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int cnt = height.size();
        vector<pair<int,int>> person_vec(cnt);
        for(int i = 0; i < cnt; i++){
            pair<int,int> p;
            p = make_pair(height[i],weight[i]);
            person_vec[i] = p;
        }
        //先按照身高升序，如果身高相等则按体重排序
        sort(person_vec.begin(), person_vec.end(),compare);

        //接下来，就是求体重的最长递增子序列
        int res = 0;
        vector<int> top(cnt);
        for(int i = 0; i < cnt; i++){
            int poker = person_vec[i].second;
            int left = 0;
            int right = res;
            while(left < right){
                int mid = left+(right-left)/2;
                if(top[mid] < poker){
                    left = mid+1;
                }else if(top[mid] > poker){
                    right = mid;
                }else{
                    right = mid;
                }
            }
            //left==res表示在[left,right)这样的左闭右开搜索区间，没有找到等于当前数组元素值的。
            if(left == res){
                res++;
            }
            //新建一个堆，或者是更新已有堆的最上面元素值
            top[left] = poker;
        }
        return res;
    }
};