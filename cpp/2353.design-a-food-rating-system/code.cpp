#include "../Utils/io.cpp"

/* 
设计一个支持下述操作的食物评分系统：

修改 系统中列出的某种食物的评分。
返回系统中某一类烹饪方式下评分最高的食物。
实现 FoodRatings 类：

FoodRatings(String[] foods, String[] cuisines, int[] ratings) 初始化系统。食物由 foods、cuisines 和 ratings 描述，长度均为 n 。
foods[i] 是第 i 种食物的名字。
cuisines[i] 是第 i 种食物的烹饪方式。
ratings[i] 是第 i 种食物的最初评分。
void changeRating(String food, int newRating) 修改名字为 food 的食物的评分。
String highestRated(String cuisine) 返回指定烹饪方式 cuisine 下评分最高的食物的名字。如果存在并列，返回 字典序较小 的名字。
注意，字符串 x 的字典序比字符串 y 更小的前提是：x 在字典中出现的位置在 y 之前，也就是说，要么 x 是 y 的前缀，或者在满足 x[i] != y[i] 的第一个位置 i 处，x[i] 在字母表中出现的位置在 y[i] 之前。
*/


// 2022/07/30
#include <set>
#include <unordered_map>
struct PerRating {
    string food;
    int rating;
    PerRating(string& a, int b): food(a), rating(b) {}
    bool operator<(const PerRating& a) const{
        if (rating==a.rating)
            return food < a.food;
		return rating > a.rating;
	}
};
class FoodRatings {
    public:
        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            int n = foods.size();
            for (int i=0; i<n; i++)
                if (cuisineToRatingSet.find(cuisines[i])==cuisineToRatingSet.end())
                    cuisineToRatingSet[cuisines[i]] = new set<PerRating>;

            for (int i=0; i<n; i++) {
                cuisineToRatingSet[cuisines[i]]->emplace(PerRating(foods[i], ratings[i]));
                foodToRating[foods[i]] = ratings[i];
                foodToCuisine[foods[i]] = cuisines[i];
            }
        }
        
        void changeRating(string food, int newRating) {
            string cuisine = foodToCuisine[food];
            int rating = foodToRating[food];

            foodToRating[food] = newRating;
            cuisineToRatingSet[cuisine]->erase(cuisineToRatingSet[cuisine]->find(PerRating(food, rating)));
            cuisineToRatingSet[cuisine]->emplace(PerRating(food, newRating));
        }
        
        string highestRated(string cuisine) {
            PerRating highest = *(cuisineToRatingSet[cuisine]->begin());
            return highest.food;
        }

    private:
        unordered_map<string, int> foodToRating;
        unordered_map<string, string> foodToCuisine;
        unordered_map<string, set<PerRating>*> cuisineToRatingSet;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */



int main() {

    // inputs
    vector<string> foods = {"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisines = {"korean","japanese","japanese","greek","japanese","korean"};
    vector<int> ratings = {9,12,8,15,14,7};

    // invokes
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
    cout<<(obj->highestRated("korean"))<<endl;
    cout<<(obj->highestRated("japanese"))<<endl;
    obj->changeRating("sushi",16);
    cout<<(obj->highestRated("japanese"))<<endl;
    obj->changeRating("ramen",16);
    cout<<(obj->highestRated("japanese"))<<endl;

    return 0;
}



