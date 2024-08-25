class Solution {
public:
    int countPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i<nums.size()-1;i++){
            for(int j = i+1;j<nums.size();j++){
                int first = nums[i];
                int second = nums[j];
                count += isEqual(first,second) ? 1 : 0;
            }
        }
        return count;
    }
private: 
    bool isEqual(int first , int second){
        if(first == second)
            return true;
        int swap = 0;
        unordered_map<int,int> num1 = getArray(first);
        unordered_map<int,int> num2 = getArray(second);
        for(auto &[d,f] : num1){
            if(num2.find(d)==num2.end()||num2[d]!=f)
                return false;
        }
        while(first || second){
            int f = first%10;
            int s = second%10;
            if(f!=s)
                swap++;
            first/=10;
            second/=10;
        }
        return swap<=2;
    }
    unordered_map<int,int> getArray(int no){
        unordered_map<int,int> vec;
        int place = 0;
        while(place<7){
            int num = no%10;
            // vec[place] = num;
            vec[num]++;
            no/=10;
            place++;
        }
        // cout<<no<<" -> ";
        // for(auto &x : vec)
        //     cout<<x<<" ";
        // cout<<endl;
        return vec;
    }
    
};