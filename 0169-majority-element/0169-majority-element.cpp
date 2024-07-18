class Solution {
public:
    //method 1 brute force ( hash the frequency of the numbers)
        //time O(N)
        //space O(N)
    //method 2 brute force ( sort the array and then iterate and count frequency of each number )
        //time O(NLogN) 
        //space O(1)
    //method 3 (Boyer - Moore Voting Algorithm) 
        //candidate and count tracker , since freq(candidate) >= n/2 , its count will always overwhelm the others 
        //time O(N)
        //space O(1)
        int optimized(vector<int>& nums){
            int candidate = nums[0];
            int count = 1;
            for(int i =1;i<nums.size();i++){
                if(count==0){
                    count=1;
                    candidate = nums[i];
                }
                else{
                    if(candidate == nums[i])
                        count++;
                    else
                        count--;
                }
                
            }
            // if no majority found
            if(count==0)
                return -1;
            // confirming if the candidate is majority
            count = 0;
            for(int i = 0; i<nums.size();i++){
                if(nums[i]==candidate)
                    count++;
            }
            if(count>nums.size()/2)
                return candidate;
            else
                return -1;
        }
    int majorityElement(vector<int>& nums) {
        return optimized(nums);
    }
};