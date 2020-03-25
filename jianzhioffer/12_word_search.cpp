// 深度优先搜索
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<pair<int,int>> visit;
        for(int i=0; i < row; i++){
            for(int j=0; j <col; j++){
                if(findPath(i,j,board, word, 0, visit)){
                    return true;
                }
            }
        }
        return false;
    }
// 这种判断符合条件，再去深度遍历。代码很长，冗余。
 bool findPath(int i, int j, vector<vector<char>>& board, string& word, int str_index, vector<pair<int,int>>& visit){
        if(find(visit.begin(), visit.end(), make_pair(i,j)) == visit.end() && board[i][j] == word[str_index]){
            if(str_index == word.size()-1){
                return true;
            }
            //没被访问过，并且值相同
            visit.push_back(make_pair(i,j));
            if(i-1 >= 0 && i-1 < board.size()){
                cout<<"up"<<endl;
                bool up = findPath(i-1, j, board, word, str_index+1, visit);
                if(up){
                    return true;
                }
            }
            if(i+1 >= 0 && i+1 < board.size()){

                bool dowm = findPath(i+1, j, board, word, str_index+1, visit);

                if(dowm){
                    return true;
                }
            }
            if(j-1 >= 0 && j-1 < board[0].size()){

                bool left = findPath(i, j-1, board, word, str_index+1, visit);

                if(left){
                    return true;
                }

            }
            if(j+1 >= 0 && j+1 < board[0].size()){

                bool right = findPath(i, j+1, board, word, str_index+1, visit);

                if(right){
                    return true;
                }
            }
            visit.pop_back();
        }
        return false;;

    }
};


// 第二种方法：先做剪枝（即那些不符合继续深度遍历的， 直接return）
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<pair<int,int>> visit;
        for(int i=0; i < row; i++){
            for(int j=0; j <col; j++){
                if(findPath(i,j,board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
 bool findPath(int i, int j, vector<vector<char>>& board, string& word, int str_index){
     if(i < 0 || i >= board.size()){
         return false;
     }
     if(j < 0 || j >= board[0].size()){
         return false;
     }
     if(str_index >= word.size()){
         return false;
     }
     if(word[str_index] != board[i][j]){
         return false;
     }
    if(str_index == word.size()-1){
            return true;
    }
    char tmp = board[i][j];
    board[i][j] = '.';
    bool res = findPath(i+1,j,board,word,str_index+1) || findPath(i-1,j,board,word,str_index+1) || findPath(i,j+1,board,word,str_index+1) || findPath(i,j-1,board,word,str_index+1);
    board[i][j] = tmp;
    return res;
 }
};