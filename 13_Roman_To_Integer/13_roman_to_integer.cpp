class Solution {
public:
    int romanToInt(string s) {
        int len=s.length(),ans=0;
        for(int i=0;i<len;i++){
            int value=func(s[i]);
            if (i < len-1 && value < func(s[i+1])){
                ans -= value;
            }
            else{
                ans+= value;
            }
        }
        return ans;
    }
private:
    int func(char c){
        switch (c){
                case 'I' : return 1;
                case 'V' : return 5;  
                case 'X' : return 10;  
                case 'L' : return 50;
                case 'C' : return 100;
                case 'D' : return 500;
                case 'M' : return 1000;
                default: return 0;
        }
    }
};