class Solution {
public:
    bool recursion(string & s , int start , int end){
        if(start>=end)
            return true;
        if(s[start]==s[end])
            return recursion(s,start+1,end-1);
        if(start - 0 != s.length() - end - 1)
            return false;
        bool ans = false;
        if(s[start+1] == s[end])
            ans |= recursion(s,start+2,end-1);
        if(ans) return true;
        if(s[start] == s[end-1])
            ans|= recursion(s,start+1,end-2);
        return ans;
    }
    //other approach 
    bool isPalindrome(string& s, int start , int end){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // return recursion(s,0,s.length()-1);
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return isPalindrome(s,start+1,end) || isPalindrome(s,start,end-1);
            }
            start++;
            end--;
        }
        return true;
    }
};