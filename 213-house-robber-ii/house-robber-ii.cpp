class Solution {
public:
    int function(vector<int> &nums,int start , int end){ 
        int prev=0;
        int prev2=0;
        int curr=0;
        for(int i=start;i<=end;i++){
            int pick=nums[i]+prev2;
            int notpick=prev;
            curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(function(nums,0,n-2),function(nums,1,n-1));
    }
};