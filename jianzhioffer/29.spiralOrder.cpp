class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if(rows <= 0){
            return res;
        }
        int cols = matrix[0].size();
        int start = 0;
        while(start*2 < rows && start*2 < cols){
            loop(matrix, start, res);
            start++;
            cout<<start<<endl;
        }
        return res;
    }
void loop(vector<vector<int>>& matrix, int start, vector<int>& res){
    int endRow = matrix.size()-start-1;
    int endCol = matrix[0].size()-start-1;
    //从左到右打印行
    for(int i=start; i <= endCol; i++){
        res.push_back(matrix[start][i]);
    }
    //从上到下打印列
    if(endRow > start){
        for(int i = start+1; i <= endRow;i++){
            res.push_back(matrix[i][endCol]);
        }
    }
    //从右到左打印行
    if(endRow > start && endCol > start){
        for(int i = endCol-1; i >= start; i--){
            res.push_back(matrix[endRow][i]);
        }
    }
    //从下到上打印列
    if(endRow-1 > start && endCol > start){
        for(int i=endRow-1; i >= start+1; i--){
            res.push_back(matrix[i][start]);
        }
    }
}
};