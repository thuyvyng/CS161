#include <iostream>

using namespace std;

// Dynamic memory is allocated using operator new. new is followed by a data type specifier and, 
// if a sequence of more than one element is required, the number of these within brackets []. 
// It returns a pointer to the beginning of the new block of memory allocated. Its syntax is:

// allocate memory to contain one single element of type type
// pointer = new type

// allocate a block (an array) of elements of type type, where number_of_elements is an integer value
// pointer = new type [number_of_elements]

//passing the pointer by pointer
/*******************************************************/
void changePtrVal(int **DataLoc, int numLen){
    int n;
    int loc;
    int val;

    cout << "You have following in Memory: " << endl;

    for (n=0; n<numLen-1; n++)
       cout << n << ":" << *(*DataLoc+n) << ", ";
    cout << n << ":" << *(*DataLoc+n) << endl;

    cout << "Which pointer location you want to change? ";
    cin >> loc;
    cout << "what value you want in pointer location? ";
    cin >> val;

    *(*DataLoc+loc) = val;

    cout << "You currently have following in Memory: " << endl;
    for (n=0; n<numLen-1; n++)
       cout << n << ":" << *(*DataLoc+n) << ", ";
    cout << n << ":" << *(*DataLoc+n) << endl;
}

//passing the pointer by reference
/*******************************************************/
void changePtrLoc(int *&DataLoc, int numLen){
    int n;
    int loc;
    int val;

    int *newLoc;
    newLoc = new (nothrow) int[numLen];

    cout << "You have following in Memory: " << endl;
    for (n=0; n<numLen-1; n++)
       cout << n << ":" << *(DataLoc+n) << ", ";
    cout << n << ":" << *(DataLoc+n) << endl;

    for (n=0; n<numLen; n++)
       *(newLoc+n) = *(DataLoc+n);

    cout << "You have following in new Memory: " << endl;
    for (n=0; n<numLen-1; n++)
       cout << n << ":" << *(newLoc+n) << ", ";
    cout << n << ":" << *(newLoc+n) << endl;

    delete[] newLoc;
    newLoc = NULL;
}

/*******************************************************/
void setVal(int *DataLoc, int numLen){
    int n;

    if (DataLoc == NULL)
       cout << "Error: memory could not be allocated";
    else {
       for (n=0; n<numLen; n++) {
           cout << "Enter number for location " << n+1 << ": ";
           cin >> DataLoc[n];
       }
    }

    cout << "You have entered: ";
    for (n=0; n<numLen-1; n++)
       cout << DataLoc[n] << ", ";
    cout << DataLoc[n] << endl;
}

/*******************************************************/
void changeVal(int *DataLoc, int numLen){
    int n;
    int loc;
    int val;

    cout << "You have following in Memory: " << endl;
    for (n=0; n<numLen-1; n++)
       cout << n << ":" << DataLoc[n] << ", ";
    cout << n << ":" << DataLoc[n] << endl;

    cout << "Which location you want to change? ";
    cin >> loc;
    cout << "what value you want in location? ";
    cin >> val;

    DataLoc[loc] = val;

    cout << "You currently have following in Memory: " << endl;
    for (n=0; n<numLen-1; n++)
       cout << n << ":" << DataLoc[n] << ", ";
    cout << n << ":" << DataLoc[n] << endl;
}

/*******************************************************/
//deleting the pointer, in order to set back to NULL properly
//it must by passed by pointer (or reference)
/*******************************************************/
void deletePtr(int **x){
    delete[] *x;
    *x = NULL;
}

/*******************************************************/
int main(){

    int n;
    int Len;
    int *Loc;
    string ans;

    cout << "Do you want to set numbers (yes/no) ? ";
    cin >> ans;
    if (ans == "yes") {
        cout << "How many numbers would you like to set? ";
        cin >> Len;
        Loc = new (nothrow) int[Len];
        setVal(Loc, Len);

        cout << "Do you want to change numbers by Location (yes/no) ? ";
        cin >> ans;
        if (ans == "yes") {
            changeVal(Loc, Len);
        }

        cout << "Do you want to change numbers by Pointer (yes/no) ? ";
        cin >> ans;
        if (ans == "yes") {
            changePtrVal(&Loc, Len);
        }

        cout << "Do you want to change Pointer Location (yes/no) ? ";
        cin >> ans;
        if (ans == "yes") {
            changePtrLoc(Loc, Len);
        }

        deletePtr(&Loc);
     
/*
        cout << "You currently have following in Memory: " << endl;
        for (n=0; n<Len-1; n++)
            cout << n << ":" << Loc[n] << ", ";
        cout << n << ":" << Loc[n] << endl;

//or

        for (n=0; n<Len-1; n++)
           cout << n << ":" << *(Loc+n) << ", ";
        cout << n << ":" << *(Loc+n) << endl;
*/

    }

/*
    x = changeVal();
    setVal(x);
    deletePtr(&x);

    changePtr(&x);
    setVal(x);
    deletePtr(&x);

    changeRef(x);
    setVal(x);
    deletePtr(&x);
*/

}
