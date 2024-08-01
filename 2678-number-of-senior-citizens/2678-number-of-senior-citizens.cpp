class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto &x : details){
            // string age = x.substr(11,2);
            int first = x[11]-'0';
            int second = x[12]-'0';
            int ageN = first*10 + second;
            cout<<ageN<<" ";
            if(ageN>60)
                count++;
        }
        return count;
    }
};