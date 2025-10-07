#include<iostream>
#include<string>
using namespace std;

class manual_car {
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currSpeed;
        int currGear;
    public:
        manual_car(string b,string m){
            this->brand= b;
            this->model= m;
            isEngineOn=false;
            currSpeed=0;
            currGear=0; //neutral
        }

        void start_engine(){
            isEngineOn=true;
            cout<<brand<<" "<<model<<" :Engine starts with a roar"<<endl;
        }
        void shift_gear(int gear){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" :Engine is off! Cannot shift the gear"<<endl;
                return;
            }
            currGear=gear;
            cout<<brand<<" "<<model<<" :Shifted to gear "<<currGear<<endl;
        }
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" "<<" :Engine is off! Cannot accelerate"<<endl;
                return;
            }
            currSpeed+=20;
            cout<<brand<<" "<<model<<" "<<": Acceleratingg to "<<currSpeed<<"km/hr"<<endl;
        }
        void accelerate(int speed){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" "<<" :Engine is off! Cannot accelerate"<<endl;
                return;
            }
            currSpeed+=speed;
            cout<<brand<<" "<<model<<" "<<": Acceleratingg to "<<currSpeed<<"km/hr"<<endl;
        }      
        void brake(){
            currSpeed-=20;
            if(currSpeed<0)currSpeed=0;
            cout<<brand<<" "<<model<<" :Braking speed is now: "<<currSpeed<<"km/hr"<<endl;
        }
        void stop_engine(){
            isEngineOn=false;
            currGear=0;
            currSpeed=0;
            cout<<brand<<" "<<model<<" :Engine has been stopped"<<endl;
        }
};

int main(){
    manual_car *mycar=new manual_car("Ford","Mustang");
    mycar->start_engine();
    mycar->shift_gear(1);
    mycar->accelerate();
    mycar->accelerate(30); //function overloading
    mycar->brake();
    mycar->shift_gear(2);
    mycar->stop_engine();
    delete mycar;
    return 0;
}