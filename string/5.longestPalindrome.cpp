// 原题链接：
// https://leetcode-cn.com/problems/longest-palindromic-substring/

 // 题目要求找到最长回文子串

 //方法一：暴力求解法 O(n^3)的时间复杂度，两层for循环得到子串，一层循环判断子串是否为回文
 // 提交时，超出时间限制
 class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() <= 1){
            return s;
        }
        int n = s.size();
        string res = "";
        //cout << "n=" << n << endl;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                //cout << "i=" << i << "\tj=" << j << endl;
                if(isPalindrome(s.substr(i, j-i+1)) && res.size() < j-i+1){
                    res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
bool isPalindrome(string s){
    string reverseStr = s;
    reverse(reverseStr.begin(), reverseStr.end());
    //cout << "origin :" << s << endl;
    //cout << "reversed : " << reverseStr << endl;
    if(reverseStr == s){
        return true;
    }else{
        return false;
    }
}
};


// 方法二：中心法
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() <= 1){
            return s;
        }
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++){
            vector<int> len1 = find(s, i, i); // 以i为中心
            vector<int> len2 = find(s, i, i+1); // 以i、i+1作为中心
            if (len1[1]-len1[0]+1 > res.size()){
                res = s.substr(len1[0],len1[1]-len1[0]+1);
            }
            int len = res.size();

            if(len2[1]-len2[0]+1 > res.size()){
                res = s.substr(len2[0],len2[1]-len2[0]+1);
                cout<<"res2:" << res <<endl;

            }
        }
        return res;
    }
vector<int> find(string s, int i, int j){
    int left = i;
    int right = j;
    while(left >= 0 && right < s.size()){
        if(s[left] == s[right]){
            left--;
            right++;
        }else{
            break;
        }
    }
    return {left+1,right-1};
}
};


// 方法三：动态规划（重点在于动态方程以及初始化）

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() <= 1){
            return s;
        }
        int n = s.size();
        //初始化动态方程的数组
        int res[n][n] = {0};//此处要初始化为0，否则默认值为随机值(局部变量数组，系统默认值为随机值)
        res[0][0] = 1;
        int start = 0;
        int max = 1;
        for(int i = 1; i < n; i++){
            res[i][i] = 1;
            if(s[i] ==  s[i-1]){
                res[i-1][i] = 2;
                start = i-1;
                max = 2;
            }
        }

        for(int l=3; l <= n; l++){
            for(int i = 0; i <= n-l; i++){
                int j = i+l-1;
                if(s[i] == s[j] && res[i+1][j-1]){
                    res[i][j] = l;
                    start = i;
                    max = l;
                }
            }
        }
        return s.substr(start, max);
    }
};