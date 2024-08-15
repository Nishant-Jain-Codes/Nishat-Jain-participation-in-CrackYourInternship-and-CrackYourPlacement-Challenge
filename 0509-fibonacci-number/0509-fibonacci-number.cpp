class Solution {
public:
    //time : O(N)
    //space : O(1)
    int fib(int n) {
        int a = 0;
        int b = 1;
        int c;
        if(n<2){
            if(n==0)
                return a;
            if(n==1)
                return b;
        }
        while(n>=2){
            c = a + b;
            a = b;
            b = c;
            n--;
        }
        return c;
    }
};