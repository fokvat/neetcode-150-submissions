class Solution {
public:

    bool compare26 (int (&a1) [26], int (&a2)[26]){
        for(int i=0;i<26;i++){
            if(a1[i] != a2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;

        int arr[26]= {0}, temp[26] = {0};
        for(int i=0;i<s1.length();i++){
            arr[s1[i] - 'a'] += 1;
            temp[s2[i] - 'a'] += 1;
        }

        int i=0, j=s1.length() - 1;
        while(j < s2.length()){
           if(compare26(arr, temp)) return true;

           temp[s2[i] - 'a'] -= 1;
           j++;
           if(j<s2.length()) temp[s2[j] - 'a'] += 1;
           i++;
        }


        return false;
    }
};
