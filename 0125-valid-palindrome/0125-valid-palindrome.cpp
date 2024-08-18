class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length();
        while(l<r){
            if(isalpha(s[l])&&isalpha(s[r])){
                if(tolower(s[l])!=tolower(s[r]))
                    return false;
                l++;
                r--;
            }
            else if(!isalpha(s[l]))
                l++;
            else if(!isalpha(s[r]))
                r--;
        }
        return true;
    }
};