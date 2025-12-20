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


void   search(vector<Book>&books) {
    int ID ;
    cout << " Enter the book ID to search :-";
    cin >> ID;
    cin.ignore();
    for(auto it: books){
        if( it.ID == ID) {
            cout << it.ID << "|" 
            << it.Title << " " 
            << it.Author << endl;
        }
    }

    
}
void searcht(vector<Book>&books) {
    string title;
    cout << "Enter the title to check the book :-";
    getline(cin,title);
    for(auto it: books){
        if( it.Title == title) {
            cout << it.ID << "|" 
            << it.Title << " " 
            << it.Author << endl;
            break;
        }
        
    }
    
}
void display(vector<Book>&books){
    for(auto it: books){
        cout << it.ID << "|" 
        << it.Title << " " 
        << it.Author << endl;
    }
}
void addbooks(vector<Book>&books) {
    cout << "We are adding the books so please enter the details "<<endl;
    Book b1;
    cout <<" Enter the book ID :-";
    cin >> b1.ID;
    cin.ignore();
    cout << "Enter the book Title :-";
    getline(cin,b1.Title);
    cout << "Enter the book Author :-";
    getline(cin,b1.Author);
    cout <<" Enter the book year :-";
    cin >> b1.year;
    cin.ignore();
    books.push_back(b1);

}

int main (){
    vector<Book> books;
    string input;
    while(true) {
        cout << " We are in loop now so u can do the tasks"<<endl;
        int num;
        cout << "Enter the case for the switch :-" << endl;
        cin>>num;
        cin.ignore();
        switch (num)
        {
        case 1:
            addbooks(books);
            break;
        case 2:
            display(books);
            break;
        case 3:
            search(books);
            break;
        case 4:
            searcht(books);
            break;
        case 5:
            cout << "Exiting program\n";
            return 0;
            
        
        default:
            cout << " enter the correct option";
            break;
        }
      


    }
}
    
    
