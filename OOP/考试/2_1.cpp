#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
    string title, ISBN;
    vector<string> author;

public:
    Book();
    Book(const string &title, const string &ISBN);
    void addAuthor(const string &author);
    void setTitle(const string &title);
    void setISBN(const string &ISBN);
    string getTitle() const;
    string getISBN() const;
};