class FoodRatings {
private:
    struct Compare {
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Compare>> cuisineToHeap;

    map<string,int> foodToRating;
    map<string,string> foodToCuisine;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int n = foods.size();
        for(int i=0;i<n;i++){
            cuisineToHeap[cuisines[i]].push({ratings[i],foods[i]});
            foodToRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        foodToRating[food] = newRating;
        string cuisine = foodToCuisine[food];
        cuisineToHeap[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        string highestRatedFood;
        while(true){
            auto [rating, food] = cuisineToHeap[cuisine].top();
            
            if(rating==foodToRating[food]){
                highestRatedFood = food;
                break;
            }
            else{
                cuisineToHeap[cuisine].pop();
            }
        }

        return highestRatedFood;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */