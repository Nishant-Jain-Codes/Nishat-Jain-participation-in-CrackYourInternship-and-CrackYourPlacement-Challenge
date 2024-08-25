class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        unordered_map<char,pair<int,int>> dir ={
            {'L',{0,-1}},
            {'R',{0,1}},
            {'U',{-1,0}},
            {'D',{1,0}}
        };
        for(auto &m : moves){
            x+=dir[m].first;
            y+=dir[m].second;
        }
        return x==0 && y==0;
    }
};