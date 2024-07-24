class Solution {
public:
    //time : O(N)
    //space : O(1)
    string addBinary(string a, string b) {
        string answer = "";
        int s1 = a.length()-1;
        int s2 = b.length()-1;
        int carry = 0;
        int count=0;
        while(s1>=0 || s2>=0 || carry){
            // cout<<"loop ran"<<count++<<endl;
            int v1 = 0;
            int v2 = 0;
            if(s1>=0){
                // cout<<a[s1]<<" ";
                v1 = a[s1]-'0';
                s1--;
            }
            if(s2>=0){
                // cout<<a[s2]<<" ";
                v2 = b[s2]-'0';
                s2--;
            }
            // cout<<v1<<" "<<v2<<" "<<carry<<endl;
            int valAdd = v1+v2+carry;
            carry = valAdd/2;
            valAdd%=2;
            char charAdd = '0' + valAdd;
            answer.push_back(charAdd);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};