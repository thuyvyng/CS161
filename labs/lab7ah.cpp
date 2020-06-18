#include <iostream>

using namespace std;

//returning the address of the new int
int* changeVal(){
    return new int;
}

//passing the pointer by pointer
void changePtr(int **x){
    *x = new int;
}

//passing the pointer by reference
void changeRef(int *&x){
    x = new int;
}

void setVal(int *x){
    *x = 5;
}

//deleting the pointer, in order to set back to NULL properly
//it must by passed by pointer (or reference)
void deletePtr(int **x){
    delete *x;
    *x = NULL;
}

int main(){

    int *x;

    x = changeVal();
    setVal(x);
    deletePtr(&x);

    changePtr(&x);
    setVal(x);
    deletePtr(&x);

    changeRef(x);
    setVal(x);
    deletePtr(&x);

}
