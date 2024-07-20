class Solution {
public:
    //time : O(N)
    //space : O(1)
    int recursion(int x , int y ,int curP){
        if(x>=1 && y>=4)
            return recursion(x-1,y-4,!curP);
        else
            return !curP;
    }
    string losingPlayer(int x, int y) {
        // int winner = 0; // 1-> alice;
        int winner =  recursion(x,y,0);
        return winner == 0 ? "Alice" : "Bob";
    }

};