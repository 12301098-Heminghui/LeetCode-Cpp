class Solution {
public:
    int numWays(int n) {
        if(n == 0){
            return 1;
        }
        if( n <= 2){
            return n;
        }
        int one = 1;
        int two = 2;
        int num = 0;
        for(int i=3; i <= n; i++){
            num = (one + two)%1000000007;
            one = two;
            two = num;
        }
        return num;
    }
};