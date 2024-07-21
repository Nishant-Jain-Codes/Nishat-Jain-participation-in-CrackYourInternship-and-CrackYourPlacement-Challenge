class Solution {
public:
    // time : O(N)
    // space : O(1)
    bool doesAliceWin(string s) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        int count = 0;
        for(auto &x : s){
            if(vowel.find(x)!=vowel.end())
                count++;
        }
        if(count == 0)
            return false;
        else
            return true;
    }
//     since alice can remove odd number of vowels 
// therefore 

// 2cases vowel = odd , even 
// if odd ( alice remove all of them and wins ) 
// if even ( alice remove odd , ( now even - odd ) = odd ,but since bob can only remove even , he will lose ) 

// so only case when alice wins is when vowels are 0
};