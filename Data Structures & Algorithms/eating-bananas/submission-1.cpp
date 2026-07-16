class Solution {
public:
    bool validateBanana(vector<int> &arr, int speed, int h){
        int j = 0, i = 0;
        while(i < arr.size()){
            int temp = arr[i];
            if(temp % speed == 0){
                j += temp / speed;
            }else{
                 j += (temp / speed) + 1;
            }

            if(j > h) return false;

            i++;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int k = 0;
        
        int start = 1;
        int end = piles[piles.size()-1];

        while (start <= end){
            int mid = (start + end)/2;
            if(validateBanana(piles, mid, h)){
                k = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            
        }

        return k;
        
    }
};
