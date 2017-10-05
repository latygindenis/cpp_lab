//
// Created by Денис on 08.09.2017.
/*Постpоить класс для pаботы с книгами: название (динамическое выделение памяти),
количество страниц, тираж.
Класс должен обеспечивать пpостейшие функции
для pаботы с данными классами: изменение значений, вывод значений*/
//
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#ifndef CLIONPROGET_HEDERS_H
#define CLIONPROGET_HEDERS_H
class Books
{
    char *name;
    int num_page;
    int amount;
public:
    /*-------------------Конструкторы------------------------*/
    Books(char *name_book, int num_page_book, int amount_book);
    Books(const char name_book[], int num_page_book, int amount_book);
    Books(const Books &book);
    Books();

    /*-------------------Перегруженные операторы-------------*/
    Books operator + (Books books);
    Books & operator = (Books &books);
    Books & operator ++ (int); //постфиксная форма
    Books & operator ++ (); //префиксная форма
    operator float() const;
    friend Books operator - (Books one, Books two);
    friend ostream& operator << (ostream& os, Books &book);
    friend istream& operator >> (istream& is, Books &book);

    /*-------------------Методы-----------------------------*/
    void write(ofstream &os);
    void read(ifstream &is);
    int get_amount(); // геттер amount
    int getNum_page() const;
    char *getName() const;
    void setdata(char *name_book, int num_page_book, int amount_book);
    void enterdata();
    void print();
    ~Books();
};

#endif //CLIONPROGET_HEDERS_H
