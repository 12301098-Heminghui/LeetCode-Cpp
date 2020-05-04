// https://leetcode-cn.com/problems/spiral-matrix-ii/

// 给定一个数n，按照顺时针打印出1到n*n的元素(一个方阵)
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int val = 1;
        vector< vector<int> > res(n,vector<int> (n,0));
        while(val <= n*n){
            //上行
            for(int i = left; i <= right; i++){
                res[up][i] = val;
                val++;
            }
            //cout << val << endl;
            //右列
            for(int i = up+1; i <= down; i++){
                res[i][right] = val;
                val++;
            }
            //下行
            for(int i=right-1; i >= left;i--){
                res[down][i] = val;
                val++;
            }
            //左列
            for(int i = down-1; i > up; i--){
                res[i][left] = val;
                val++;
            }
            up++;
            down--;
            left++;
            right--;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector< vector<int> > res = s.generateMatrix(2);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ",";
        }
        cout << endl;
    }
}