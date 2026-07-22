class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums: number[], k: number): number[] {
        // 1. Explicitly type the accumulator as a Record<number, number>
        const count = nums.reduce<Record<number, number>>((acc, cur) => {
            acc[cur] = acc[cur] !== undefined ? acc[cur] + 1 : 1;
            return acc;
        }, {});

        // 2. Object.entries automatically provides [string, number], no need to remap it
        const buc_sort = Object.entries(count).sort((a, b) => b[1] - a[1]);
        const ans: number[] = [];

        // 3. Prevent runtime errors if k is greater than unique elements
        const limit = Math.min(k, buc_sort.length);
        for (let i = 0; i < limit; i++) {
            ans.push(Number(buc_sort[i][0]));
        }

        return ans;
    }
}
