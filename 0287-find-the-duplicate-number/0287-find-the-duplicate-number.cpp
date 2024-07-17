class Solution {
public:
    //method 1 brute force 
        //time O(N^2)
        //space O(1)
        // -> for every number i : 0->n-1 
        //   -> check if i exits in j : i -> n
    //method 2 better  sort the array
        //time O(nlogn)
        //space O(1)
        // 1. sort the array 
        // 2. for i : 0 -> n-1 
            //   if a[i] == a[i+1] : return a[i]
    //method 3 better use a hashmap
        //time O(N)
        //space O(N)
        // create a hashmap and count frequcny of each number and return the one with >1 frequency
    // method 4 better use the array as hash
        //time O(N)
        //space O(1)
        //modify the array , i.e mark their value as -1 
        int modificationSolution(vector<int>& nums){
            for(int i=0;i<nums.size();i++){
                int curVal = abs(nums[i])-1;
                if(nums[curVal]<0){
                    return curVal + 1;
                }
                else{
                    nums[curVal]*=-1;
                }
            }
            return -1;
        }
    int findDuplicate(vector<int>& nums) {
    return modificationSolution(nums);
    }
};