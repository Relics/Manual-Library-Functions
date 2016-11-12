class Node {
public:
    int key;
    int val;
    int frequency;
    int timeStamp;
    
    Node() {}
    Node(int key, int val, int frequency, int timeStamp) {
        this->key = key;
        this->val = val;
        this->frequency = frequency;
        this->timeStamp = timeStamp;
    }
    
    bool operator< (const Node& n2) const
    {
        if (this->frequency != n2.frequency)
            return this->frequency < n2.frequency;
        else
            return this->timeStamp < n2.timeStamp;
    }
    
    int getKey() {
        return this->key;
    }
    
    int getVal() {
        return this->val;
    }
    
    void setFrequency (int frequency) {
        this->frequency = frequency;
    }
    
    void setTimeStamp (int timeStamp) {
        this->timeStamp = timeStamp;
    }
    
    void setVal (int value) {
        this->val = value;
    }
};


class LFUCache {
private:
    int maxCapcity = 0;
    int timeStamp = 0;
    set<Node> s;
public:
    LFUCache(int capacity) {
        this->maxCapcity = capacity;
    }
    void get(int key) {
        ++ timeStamp;
        for (auto i=s.begin(); i != s.end(); ++i) {
            if (i->key == key) {
                int t = i->val;
                Node temp(key, i->val, i->frequency + 1, timeStamp);
                s.erase(i);
                s.insert(temp);
                cout << t << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
    void set(int key, int value) {
        ++ timeStamp;
        
        for (auto i=s.begin(); i != s.end(); ++i) {
            if (i->key == key) {
                Node temp = *i;
                temp.setVal(value);
                temp.setFrequency(i->frequency + 1);
                temp.setTimeStamp(timeStamp);
                return;
            }
        }
        
        int ssize = (int)s.size();
        if (ssize < maxCapcity) {
            Node temp(key, value, 1, timeStamp);
            s.insert(temp);
        } else {
            s.erase(s.begin());
            Node temp(key, value, 1, timeStamp);
            s.insert(temp);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */