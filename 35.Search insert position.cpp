using namespace std;
#include <vector>
#include <iostream>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right){
            mid = left + (right - left)/2;
            if (target <= nums[mid]){
                right = mid - 1;
            }else{
                left = mid+1;
            }
            cout << mid << ',';
        }
        return left;
    }
};