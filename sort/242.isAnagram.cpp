// 原题链接：
// https://leetcode-cn.com/problems/valid-anagram/
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int hash[26] = {0};
        for(int i = 0; i < s.size(); i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        for(int i=0; i < 26; i++){
            if(hash[i] != 0){
                return false;
            }
        }
        return true;
    }
};
