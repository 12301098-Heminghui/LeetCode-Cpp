// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  


class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size()-1;
        int mid = left;//此处初始化为left,考虑的是数组未做旋转
        while(numbers[left] >= numbers[right]){
            cout << "left="<<left<<",right="<<right<<",mid="<<mid<<endl;
            if(left+1 == right){
                return numbers[right];
            }
            mid = left + (right-left)/2;
            if(numbers[left] == numbers[mid] && numbers[mid] == numbers[right]){
                //这种情况就只能顺序查找了
                cout << "特殊情况处理"<<endl;
                int tmp = numbers[left];
                for(int i=left+1; i <= right; i++){
                    tmp = min(tmp, numbers[i]);
                }
                return tmp;
            }
            if(numbers[left] <= numbers[mid]){
                left = mid;
            }else if(numbers[mid] <= numbers[right]){
                right = mid;
            }
        }
        return numbers[mid];
    }
};


