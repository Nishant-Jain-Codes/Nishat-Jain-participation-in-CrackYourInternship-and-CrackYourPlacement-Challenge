#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;
        for(auto x : strs){
            // minLen = min(minLen , x.length());
            if(minLen>x.length())
                minLen = x.length();
        }
        cout<<minLen<<endl;
        int i =0;
        for(;i<minLen;i++){
            char curChar = strs[0][i];
            bool breakRan = false;
            for(auto x : strs){
                if(x[i]!=curChar)
                    {
                        cout<<"break ran " <<endl;
                        breakRan = true;
                        break;
                    }
            }
            if(breakRan)
                break;
        }
        return strs[0].substr(0,i);
    }

};