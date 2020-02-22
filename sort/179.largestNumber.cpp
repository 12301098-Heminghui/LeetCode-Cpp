// 原题链接：
// https://leetcode-cn.com/problems/largest-number/
// 题目：将非负数组中的所有元素重新排列，得到一个最大的数字(以string返回，否则可能超出计算机支持的最大值)
// 思路：重新定义一个比较两个元素大小的方法
// (如果两个string x,y 如果x+y大于y+x，则返回TRUE，说明这两个元素不需要交换位置)


#include<vector>
#include<string>
using namespace std;
bool compare(string x, string y){
    return x+y > y+x;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for(int i=0; i < nums.size(); i++){
            nums_str.push_back(to_string(nums[i]));
        }
        sort(nums_str.begin(), nums_str.end(), compare);
        if(nums_str[0] == "0"){
            return nums_str[0];
        }
        string str = "";
        for(int i=0; i < nums_str.size(); i++){
            str += nums_str[i];
        }
        return str;
    }
};