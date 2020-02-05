#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++) {
            char tmp = s[i];
            if(tmp == '(' || tmp == '{' || tmp == '[') {
                stk.push(tmp);
            }else if (stk.size() && isPair(stk.top(), tmp)) {
                stk.pop();
            }else{
                return false;
            }
        }
    return stk.empty();
    }
private : 
    bool isPair(char ch1, char ch2){
    if ((ch1 == '(' and ch2 == ')') || 
    (ch1 == '{' and ch2 == '}') ||
    (ch1 == '[' and ch2 == ']')){
        return true;
    }
    return false;
    }
};