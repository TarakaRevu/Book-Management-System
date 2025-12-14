#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
    public:
        int ID;
        string Title;
        string Author;
        int year;
        
    };


vector<Book> books;
bool search(vector<Book>&books,int ID) {
    for(auto it: books){
        if( it.ID == ID) {
        return true;
        }
    }
    return false;
    
}
bool searcht(vector<Book>&books, string title) {
    for(auto it: books){
        if( it.Title == title) {
        return true;
        }
    }
    return false;
    
}
void display(vector<Book>&books){
    for(auto it: books){
        cout << it.ID << "|" 
        << it.Title << " " 
        << it.Author << endl;
    }
}

int main (){
    int n;
    cout <<"enter the number of book's u want" << endl;
    cin >> n ;
    for ( int i = 0; i < n; i++){
        Book b1;
        cin >> b1.ID;
        cin >> b1.Title;
        cin >> b1.Author;
        cin >> b1.year;
        books.push_back(b1);
    }
    display(books);
    bool sea = search(books,4);
    bool seat = searcht(books,"me");
    cout << "search " << sea <<endl;
    cout << "search " << seat <<endl;
    
    

}