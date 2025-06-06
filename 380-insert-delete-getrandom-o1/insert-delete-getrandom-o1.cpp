class RandomizedSet {
public:
    /**
     * we need to make any operation in O(1)
     * vector good in insert and return (get)
     * map good in search and delete
     */
    unordered_map<int, int> s;
    vector<int> a;
    RandomizedSet() {}

    bool insert(int val) {
        auto it = s.find(val);

        if (it == s.end()) {
            s[val] = a.size();
            a.push_back(val);
            return true;
        } else
            return false;
    }

    bool remove(int val) {
        
        if (s.find(val) == s.end()) {
            return false;
        }

        int idx = s[val];    
        int last = a.back(); 
     
        a[idx] = last; 
        s[last] = idx; 

        a.pop_back(); 
        s.erase(val); 

        return true;
    }

    int getRandom() {
        size_t index = rand() % a.size();

        return a[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */