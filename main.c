1.Write a C++ program to convert Primitive type to Complex type.

#include <iostream>
#include <typeinfo>

using namespace std;

class Complex {
    int real;
public:
    Complex() {};

    Complex(int x) {
        real = x;
        cout<<"parameterised called";
    };

};

int main() {
    Complex c1;
    int x=3;
    c1 = x;
    return 0;
}

2. Write a C++ program to convert Complex type to Primitive type.

#include<iostream>

using namespace std;

class Complex {
private:
    int real, img;
public:
    void setdata(int real, int img) {
        this->real = real;
        this->img = img;
    }

    operator int() {
        return this->real;
    }


};

int main() {
    Complex c1;
    c1.setdata(5, 2);
    char x;
    x = c1;
    cout << x;
    return 0;
}

3. Create a Product class and convert Product type to Item type using constructor
#include<iostream>

using namespace std;


class Product {
private:
    int x, y;
public:
    Product() {};

    void setData(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }

    int getY() { return y; }
};

class Item {
private:
    int x, y;
public:
    Item() {}

    Item(Product p) {
        this->x = p.getX();
        this->y = p.getY();
    }
    void showData(){
        cout<<x<<" "<<y;
    }
};

int main() {
    Item i1;
    Product p1;
    p1.setData(3, 4);
    i1 = p1;
    i1.showData();
    return 0;

}

4. Create Product class and convert Product type to Item type using casting operator


#include <iostream>

using namespace std;

class Item {
private:
    int y;
public:
    Item() {};

    void setData(int z) { y = z; };

    void showdata() {
        cout << y << endl;
    }

};

class Product {
private:
    int x;
public:
    Product() {}

    Product(int a) { x = a; };

    int getX() {
        return this->x;
    }

    operator Item() {
        Item temp;
        temp.setData(x);
        return temp;
    }
};


int main() {
    Product p1 = 4;
    Item i1;
    i1 = Item(p1);
    i1.showdata();
    return 0;
}


5. Create two classes Invent1 and Invent2 and also add necessary constructors in it. Now add
functions to support Invent1 to float and Invent1 to Invent2 type

#include <iostream>
using namespace std;
class Invent2{
private:
    int a;
    int b;
public:
    Invent2(){};
    void setData(int x,int y){ a=x,b=y;};
    void show(){
        cout<<a<<" "<<b;
    }

};
class Invent1 {
private:
    int num1, num2;
public:
    Invent1() {};

    Invent1(int x, int y) {
        num1 = x;
        num2 = y;
    }
    operator float (){
        return num1;
    }

    void show(){
        cout<<num1;
    }

    operator Invent2(){
        Invent2 temp;
        temp.setData(num1,num2);
        return temp;
    }
};

int main() {
    Invent1 s1(4,5);
    Invent2 d1;
    float tv;
    tv=s1;
    d1=s1;
    d1.show();
    return 0;
}
6. Create a Time class and take Duration in seconds. Now you need to convert seconds(i.e in
int ) to Time class.
#include <iostream>
using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;
public:

    Time(){};
    Time(int minute){
        int temp = minute/60 ;
        this->hour = temp;
        int b=temp*60;
        this->minute = minute-b;

    };

    void display(){
        cout<<hour<<"  "<<minute;
    }

};
int main()
{
    int duration;
    cout<<"Enter time duration in minutes";
    cin>>duration;
    Time t1 = duration;
    t1 = duration;
    t1.display();
    return 0;
}


7. Create two class Time and Minute and add required getter and setter including constructors.
Now you need to type cast Time object into Minute to fetch the minute from Time and display it.

#include <iostream>
using namespace std;

class Time{
private:
    int t;
    int minu;
public:
    void display(){
        cout<<t<<" "<<minu<<endl;
    }
    Time(){};
    Time(int x,int y){
        t=x;
        minu=y;
    };
    int getMinu(){return minu;}
    int gett(){return t;}
};

class Minute{
private:
    int m;
public:

    void display(){
        cout<<m<<endl;
    }
    Minute(){};
    Minute(Time t){
        this->m = 60*t.gett()+t.getMinu();
    }

};
int main()
{
    Time t1(2,30);
    t1.display();
    Minute m1;
    m1.display();
    m1 = t1 ;
    t1.display();
    m1.display();
    return 0;

}

8. Create a Rupee class and convert it into int. And Display it.

#include <iostream>
#include <typeinfo>
using namespace std;

class Rupee {
private:
    int r;
public:
    Rupee() {};

    Rupee(int x) { r = x; };

    operator int(){
        return this->r;
    }
};

int main() {
    Rupee r = 10;
    int x = r;
    cout << x;
    return 0;
}

9. Create a Dollar class and add necessary functions to support int to Dollar type conversion.
#include <iostream>
#include <typeinfo>
using namespace std;

class Dollar {
private:
    int d;
public:
    Dollar() {};

    Dollar(int x) { d = x; };
    void display(){
        cout<<d;
    }

};

int main() {
    int x = 50;
    Dollar d;
    d = x;
    d.display();
    return 0;
}

10. Create two classes Rupee and Dollar and add necessary functions to support Rupee to
Dollar and Dollar to Rupee conversion.
#include <iostream>

using namespace std;

class Rupee {
private:
    float r;
public:
    Rupee() {};

    Rupee(float x) { r = x; }

    int getR() { return r; };
    void display(){
        cout<<r<<endl;
    }
};


class Dollar {
private:
    float d;
public:
    Dollar() {};

    Dollar(float x) { d = x; };

    Dollar(Rupee t) {
        d = t.getR()/70.0;
    }

    void display() {
        cout << d<<endl;
    }

    operator Rupee(){
        return 70.0* this->d;
    }
    operator Dollar(){
        return (this->d/70);
    }

};

int main() {
    Rupee r = 23;
    Dollar d = r; // Rupee to Dollar conversion
    d.display();
    r.display();
    r = d; // Dollar to Rupee Conversion
    d = r;
    d.display();
    r.display();
    return 0;
}



