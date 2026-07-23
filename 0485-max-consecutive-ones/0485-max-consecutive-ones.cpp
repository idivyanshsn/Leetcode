class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak = 0;
        int currentStreak = 0;
        for (int num : nums) {
            if (num == 1) {
                currentStreak++;
                streak = max(streak, currentStreak);
            } else {
                currentStreak = 0;
            }
        }
        return streak;
    }
};