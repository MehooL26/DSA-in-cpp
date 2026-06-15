#include<iostream>
using namespace std;

class Student{
    public:
    int rollno;
    string name;
    Student(int x){
        rollno = x;
        name = "None";
    }

    Student(int x, string str){
        rollno = x;
        name = str;
    }

    void display(){
        cout<<"x = :"<<rollno<<"name = "<<name;
    }

    ~Student(){     //DESTRUCTOR
        cout<<"Destructor called"<<endl;
    }  
};

int main(){
    Student A(10);
    A.display();
    Student B(11,"John");
    B.display();
}