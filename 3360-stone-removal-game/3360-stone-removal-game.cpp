class Solution {
public:
    bool canAliceWin(int n) {
        bool alice= true;
        int x=10;
        while(true){
            if(alice){
                n-=x;
                if(n<0) return false;
            }
            else{
                n-=x;
                if(n<0) return true;
            }
            alice=!alice;
            x--;
        }
        
        return true;
    }
};