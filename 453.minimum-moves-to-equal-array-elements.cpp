
# include<limits.h>
# include<vector>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum = INT_MAX;
        int sum = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) minnum = min(minnum, *it);
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) sum += (*it - minnum);
        return sum;
    }

};