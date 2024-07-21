class Solution {
public:
    // time : O(N)
    // space : O(1)
    int maxOperations(string s) {
        if(s.length()==0)
            return 0;
        int cur1 = 0;
        bool continuous = true;
        int curIdx = 0;
        int ans = 0;
        while(curIdx<s.length()){
            if(curIdx==s.length()-1 )
                {   
                    if(!continuous || s[curIdx]=='0')
                        ans+=cur1;
                    return ans;    
                }
            if(s[curIdx]=='0')
                {
                    continuous=false;
                    curIdx++;
                }
            else if (s[curIdx]=='1' && continuous)
                {
                    cur1++;
                    curIdx++;
                }
            else 
                {
                    cout<<curIdx<<" "<<cur1<<" "<<ans<<endl;
                    ans+=cur1;
                    continuous=true;
                    cur1++;
                    curIdx++;
                }

        }
        return 0;
    }
};