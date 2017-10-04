//
// Created by Денис on 08.09.2017.
/*Постpоить класс для pаботы с книгами: название (динамическое выделение памяти),
количество страниц, тираж.
Класс должен обеспечивать пpостейшие функции
для pаботы с данными классами: изменение значений, вывод значений*/
//
#include <iostream>
#include <string.h>
using namespace std;

#ifndef CLIONPROGET_HEDERS_H
#define CLIONPROGET_HEDERS_H
class Books
{
    char *name;
    int num_page;
    int amount;
public:
    Books(char *name_book, int num_page_book, int amount_book);
    Books();
    Books(const Books &book);

    Books operator + (Books books);
    Books & operator = (Books &books);
    Books & operator ++ (int); //постфиксная форма
    Books & operator ++ (); //префиксная форма
    operator float();
    friend Books operator - (Books one, Books two);

    Books(const char name_book[], int num_page_book, int amount_book);
    int get_amount();
    void setdata(char *name_book, int num_page_book, int amount_book);
    void enterdata();
    void print();
    ~Books();
};

#endif //CLIONPROGET_HEDERS_H
