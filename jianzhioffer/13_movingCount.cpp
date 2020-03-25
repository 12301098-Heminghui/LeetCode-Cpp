// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

// 从上面题目描述中提取关键条件：
// 1.机器人可以四个方向移动，并且没有限制格子只能访问一次
// 2.数位之和<=k

// 记录这个题目的思路（与矩阵字符搜索那个题一样）：
// 一开始想的是用一个set来记录机器人访问的格子。对上下左右四个方向深度优先遍历的结果，求max。
// 这种思路存在一个问题：机器人会在两个格子来回，陷入死循环。


// 由于题目并未要求返回路径，所以不需要保存访问路径。同样还是采用深度优先遍历，我们可以只保存格式是否被访问。
// 如果当前格式没有被访问并且没有出方格边界,并且没有超过k值。那返回结果加1即可。

// python版
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        def dfs(i,j,k, visit):
            if i < 0 or i >= m or j < 0 or j >= n or (i,j) in visit:
                return 0
            bitSum = 0
            a = i
            b = j
            while a:
                bitSum += a%10
                a = a/10
            
            while b:
                bitSum += b%10
                b = b/10
            
            if bitSum > k:
                return 0
            visit.add((i,j))

            return 1 + dfs(i, j+1, k, visit) + dfs(i+1, j, k, visit)
        if k < 0:
            return 0
        visit = set()
        return dfs(0,0,k,visit)
            

// C++版

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k < 0){
            return 0;
        }
        set<pair<int,int>> visit;
        return dfs(m,n,k,0,0,visit);
    }
int dfs(int m, int n, int k, int i, int j, set<pair<int,int>>& visit){
    if(i < 0 || i >= m || j < 0 || j >= n){
        return 0;
    }
    if(find(visit.begin(), visit.end(), make_pair(i,j)) != visit.end()){
        return 0;
    }
    int a = i;
    int b = j;
    int bitSum = 0;
    while(a){
        bitSum += a%10;
        a = a/10;
    }
    while(b){
        bitSum += b%10;
        b = b/10;
    }
    if(bitSum > k){
        return 0;
    }
    visit.insert(make_pair(i,j));
    return 1 + + dfs(m, n, k, i+1, j, visit) + dfs(m, n, k, i, j+1, visit);
}
};