

class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    
    groupAnagrams(strs: string[]): string[][] {
        const mp = new Map<string, string[]>();

        for(let str of strs){
            let arr: number[] = Array(26).fill(0);

            for(let i = 0; i < str.length; i++){
                arr[str[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
            }

            let hasVal = "";
            for(let x of arr){
                hasVal += "#" + x;
            }
            if(mp.has(hasVal)){
                mp.set(hasVal, [...mp.get(hasVal), str])
            }else{
                mp.set(hasVal, [str]);
            }
        }

        let ans: string[][] = [];

        mp.forEach((item)=>{
            ans.push([...item]);
        })

        return ans;
    }
}
