class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        
        int i, j, k;

        queue<pair<string, int>> bfs;
        bfs.push(make_pair(beginWord, 1));
        visited.insert(beginWord);
        
        while(!bfs.empty()){
            pair<string, int> p = bfs.front();
            bfs.pop();
            string current = p.first;
            int dist = p.second;

            if(current == endWord)
                return dist;
            
            for(i = 0; i < current.length(); i++){
                string next = current;
                for(j = 1; j < 26; j++){
                    k = (current[i] - 'a' + j) % 26;
                    next[i] = k + 'a';
                    
                    if(visited.find(next)==visited.end() && wordSet.find(next)!=wordSet.end()){
                        visited.insert(next);
                        bfs.push(make_pair(next, dist + 1));
                    }
                }
            }
        }
        
        return 0;
    }
};