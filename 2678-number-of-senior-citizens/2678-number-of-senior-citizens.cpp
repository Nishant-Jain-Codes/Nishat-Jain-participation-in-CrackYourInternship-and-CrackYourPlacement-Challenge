class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto x : details){
            string age = x.substr(11,2);
            cout<<age<<" ";
            int ageN = stoi(age);
            if(ageN>60)
                count++;
        }
        return count;
    }
};