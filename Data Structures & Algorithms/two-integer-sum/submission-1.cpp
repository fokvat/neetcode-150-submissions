class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> isSum;
        for(int i = 0; i < nums.size();i++){
            if(isSum.contains(nums[i])){
                return {isSum[nums[i]], i};
            }
            isSum[target-nums[i]] = i;
        }
        return {};
    }
};
