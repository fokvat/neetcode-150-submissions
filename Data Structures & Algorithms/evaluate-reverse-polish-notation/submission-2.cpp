class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s : tokens){
            if(s != "+" && s != "-" && s != "/" && s != "*"){
                st.push(stoi(s));
            }else{
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                // switch(x){
                //     case '+': st.push(t2 + t1); break;
                //     case '-': st.push(t2 - t1); break;
                //     case '/': st.push(t2 / t1); break;
                //     case '*': st.push(t2 * t1); break;
                // }
                if(s == "+"){
                    st.push(t2 + t1);
                }else if(s == "-"){
                    st.push(t2 - t1);
                }else if(s == "/"){
                    st.push(t2 / t1);
                }else if(s == "*"){
                    st.push(t2 * t1);
                }
            }
        }

        return st.top();
    }
};
