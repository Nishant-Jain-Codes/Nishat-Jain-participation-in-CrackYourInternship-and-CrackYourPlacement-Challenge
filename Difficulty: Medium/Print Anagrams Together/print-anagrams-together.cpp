//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++;


class Solution{
  public:
    // time : O(N*M) , M : size of largest string , N : total Strings
    // space : O(N)
     string countSort(string & str){
        int hash[26] = {0};
        for(auto &x : str)
            hash[x-'a']++;
        string output ="";
        for(int i=0;i<26;i++){
            for(int j = 0;j<hash[i];j++){
                output+= ('a'+i);
            }
        }
        return output;
    }
    vector<vector<string>> Anagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto str : strs){
            string curStr = countSort(str);
            
            map[curStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto x : map){
            ans.push_back(x.second);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends