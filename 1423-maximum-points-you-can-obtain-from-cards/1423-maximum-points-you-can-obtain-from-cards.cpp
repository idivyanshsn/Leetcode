class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rightsum = 0;
        int leftsum = 0;
        int maxSum = 0;
        int rightIndex = n - 1;
        for (int i = 0; i < k; i++) {
            leftsum += cardPoints[i];
            
        }
        maxSum = leftsum;
        for (int i = k - 1; i >= 0; i--) {
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rightIndex];
            maxSum = max(leftsum + rightsum, maxSum);
            rightIndex--;
        }
        return maxSum;
    }
};