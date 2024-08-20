class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0)
            return;
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        // print(nums);
        reverse(nums.begin(),nums.begin()+k);
        // print(nums);
        reverse(nums.begin()+k,nums.end());
        // print(nums);
    }
private: 
    void print(vector<int>& v){
    
        for(auto &x: v)
            cout<<x<<" ";
        cout<<endl;
    }
};