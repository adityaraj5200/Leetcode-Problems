class FoodRatings {
    using pis = pair<int, string>;

    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;
    unordered_map<string, set<pis>> mp;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];

        mp[cuisine].erase({-oldRating, food});
        mp[cuisine].insert({-newRating, food});
        foodRating[food] = newRating;
    }

    string highestRated(string cuisine) { return mp[cuisine].begin()->second; }
};