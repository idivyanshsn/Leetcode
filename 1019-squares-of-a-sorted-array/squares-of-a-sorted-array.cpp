class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        int index=n-1;
        vector<int> result(n);
        while(left<=right){
            int rightVal=abs(nums[right]);
            int leftVal=abs(nums[left]);
            if(leftVal<rightVal){
                result[index]=rightVal*rightVal;
                right--;
            }
            else {
                result[index]=leftVal*leftVal;
                left++;
            }
            index--;
        }
        return result;
    }
};