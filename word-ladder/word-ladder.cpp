class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> hashmap;
        unordered_map<string, bool> vis;
        sort(wordList.begin(),wordList.end());
        auto newendit = unique(wordList.begin(),wordList.end());
        wordList.resize(distance(wordList.begin(),newendit));
        
        // Creating Graph
        for(string &s1: wordList){
            vis[s1] = false;
            for(string &s2: wordList){
                if(singleLetterDiff(s1,s2))
                    hashmap[s1].push_back(s2);
            }
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        vis[beginWord] = true;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string currWord = p.first;
            int dist = p.second;
            if(currWord == endWord)
                return dist;
            
            for(string &nextWord: hashmap[currWord]){
                if(vis[nextWord]) continue;
                
                q.push({nextWord,dist+1});
                vis[nextWord] = true;
            }
        }
        
        return 0;
    }
    
    bool singleLetterDiff(string &s1,string &s2){
        int n=s1.length(), m=s2.length(), diff = 0;
        for(int i=0;i<n;i++)
            if(s1[i] != s2[i])
                diff++;
        return diff==1;
    }
};