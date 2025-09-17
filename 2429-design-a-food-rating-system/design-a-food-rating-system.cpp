// TC: O(n log n), SC: O(n), where n = number of foods
class FoodRatings {
private:
    // For each cuisine, maintain a set of (−rating, foodName)
    // Negative rating so that highest rating foods come first (since set is ordered ascending)
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;
    // Map each food to its current rating
    unordered_map<string, int> foodToRating;
    // Map each food to its cuisine
    unordered_map<string, string> foodToCuisine;

public:
    // Constructor
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            const string &f = foods[i];
            const string &c = cuisines[i];
            int& r = ratings[i];

            foodToRating[f] = r;
            foodToCuisine[f] = c;
            cuisineToFoods[c].insert({ -r, f });
        }
    }

    // Change the rating of a food
    // TC: O(log m), where m = number of foods in that food's cuisine
    void changeRating(string food, int newRating) {
        string c = foodToCuisine[food];
        int oldRating = foodToRating[food];
        // Remove old entry
        cuisineToFoods[c].erase({ -oldRating, food });
        // Insert new rating
        cuisineToFoods[c].insert({ -newRating, food });
        // Update in map
        foodToRating[food] = newRating;
    }

    // Return the highest rated food for a cuisine
    // If tie in rating, lexicographically smaller food name is chosen because set orders by pair
    // TC: O(1) for lookup of begin()
    string highestRated(string cuisine) {
        auto &st = cuisineToFoods[cuisine];
        // The first element in the set is what we want
        return st.begin()->second;
    }
};