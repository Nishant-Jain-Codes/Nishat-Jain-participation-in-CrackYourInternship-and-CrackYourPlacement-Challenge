class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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