//
// Created by Денис on 08.09.2017.
//
#include "heders.h"

Books::Books (char *name_book, int num_page_book, int amount_book) //Конструктор с указателем
{
    name = new char[strlen(name_book)+1];
    strcpy(name, name_book);
    num_page = num_page_book;
    amount = amount_book;
}
Books::Books() //конструктор по умолчанию
{
    char startname[] = "";
    name = new char[strlen(startname)+1];
    name = strcpy(name, startname);
    num_page = 0;
    amount = 0;
}
Books::Books(const char name_book[], int num_page_book, int amount_book) //Конструктор с константной строкой
{
    name = new char[sizeof(name_book)+1];
    name = strcpy(name, reinterpret_cast<const char *>(name_book));
    num_page = num_page_book;
    amount = amount_book;
}
Books::Books(const Books &book) //Конструктор копирования
{
    name = new char[strlen(book.name)+1];
    name = strcpy(name, book.name);
    num_page = book.num_page;
    amount = book.amount;
}
Books Books::operator + (Books books)
{
    Books myBook;
    myBook.name = new char[strlen(this->name) + strlen(books.name) + 1]; // выделяем память
    strcpy(myBook.name, this->name);
    strcat(myBook.name, "+");
    strcat(myBook.name, books.name);
    myBook.amount=this->amount + books.amount;
    myBook.num_page=this->num_page + books.num_page;
    return myBook;
}

Books & Books::operator=(Books &books){
    if (&books == this) return *this;//Проверка на самоприсваивание
    if (name) delete [] name; //Очищаем память
    if (books.name)
    {
        name = new char[strlen(books.name) + 1];
        strcpy(name, books.name);
    }
    else
    {
        name = 0;
    }
    num_page = books.num_page;
    amount = books.amount;
    return *this;
}

Books operator - (Books one, Books two)
{
    Books myBook;
    myBook.name = new char[strlen(one.name) + strlen(two.name) + 1]; // выделяем память
    strcpy(myBook.name, one.name);
    strcat(myBook.name, "-");
    strcat(myBook.name, two.name);
    myBook.amount = one.amount - two.amount;
    myBook.num_page = one.num_page - two.num_page;
    return  myBook;
}
Books & Books::operator++(int)
{
    amount++;
    return *this;
}
Books & Books::operator++()
{
    amount++;
    return *this;
}
Books::operator float()
{
    return amount;
}

void Books::print()
{
    cout<<name<<" "<<num_page<<" "<<amount<<endl;
}
void Books::setdata(char *name_book, int num_page_book, int amount_book)
{
    name = new char[strlen(name_book)+1];
    strcpy(name, name_book);
    num_page = num_page_book;
    amount = amount_book;
}
int Books::get_amount()
{
    return amount;
}
void Books::enterdata()
{
    delete name;
    char *a;
    a = new char[100];
    cout<<"Enter book name"<<endl;
    gets(a);
    name = new char[strlen(a)+1];
    strcpy(name, a);
    cout<<"Enter num_pages"<<endl;
    cin>>num_page;
    cout<<"Enter amount"<<endl;
    cin>>amount;
}

Books::~Books()
{
    delete[] name;
}



