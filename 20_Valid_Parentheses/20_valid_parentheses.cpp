class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(char c: s){
            if(c=='(' || c=='{' || c=='['){
                str.push(c);            //push left bracket into stack
            }
            else{
                if (str.empty()) return false;
                char top = str.top();           //check top of bracket
                if( (c==')' && top != '(') ||   
                    (c=='}' && top != '{') ||                
                    (c==']' && top != '[') ){
                        return false;
                }
                str.pop();          //if top of bracket pair with right bracket then pop
            }
        }
        return str.empty();
    }
};


/*
class Solution {
public:
    int func(char c){
        switch(c){
            case '(': return 1;
            case ')': return -1;
            case '{': return 2;
            case '}': return -2;
            case '[': return 3;
            case ']': return -3;
            default : return 0;
        }

    }
    bool isValid(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int c=func(s[i]);
            sum += c;
            if (sum<0) return false;
        }    
        if (sum==0){
            return true;
        }
        else{
            return false;
        }
    }
};
*/
