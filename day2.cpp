#include <iostream>

// OPEN SSL simulation starts
struct XBio{
    double x;
    double y;
};

char* get_sequence_sl(int y){
    return "get_sequence_sl_openssl";
}

void set_xbio_sequence(XBio* n){}
// OPEN SSL ends here

// Cisco's internal security library starts
class CiscoSec{
    public:
        void init(const std::string& val){}
        std::string process(){ 
            return "CiscoSec process";
        }
};
// Cisco's internal security library end


class ISecurityWrapper{
    public:
        /**
        */ 
        virtual void init(const std::string& inpStr) = 0;
        virtual std::string process() = 0;
};

class OpenSSLWrapper : public ISecurityWrapper{
    public:
        virtual void init(const std::string& inpStr){
            set_xbio_sequence(nullptr);
        }

        std::string process(){
             std::string d(get_sequence_sl(10));
            return d;
        }
};

class CiscoSecWrapper : public ISecurityWrapper{
    CiscoSec *csec;
    public:
        CiscoSecWrapper(){
            csec = new CiscoSec();
        }
        
        void init(const std::string& inpStr){
            csec->init(inpStr);
        }

        std::string process(){
             return csec->process();
        }
};


// #include <openssl.h>
class WrapperSecurity{
    private:
        std::string _val;
        double _a;
        int _b;
    public:
        WrapperSecurity(const std::string& val){
            _val = val;
            // some computation on val.
            _a = 10;
            _b = 9;
        }

        void initSecurityLib(){
            set_xbio_sequence(nullptr);
        }

        std::string getSequence(){
            std::string d(get_sequence_sl(_b));
            return d;
        }

};

void factoryMethod(ISecurityWrapper& sWrapper, int in){
    if(1 == in) // Factory
        sWrapper = new OpenSSLWrapper();
    if(2 == in)
        sWrapper = new CiscoSecWrapper();
    //if(3 == in)
        //sWrapper = new NewWrapperClass();
}

// some other cpp file
int main(){
    //WrapperSecurity s("eeqfeqf");
    //s.initSecurityLib();
    //std::cout << s.getSequence() << std::endl;
    int in;
    std::cin >> in;
    // factory pattern 
    // factory method would have a function that takes
    // input and determines the concrete class
    ISecurityWrapper *sWrapper = nullptr;
    factoryMethod(sWrapper, in);
    //if(1 == in) // Factory
    //    sWrapper = new OpenSSLWrapper();
    //if(2 == in)
    //    sWrapper = new CiscoSecWrapper();

    sWrapper->init("ewfewfe");
    std::cout << sWrapper->process() << std::endl;

    return 0;
}
