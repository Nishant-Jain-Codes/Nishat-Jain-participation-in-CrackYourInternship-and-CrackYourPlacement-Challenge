class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long useInOneItration = 0;
        for(auto & x : chalk)
            useInOneItration += x;
        if(k>=useInOneItration)
            k%=useInOneItration;
        int i = 0;
        while(true){
            if(k< chalk[i])
                return i;
            k-=chalk[i];
            i++;
            i%=chalk.size();
        }
    }
};