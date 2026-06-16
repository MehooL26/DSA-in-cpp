#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<string> cars = {"Volvo","BMW","Merc","Tesla"};    //creating a vector

for(string car : cars){     //printing vector elements
    cout<<car<<"\n";
}

cout<<cars[0];   //getting first element
cout<<cars.front();      //getting first element
cout<<cars.back();       //getting last element
cout<<cars.at(1);       //getting second element
cars.push_back("Tesla");    //adding an element to the last
cars.pop_back();        //removes the last element
cout<<cars.size();      //gives size of vector
cout<<cars.empty();      //checks whether vector is empty
}