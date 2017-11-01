#include "heders.h"
#include "myList.h"
using namespace std;

int main() {
///*-------Запись и чтение из текстового------------*/
//    Books myBin("Help", 111789, 50), myBintest;
//    ofstream f("out.txt"); //Открытие файла для записи
//    if (!f){
//        cout << "Ошибка открытия файла";
//        return 1;
//    }
//    f << myBin;
//    f.close();
//    cout<<myBin<<endl;
//
//    Books myOutputBook;
//    ifstream input("out.txt"); // Открытие файла для чтения
//    input >> myOutputBook;
//    input.close();
//    cout << myOutputBook <<endl;
//    cout<<endl;
///*------Запись и чтение из бинарного------------*/
//
//    ofstream input_bin("out.bin", std::ios_base::binary);  //Запись в бинарный
//    myBin.write(input_bin);
//    input_bin.close();
//
//    ifstream output_bin("out.bin", std::ios_base::binary);
//    myBintest.read(output_bin);  //Чтение из бинарный
//    output_bin.close();
//    cout<<myBintest<<endl;
//
///*-----------Работа с перешруженными операторами--------------------------------*/
//    Books myBook;
//    Books myTest, myTest2;
//    Books myBook1 ("Prestuplenie", 255, 15);
//    Books myBook2 ("Dostoevsky", 1000, 2577);
//    Books myBook3("Nakazanie", 133, 57);
//    myBook.print();
//    myBook1.print();
//    myBook2.print();
//    myBook3.print();
//    cout<<endl;
//
//    cout<<"(myBook1 + myBook3)"<<endl;
//    (myBook1 + myBook3).print(); //сумма тиража, сумма кол-ва строк
//    (myBook1.operator+(myBook3)).print();
//    cout<<endl;
//
//    cout<<"(myBook1 = myBook3)"<<endl; //присваивание
//    (myBook1 = myBook3).print();
//    cout<<endl;
//
//    cout<<"(myBook3 - myBook2)"<<endl;
//    (myBook3 - myBook2).print(); //разность тиража, разность кол-ва строк
//    cout<<endl;
//
//    cout<<"(++myBook3) and (myBook3++)"<<endl;
//
//    cout<<myBook3++<<endl;
//    cout<<myBook3<<endl;
//
//    cout<<myTest.get_amount()<<" "<<myBook3.get_amount()<<endl;
//    cout<<myBook3++<<endl;
//    cout<<endl;
//
//
//
//    cout<<"float(myBook3)"<<endl;
//    cout<<(float)myBook3<<endl;
/*-----------Демонстрация наследования--------------------------------*/


    NumBook myNumBook("Dostevsky", 975, 784, 71);
    AboutBook myAboutBook("Joo", 145, 325, "Kolly");
    Books myMainBook("Dostevsky", 975, 784);

    myList testlist;
    testlist.add(&myMainBook);
    testlist.add(&myAboutBook);
    testlist.add(&myNumBook);
    testlist.add(&myAboutBook);
    testlist.print();
    cout<<endl;
    testlist.findbyname("Joo");
    cout<<endl;
    testlist.findbydescription("Kolly");
    return 0;
}