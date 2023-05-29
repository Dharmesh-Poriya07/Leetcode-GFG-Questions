class ParkingSystem {
public:
    vector<int> slots;
    ParkingSystem(int big, int medium, int small) {
        slots.push_back(small);
        slots.push_back(big);
        slots.push_back(medium);
    }
    
    bool addCar(int carType) {
        if(slots[carType%3]>0){
            slots[carType%3] --;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */