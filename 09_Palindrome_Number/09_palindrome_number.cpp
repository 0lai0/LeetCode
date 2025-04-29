class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;          
        if (x>=0 && x<10) return true; 

        int a[100000]={0};
        int i=0,temp=x;

        while(temp!=0){
            a[i]=temp%10;
            temp=temp/10;
            i++;
        }
        if (i == 2) {
            return a[0] == a[1];
        }
        int k=0, j=i-1;
        while(j > k){
            if(a[k]!=a[j]){
                return false;
            }
            j--;
            k++;
        }
        return true; 
    }
};
