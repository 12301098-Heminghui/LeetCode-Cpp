using namespace std;
#include<string>
class Solution {
public:
    string countAndSay(int n) {

        string res = "1";
        while(--n){
            string tmp = "";
            
            for(int i = 0; i < res.size(); i++){
                int cnt = 1;
                while((i+1) < res.size() && res[i+1] == res[i]){
                    cnt++;
                    i++;
                }
                tmp += to_string(cnt) + res[i];
                
            }
            res = tmp;
        }
        return res;
    }
};
