class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        int arrSize = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < arrSize-2;i++){
            while(i > 0 and nums[i] == nums[i-1] and i < arrSize - 2){
                i++;
            }

            int j = i+1;
            int k = arrSize-1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if( sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j ++;
                    k --;
                    while(nums[j] == nums[j-1] and j < k){
                        j++;
                    }
                }
                else if(sum < 0){
                    j ++;
                }
                else{
                    k --;
                }
                
                // while(k < arrSize - 1 and nums[k] == nums[k+1] and k > j){
                //     k --;
                // }
            }

        }
        return ans;
    }
};
