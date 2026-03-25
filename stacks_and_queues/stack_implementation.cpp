#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public:

    int *arr;
    int top;
    int size;

    //behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element){
        //checking whether we can push elements in stack
        if(size - top > 1){

            top++;
            arr[top] = element;

        }
        else{
            cout << "Stack Overflow" << endl;
        }

    }

    void pop(){

        if (top >= 0){

            top--;

        }
        else{
            cout << "Stack Underflow" << endl;
        }

    }

    int peek(){

        if (top >= 0){
            return arr[top];
        }
        else{
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if (top == -1){
            cout << " Stack is Empty." << endl;
            return true;
        }

        else{
            return false;
        }

    }
};


/*
Stack implementation : STL is not used.
It is implemented using class.

Two implementations : Array and Linked lists

Here : One stack in a single array

*/

int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    //pushing three more elements so that size becomes 6

    st.push(21);
    st.push(33);
    st.push(53);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()){
        cout << "Stack is Empty." << endl;
    }
    else{

        cout << "Stack is not empty." << endl;
    }

}
