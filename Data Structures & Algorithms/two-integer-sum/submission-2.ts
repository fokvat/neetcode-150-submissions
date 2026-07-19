class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums: number[], target: number): number[] {
        let ans: number[];
        let mp = new Map<number, number>();

        for(let i = 0; i < nums.length; i++){
            if(mp.has(nums[i])){
                return [mp.get(nums[i]), i];
            }
            mp.set(target - nums[i], i);
        }
    }
}
