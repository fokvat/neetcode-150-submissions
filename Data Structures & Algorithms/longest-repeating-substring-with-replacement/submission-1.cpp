class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        int curMax = 0;
        int maxSubString = 0;
        int i=0;
        int j = 0;
        while(j < s.length()){
            int c = s[j] - 'A';
            mp[c] += 1;
            if(curMax < mp[c]){
                curMax = mp[c];
            }
            j++;
            if((j-i) - curMax > k){
                mp[s[i] - 'A'] -= 1;
                i++;
            }
            cout<<i<<" "<<j<<" "<< curMax <<endl;

            maxSubString = max(maxSubString, j - i);
        }
        return maxSubString;
    }
};
