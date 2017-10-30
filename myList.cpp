//
// Created by Денис on 30.10.2017.
//

#include "myList.h"

myList::elem::elem(Books *d)  {
    next = prev = NULL;
    field = d;
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
    pv->field->print();
    pv=pv->next;
    while (pv != lstart)
    {
        pv->field->print();
        pv = pv->next;
    }
}
