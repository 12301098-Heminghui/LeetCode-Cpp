// 原题链接：
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
//思路： 定义滑动窗口[i, j) 利用一个Hash表，存储string的每个字符的位置。
// j往后滑动时，判断s[j]是否已经在Hash表中出现过。如果已出现，说明i的位置需要更新。
// j往后滑动时，更新子串的最大长度


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        if(s.size() <= 1){
            return s.size();
        }
        map<int, int> intMap;
        //定义滑动窗口
        int i=0;
        int j=0;
        int n = s.size();
        int res = 0;
        while(i < n && j < n){
            cout <<"i = " << i << ",j = " << j << endl;
            cout <<"s[i] = " << s[i] << ", s[j]=" << s[j] << endl;
            if(intMap.find(s[j]) != intMap.end()){
                cout << intMap[s[j]] << endl;
                i = max(i, intMap[s[j]]+1); // 如果s[j]已经在子串中，则需要更新窗口的起始位置.比如abba情况，i的值为i和intMap[s[j]]+1的最大值
            }
            cout <<"res1=" << res << endl;
            res = max(res, j-i+1);
            cout <<"res2=" << res << endl;
            intMap[s[j]] = j;
            j++;
        }
        return res;
    }
};