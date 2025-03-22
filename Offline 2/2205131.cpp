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
    Rectangle(const Rectangle &r){
        length = r.length;
        width = r.width;
        color = (char*) malloc((strlen(r.color)+1)*sizeof(char));
        strcpy(color,r.color);
    }
    ~Rectangle(){
        free(color);
        //cout << "Destructing Rectangle" << endl;
    }
    Rectangle *clone(){
        Rectangle *temp = new Rectangle(length,width,color);
        return temp;
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
    Triangle(const Triangle &t){
        a = t.a;
        b = t.b;
        c = t.c;
        color = (char*) malloc((strlen(t.color)+1)*sizeof(char));
        strcpy(color,t.color);
    }
    ~Triangle(){
        free(color);
        //cout << "Destructing Triangle" << endl;
    }
    Triangle *clone(){
        Triangle *temp = new Triangle(a,b,c,color);
        return temp;
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
    Circle(const Circle &c){
        radius = c.radius;
        color = (char*) malloc((strlen(c.color)+1)*sizeof(char));
        strcpy(color,c.color);
    }
    ~Circle(){
        free(color);
        //cout << "Destructing Circle" << endl;
    }
    Circle *clone(){
        Circle *temp = new Circle(radius,color);
        return temp;
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
    int r, t, c, RecCap, TriCap, CircCap;
    Rectangle **rectangles;
    Triangle **triangles;
    Circle **circles;
    public:
    ShapeCollection(){
        r = 0;
        t = 0;
        c = 0;
        rectangles = (Rectangle**)malloc(sizeof(Rectangle*));
        triangles = (Triangle**)malloc(sizeof(Triangle*));
        circles = (Circle**)malloc(sizeof(Circle*));
        RecCap = 1;
        TriCap = 1;
        CircCap = 1;
    }
    ~ShapeCollection(){
        for(int i=0; i<r;i++){
            free(rectangles[i]);
            //cout << "Freeing rectangle of rectangle[" << i << "]" << endl;
        }
        for(int i=0;i<t;i++){
            free(triangles[i]);
            //cout << "Freeing triangle of triangle[" << i << "]" << endl;
        }
        for(int i=0;i<c;i++){
            free(circles[i]);
            //cout << "Freeing circle of circle[" << i << "]" << endl;
        }
        free(rectangles);
        free(triangles);
        free(circles);
        //cout << "Destructing Shape Collection" << endl;
    }
    void add(Rectangle rect){
        if(r==RecCap){
            cout << "Increasing capacity of rectangles from " << RecCap << " to " << 2*RecCap << endl;
            Rectangle **temp = (Rectangle **) malloc(sizeof(Rectangle*)*2*RecCap);
            for(int i=0;i<RecCap;i++){
            temp[i] = rectangles[i]->clone();
            }
            free(rectangles);
            rectangles = temp;
            RecCap = 2*RecCap;
        }
        rectangles[r] = rect.clone();
        r++;
    }
    void add(Triangle tri){
        if(t==TriCap){
            cout << "Increasing capacity of triangles from " << TriCap << " to " << 2*TriCap << endl;
            Triangle **temp = (Triangle **) malloc(sizeof(Triangle*)*2*TriCap);
            for(int i=0;i<TriCap;i++){
            temp[i] = triangles[i]->clone();
            }
            free(triangles);
            triangles = temp;
            TriCap = 2*TriCap;
        }
        triangles[t] = tri.clone();
        t++;
    }
    void add(Circle cir){
        if(c==CircCap){
            cout << "Increasing capacity of circles from " << CircCap << " to " << 2*CircCap << endl;
            Circle **temp = (Circle **) malloc(sizeof(Circle*)*2*CircCap);
            for(int i=0;i<CircCap;i++){
                temp[i] = circles[i]->clone();
            }
            free(circles);
            circles = temp;
            CircCap = 2*CircCap;
        }
        circles[c] = cir.clone();
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
            cout << "Rectangle " << i << ": " << "length" << ": " << rectangles[i]->getLength()  << " width" << ": " << rectangles[i]->getWidth() << endl;
        }
    }
    void printTriangles(){
        for(int i=0; i<t; i++){
            cout << "Triangle " << i << ": " << "a" << ": " << triangles[i]->getSide1() << " b" << ": " << triangles[i]->getSide2() << " c" << ": " << triangles[i]->getSide3() << endl;
        }
    }
    void printCircles(){
        for(int i=0; i<c; i++){
            cout << "Circle " << i << ": " << "radius" << ": " << circles[i]->getRadius() << endl;
        }
    }
};

int main() {
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
    When constructing the ShapeCollection class, you will create dynamic for 
    rectangles, triangles and circles. You have to dynamically allocate memory for this.
    */ 
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by value to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied. So, you have to write copy constructor so that 
    memory allocation is properly done and no double free error occurs.
    */ 


    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);

    Rectangle r2(15, 25, "Black");
    Rectangle r3(150, 225, "Green");
    shapes.add(r2);
    shapes.add(r3);
    Triangle t2(5, 12, 13, "White");
    shapes.add(t2);

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}