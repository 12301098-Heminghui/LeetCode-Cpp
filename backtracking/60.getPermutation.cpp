// https://leetcode-cn.com/problems/permutation-sequence/
// 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
// 按大小顺序列出所有排列情况，并一一标记

// 超时
class Solution {
void helper(vector<string> &res, string &str, int n, int k){
    if(str.size() == n){
        if(res.size() == k){
            return;
        }else{
            res.push_back(str);
        }
    }else{
        for(int i = 1; i <= n; i++){
            if(str.find(to_string(i)) != str.npos){
                continue;
            }
            str += to_string(i);
            helper(res, str, n, k);
            str = str.substr(0,str.size()-1);
        }
    }
}
public:
    string getPermutation(int n, int k) {
        int num = 1;
        for(int i=1; i < n; i++){
            num *= i;
        }
        if(n == 1){
            return to_string(n);
        }
        vector<string> res;
        string str = to_string(1 + (k-1)/num);
        k = k%num==0?num:k%num;
        //cout << "str=" << str << ",k=" << k << endl;

        cout << k << endl;
        helper(res, str, n, k);
        cout << res.size();
        return res[k-1];
    }
};

// 优化后，可通过

class Solution {
void helper(string &str, int n, int k, int num, int i){
        int tmp = 1 + (k-1)/num;//从右到左第i个元素大小顺序
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(str.find(to_string(i)) != str.npos){
                continue;
            }else{
                cnt += 1;
            }
            if(tmp == cnt){
                str += to_string(i);
                break;
            }
        }
        k = k%num==0?num:k%num;
        if (i == 1){
            return;
        }
        helper(str, n, k, num/(i-1), i-1);
}
public:
    string getPermutation(int n, int k) {
        int num = 1;
        for(int i=1; i < n; i++){
            num *= i;
        }
        if(n == 1){
            return to_string(n);
        }
        string str = to_string(1 + (k-1)/num);
        k = k%num==0?num:k%num;
        //str表示要返回的第k个排列。
        //k表示剩下的(n-1)!种排列中的第k个
        //n-1表示接下来寻找的是1到n-1集合组成的排列
        helper(str, n, k, num/(n-1), n-1);
        return str;
    }
};