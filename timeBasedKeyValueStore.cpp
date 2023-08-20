class TimeMap {
public:
    TimeMap() {
        

    }
    
    void set(string key, string value, int timestamp) {
        
        myMap[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        
        //check if the key is present in the map
        if(myMap.find(key) == myMap.end())
            return "";

        int l = 0, r = myMap[key].size() - 1;

        while(l <= r)
        {
            int mid = (l + r)/2;

            if(myMap[key][mid].second < timestamp)
                l = mid + 1;
            else if (myMap[key][mid].second > timestamp)
                r = mid - 1;
            else
                return myMap[key][mid].first; //return the value
        }

        //if the mentioned timestamp doesn't exist, return the smallest closest value to it
        // the smallest value compared to the given timestamp is given by 'r'

        if(r >= 0)  //if r is valid
            return myMap[key][r].first;
        return ""; //as there exists no smaller value than the given timestamp 

    }

    private:
        unordered_map<string, vector<pair <string,int>>> myMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
