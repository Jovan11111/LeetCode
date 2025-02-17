#include <vector>
#include <random>
class RandomizedSet {
public:
    RandomizedSet() {
        set = std::vector<int>();
        n = 0;
    }

    bool insert(int val) {
        for(int i = 0 ; i < n; i++) if(set[i] == val) return false;
        set.push_back(val);
        n++;
        return true;
    }

    bool remove(int val) {
        for(int i = 0; i <n; i++) if(set[i] == val ){
                n--;
                set.erase(set.begin() +i );
                return true;
            }
        return false;
    }

    int getRandom() {
        if(n == 0) return 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, n - 1);
        int rand = dist(gen);
        return set[rand];
    }
private:
    std::vector<int> set;
    int n;
};