#include <iostream>
#include <vector>

template <typename T>
struct base{
    void dosomething(){
        //std::cout << "base" << std::endl;
        T* derivedPtr = static_cast<T*>(this);
        derivedPtr->dosomething(); 
    }
};

struct derived1: public base<derived1>{
    void dosomething(){
        std::cout << "derived1" << std::endl;
    }
};

struct derived2: public base<derived2>{
    void dosomething(){
        std::cout << "derived2" << std::endl;
    }
};

struct derived3: public base<derived3>{
    void dosomething(){
        std::cout << "derived3" << std::endl;
    }
};

template <typename T>
class MultiplyByTwo{
    public: 
        T implement(T inp){
            return inp * 2; 
        }
};

int main(){

    base<derived2>* ptr = new derived2();
    ptr->dosomething();
    return 0;

    /*MultiplyByTwo<double> h;
    std::cout << h.implement(4) << std::endl;

    MultiplyByTwo<unsigned int> l;
    std::cout << l.implement(14) << std::endl;

    return 0;

    std::vector<float> v;
    std::vector<base*> j; 


    base b;
    b.dosomething();

    derived d;
    d.dosomething();

    base *ptrB = new derived();
    ptrB->dosomething();

    delete ptrB;

    return 1;*/
}