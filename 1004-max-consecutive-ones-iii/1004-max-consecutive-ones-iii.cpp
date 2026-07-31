class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int n=nums.size();
        int maxLen=0;
        int zeros=0;
        while(right<n){
            if(nums[right]==0)
                zeros++;
            
            if(zeros>k){
                if(nums[left]==0)
                    zeros--;
                left++;
            }
            int len=right-left+1;
            maxLen=max(len,maxLen);
            right++;

        }
        return maxLen;
    }
};