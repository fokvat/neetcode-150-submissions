class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums: number[], k: number): number[] {
        const count = nums.reduce((acc, cur) => {
            acc[cur] = acc[cur] != undefined ?  acc[cur] + 1 : 1;
            return acc;
        }, {});

        const buc_sort = Object.entries(count).map(([key, val]) => [key, val]).sort((a:[string, number],b:[string, number]) => b[1] - a[1]);
        const ans: number[] = [];

        for(let i = 0; i < k ;i++){
            ans.push(Number(buc_sort[i][0]));
        }

        return ans;
    }
}
