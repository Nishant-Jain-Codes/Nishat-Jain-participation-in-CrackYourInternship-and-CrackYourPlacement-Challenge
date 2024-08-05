class Solution {
public:
    // time : O(N)
    // space : O(N)
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> map;
        for(auto &x : arr)
            map[x]++;
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(map[arr[i]]==1)
                {
                    if(k==1)
                        return arr[i];
                    else 
                        k--;
                }
        }
        return "";
    }
};