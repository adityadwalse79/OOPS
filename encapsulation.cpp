#include <iostream>
#include <string>
using namespace std;

class sports_car {
    private :
        string brand;
        string model;
        bool iseEngineOn;
        int currSpeed;
        int currGear;
        string tyre;

    public:
        sports_car(string b,string m){
            this->brand= b;
            this->model= m;
            iseEngineOn=false;
            currSpeed=0;
            currGear=0; //neutral
            tyre="MRF";
        }

        int getCurrSpeed(){
            return this->currSpeed;
        }

        string getTyre(){
            return this->tyre;
        }
        void setTyre(string getTyre){
            this->tyre=tyre;
        }
        void start_engine(){
            iseEngineOn=true;
            cout<<brand<<" "<<model<<" Engine starts with a roar"<<endl;
        }
        void shift_gear(int gear){
            if(!iseEngineOn){
                cout<<brand<<" "<<model<<" :Engine is off! Cannot shift the gear"<<endl;
                return;
            }
            currGear=gear;
            cout<<brand<<" "<<model<<" Shifted to gear `"<<currGear<<endl;
        }
        void accelerate(){
            if(!iseEngineOn){
                cout<<brand<<" "<<model<<" "<<" :Engine is off! Cannot accelerate"<<endl;
                return;
            }
            currSpeed+=20;
            cout<<brand<<" "<<model<<" "<<": Acceleratingg to "<<currSpeed<<"km/hr"<<endl;
        }
        void brake(){
            currSpeed-=20;
            if(currSpeed<0)currSpeed=0;
            cout<<brand<<" "<<model<<" Braking speed is now: "<<currSpeed<<"km/hr"<<endl;
        }
        void stop_engine(){
            iseEngineOn=false;
            currGear=0;
            currSpeed=0;
            cout<<brand<<" "<<model<<" :Engine has been stopped"<<endl;
        }
};

int main(){
    sports_car *mycar=new sports_car("Ford","Mustang");  //parent class ka ek pointer,child class ke object ko point kar sakta hai!

    mycar->start_engine();
    mycar->shift_gear(1);
    mycar->accelerate();
    mycar->shift_gear(2);
    mycar->accelerate();
    mycar->brake();
    mycar->stop_engine();
    delete mycar;
    return 0;
}