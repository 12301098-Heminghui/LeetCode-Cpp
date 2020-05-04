// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

// 方法一：分治求解（这种方法在给定数组为单调递减的情况下，会超时）
class Solution {
int helper(vector<int> & heights, int low, int high){
    if(heights.size() <= 0 || low > high){
        return 0;
    }
    //找到最矮的柱子在数组中的index
    int minIndex = low;
    for(int i = low+1; i <= high; i++){
        if(heights[i] < heights[minIndex]){
            minIndex = i;
        }
    }
    int leftMax = helper(heights, low, minIndex-1);
    int rightMax = helper(heights, minIndex+1, high);
    int area = heights[minIndex]*(high-low+1);
    //cout << "area="<<area<<endl;
    return max(area, max(leftMax, rightMax));
}
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() <= 0){
            return 0;
        }
        int maxArea = helper(heights, 0, heights.size()-1);
        return maxArea;
    }
};

// 方法二：单调栈
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() <= 0){
            return 0;
        }
        //int maxArea = helper(heights, 0, heights.size()-1);
        // 维护一个单调栈来实现
        stack<int> st; // 维护一个单调关系的数组的index
        heights.insert(heights.begin(), 0);
        heights.push_back(0);//在最后添加一个0是为了保证数组为递增的情况下也可以弹出
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            //栈不为空，且当前元素大于栈顶元素时，计算以栈顶元素为高的矩形面积
            while(!st.empty() && heights[i] < heights[st.top()]){
                int curr_index = st.top();
                cout << "curr_index="<< curr_index << endl;

                st.pop();
                int left = st.top()+1;
                int right = i-1;
                cout << "left=" << left <<",right="<<right <<endl;

                maxArea = max(maxArea, (right-left+1)*heights[curr_index]);
                cout << "maxArea=" << maxArea << endl;
            }
            st.push(i);
        }
        return maxArea;
    }