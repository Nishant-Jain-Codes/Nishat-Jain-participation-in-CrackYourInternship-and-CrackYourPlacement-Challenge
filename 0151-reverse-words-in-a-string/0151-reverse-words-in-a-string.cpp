class Solution {
public:
    //optimised solution 
        //time O(N)
        //space O(1)
    string reverseWords(string s) {
        //reverse the whole string 
        int first = 0;
        int last = s.length()-1;
        for(int i = 0;i<=(s.length()-1)/2;i++){
            swap(s[first++],s[last--]);
        }
        //reverse the string's each word
        int startWord = 0;
        int i = 0;
        while(i<=s.length()){
            if(i==s.length()|| s[i]==' '){
                int endWord = i-1;
                int left = startWord;
                int right = endWord;
                while(left<right){
                    swap(s[left++],s[right--]);
                }
                startWord = endWord + 2;
            }
            i++;
        }
        //remove starting space
        int startSpace = 0;
        while(s[startSpace]==' ')
            startSpace++;
        s = s.substr(startSpace);
        //remove ending spaces
        int endSpace = s.length()-1;
        while(s[endSpace]==' ')
            endSpace--;
        s = s.substr(0,endSpace+1);
        //remove middle spaces 
        int nextNonSpace = 0;
        bool seenSpace = false;
        for(int i =0;i<s.length();i++){
            if(s[i]==' '){
                if(!seenSpace){
                    s[nextNonSpace] = s[i];
                    seenSpace = true;
                    nextNonSpace++;
                }
            }
            else{
                s[nextNonSpace] = s[i];
                nextNonSpace++;
                seenSpace = false;
            }
        }
        s = s.substr(0,nextNonSpace);
        return s;
    }
};