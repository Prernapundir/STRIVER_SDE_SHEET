
/*
Approach :

----------------

1. Do the BFS : we need to find the amsllest sequence , so that's y we are using BFS here, becoz it will traverse level wise and when we will find target return.

Advance Version : Word Ladder 2 -> Refer { DFS Folder }

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return 0;
        
        int ans=0;
        set<string> st;
        
        for(auto word:wordList){
            st.insert(word);
        }
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            ans++;
            int size=q.size();
            
            while(size--){
                string front=q.front();
                q.pop();
                
                string temp=front;
                
                for(int i=0;i<front.length();i++){
                    temp=front;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        
                        if(temp==front) continue;
                        else if(temp==endWord) return ans+1;
                        else {
                            if(st.find(temp)!=st.end()){
                                q.push(temp);
                                st.erase(temp);
                            }
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
