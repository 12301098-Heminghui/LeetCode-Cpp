// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

// char数组在C++中，使用起来还是比较费劲
class Solution {
public:
    string replaceSpace(string s) {
        //先找出有多少个空格
        int numspace = 0;
        for(int i=0; i < s.size(); i++){
            if(s[i]==' '){
                numspace++;
            }
        }
        cout << "numspace="<<numspace<<endl;
        //char newchar[s.size()+2*numspace]; //替换后的字符串长度
        char newchar[s.size()+2*numspace+1];
        newchar[s.size()+2*numspace] = '\0'; //此处末尾需要定义一个结束符。char的特殊用法
        int j=s.size()+2*numspace-1;
        int i = s.size()-1;

        while(i >=0 && j >=0){
            if(s[i] != ' '){
                newchar[j] = s[i];
                j--;   
            }else{
                newchar[j--]='0';
                newchar[j--]='2';
                newchar[j--]='%';
            }
            i--;
        }
 
        return string(newchar);
    }
};
