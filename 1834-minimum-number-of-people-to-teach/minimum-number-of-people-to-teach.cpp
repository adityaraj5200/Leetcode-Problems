class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {


        vector<vector<int>> edges; // only edges between people having no common language

        for(vector<int>& language: languages){
            sort(language.begin(), language.end());
        }

        // We don't care about those friendship which already have common language, they can talk.
        // We can about edges, the vertices of which doesn't have any common language
        // Keep only those edges.
        set<int> uniqueVertices;
        for(vector<int>& friendship: friendships){
            int u = friendship[0]-1;
            int v = friendship[1]-1;
            if(!checkCommonLanguage(languages[u],languages[v])){
                edges.push_back({u,v});
                uniqueVertices.insert(u);
                uniqueVertices.insert(v);
            }
        }

        vector<int> knownBy(n,0);
        int winnerLang = -1, maxKnownBy=0;
        for(int vertex: uniqueVertices){
            for(int lang: languages[vertex]){
                lang--;
                knownBy[lang]++;
                if(knownBy[lang]>maxKnownBy){
                    maxKnownBy = knownBy[lang];
                    winnerLang = lang;
                }
            }
        }

        int teachCount = uniqueVertices.size() - maxKnownBy;
        return teachCount;
    }
private:
    bool checkCommonLanguage(vector<int>& l1, vector<int>& l2){
        if(l1.size() > l2.size()){
            return checkCommonLanguage(l2,l1);
        }

        for(int& lang: l1){
            auto it = lower_bound(l2.begin(),l2.end(), lang);
            if(it != l2.end() && *it==lang){
                return true;
            }
        }

        return false;
    }
};