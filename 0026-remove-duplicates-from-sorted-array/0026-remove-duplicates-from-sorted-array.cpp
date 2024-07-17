class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if the array has 0 or 1 element, no duplicates to remove
        if(nums.size() <= 1) {
            return nums.size();
        }
        
        int slow = 0; // slow pointer to track unique elements
        int fast = 1; // fast pointer to iterate through the array
        
        while(fast < nums.size()) {
            // If current element is different from previous unique element
            if(nums[fast] != nums[slow]) {
                // Move slow pointer forward
                slow++;
                // Update the current slow pointer position with the unique element
                nums[slow] = nums[fast];
            }
            // Move fast pointer forward
            fast++;
        }
        
        // Return the length of the array up to the last unique element found
        return slow + 1;
    }
};


// class Solution {
// public:
// // two pointer approach 
// // time O(N)
// // space O(1);
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size()<=1 )
//             return nums.size();
            
//         int i =0;
//         int j = 0;
//         while(j<nums.size()-1){
//             while(j<nums.size()-1 && nums[j]==nums[j+1]){
//                 j++;
//             }
//             nums[i]=nums[j];
//             j++;
//             i++;
//         }
//         if(j== nums.size()-1 && nums[j]!=nums[j-1]){
//             nums[i] = nums[j];
//             i++;
//         }
//         return i;
//     }
// };
