class FoodRatings {
private:
    unordered_map<string, pair<int, string>> mp0;
    unordered_map<string, set<pair<int, string>>> mp1;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++) {
            mp0[foods[i]] = {-ratings[i], cuisines[i]};
            mp1[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    void changeRating(string food, int newRating) {
        int oldRating = mp0[food].first;
        string cuisine = mp0[food].second;
        mp0[food].first = -newRating;
        mp1[cuisine].erase({oldRating, food});
        mp1[cuisine].insert({-newRating, food});
    }
    string highestRated(string cuisine) {
        return (*mp1[cuisine].begin()).second;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */