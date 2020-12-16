#include <iostream>
#include <string>

// RAII: Resource Acquisition Is Initialization

class Sample{
    private:
    public:
};

class Chair{
    private:
        std::string _legs;
        unsigned short _numLegs;
    
    public:
        unsigned short getLegsCount(){
            return _numLegs;
        }

        void setLegsCount(unsigned short l){
            _numLegs = l;
        }
};

class Cuboid{
    double _width;
    double _length;
    double _height;

    public:
        Cuboid(double width, double height, double length){
            _width = width;
            _height = height;
            _length = length;
        }

        double getArea(){
            return _width * _height * _length;
        }
};

class Rectangle: public Cuboid{
    //double _width;
    //double _length;

    public:
    Rectangle(double width, double length): Cuboid(width, 1, length){
        //_width = width;
        //_length = length;
    }
};

class Shape{
    public:
        virtual double area() = 0; // pure virtual function
};

//void setShape(Shape){
//}

class Rectangle2 : public Shape{
    double _l;
    double _b;
    public:
        Rectangle2(double l, double b){
            _l = l;
            _b = b;
        }

        double area() {
            return _l * _b;
        }
};

class Triangle : public Shape{
    double _h;
    double _b;
    public:
        Triangle(double h, double b){
            _h = h;
            _b = b;
        }

        double area() {
            return 0.5 * _h * _b;
        }
};

int main(){
    Shape* s = nullptr;
    Rectangle2 r2(10,7);
    s = &r2;
    std::cout << "Rectangle = " << s->area() << std::endl;

    Triangle t1(10,5);
    s = &t1;
    std::cout << "Triangle = " << s->area() << std::endl;

    /*Sample s;
    Cuboid c(2,4,5);
    std::cout << c.getArea() << std::endl;
    Rectangle r(5,6);
    std::cout << r.getArea() << std::endl;*/
}