class Solution {
public:
    int reverse(int x) {
        cout<<INT_MAX<<" "<<INT_MIN<<endl;
        int ans = 0;
        int sign = x<0 ? -1:1;
        // x*=sign;
        while(x){
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
                return 0;
            ans = ans*10 +x%10;
            x/=10;
        }        
        return ans;
    }
};