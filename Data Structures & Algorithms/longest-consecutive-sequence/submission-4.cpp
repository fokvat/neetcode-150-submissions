class Solution {
public:
    bool contains(const std::vector<int>& nums, int target) {
        for (int num : nums) {
            if (num == target) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        int longestStreak = 0;

        // Iterate through each number as a starting candidate: O(n)
        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            // Continually look for the next consecutive number: O(n) worst-case
            while (contains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            // Update the maximum streak found so far
            longestStreak = std::max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
};
