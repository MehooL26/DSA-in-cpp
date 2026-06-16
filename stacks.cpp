// WORKS ON THE PRINCIPLE OF LAST IN, FIRST OUT. 
// SO THE TOP ELEMENT IS THE FIRST ELEMENT
#include<iostream>
#include<stack>
using namespace std;

int main(){
    //stack<string> cars = {"Volvo","BMW","Ford","Mazda"};          THIS IS WRONG
    stack<string> cars;     //we have to add elements using push
    cars.push("Merc");     //adding element to the stack
    cars.push("Audi");     //adding element to the stack
    cars.push("BMW");     //adding element to the stack

    cout<<cars.top();       //outputs the top element i.e. mazda
    cars.pop();     //remove the last(top) element
    cout<<cars.size();       //gives size of stack
    cout<<cars.empty();      //checks whether stack is empty or not
}