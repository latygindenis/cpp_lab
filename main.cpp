#include <iostream>
#include "heders.h"

using namespace std;

int main() {

    char *a;
    a = const_cast<char *>("Const");
    Books myBook;
    Books myTest, myTest2;
    Books myBook1 ("Prestuplenie", 255, 10);
    Books myBook2 ("Dostoevsky", 1000, 2577);
    Books myBook3("Nakazanie", 133, 57);
    myBook.print();
    myBook1.print();
    myBook2.print();
    myBook3.print();
    cout<<endl;

    cout<<"(myBook1 + myBook3)"<<endl;
    (myBook1 + myBook3).print(); //сумма тиража, сумма кол-ва строк
    cout<<endl;

    cout<<"(myBook1 = myBook3)"<<endl; //присваивание
    (myBook1 = myBook3).print();
    cout<<endl;

    cout<<"(myBook3 - myBook2)"<<endl;
    (myBook3 - myBook2).print(); //разность тиража, разность кол-ва строк
    cout<<endl;

    cout<<"(++myBook3) and (myBook3++)"<<endl;
    myTest = (++myBook3);
    cout<<myTest.get_amount()<<" "<<myBook3.get_amount()<<endl;
    myTest2 = (myBook3++);
    cout<<myTest.get_amount()<<" "<<myBook3.get_amount()<<endl;
    cout<<endl;
    cout<<"float(myBook3)"<<endl;
    cout<<float(myBook3)<<endl;

    return 0;
}