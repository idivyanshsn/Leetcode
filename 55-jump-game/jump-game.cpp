class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthestDist=nums[0];
        for(int i=1;i<n;i++){
            if(i>farthestDist) return false;
            farthestDist=max(i+nums[i],farthestDist);
            
        }
        return true;
    }
};