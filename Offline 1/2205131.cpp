#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define PI 3.14

class Rectangle{
    private:
    int length, width;
    char *color;
    public:
    Rectangle(){
        length = 1;
        width = 1;
        color = (char*) malloc((strlen("White")+1)*sizeof(char));
        strcpy(color,"White");
    }
    Rectangle(int l, int w, char c[]){
        length = l;
        width = w;
        color = (char*) malloc((strlen(c)+1)*sizeof(char));
        strcpy(color,c);
    }
    ~Rectangle(){
        free(color);
    }
    int getPerimeter(){
        return 2*(length+width);
    }
    int getArea(){
        return length*width;
    }
    char *getColor(){
        return color;
    }
    void setColor(char *c){
        free(color);
        color = (char*) malloc((strlen(c)+1)*sizeof(char));
        strcpy(color,c);
    }
    int getLength(){
        return length;
    }
    int getWidth(){
        return width;
    }
    void setLength(int l){
        length = l;
    }
    void setWidth(int w){
        width = w;
    }
};

class Triangle{
    private:
    int a, b, c;
    char *color;
    public:
    Triangle(){
        a = 3;
        b = 4;
        c = 5;
        color = (char*) malloc((strlen("White")+1)*sizeof(char));
        strcpy(color,"White");
    }
    Triangle(int s1, int s2, int s3,  char str[]){
        a=s1;
        b=s2;
        c=s3;
        color = (char*) malloc((strlen(str)+1)*sizeof(char));
        strcpy(color,str);
    }
    ~Triangle(){
        free(color);
    }
    int getPerimeter(){
        return a+b+c;
    }
    float getArea(){
        int s = (a+b+c)/2.0;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    char *getColor(){
        return color;
    }
    void setColor(char *c){
        free(color);
        color = (char*) malloc((strlen(c)+1)*sizeof(char));
        strcpy(color,c);
    }
    int getSide1(){
        return a;
    }
    int getSide2(){
        return b;
    }
    int getSide3(){
        return c;
    }
    void setSide1(int s){
        a = s;
    }
    void setSide2(int s){
        b = s;
    }
    void setSide3(int s){
        c = s;
    }
};

class Circle{
    private:
    int radius;
    char *color;
    public:
    Circle(){
        radius = 1;
        color = (char*) malloc((strlen("White")+1)*sizeof(char));
        strcpy(color,"White");
    }
    Circle(int r, char c[]){
        radius = r;
        color = (char*) malloc((strlen(c)+1)*sizeof(char));
        strcpy(color,c);
    }
    ~Circle(){
        free(color);
    }
    float getPerimeter(){
        return 2*PI*radius;
    }
    float getArea(){
        return PI*radius*radius;
    }
    char *getColor(){
        return color;
    }
    void setColor(char *c){
        free(color);
        color = (char*) malloc((strlen(c)+1)*sizeof(char));
        strcpy(color,c);
    }
    int getRadius(){
        return radius;
    }
    void setRadius(int r){
        radius = r;
    }
};

class ShapeCollection{
    private:
    int r, t, c;
    Rectangle rectangles[100];
    Triangle triangles[100];
    Circle circles[100];
    public:
    ShapeCollection(){
        r = 0;
        t = 0;
        c = 0;
    }
    void addRectangle(Rectangle &rect){
        rectangles[r].setColor(rect.getColor());
        rectangles[r].setLength(rect.getLength());
        rectangles[r].setWidth(rect.getWidth());
        r++;
    }
    void addTriangle(Triangle &tri){
        triangles[t].setColor(tri.getColor());
        triangles[t].setSide1(tri.getSide1());
        triangles[t].setSide2(tri.getSide2());
        triangles[t].setSide3(tri.getSide3());
        t++;
    }
    void addCircle(Circle &cir){
        circles[c].setColor(cir.getColor());
        circles[c].setRadius(cir.getRadius());
        c++;
    }
    int getRectCount(){
        return r;
    }
    int getTriCount(){
        return t;
    }
    int getCircCount(){
        return c;
    }
    void printRectangles(){
        for(int i=0; i<r; i++){
            cout << "Rectangle " << i << ": " << "length" << ": " << rectangles[i].getLength()  << " width" << ": " << rectangles[i].getWidth() << endl;
        }
    }
    void printTriangles(){
        for(int i=0; i<t; i++){
            cout << "Triangle " << i << ": " << "a" << ": " << triangles[i].getSide1() << " b" << ": " << triangles[i].getSide2() << " c" << ": " << triangles[i].getSide3() << endl;
        }
    }
    void printCircles(){
        for(int i=0; i<c; i++){
            cout << "Circle " << i << ": " << "radius" << ": " << circles[i].getRadius() << endl;
        }
    }
};

int main()
{
    // Create rectangle with length, width, color
    Rectangle r1(10, 20, "Red");
    // The Color is stored using malloc, which will be freed during destruction
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    // When changing the color, you need to free the memory of the old color
    // and allocate new memory for the new color
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    // Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    /*
    When constructing the ShapeCollection class, you will create static arrays for 100
    rectangles, triangles and circles. You don’t have to dynamically allocate memory for this.
    */
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by reference to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied, leading to double free errors when things go
    out of scope. Once passed by reference, do not directly store the reference in
    the array. Instead, copy the data from the reference to the array element.
    We will see better ways to handle this in the upcoming sessions.
    */
    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);

    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}