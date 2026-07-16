class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int i = 0;
        int j = i + 1;
        int maxPrice = 0;

        while( i < size && j < size){
            // cout<<i<<" "<<j<<" "<<prices[j] - prices[i]<<endl;

            if(prices[j] - prices[i] >= 0){
                maxPrice = max(maxPrice, prices[j] - prices[i]);
                j ++;
            }
            else{
                i = j;
            }
        }
        return maxPrice;
    }
};
