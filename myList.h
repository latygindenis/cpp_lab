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

        virtual ~elem();
    };
    elem *lstart, *lend;
    public:
        myList();
        void add(Books *d);
        void del();
        void print();
        void delbynumber(int number = 0);
};


#endif //CLIONPROGET_MYLIST_H
