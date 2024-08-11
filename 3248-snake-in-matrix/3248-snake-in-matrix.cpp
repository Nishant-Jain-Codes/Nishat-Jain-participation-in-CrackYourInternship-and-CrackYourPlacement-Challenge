class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int l = 0;
        for(auto &c : commands){
            if(c == "RIGHT"){
                l++;
            }
            else if(c == "DOWN"){
                l+=n;
            }
            else if (c == "UP"){
                l-=n;
            }
            else if (c == "LEFT"){
                l--;
            }
        }
        return l;
    }
};