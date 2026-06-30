//WORKS ON THE PRINCIPLE OF FIRST IN FIRST OUT(FIFO)
// dequeue removes the first element
// enqueue adds to the last element

#include<iostream>
#include<queue>

using namespace std;
int main(){
queue<string> cars;
//queue<string> cars = {"Volvo","BMW","Ford","Mazda"};      //This is wrong

//To add elements to the queue we can use the push() function after declaring the queue
cars.push("Volvo");
cars.push("BMW");
cars.push("Ford");
cars.push("Mazda");

cout<<cars.front();     //Accessing first and oldest element
cout<<cars.back();     //Accessing last and latest element

cars.pop();     //Removes the front element
cars.size();    //Get the size of queue

cout<<cars.empty();       //gives output 0 if queue is not empty, gives 1 if queue is empty
}