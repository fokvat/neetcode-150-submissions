

class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    
    groupAnagrams(strs: string[]): string[][] {
        const mp = new Map<string, string[]>();

        for(let str of strs){
            const arr = str.split("");
            arr.sort();

            const temp = arr.join();

            if(mp.has(temp)){
                mp.get(temp).push(str)
            }else{
                mp.set(temp, [str]);
            }
        }

        let ans: string[][] = [];

        mp.forEach((item)=>{
            ans.push([...item]);
        })

        return ans;
    }
}
