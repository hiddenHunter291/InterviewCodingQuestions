#include<bits/stdc++.h>
using namespace std;

class base {
    int a,b;
    friend void privateVariables(base);
public:
    void setVariables(int x1, int x2) {
        a = x1;
        b = x2;
    }
    void getVariables() {
        cout << a << " " << b << endl;
    }
    virtual void methodOveride() {
        cout << "base class" << endl;
    }
};

class Dervied : public base {
public:
    void methodOveride() {
        cout << "Dervied class" << endl;
    }
    static void scopeResolutor() {
        cout << "using scope resolutor" << endl;
    }
};

void privateVariables(base x) {
    cout << x.a << " " << x.b << endl;
}

class Animals {
public:
    void live() {
        cout << "They need food and shelter to live" << endl;
    }
};

class Mammals {
public:
    virtual void sound() = 0;
    void walk() {
        cout << "using four legs" << endl;
    }
};

class Humans : public Mammals, public Animals {
public:
    void sound() {
        cout << "they speak" << endl;
    }
    void walk() {
        cout << "using two legs" << endl;
    }
};

int main() {
    Mammals *m = new Humans();
    m->sound();                 //use of abstract methods
    Humans h;
    h.walk();                   //method overidding
    h.live();                   //multiple inheritance
    return 0;
}