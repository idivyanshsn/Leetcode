class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0;
        int right=n-1;
        int maxArea=0;
        while(left<=right){
            int width=right-left;
            int area=min(height[left],height[right])*width;
            maxArea=max(area,maxArea);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};