class Solution {
public:
    bool validPalindrome(string s) {
        //move from left and right pointer 
        // if unmatch check if its the first unmatch 
        // check if left+1 matches right or right-1 matches left i.e we are skipping left and right respectively , if none match the return false 
        // 
        int len = s.length();
        int start = 0;
        int end = len-1;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                if(start - 0 == len - end - 1) //if left and right size is equal i.e we didnt skip anything
                {
                    if(s[start+1]==s[end]){ // skip left elelemnt
                        start++;
                    }
                    else if(s[end-1]==s[start]){ //skip right elelemnt
                        end--;
                    }
                    else{
                        return false;
                    }
                }
                else
                    return false;
            }

        }
        return true;
    }
};