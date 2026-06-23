class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> isDup;
        for(int i=0;i<nums.size();i++){
            if(isDup.contains(nums[i]))
                return true;

            isDup[nums[i]] = true;
        }

        return false;
        
    }
};