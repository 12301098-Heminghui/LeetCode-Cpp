//原题链接
// https://leetcode-cn.com/problems/container-with-most-water/submissions/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = min(height[left], height[right])*(right-left);
        while(left < right){
            int area = min(height[left], height[right])*(right-left);
            max_area = max(max_area, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }

};


int main(){
    int a[5] = {1,2,3,4,5};
    vector<int> test_case = {1,8,6,2,5,4,8,3,7};
    cout << "test======" << endl;
    Solution s ;
    int area = s.maxArea(test_case);
    cout << area << endl;
}