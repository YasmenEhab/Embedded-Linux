class ParkingSystem {
private:
int b;
int m;
int s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
        
    }
    
    bool addCar(int carType) {
        bool flag = false;
        if(carType == 1)
        {
            if(b>0)
            {
                flag = true;
                b--;
            }
            

        }
        else if (carType == 2)
        {
            if(m>0)
            {
                flag = true;
                m--;
            }
        }
        else if(carType == 3)
        {
            if(s>0)
            {
                flag = true;
                s--;
            }

        }
        else
        {
            std::cout<<"wrong carType "<<std::endl;
        }
        return flag ;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
