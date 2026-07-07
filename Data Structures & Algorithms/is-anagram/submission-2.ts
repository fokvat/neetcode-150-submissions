class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s: string, t: string): boolean {
        if (s.length !== t.length) return false;
        let count : Map<string, number> = new Map();
        for(let x of s){
            if(count.has(x)) count.set(x, count.get(x) + 1);
            else count.set(x, 1);

        }

        for(let x of t){
            if(count.has(x) && count.get(x) > 0){
                count.set(x, count.get(x)  - 1);
            }else{
                return false;
            }
        }

        return true;

    }
}
