#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty() || s.size() == 0){
            return 0;
        }
        unordered_map<char, int> roman_map = { {'I',1}, 
                                                {'V',5}, 
                                                {'X',10},
                                                {'L', 50},
                                                {'C', 100},
                                                {'D', 500},
                                                {'M', 1000}
                                            };
        
        int res = roman_map[s.back()];
        for(int i = s.size()-2; i >=0; i--){
            if (roman_map[s[i]] < roman_map[s[i+1]]) {
                res = res - roman_map[s[i]];
            }else{
                res += roman_map[s[i]];
            }
        }
        return res;
    }
};
