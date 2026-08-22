class Solution {
    bool f(int n){
        int real = n;
        int sum = 0, product = 1;
        while(n>0){
            sum += (n%10);
            product *= (n%10);
            n/=10;
        }
        
        return real % (sum + product) == 0; 
    }
public:
    bool checkDivisibility(int n) {
        return f(n);
    }
};