class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=nums.size();
        int i=0;
        
        while(i<j){
            if(nums[i]==val){
                nums[i]=nums[j-1];
                j--;
            }
            else{
                i++;
            }
        }
        return j;
    }
};