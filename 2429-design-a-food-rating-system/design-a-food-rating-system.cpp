class FoodRatings {
public:
    struct Cmp {
        bool operator()(const auto& a, const auto& b) const {
            if(a.first != b.first) {
                return a < b;
            }
            return a.second > b.second;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp>> c2f;
    unordered_map<string, pair<string, int>> f2c;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i) {
            f2c[foods[i]] = {cuisines[i], ratings[i]};
            c2f[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        f2c[food].second = newRating;
        c2f[f2c[food].first].emplace(newRating, food);
    }
    
    string highestRated(string cuisine) {
        while(c2f[cuisine].top().first != f2c[c2f[cuisine].top().second].second) {
            c2f[cuisine].pop();
        }
        return c2f[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */