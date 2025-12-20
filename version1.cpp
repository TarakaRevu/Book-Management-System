#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;




int intInput(const string& msg){
    while (true) {
        cout << msg;
        string input;
        getline(cin, input);
        try {
            return stoi(input);
        } catch (...) {
            cout << "Invalid number. Try again.\n";
        }
    }

}

string str(const string& msg){
    cout << msg;
    string input;
    getline(cin,input);
    return input;
}

class Book {
    public:
        int ID;
        string Title;
        string Author;
        int year;
        
    };

    void   search(vector<Book>&books) {
    int ID = intInput("Enter the book ID to search :-") ;
    cout << " Enter the book ID to search :-";
    for(auto &it: books){
        if( it.ID == ID) {
        
            cout << it.ID << "|" 
            << it.Title << " " 
            << it.Author << endl;
            return;
        }
        
    }
    cout << "BOOk Not found with that ID" << endl;
}

void searcht(vector<Book>&books) {
    string title;
    cout << "Enter the title to check the book :-";
    getline(cin,title);
    for(auto &it: books){
        if( it.Title == title) {
            cout << it.ID << "|" 
            << it.Title << " " 
            << it.Author << endl;
            return;
        }
        
    }

    cout << "BOOk Not found with that title" << endl;
}
void display(vector<Book>&books){
    for(auto &it: books){
        cout << it.ID << "|" 
        << it.Title << " " 
        << it.Author << endl;
    }
}
void addbooks(vector<Book> &books) {
    cout << "We are adding the books so please enter the details "<<endl;
    Book b1;
    b1.ID = intInput(" Enter the book ID :-");
    b1.Title = str( "Enter the book Title :-");
    b1.Author = str( "Enter the book Author :-");
    b1.year = intInput("Enter the book year :-");
    books.push_back(b1);

}
bool loadmem(const string& filename,vector<Book> &books){
    ifstream file(filename);
    if(!file){
        return false;
    }else{
       string line;
        while(getline(file,line)){
            if (line.empty()) continue;

        Book b1;

        size_t first = line.find(',');
        if (first == string::npos) continue;

        size_t second = line.find(',', first + 1);
        if (second == string::npos) continue;

        size_t third = line.find(',', second + 1);
        if (third == string::npos) continue;

        b1.ID = stoi(line.substr(0, first));
        b1.Title = line.substr(first + 1, second - first - 1);
        b1.Author = line.substr(second + 1, third - second - 1);
        b1.year = stoi(line.substr(third + 1));

        books.push_back(b1);
           

        }
        file.close();
        return true;
    }

}

int main (){
    vector<Book> books;
    bool ans = loadmem("library.txt",books);
    while(true) {
        cout << "\n1. Add Book\n2. Display Books\n3. Search by ID\n4. Search by Title\n5. Exit\n";
        int num = intInput("Enter the case for the switch :-");
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
    
    
