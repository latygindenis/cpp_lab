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

void myList::addbynumber(int number, Books *d) {

    elem *pv = new elem(d);
    elem *old = lstart;

    for (int i = 0; i!=number; i++)
    {
        old = old->next;
    }
    if (old == lstart)
    {
        lstart = pv;
        pv->next = old;
        pv->prev = lend;
        old->prev = pv;
        lend->next = pv;
    }
    else
    {
        pv->prev = old->prev;
        pv->next = old;
        old->prev->next = pv;
        old->prev = pv;
    }
}

void myList::findbyname(const char name[]) {
    elem *pv = lstart;
    bool check = 0;
    if (!strcmp(name,pv->field->getName()))
    {
        pv->field->print();
        check = 1;
    }
    pv=pv->next;

    while (pv != lstart)
    {
        if (!strcmp(name,pv->field->getName() ))
        {
            pv->field->print();
            check = 1;
        }
        pv=pv->next;
    }
    if (!check)
    {

        cout<<"Nothing found"<<endl;
    }
}

void myList::findbydescription(const char name[]) {

    elem *pv = lstart;
    bool check = 0;
if (pv->field->getdefinition() && !strcmp(pv->field->getdefinition(), name))
{
    pv->field->print();
    check = 1;
}
    pv=pv->next;
    while (pv != lstart)
    {
        if (pv->field->getdefinition() && !strcmp(pv->field->getdefinition(), name))
        {
            pv->field->print();
            check = 1;
        }
        pv=pv->next;
    }
    if (!check)
    {
        cout<<"Nothing found"<<endl;
    }
}

myList::~myList() {
    elem *pv;
    while (lstart != lend)
    {
        pv = lstart;
        lstart = pv->next;
        delete pv;
    }
    delete lstart;
}