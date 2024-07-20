class Solution {
public:
    int strStr(string haystack, string needle) {
        //O(N) , single pass
        
        for(int i = 0;i<haystack.length();i++){
            bool unMatch = false;
            int j =0;
            while(j<needle.length()) {
                if(i>=haystack.length()||needle[j]!=haystack[i]){
                    unMatch = true;
                    break;
                }
                i++;
                j++;
            }
            if(unMatch == false)
                return i-needle.length();
            else
                i = i-j;
        }
        return -1;
    } 
};