class Solution {
public:
    string largestPalindrome(int n, int k) {
        // k=7;
        if(k==1||k==9||k==3){ //1,3,9 okay
            string ans = "";
            for(int i = 0;i<n;i++)
                ans.push_back('9');
            return ans;
        }
        else if(k==2){//okay
            string ans = "";
            for(int i = 0;i<n-1;i++)
                ans.push_back('9');
            ans.push_back('8');
            ans[0] = '8';
            return ans;
        }
        else if(k==5){ // okay
            string ans = "";
            for(int i = 0;i<n-1;i++)
                ans.push_back('9');
            ans.push_back('5');
            ans[0] = '5';
            return ans;
        }
        else if(k==4){//last 2 multiple of 4
            string ans = "";
            if(n<=4){
            for(int i =0;i<n;i++)
                ans+='8';
                return ans;
            }
            else{
                for(int i =0;i<n;i++)
                {
                    if(i>=2 && i<n-2)
                        ans+='9';
                    else 
                        ans+='8';
                }
                return ans;
            }

        }
        else if(k==8){//last 3 mulitpkle of 8
            string ans = "";
                if(n<=6){
                for(int i =0;i<n;i++)
                    ans+='8';
                    return ans;
                }
                else{
                    for(int i =0;i<n;i++)
                    {
                        if(i>=3 && i<n-3)
                            ans+='9';
                        else 
                            ans+='8';
                    }
                    return ans;
                }

        }
        else if(k==6){//even and multiple of 3
            if(n==1)
                return "6";
            else if(n==2)
                return "66";    
            string ans = "";
            for(int i = 0;i<n;i++){
                if(i==0||i==n-1)
                    ans+='8';
                else
                    ans+='9';
            }
            if(n%2!=0){
                ans[n/2] = '8';
            }
            else{
                ans[n/2] = '7';
                ans[n/2 - 1] = '7';
            }
            return ans;
        }
        else if(k==7){//even and multiple of 7
    vector<string> pattern = {"7","77","5","77","7","","4","44","6","44","4",""};
    // for(int i=1;i<50;i++){
        // n = i;
    string curPattern = pattern[(n-1)%pattern.size()];
    int leftLen = n - curPattern.size();
    string ans = "";
    for(int i= 0;i<leftLen/2;i++)
        ans+='9';
    ans+=curPattern;
    // if(n<=)
    for(int i= 0;i<leftLen/2;i++)
        ans+='9';
        // string curPattern = pattern[i%pattern.size()];
        // cout<<n<<" => "<<curPattern<<" => " <<ans<<endl;
    // }
    return ans;
}

        return "";
    }
};