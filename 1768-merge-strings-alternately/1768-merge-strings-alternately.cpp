class Solution {
public:
    //time : O(N)
    //space : O(N)
    string mergeAlternately(string word1, string word2) {
        string output="";
        int i = 0;
        int j = 0;
        bool turn1 = 1;
        while(i<word1.size()&&j<word2.size()){
            if(turn1)
            {
                output.push_back(word1[i]);
                i++;
            }
            else{
                output.push_back(word2[j]);
                j++;
            }
            turn1=!turn1;
        }
    output+=word1.substr(i);
    output+=word2.substr(j);
    return output;
    }
};