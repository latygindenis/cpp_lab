//
// Created by Денис on 30.10.2017.
//

#ifndef CLIONPROGET_MYLIST_H
#define CLIONPROGET_MYLIST_H

#include "heders.h"
using namespace std;

class myList {
    class elem {
    public:
        Books *field; // поле данных
        elem *next; // указатель на следующий элемент
        elem *prev; // указатель на предыдущий элемент
        elem(Books *d);
    };
    elem *lstart, *lend;
public:
    myList();
    ~myList();
    void add(Books *d);//Добавить элемент в конец
    void del();//Удаление последнего элемента
    void print();
    void delbynumber(int number = 0);
    void addbynumber(int number, Books *d);
    void findbyname(const char name[]);
    void findbydescription(const char name[]);
};

#endif //CLIONPROGET_MYLIST_H
