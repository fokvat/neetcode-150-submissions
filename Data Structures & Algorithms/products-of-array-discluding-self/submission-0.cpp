class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        vector<int> sufics (size, 1);
        vector<int> prefixSum (size, 1);

        for (int i = 1; i < size; i++){
            prefixSum[i] = nums[i-1] * prefixSum[i-1];
        }
        for (int i = size-2; i >=0; i--){
            sufics[i] = nums[i+1] * sufics[i+1];
        }
        for(int i=0;i<size;i++){
            ans.push_back(prefixSum[i] * sufics[i]);
        }

        return ans;
    }
};
