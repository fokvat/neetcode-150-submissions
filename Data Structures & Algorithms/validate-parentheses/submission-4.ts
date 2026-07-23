class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s: string): boolean {
        const st: string[] = [];

        for(let i of s){
            if(i === ']' && st.at(-1) === '[')
                st.pop();
            else if(i === '}' && st.at(-1) === '{')
                st.pop();
            else if(i === ')' && st.at(-1) === '(')
                st.pop();
            else if(i === '{' || i === '[' || i === '(')
                st.push(i);
            else return false;
        }

        if(st.length === 0) return true;
        return false;
    }
}
