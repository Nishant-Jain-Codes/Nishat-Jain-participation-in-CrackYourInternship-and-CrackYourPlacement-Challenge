class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>visited;
        unordered_set<string> allWords;
        for(auto & x : wordList)
            allWords.insert(x);
        queue<pair<string,int>> q; //<word,distance>
        q.push({beginWord,1});
        visited.insert(beginWord);
        //perform bfs
        while(!q.empty()){
            // pair<string,int> qfront = q.front();
            string curWord = q.front().first;
            int curDist = q.front().second;
            q.pop();
            cout<<curWord<<" "<<curDist<<endl;
            if(curWord==endWord)
                return curDist;
            //changing character at every place from a to z except the orignal value
            for(int i = 0;i<curWord.length();i++){
                char curChar = curWord[i];
                for(char replace = 'a' ; replace<='z';replace++){
                    if(replace==curChar)
                        continue;
                    curWord[i]=replace;
                    if(allWords.find(curWord)!=allWords.end() && visited.find(curWord)==visited.end())
                    {
                        visited.insert(curWord);
                        q.push({curWord,curDist+1});
                    }
                }
                curWord[i]=curChar;
            }
        }
        return 0;
    }
};