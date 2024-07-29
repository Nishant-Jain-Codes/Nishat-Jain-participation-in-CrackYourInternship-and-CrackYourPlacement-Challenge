class Solution {
public:
    //brute force 
    // time O(N^2)
    // space O(1)
    //gettting tle
    int bruteForce(vector<int>& nums, int k){
        int ans = 0;
        for(int i = 0 ; i < nums.size();i++){
            int curSum = 0;
            for(int j = i;j<nums.size();j++){
                curSum+=nums[j];
                if(curSum%k==0)
                    {
                // cout<<"cs "<<curSum<<endl;
                        // cout<<i<<" "<<j<<endl;    
                        ans++;
                        
                    }
            }     
        }
        return ans;
    }
    // time : O(N)
    // space : O(N)
    int optimised(vector<int>& nums,int k){
        unordered_map<int,int> map;
        int curSum = 0;
        int curCount = 0;
        map[0]=1;
        for(int i = 0;i<nums.size();i++){
            curSum+=nums[i];
            // remove subarray with the same remainder i.e curSum%k , so that after removing we get 0 remainder , thus the resultant subarray will be a factor of k 
            //also did extra + k ) %k to make sure every search query is in range [0,k)
            int mod =( (curSum)%k + k )% k; 
            cout<<mod<<" ";
            curCount+=map[mod];
            map[mod]++;
        }
        cout<<endl;
        for(auto [f,s] : map){

            cout<<f<<" "<<s<<endl;
        }
        return curCount;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        // return bruteForce(nums,k);
        return optimised(nums,k);
    }
};