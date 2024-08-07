class Solution {
    unordered_map<int , string> zeroToNine,tenToNineteen,tens;
public:
    Solution(){
        this->zeroToNine = {
            {0,""},
            {1,"One"},
            {2,"Two"},
            {3,"Three"},
            {4,"Four"},
            {5,"Five"},
            {6,"Six"},
            {7,"Seven"},
            {8,"Eight"},
            {9,"Nine"}
        };
        this->tenToNineteen= {
            {10,"Ten"},
            {11,"Eleven"},
            {12,"Twelve"},
            {13,"Thirteen"},
            {14,"Fourteen"},
            {15,"Fifteen"},
            {16,"Sixteen"},
            {17,"Seventeen"},
            {18,"Eighteen"},
            {19,"Nineteen"},
        };
        this->tens = {
            {2,"Twenty"},
            {3,"Thirty"},
            {4,"Forty"},
            {5,"Fifty"},
            {6,"Sixty"},
            {7,"Seventy"},
            {8,"Eighty"},
            {9,"Ninety"},
        };
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        vector<string> suffixes = {""," Thousand"," Million"," Billion"};
        string answer = "";
        int temp = num;
        int i = 0;
        while(temp){
            int last3 = temp%1000;
            temp/=1000;
            if(last3){
                string space = "";
                string recAns = helper(last3);
                // cout<<recAns<<" ";
                recAns = recAns  + suffixes[i];
                // cout<<suffixes[i];
                if(recAns.length() && answer.length())
                    space =" ";
                cout<<recAns<<" | "<<answer<<endl;
                answer = recAns  + space + answer;
            }
            i++;

        }
        // return answer.substr(1);
        int frontSpace = 0;
        while(answer[frontSpace] == ' ')
            frontSpace++;
        return answer.substr(frontSpace);
    }
private : 
    string helper(int num){
        // cout<<num;
        string answer = "";
        int last2 = num%100;
        int hundredVal = num/100;
        if(hundredVal)
            answer+= zeroToNine[hundredVal] + " Hundred";
        // cout<<" "<<last2<<" ";
        if(last2 && hundredVal)
            answer+= " ";
        if(last2 <=9)
            answer+= zeroToNine[last2];
        else if(last2<20){
            answer+= tenToNineteen[last2];
        }
        else{
            int ten = last2/10;
            int once = last2%10;
            // cout<<ten<<" "<<once<<" ";
            answer+= tens[ten];
            if(once)
                answer+= " "+ zeroToNine[once];
        }
        // cout<<answer<<endl;
        return answer;
    }
};