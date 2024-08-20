class Solution {
public:
    int lengthLongestPath(string input) {
        for(auto &x  :input)
            {
                cout<<x;
            }
        cout<<"\n=============================\n";
        stack<pair<string,int>> s;//<name,level>
        int curStackLen = 0;
        int ans = 0;
        int i = 0;
        // int si = 0;
        // int ei = 0;
        while(i<input.length()){
            int curLevel = 0;
            while(input[i]=='\t')
            {
                curLevel++;
                i++;
            }
            int si=i;
            int ei=i;
            while(ei!=input.length() && input[ei]!='\n' ){
                ei++;
                i++;
            }
            if(ei!=input.length() && input[ei]=='\n')
                ei--;
            string curName = input.substr(si,ei-si+1);
            while(!s.empty()&&s.top().second>=curLevel)
                {
                    curStackLen-=s.top().first.length();
                    cout<<"popping -> "<<s.top().first<<" "<<s.top().second<<" "<<curStackLen<<endl;
                    s.pop();
                }
            s.push({curName,curLevel});
            curStackLen +=curName.length();
            cout<<"pushing -> "<<s.top().first<<" "<<s.top().second<<" "<<curStackLen<<endl;
            size_t found= curName.find(".");
            // size_t found2= curName.find(".");
            if (found != string::npos)
                {
                    ans = max(ans,curStackLen+curLevel);
                    cout<<"file found -> "<<curName<<endl;
                }
            i++;
        }
        return ans;
    }
};