//{ Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
//User function Template for C++

//Time : O(N)
//Space : O(1)
void radixSort(int arr[], int n) 
{ 
   // code here
   vector<int> dp(1001);
   for(int i = 0;i<n;i++){
       dp[arr[i]]++;
   }
   int k =0;
   for(int i = 0;i<dp.size();i++){
       for(int j=0;j<dp[i];j++ ){
           arr[k++]=i;
       }
   }
} 

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0; 
} 
// } Driver Code Ends