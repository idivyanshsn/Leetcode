class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        vector<int> ans;
        int p=0;
        int j=n;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans.push_back(temp[p]);
                p++;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        return ans;
        
    }
};