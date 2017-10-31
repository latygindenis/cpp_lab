//
// Created by Денис on 30.10.2017.
//

#include "myList.h"

myList::elem::elem(Books *d)  {
    next = prev = NULL;
    field = d;
}

myList::elem::~elem() {
    field = NULL;
    next = NULL;
    prev = NULL;
}


myList::myList() {
    lstart=lend=NULL;
}


void myList::add(Books *d) {
    elem *pv = new elem(d);

    if(lstart == NULL)
    {
        lstart = lend = pv;
        pv->next=pv;
        pv->prev=pv;
    }
    else
    {
        pv->prev = lend;
        pv->prev->next=pv;
        pv->next = lstart;
        lend = pv;
    }
}

void myList::print() {

    elem *pv;
    pv = lstart;
    if (lend == 0)
    {
        cout<<"Spisok pust"<<endl;
    }
    else
    {
        pv->field->print();
        pv=pv->next;
        while (pv != lstart)
        {
            pv->field->print();
            pv = pv->next;
        }
    }
}

void myList::del() {

    if (lstart == lend)
    {
        lend = lstart = 0;
    }
    else
    {
        lend->field = 0;
        lend->prev->next = lstart;
        lend = lend->prev;
    }
}

void myList::delbynumber(int number) {
    elem *pv = lstart;
    if (lstart == lend)
    {
        lend = lstart = 0;
    }
    else
    {
        for (int i = 0; i!=number; i++)
        {
            pv = pv->next;
        }
        if (pv == lstart)
        {
            lstart = pv->next;
            pv->prev->next = pv->next;
            pv->next->prev = pv->prev;
            lend->next = lstart;
            delete pv;
        }
        else
        {
            pv->prev->next = pv->next;
            pv->next->prev = pv->prev;
            delete pv;
        }
    }
}
