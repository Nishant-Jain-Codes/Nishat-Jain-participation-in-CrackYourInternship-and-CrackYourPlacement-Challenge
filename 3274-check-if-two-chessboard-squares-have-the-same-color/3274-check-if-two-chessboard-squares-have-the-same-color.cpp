class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        return color(c1[0],c1[1]) == color(c2[0],c2[1]);
    }
private:   
    int color(char c1 , char c2){
        int first = c1-'a';
        int second = c2-'0';
        unordered_set<int> s ={1,3,5,7};
        return first%2 == second%2;
    }
};