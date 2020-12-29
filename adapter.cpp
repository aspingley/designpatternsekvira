#include <iostream>

typedef int coordinate;
typedef int dimension;

// Legacy component
class Rectangle{
    private:
        coordinate _x1;
        coordinate _y1;
        coordinate _x2;
        coordinate _y2;
    public:
        //NewRectangle(coordinate x1, coordinate y1, dimension w, dimension h)
        Rectangle(coordinate x1, coordinate y1, coordinate x2, coordinate y2){
            _x1 = x1; _y1 = y1; _x2 = x2; _y2 = y2;
            std::cout << "this is constructor for legacy rectangle" << std::endl;
        }

        void drawRectangle(){
            std::cout << "\t Rectangle" << std::endl;
        }
};

class NewRectangle{
    Rectangle *r;
    public:
        NewRectangle(coordinate x1, coordinate y1, dimension w, dimension h){
            r = new Rectangle(x1, y1, x1+w, y1+h);
        }

        void drawRectangle(){
            std::cout << "\t New Rectangle" << std::endl;
        }
};

class IRectangle{
    public:
        virtual void draw() = 0;
        //virtual void setCoordinates(coordinate, coordinate) = 0;
        //virtual void setDimensions(dimension, dimension) = 0;
};

class RectangleAdapter: public IRectangle, private Rectangle{
    public:
        RectangleAdapter(coordinate x1, coordinate y1, dimension w, dimension h):\
         Rectangle(x1, y1, x1+w, y1+h){
        }

        void draw(){
            std::cout << "\t ShinyRectangle" << std::endl;
            drawRectangle();
        }
};

int main(){
    //Rectangle r(2,3,4,5);
    //r.drawRectangle();

    //NewRectangle nr(2,3,4,5);
    //nr.drawRectangle();

    RectangleAdapter sr(2,3,4,5);
    sr.draw();

    return 0;
}