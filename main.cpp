#include <iostream>
#include <cmath>
using namespace std;
class Point
{
    int x;
    int y;
public:
    Point();
    Point(int x,int y);
    int get_x() { return x; }
    int get_y() { return y; }
    void set_x(int a) {x=a;}
    void set_y(int b) {y=b;}
    Point operator+(Point);
    Point operator-(Point);
    Point operator*(int);
    Point operator/(int);
    int operator*(Point);
    int operator%(Point);// - косое произведение
    int sqlen(); // - квадрат длины вектора
    double angle(Point); // - угол между векторами(в радианах)
    bool operator==(Point);
    bool operator!=(Point);
    friend ostream& operator<<(ostream&, const Point&);
};

Point::Point(int a,int b) {
    x=a;
    y=b;
}

Point::Point(){
    x=0;
    y=0;
}

Point Point::operator+(Point a) {
    return Point(x+a.x,y+a.y);
}

Point Point::operator-(Point a) {
    return Point(x-a.x,y-a.y);
}

Point Point::operator*(int a) {
    return Point(a*x,a*y);
}

int Point::operator*(Point a){
    return x*a.x+y*a.y;
}

int Point::operator%(Point a){
    return x*a.y-y*a.y;
}

int Point::sqlen(){
    return x*x+y*y;
}

double Point::angle(Point a){
    return atan2(abs(y-a.y),abs(x-a.x));
}

bool Point::operator==(Point a){
    return (x==a.x && y==a.y);
}

bool Point::operator!=(Point a){
    return (x!=a.x || y!=a.y);
}

ostream& operator<<(ostream& out, const Point& a){
    return out<<a.x<<" "<<a.y;
}


int main() {
    Point a,b;
    int x,y,c;
    cout<<"Enter the a-vector: ";
    cin>>x>>y;
    a.set_x(x);
    a.set_y(y);
    cout<<"Enter the b-vector: ";
    cin>>x>>y;
    b.set_x(x);
    b.set_y(y);
    cout<<"Enter c: ";
    cin>>c;
    cout<<"a+b: ";
    cout<<a+b<<endl;
    cout<<"a-b: ";
    cout<<a-b<<endl;
    cout<<"a*c: ";
    cout<<a*c<<endl;
    cout<<"b*c: ";
    cout<<b*c<<endl;
    cout<<"a*b: ";
    cout<<a*b<<endl;
    cout<<"Square of a-vector length: ";
    cout<<a.sqlen()<<endl;
    cout<<"Square of b-vector length: ";
    cout<<b.sqlen()<<endl;
    cout<<"Angle between a-vector and b-vector: ";
    cout<<a.angle(b)<<endl;
    cout<<"a==b: ";
    cout<<(a==b)<<endl;
    cout<<"a!=b: ";
    cout<<(a!=b)<<endl;
    return 0;
}
