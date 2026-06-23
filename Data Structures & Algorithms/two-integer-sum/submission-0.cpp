class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;
        vector<int> res;

        for (int i=0;i <nums.size();i++){
            if (diff.count(target - nums[i]) > 0)
            {
                res.push_back(diff[target - nums[i]]);
                res.push_back(i);
            }
            diff[nums[i]] = i;
        }

        return res;
    }
};
