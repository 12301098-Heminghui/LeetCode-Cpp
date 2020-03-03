// https://leetcode-cn.com/problems/longest-common-prefix/
// 最长公共前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_size = INT_MAX;
        if(strs.empty()){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() < min_size){
                min_size = strs[i].size();
            }
        }
        int cnt = 0;
        for(int i = 0; i < min_size; i++){
            int j;
            for(j = 0; j < strs.size()-1; j++){
                if(strs[j][i] != strs[j+1][i]){
                    break;
                }
            }
            if(j != strs.size()-1){
                break;
            }else{
                cnt += 1;
            }
        }
        return strs[0].substr(0, cnt);
    }
};
