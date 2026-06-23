class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> num2;
        for(int i=0;i<nums.size();i++){
            if(num2.count(nums[i]) > 0) return true;
            num2[nums[i]] = 1;
        }
        return false;
    }
};
