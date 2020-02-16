//原题链接：
// https://leetcode-cn.com/problems/merge-intervals/
// 思路：1.先对二维数组排序，排完序后，start是有序的状态
//      2.进行Merge，merge时判断当前元素的start值与merged的最后一个元素的end值小大。
//      3.如果当前元素start值大于merged的最后一个元素的end值,说明无法合并，直接将当前元素push到vector
//      4.如果当前元素start值小于等于merged的最后一个元素的end值，说明可合并。更新merged的最后一个元素的end值

#include<vector>
using namespace std;
bool compare(vector<int>& a, vector<int>& b){
    return a[0] == b[0]?a[1] < b[1]:a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int cnt = intervals.size();
        if(cnt <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < cnt; i++){
            vector<int> tail = res.back();
            if(intervals[i][0] > tail[1]){
                res.push_back(intervals[i]);
            }else{
                res.pop_back();
                res.push_back({tail[0], max(intervals[i][1],tail[1])});
            }
        }
        return res;
    }
};