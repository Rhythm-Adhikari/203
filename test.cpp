#include<fstream>
#include<iostream>
#include<stdlib.h>


using namespace std;
//Global Variables
const int Stacksize = 100;
string  wordStack[Stacksize];
int point = -1;
//Functions
void push(char word[]);
string top();
void pop();
bool isEmpty();

int main(){
    //input filename
    char FileName[20];
    char word[20];
    cout << "Enter FileName: ";
    cin >> FileName;
    //open file
    ifstream TestFile;
    TestFile.open(FileName);
    if(!TestFile.is_open()){
        cout << "Unable to open file";
        exit(1);
    }
   do {
        TestFile >> word;
        if (TestFile.fail()) {
            break;
        }
        push(word);
    } while(!TestFile.eof());

     TestFile.close();

    while(!isEmpty()){
        cout << top() << " ";
        pop();
    }    cout << endl;
    return 0;
}
//push word on top of stack
void push(char word[]){
    point++;
    wordStack[point] = word;
}
//return to the top of the stack
string top(){
    return  wordStack[point];
}
//remove the word fromt he stack
    wordStack[point] = "";
    point--;
}//checks if stack is empty
bool isEmpty(){
    if(point < 0){
        return true;
    }
    return false;
}
