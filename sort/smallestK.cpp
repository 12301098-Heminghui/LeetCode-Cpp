//原题链接
// https://leetcode-cn.com/problems/smallest-k-lcci/submissions/

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        // 使用快排来实现，不能保证找到的k个数按照有序的状态输出
        // 使用堆排序可以做到,构建最小堆
        int len = arr.size();
        for(int i = len/2-1; i >= 0; i--){
            adjust_dowm(arr, i, len);
        }
        vector<int> res;
        for(int i = len-1; i >= len-k; i--){
            // cout << "===find k min===" << endl;
            // cout << "arr[0]=" << arr[0] << ",arr[i]=" << arr[i] << endl;
            res.push_back(arr[0]);
            int tmp = arr[i];
            arr[i] = arr[0];
            arr[0] = tmp;
            adjust_dowm(arr, 0, i);
        }
        return res;
    }
    void adjust_dowm(vector<int>& arr, int k, int len){
        int target = arr[k];
        int i;
        // cout << "before just,k=" << k <<endl;
        // for训练中i=i*2+1这个赋值，debug了快1个小时！！！！！！！
        for(i = k*2+1; i < len; i = i*2+1){
            if(i+1 <len && arr[i+1] < arr[i]){
                i++;
            }
            // cout << "i=" << i << endl;
            //把小的孩子调到父节点
            if(arr[i] < target){ 
                arr[k] = arr[i];
                k = i;
            }else{
                break;
            }
        }
        arr[k] = target;
        // cout << "after just,k=" <<k<< endl;

    }
};