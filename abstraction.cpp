#include <iostream>
#include <string>
using namespace std;

class car{
    public :
        virtual void start_engine()=0;    //we declare functions like this its not defined yet!
        virtual void shift_gear(int gear)=0;
        virtual void accelerate()=0;
        virtual void brake()=0;
        virtual void stop_engine()=0;
        virtual ~car(){}     //destructor
};

class sports_car : public car {
    public :
        string brand;
        string model;
        bool iseEngineOn;
        int currSpeed;
        int currGear;

        sports_car(string b,string m){
            this->brand= b;
            this->model= m;
            iseEngineOn=false;
            currSpeed=0;
            currGear=0; //neutral
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
            cout<<brand<<" "<<model<<" Shifted to gear"<<currGear<<endl;
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
    car *mycar=new sports_car("Ford","Mustang");  //parent class ka ek pointer,child class ke object ko point kar sakta hai!

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