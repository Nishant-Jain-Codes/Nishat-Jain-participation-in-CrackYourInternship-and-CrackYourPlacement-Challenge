class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k<=1)
            return nums;
        vector<int> ans; 
        for(int i = 1;i<k;i++){
            if(nums[i]!=nums[i-1]+1){
                ans.push_back(-1);
                break;
            }
        }
        if(ans.size()==0)
            ans.push_back(nums[k-1]);
        for(int i = 1 ; i<nums.size()-k+1;i++){
            int prevStart = i-1;
            bool isPrevSorted = ans[i-1] !=-1;
            int prevEndEle = nums[prevStart+k-1];
            bool isConsSort = prevEndEle + 1 == nums[i+k-1];
            if(!isConsSort)
                {
                    // cout<<"NotS\n";
                    ans.push_back(-1);
                }
            else{
                if(isPrevSorted)
                    {
                        // cout<<"prevT"<<endl;
                        ans.push_back(nums[i+k-1]);
                    }
                else{
                    int isValid = true;
                    for(int j = 1;j<k;j++){
                        if(nums[i+j]!=nums[i+j-1]+1){
                            // cout<<"notV\n";
                            isValid = false;
                            ans.push_back(-1);
                            break;
                        }
                    }
                    if(isValid)
                     {
                        // cout<<"yesV\n";
                           ans.push_back(nums[i+k-1]);}
                }
            }
            
        }
        return ans;
    }
};