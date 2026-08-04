class MinStack {
    st:number[];
    min_st:number[];

    constructor() {
        this.st = [];
        this.min_st = [];
    }

    /**
     * @param {number} val
     * @return {void}
     */
    push(val: number): void {
        this.st.push(val);
        let curMin = this.min_st.at(-1);
        curMin != undefined && curMin < val ? this.min_st.push(curMin) : this.min_st.push(val);
    }

    /**
     * @return {void}
     */
    pop(): void {
        this.st.pop();
        this.min_st.pop();
    }

    /**
     * @return {number}
     */
    top(): number {
        return this.st.at(-1);
    }

    /**
     * @return {number}
     */
    getMin(): number {
        return this.min_st.at(-1);
    }
}
