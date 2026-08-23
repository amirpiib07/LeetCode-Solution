class Solution {
    
public:
    bool isPalindromic(string s) {
        string bin;
        for(char c: s){
            for(int i= 7; i>=0; i--){
                bin +=((c>>i)&1)?"1":"0";
            }
        }
        int l=0,r=bin.size()-1;
        while(l<r){
            if(bin[l]!=bin[r]) return false;
            l++;r--;
        }
        return true;
    }
};