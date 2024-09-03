class Solution {
public:
    int getLucky(string s, int k) {
        string converted = convert(s);
        // cout<<converted<<"\n";
        int curNum = 0;
        for(auto &x : converted){
            curNum+= (x-'0');
        }
        // cout<<curNum<<endl;
        for(int i = 1;i<k;i++){
            int temp = 0;
            while(curNum>0){
                temp += curNum%10;
                curNum/=10;
                // cout<<temp<<" ";
            }
            // cout<<temp<<" "<<curNum<<endl;
            curNum = temp;
        }
        return curNum;
    }
private: 
    string convert(string &s){
        string temp = "";
        for(auto &x : s){
            temp += to_string((x-'a') + 1);
        }
        return temp;
    }
};