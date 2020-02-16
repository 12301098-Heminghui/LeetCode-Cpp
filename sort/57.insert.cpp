//原题链接：
// https://leetcode-cn.com/problems/insert-interval/submissions/
//题目：给定一个无重叠，并且按照区间起始端点排序的区间列表。
// 给一个新的区间，插入到区间列表里，插入后要保证区间列表有序无重叠(有重叠，需要进行区间合并)

//思路：1.先遍历区间列表，将newInternal插入到区间列表，保证插入后区间列表依然有序
//     2.进行重叠部分的合并。


#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int cnt = intervals.size();
        if(cnt <= 0){
            res.push_back(newInterval);
            return res;
        }
        //先把newInternal插入到一个合适的位置(保证插入后intervals的start依然有序)
        // vector<vector<int>> newIntervals(cnt+1)
        for(int i = 0; i < cnt; i++){
            if(newInterval[0] >  intervals[i][0]){
                continue;
            }else{
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
        }
        //此处需要考虑newInternal不满足在intervals中间插入的情况。
        if(intervals.size() == cnt){
            intervals.push_back(newInterval);
        }
        cout <<"intervals size: "<< intervals.size() << endl;
        res.push_back(intervals[0]);
        for(int i = 1; i < cnt+1; i++){
            vector<int> tail = res.back();
            if(intervals[i][0] > tail[1]){
                res.push_back(intervals[i]);
            }else{
                res.back()[1] =  max(tail[1], intervals[i][1]);
            }
        }
        return res;
    }
};