/*Imagine a publishing company which does marketing for book
and audio cassette versions. Create a class publication that
stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count
(type int) and tape which adds a playing time in minutes
(type float). Write a program that instantiates the book
and tape class, allows user to enter data and displays the
data members. If an exception is caught, replace all the
data member values with zero values.*/
#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string name;
    float price;
};


class Book : private Publication
{
    int pages;
public:
    void read();
    void display();
};

void Book::read()
{
    try
    {
        cout << "Enter Name Of Book:" << endl;
        getline(cin, name);
        if (name.length() < 3)
        {
            throw name;
        }
        cout << "Enter Price Of Book" << endl;
        cin >> price;
        if (price <= 0)
        {
            throw price;
        }
        cout << "Enter No of pages of " << name << " : " << endl;
        cin >> pages;
        if (pages <= 0)
        {
            throw pages;
        }
    }
    catch (string&)
    {
        name = "_____";
        price = 0.0;
        pages = 0.00;
    }
    catch (float)
    {
        name = "_____";
        price = 0.0;
        pages = 0.00;
    }

    catch (int)
    {
        name = "_____";
        price = 0.0;
        pages = 0;
    }
}

void Book::display()
{
    cout << "Name: " << name << endl;
    cout << "Price: " << price << "/- only" << endl;
    cout << "No of Pages In " << name << " Are : " << pages << endl;
}

class Tape : private Publication
{
    float minutes;
public:
    void read();
    void display();
};

void Tape::read()
{

    try
    {
        cout << "Enter Name Of Book:" << endl;
        cin.ignore();
        getline(cin, name);
        if (name.length() < 3)
        {
            throw name;
        }
        cout << "Enter Price Of Book: " << endl;
        cin >> price;
        if (price <= 0)
        {
            throw price;
        }
    }
    catch (string&)
    {
        name = "_____";
        price = 0.0;
        minutes = 0.00;
    }

    catch (float)
    {
        name = "_____";
        price = 0.0;
        minutes = 0.00;
    }

    try
    {
        cout << "Enter length of Audio Casette Of the Book " << name << " : " << endl;
        cin >> minutes;
        if (minutes <= 0)
        {
            throw minutes;
        }
    }
    catch (float)
    {
        name = "_____";
        price = 0.0;
        minutes = 0.00;
    }
}

void Tape::display()
{
    cout << "Name: " << name << endl;
    cout << "Price: " << price << "/- only" << endl;
    cout << "The Audio Casette is " << minutes << " minutes long." << endl;
}

int main()
{
    Book b;
    Tape t;
    b.read();
    b.display();
    t.read();
    t.display();
    return 0;
}
