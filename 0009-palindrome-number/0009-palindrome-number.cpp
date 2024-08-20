class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long num = 0;
        int temp = x;
        while(temp)
        {
            num = num*10 + temp%10;
            temp/=10;
        }
        return x == num;
    }
};