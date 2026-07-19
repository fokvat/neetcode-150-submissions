class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isAlnum (s:string):boolean{
        return ((s.toLowerCase() >= 'a' 
            && s.toLowerCase() <='z') 
            || (s.toLowerCase() >= '0' 
            && s.toLowerCase() <='9'));
    }

    isPalindrome(s: string): boolean {
        let l = 0, r = s.length - 1;

        while(l <= r){
            if(!this.isAlnum(s[l])){
                l++;
            }else if(!this.isAlnum(s[r])){
                r--;
            }
            else if(s[l].toLowerCase() === s[r].toLowerCase()) {
                l ++;
                r --;
            }else{
                return false;
            }
        }
        return true;
    }
}
