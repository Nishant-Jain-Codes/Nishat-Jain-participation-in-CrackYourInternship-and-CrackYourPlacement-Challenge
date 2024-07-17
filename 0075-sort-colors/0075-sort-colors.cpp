class Solution {
public:
    //time = O(2N)
    //space = O(1)
    void approach1 (vector<int>& nums ){

        //approach 1 , count ( 0 , 1 , 2 and then put the values on nums respectively)
        int hash[3] = {0};
        for(auto x : nums)
            hash[x]++;
        int idx = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<hash[i];j++){
                nums[idx++]=i;
            }
        }
    
    }
    //dutch national flag algorithm
    //time = O(N)
    //space = O(1)
    void approach2(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        // approach1(nums);
        approach2(nums);
    }
};