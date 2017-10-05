#include "heders.h"

using namespace std;

int main() {
/*-------Запись и чтение из текстового------------*/
    Books myInputBook("Test_name", 144, 78);
    ofstream f("out.txt"); //Открытие файла для записи
    if (!f){
        cout << "Ошибка открытия файла";
        return 1;
    }
    f << myInputBook;
    f.close();
    cout<<myInputBook<<endl;

    Books myOutputBook;
    ifstream input("out.txt"); // Открытие файла для чтения
    input >> myOutputBook;
    input.close();
    cout << myOutputBook <<endl;
    cout<<endl;
/*------Запись и чтение из бинарного------------*/

    Books myBin("Hep", 111, 50), myBintest;
    ofstream input_bin("out.bin", std::ios_base::binary);  //Запись в бинарный
    myBin.write(input_bin);
    input_bin.close();

    ifstream output_bin("out.bin", std::ios_base::binary);
    myBintest.read(output_bin);  //Чтение из бинарный
    output_bin.close();
    cout<<myBintest<<endl;

/*--------------------------------------------*/
    Books myBook;
    Books myTest, myTest2;
    Books myBook1 ("Prestuplenie", 255, 15);
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
    cout<<(float)myBook3<<endl;
    return 0;
}