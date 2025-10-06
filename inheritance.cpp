#include<iostream>
#include<string>

using namespace std;
class car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currSpeed;

    public:
        car(string b,string m){
            this->brand=b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0;
        }
        void start_engine(){
            isEngineOn=true;
            cout<<brand<<" "<<model<<" :Engine starts with a roar"<<endl;
        }
        void stop_engine(){
            isEngineOn=false;
            currSpeed=0;
            cout<<brand<<" "<<model<<" :Engine turned off"<<endl;
        }
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" :Engine is off! Cannot accelerate"<<endl;
                return;
            }
            currSpeed+=20;
            cout<<brand<<" "<<model<<" :Accelerating to "<<currSpeed<<"km/hr"<<endl;
        }
        void brake(){
            currSpeed-=20;
            if(currSpeed<0)currSpeed=0;
            cout<<brand<<" "<<model<<" :Braking speed is now: "<<currSpeed<<"km/hr"<<endl;
        }
        virtual ~car(){}  //destructor
};

class manual_car : public car {
    private:
        int currGear;
    public:
        manual_car(string b,string m):car(b,m){
            currGear=0; //neutral
        }
        void shift_gear(int gear){
            currGear=gear;
            cout<<brand<<" "<<model<<" :Shifted to gear `"<<currGear<<endl;
        }
};

class electric_car : public car {
    private:
        int batteryLevel;
    public:
        electric_car(string b,string m):car(b,m){
            batteryLevel=100; //fully charged
        }
        void show_battery(){
            cout<<brand<<" "<<model<<" :Battery level is "<<batteryLevel<<"%"<<endl;
        }
        void charge_battery(){
            batteryLevel=100;
            cout<<brand<<" "<<model<<" :Battery fully charged"<<endl;
        }
    };
int main(){
    manual_car *myManualCar = new manual_car("Ford","Mustang");
    electric_car *myElectricCar = new electric_car("Tesla","Model S");

    myManualCar->start_engine();
    myManualCar->shift_gear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stop_engine();
    cout<<endl;

    cout<<"------------------------------"<<endl;

    myElectricCar->charge_battery();
    myElectricCar->start_engine();
    myElectricCar->show_battery();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stop_engine();
}
