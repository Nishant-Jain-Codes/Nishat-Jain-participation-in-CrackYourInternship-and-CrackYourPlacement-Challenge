//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> map; //<prefixSum, index> 
        int maxLen = 0;
        int curSum = 0;
        map[0] = -1;
        for(int i=0;i<N;i++){
            curSum+=A[i];
            int target = curSum-K;
            if(map.find(target)!=map.end()){
                int len = i - map[target];
                maxLen = max(maxLen,len);
            }
            if(map.find(curSum)==map.end())
                map[curSum]=i;
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends