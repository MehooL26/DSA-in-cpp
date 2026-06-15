#include<iostream>
using namespace std;

class Example{
    int a,b;
    public:
    Example(){
        a = 50;
        b = 100;
        cout<<"This is a constructor"<<endl;
    }

    Example(int x, int y){
        a = x;
        b = y;
        cout<<"This is a constructor"<<endl;
    }

    void Display(){
        cout<<"Values: "<<a<<"\t"<<b;
    }
};

int main(){
    Example Object(10,20);
    Example Object2;
    Object.Display();
    Object2.Display();
}