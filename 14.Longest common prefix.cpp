#include <vector>
#include <string>
#include <algorithm> 
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0){
            return "";
        }
        auto minSize = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            minSize = minSize > strs[i].size()?strs[i].size():minSize;
        }
        bool isSame = true;
        string res = "";
        
        for (int i = 0; i < minSize; i++){
            char tmp = strs[0][i];
            for(int j = 0; j < strs.size(); j++) {
                if(tmp != strs[j][i]){
                    isSame = false;
                    break;
                }
            }
            if (isSame){
                    res += tmp;
            }else{
                break;
            }
        }
        return res;
    }
};