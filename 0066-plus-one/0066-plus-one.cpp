class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> answer(digits.size()+1);
        for(int i = digits.size()-1;i>=0;i--){
            int curNum = digits[i]  + carry;
            carry = curNum/10;
            curNum%=10;
            answer[i+1]=curNum;
        }
        answer[0] = carry;
        if(!carry)
            {
                vector<int> answer2(answer.begin()+1,answer.end());
                return answer2;
            }
        return answer;

    }
};