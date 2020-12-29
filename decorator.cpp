#include <iostream>
#include <string>
#include <map>


// Kavin's solution
class KBeverage{
    private:
        double _caramel_price;
        double _powder_price;
        double _chocolate_price;
        double _milk_price;

    public:

};
/////

/// Kavitha's solution
std::map<std::string, double> database;

class KavithaEspresso{
    private:
        double _totalPrice;
    public:
        double getCost(){
        _totalPrice = database["espresso"];
        return _totalPrice;
    }
};

class KavithaLatte: public KavithaEspresso{
    private:
        double _mp;
        double _totalPrice;
    public:
        double getCost(){
        _totalPrice = _mp * database["milk"] + KavithaEspresso::getCost();

        return _totalPrice;
    }
};

class KavithaCaramelLatte: public KavithaLatte{
    private:
        double _cp;
        //double _mp;
        double _totalPrice;
    public:
        double getCost(){
        _totalPrice = _cp * database["caramel"] + KavithaLatte::getCost();

        return _totalPrice;
    }
};

class KavithaChocoCaramelLatte: public KavithaCaramelLatte{
    private:
        double _chp;
        //double _mp;
        double _totalPrice;
    public:
        double getCost(){
        _totalPrice = _chp * database["chocolate"] + KavithaCaramelLatte::getCost();
        return _totalPrice;
    }
};
/////

// The Decorator Pattern
class IBeverage{
    public:
        virtual double getCost() = 0;
        virtual std::string getDescription() = 0;
};

// Espresso
// Latte - Milk
// CaramelLatte - Milk + Caramel
// ChochoCaramelLatte - Milk + Caramel + Choco

class CoffeeEspresso: public IBeverage{
    private:
        IBeverage* _beverage;
    public:
        CoffeeEspresso(){}
        CoffeeEspresso(IBeverage* b){
            _beverage = b;
        }

        double getCost(){
           return 90;
        }

        std::string getDescription(){
            return "Espresso";
        }
};

class CoffeeLatte: public IBeverage{

    private:
        IBeverage* _beverage;
    public:
        CoffeeLatte(IBeverage* b){
            _beverage = b;
        }

        double getCost(){
            return _beverage->getCost() + 20;
        }

        std::string getDescription(){
            return _beverage->getDescription() + " with Milk";
        }
};

class CoffeeCaramelLatte: public IBeverage{
    private:
        IBeverage* _beverage;
    public:
        CoffeeCaramelLatte(IBeverage* b){
            _beverage = b;
        }
    
        double getCost(){
            return _beverage->getCost() + 30;
        }

         std::string getDescription(){
            return _beverage->getDescription() + " with Caramel";
        }
};

class CoffeeChocoCaramelLatte: public IBeverage{
    private:
        IBeverage* _beverage;
    public:
        CoffeeChocoCaramelLatte(IBeverage* b){
            _beverage = b;
        }

        double getCost(){
            return _beverage->getCost() + 10;
        }

         std::string getDescription(){
            return _beverage->getDescription() + " with Chocolate";
        }
};


int main(){

    CoffeeEspresso* esp = new CoffeeEspresso();
    std::cout << esp->getDescription() << "\t" << esp->getCost() << std::endl;
    CoffeeLatte* cfl = new CoffeeLatte(esp);
    std::cout << cfl->getDescription() << "\t" << cfl->getCost() << std::endl;
    CoffeeCaramelLatte *cml = new CoffeeCaramelLatte(cfl);
    std::cout << cml->getDescription() << "\t" << cml->getCost() << std::endl;
    CoffeeChocoCaramelLatte *chml = new CoffeeChocoCaramelLatte(cml);
    std::cout << chml->getDescription() << "\t" << chml->getCost() << std::endl;

    

    return 0;
}