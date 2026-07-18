class Solution {
public:
    int trap(vector<int>& height) {
        int s = height.size();
        vector<int> l (s, 0);
        vector<int> r (s, 0);
        int trapWater = 0;

        l[0] = height[0];
        for(int i=1;i<s;i++){
            l[i] = max(height[i], l[i - 1]);
        }
        r[s-1] = height[s-1];
        for(int i=s-2;i>=0;i--){
            r[i] = max(height[i], r[i + 1]);
        }

        for(int i=1;i<s;i++){
            trapWater += min(l[i], r[i]) - height[i];
        }

        return trapWater;
        
    }
};
