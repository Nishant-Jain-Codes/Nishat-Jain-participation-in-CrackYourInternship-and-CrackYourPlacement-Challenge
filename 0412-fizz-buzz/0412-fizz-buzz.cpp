class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1;i<=n;i++){
            string curVal = "";
            if(i%3==0)
                curVal+="Fizz";
            if(i%5==0)
                curVal+="Buzz";
            if(curVal.length() == 0) 
                answer.push_back(to_string(i));
            else
                answer.push_back(curVal);


        }
        return answer;
    }
};