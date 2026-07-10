class Solution {
public:
    bool isValid(string s) {
        stack<char> cont;

        for(char a : s){
            if(a == '(' || a == '[' || a == '{'){
                cont.push(a);
            }else{
                if(cont.empty()) return false;
                char top = cont.top();
                switch(a){
                    case ')':  if(top != '(') return false;
                                cont.pop();
                                break;
                    case ']':  if(top != '[') return false;
                                cont.pop();
                                break;
                    case '}':  if(top != '{') return false;
                                cont.pop();
                                break;
                }
            }
        }
        if(cont.empty()) return true;

        return false;
    }
};
