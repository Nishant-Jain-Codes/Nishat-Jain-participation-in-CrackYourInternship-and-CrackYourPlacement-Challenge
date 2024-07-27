class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1);
        answer[0] = 0;
        for(int i=1;i<=n;i++){
            
                if((i%2)!=0)
                    answer[i] = answer[i/2]+1;
                else{
                    int k = i;
                    while(k%2==0){
                        k/=2;
                    }
                    cout<<i<<" "<<k<<endl;
                    answer[i] = answer[k];
                }
            
        }
        return answer;
    }
};