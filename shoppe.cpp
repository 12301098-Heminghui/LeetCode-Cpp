# include<limits.h>
# include<vector>
# include<map>
# include<string>
# include<iostream>
using namespace std;

// 一个输入流不断输入字符串，每个字符串进来时，输出当前接受到的字符串中第一个不重复的字符串
// example input: ab ab a b b c a
// output ab * a a a a c
map<string, int> strMap;
vector<string> strVec;
class Solution {
public:
    void findFirstNoRepeate(string s) {
        map<string, int>::iterator it;
        if (strMap.empty() || it != strMap.end()) {
            // s第一次出现
            strMap.insert(pair<string, int>(s, 1));
            strVec.push_back(s);
            cout << strVec.front();
        }else {
            // s已经出现在Map中
            it = strMap.find(s);
            for (vector<string>::iterator tmpIt = strVec.begin(); tmpIt < strVec.end(); tmpIt++) {
                if (s == *tmpIt) {
                    tmpIt=strVec.erase(tmpIt);
                    if (tmpIt == strVec.end()) {
                        cout << "*";
                        break;
                    }
                }else{
                    cout << *tmpIt;
                    break;
                }
            }
        }
        return;  
    }

};