//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    //time : O(N)
    //space :O(1)
    char firstRep (string s)
    {
        //code here.
        int firstSeen = 0;
        int secondSeen = 0;
        for(auto &ch : s){
            int curIdx = ch-'a' ;
            int curBitMask = 1<<curIdx;
            if(firstSeen&curBitMask)
                secondSeen|= curBitMask;
            else 
                firstSeen|= curBitMask;
        }
        for(auto & ch: s){
            int curIdx = ch-'a' ;
            int curBitMask = 1<<curIdx;
            if(secondSeen&curBitMask)
                return ch;
        }
        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends