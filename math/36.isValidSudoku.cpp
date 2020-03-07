// https://leetcode-cn.com/problems/valid-sudoku/
// 判断9*9的数独是否有效

// 自己ac的代码太长。。。。。。。
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i =0; i < 9; i++){
            //每一行判断
            if(!isValid(board[i])){
                return false;
            }
            //每一列判断
            vector<char> tmpVec(9);
            for(int j = 0; j < 9; j++){
                tmpVec[j] = board[j][i];
            }
            if(!isValid(tmpVec)){
                return false;
            }
        }
        // 9个小方格判断
        for(int i=0; i < 9;){
            vector<char> tmpVec = generateGrid(board, i, i+2, 0, 2);

            if(!isValid(tmpVec)){
                for(auto c: tmpVec){
                    cout << c;
                }
                cout << endl;
                return false;
            }
            if(!isValid(generateGrid(board, i, i+2, 3, 5))){
                return false;
            }
            if(!isValid(generateGrid(board, i, i+2, 6, 8))){
                return false;
            }
            i = i+3;
        }
        return true;

    }
// 生产小方格
vector<char> generateGrid(vector<vector<char>>& board, int rowStart, int rowEnd, int colStart, int colEnd){
    vector<char> vec;
    for(int i = rowStart; i <= rowEnd; i++){
        for(int j = colStart; j <= colEnd; j++){
            vec.push_back(board[i][j]);
        }
    }
    for(auto c: vec){
        cout<<c;
    }
    cout << endl;
    return vec;
}
// 判断是否重复
bool isValid(vector<char> vec){
    map<char, bool> myMap;
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if(vec[i] == '.'){
            continue;
        }
        if(myMap.find(vec[i]) != myMap.end()){
            return false;
        }else{
            myMap[vec[i]] = true;
        }
    }
    return true;
}
};


// 官方解题 (多用了几个HashMap来实现, 代码清爽很多)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char,int>> rowMap(9);
        vector<map<char,int>> colMap(9);
        vector<map<char,int>> gridMap(9);

        for(int i = 0; i < 9; i++){
            map<char, int> tmpMap;
            rowMap[i] = tmpMap;
            colMap[i] = tmpMap;
            gridMap[i] = tmpMap;
        }
        for(int i =0; i < 9; i++){
            for(int j=0; j < 9; j++){
                char val = board[i][j];
                if(val == '.'){
                    continue;
                }
 
                if(rowMap[i].find(val) != rowMap[i].end()){
                    return false;
                }else{
                    rowMap[i].insert(make_pair(val, 1));
                }
                if(colMap[j].find(val) != colMap[j].end()){
                    return false;
                }else{
                    colMap[j].insert(make_pair(val, 1));

                }
                // 此处board的元素，对应第几个小方格
                if(gridMap[i/3*3+j/3].find(val) != gridMap[i/3*3+j/3].end()){
                    return false;
                }else{
                    gridMap[i/3*3+j/3].insert(make_pair(val, 1));
                }
            }
        }
        return true;
    }
};

