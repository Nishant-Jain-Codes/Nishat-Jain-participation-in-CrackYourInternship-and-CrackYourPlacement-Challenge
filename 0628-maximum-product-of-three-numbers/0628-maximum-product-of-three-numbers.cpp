class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // int m1 =0,m2=0,m3=0;
        // int mx1 =INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     if(m1 == -1 || nums[i]>mx1)
        //         {
        //             m2 = m1;
        //             mx2 = mx1;
        //             m1=i;
        //             mx1 = nums[i];

        //         }
        //     if((m2==-1 || nums[i] > mx2) && i != m1 )
        //         {   
        //             m3 = m2;
        //             mx3 = mx2;
        //             mx2=nums[i];
        //             m2 = i;}
        //     if((m3 == -1 || nums[i]>mx3) && (i!=m1 && i!=m2))
        //         {
        //             mx3 = nums[i];
        //             m3 = i;}
        // }
        // cout<<m1<<" "<<m2<<" "<<m3<<endl; 
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[2],nums[0]*nums[nums.size()-1]*nums[nums.size()-2]);
    }
};