// Abstract product class
#include <iostream>
#include <string>
class Vehicle {
public:
    short unsigned int wheels;
    Vehicle(){
        wheels = 0;
    }
    virtual void print() = 0;
    virtual ~Vehicle() {
    } // Virtual destructor for polymorphism
};
// Concrete product class - Car
class Car : public Vehicle {
public:
    std::string bodyStyle;
    Car(std::string bodyStyle_) {
        wheels = 4;
        bodyStyle = bodyStyle_;
    }
    void print() override
    {
        std::cout << "Vehicle type: car, body type: " << bodyStyle << " number of wheels: " << wheels << std::endl;
    }
};

// Concrete product class - Motorcycle
class Motorcycle : public Vehicle {
public:
    Motorcycle() {
        wheels = 2;
    }
    void print() override
    {
        std::cout << "Vehicle type: motorcycle, number of wheels: " << wheels << std::endl;
    }
};
// Abstract creator class
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() {
    } // Virtual destructor for polymorphism
};


// Concrete creator class - CarFactory
class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override { return new Car("Sedan"); }
};

// Concrete creator class - MotorcycleFactory
class MotorcycleFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override { return new Motorcycle(); }
};
int main()
{
    VehicleFactory* carFactory = new CarFactory();
    VehicleFactory* motorcycleFactory = new MotorcycleFactory();

    Vehicle* car = carFactory->createVehicle();
    Vehicle* motorcycle = motorcycleFactory->createVehicle();

    car->print();
    motorcycle->print();

    delete carFactory;
    delete motorcycleFactory;
    delete car;
    delete motorcycle;

    return 0;
}