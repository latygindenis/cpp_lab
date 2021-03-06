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
    try {
        name = new char[sizeof(name_book)+1];
        name = strcpy(name, reinterpret_cast<const char *>(name_book));
        if (num_page_book<0) throw 0;
        else { num_page = num_page_book;}
        if (amount_book<0) throw 1;
        else {   amount = amount_book;}
    }catch (int i)
    {
        if (i == 0) cout<<"Error value of num_page"<<endl;
        if (i == 1) cout<<"Error value of amount_book"<<endl;
    }


}


Books::Books(const Books &book) //Конструктор копирования
{
    name = new char[strlen(book.name)+1];
    strcpy(name, book.name);
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
Books  Books::operator++(int)
{
    Books myObj(*this);
    ++(*this);
    int x=1;
    ++x;
    return myObj;
}
Books & Books::operator++()
{
    this->amount++;
    return *this;
}
Books::operator float() const
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

ostream & operator << (ostream &os, Books &book) {
    os << book.name<<" "<<book.num_page<<" "<<book.amount;
    return os;

}
istream& operator >> (istream& is, Books &book)
{
    try
    {
        if (!is) throw 0;
        else
        {
            is >>book.name>>book.num_page>>book.amount;
            return is;
        }
    }catch (int i) {
        if (i == 0) {
            cout << "Empty .txt file" << endl;
        }
    }
}

char *Books::getName() const {
    return name;
}

int Books::getNum_page() const {
    return num_page;
}

void Books::write(ofstream &os) {
    os.write(name, strlen(name) + 1);
    os.write(reinterpret_cast<char *>(&num_page), sizeof(num_page));
    os.write(reinterpret_cast<char *>(&amount), sizeof(amount));
}

void Books::read(ifstream &is){
    try
    {
        if (!is) throw 0;
        else{
        char ch;
        int i=0;
        streampos s = is.tellg();
        while ((ch = is.get()) !='\0')
        {
            i++;
        }
        is.seekg(s);
        if (name != nullptr)
        {
            delete[] name;
        }
        name = new char[i + 1];
        is.read(name, i + 1);
        is.read(reinterpret_cast<char *>(&num_page), sizeof(num_page));
        is.read(reinterpret_cast<char *>(&amount), sizeof(amount));
        }
    }catch (int i)
    {
        cout<<"Empty .bin file"<<endl;
    }

}

char *Books::getdefinition() const {
    return 0;
}


AboutBook::AboutBook() : Books(){
    description = new char[strlen("")];
    description = strcpy(description, reinterpret_cast<const char *>(""));
}

AboutBook::AboutBook(const AboutBook &myAboutBook):Books(myAboutBook)
{
    description = new char[strlen(myAboutBook.description)+1];
    description = myAboutBook.description;
}

AboutBook::~AboutBook() {
    delete []description;
}
void AboutBook::print()
{
    cout<<description<<" ";
    Books::print();
}


AboutBook::AboutBook(const char *name_book, int num_page_book, int amount_book, const char *mydescription) : Books(name_book,
                                                                                                           num_page_book,
                                                                                                           amount_book){
    description = new char[strlen(mydescription) + 1];
    strcpy(description, mydescription);
}

char *AboutBook::getDescription() const {
    return description;
}

char *AboutBook::getdefinition() const {
    return description;
}

NumBook::NumBook(const char *name_book, int num_page_book, int amount_book, int myNumber) : Books(name_book, num_page_book,
                                                                                    amount_book) {
    number = myNumber;
}

void NumBook::print() {
    cout<<number<<" ";
    Books::print();
}

NumBook::NumBook() : Books() {
    number = 0;
}

NumBook::NumBook(const NumBook &myNumBook):Books(myNumBook)
{
    number = myNumBook.number;
}

char *NumBook::getdefinition() const {
    return 0;
}
