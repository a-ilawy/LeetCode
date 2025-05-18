class RandomizedSet {
public:
    set<int> s = {};
    RandomizedSet() {}

    bool insert(int val) {
        auto it = s.find(val);

        if (it == s.end()) {
            s.insert(val);
            return true;
        } else
            return false;
    }

    bool remove(int val) {

        auto it = s.find(val);

        if (it != s.end()) {
            s.erase(val);
            return true;
        } else
            return false;
    }

    int getRandom() {
        size_t index = rand() % s.size();

     
        auto it = s.begin();

       
        advance(it, index);

        return *it; 
    }
    };

    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */