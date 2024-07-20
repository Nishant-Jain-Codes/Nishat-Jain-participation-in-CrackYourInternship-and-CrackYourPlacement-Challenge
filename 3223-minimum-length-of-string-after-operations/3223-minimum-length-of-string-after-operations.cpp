#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // time O(N)
    // space O(N)
    int minimumLength(string s) {
        unordered_map<char,int> map;
        for(int i = 0;i<s.length();i++){
            map[s[i]]++;
        }
        int ans = 0;
        for(auto pairs : map){
            if(pairs.second%2==0)   
                ans+=2;
            else 
                ans+=1;
        }
        return ans;
    }
};