class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.length()-1;
        while(r>=0 && s[r]==' ')
            r--;
        int wordEnd = r;
        while(r>=0 &&s[r]!=' ' )
            r--;
        // if(r<0)
        //     r=0;
        return wordEnd-r;
    }
};