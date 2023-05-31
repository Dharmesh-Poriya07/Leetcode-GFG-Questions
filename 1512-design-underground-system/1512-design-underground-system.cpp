class UndergroundSystem {
public:
    map<int,pair<string,int>> checkin;
    map<pair<string,string>,pair<int,int>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin.insert({id,{stationName,t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        auto in = checkin[id];
        auto exist = avg.find({in.first,stationName});
        if(exist != avg.end()){
            exist->second.second ++;
            exist->second.first += (t-in.second);
            avg.insert({{in.first,stationName},{exist->second.first,exist->second.second}});
        }else{
            avg.insert({{in.first,stationName},{t-in.second,1}});
        }
        checkin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto p = avg[{startStation,endStation}];
        int total_time = p.first;
        int total_trips = p.second;
        return 1.0*total_time/total_trips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */