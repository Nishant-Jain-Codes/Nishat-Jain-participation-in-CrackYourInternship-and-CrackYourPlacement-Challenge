class Solution {
public:
    // time : O(n+m)
    // space : O(1)
    //sort from the back i.e largest elements first and sort the array inplace
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int left = m-1;
        int right = n-1;
        int tempidx = m+n-1;
        while(left>=0 && right>=0){
            if(nums1[left]>=nums2[right]){
                nums1[tempidx] = nums1[left];
                left--;
                tempidx--;
            }
            else{
                nums1[tempidx] = nums2[right];
                right--;
                tempidx--;
            }
        }
        while(right>=0)
            {
                nums1[tempidx] = nums2[right];
                right--;
                tempidx--;
            }
    }
    // time : O(n+m)
    // space : O(n+m)
    void merge_less_optimised(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(n+m) ; 
        int li = 0;
        int ri = 0 ;
        int ti = 0;
        while(li<m && ri<n){
            if(nums1[li]<=nums2[ri]){
                temp[ti++]=nums1[li++];
            }
            else{
                temp[ti++]=nums2[ri++];
            }
        }
        while(li<m){
            temp[ti++]=nums1[li++];
        }
        while(ri<n){
            temp[ti++]=nums2[ri++];
        }
        for(int i = 0;i<m+n ; i++){
            nums1[i] = temp[i];
        }
    }
};