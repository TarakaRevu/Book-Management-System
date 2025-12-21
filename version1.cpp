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
        int copies;
        
 };

 void addbooks(vector<Book> &books) {
    cout << "We are adding the books so please enter the details "<<endl;
    int id = intInput(" Enter the book ID :-");
     for (auto& it : books) {
        if (it.ID == id) {
            int extra = intInput("ID exists. Enter copies to add :- ");
            it.copies += extra;
            cout << "Copies updated successfully\n";
            return;
        }
    }
    Book b1;
    b1.ID = id;
    b1.Title = str( "Enter the book Title :-");
    b1.Author = str( "Enter the book Author :-");
    b1.year = intInput("Enter the book year :-");
    b1.copies = intInput(" Enter the number of copies :-");
    books.push_back(b1);

}

    void   search(vector<Book>&books) {
    int ID = intInput("Enter the book ID to search :-") ;
    cout << " Enter the book ID to search :-";
    for(auto &it: books){
        if( it.ID == ID) {
        
            cout << it.ID << "|" 
            << it.Title << " " 
            << it.Author << " "
            << it.year << " " 
            << it.copies << endl;
            return;
        }
        
    }
    cout << "BOOk Not found with that ID" << endl;
}

void searcht(vector<Book>&books) {
    string title = str("Enter the title to check the book :-");
    for(auto &it: books){
        if( it.Title == title) {
            cout << it.ID << "|" 
            << it.Title << " " 
            << it.Author << " " 
            << it.year << " " 
            << it.copies << endl;
            return;
        }
        
    }

    cout << "BOOk Not found with that title" << endl;
}
void display(vector<Book>&books){
    for(auto &it: books){
        cout << it.ID << "|" 
        << it.Title << " " 
        << it.Author << " "
        << it.year << " " 
        << it.copies << endl;
    }
}

void del(vector<Book>& books) {
    int ID = intInput("Enter the book ID to delete :-");

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->ID == ID) {
            if (it->copies > 1) {
                it->copies--;
                cout << "One copy removed. Remaining: "
                     << it->copies << endl;
            } else {
                books.erase(it);
                cout << "Book removed completely\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}

void update(vector<Book>&books){
    int ID = intInput("Enter the book ID to Update :-") ;
    for(auto &it: books){
        if(it.ID == ID){
            it.Title = str("Enter new title :-");
            it.Author = str("Enter new author :-");
            it.year = intInput("Enter new year :-");
            it.copies = intInput("Enter new copies :-");
            cout << "Book updated successfully\n";
            return;
            
        }
    }
    cout << "Book not found\n";

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

        size_t fourth = line.find(',', third + 1);
        if (fourth == string::npos) continue;

        b1.ID = stoi(line.substr(0, first));
        b1.Title = line.substr(first + 1, second - first - 1);
        b1.Author = line.substr(second + 1, third - second - 1);
        b1.year = stoi(line.substr(third + 1, fourth - third -1));
        b1.copies = stoi(line.substr(fourth + 1));

        books.push_back(b1);
           

        }
        file.close();
        return true;
    }

}
bool savemem(const string& filename, const vector<Book>& books) {
    ofstream file(filename,ios::out | ios::trunc );
    if (!file) {
        cout << "Failed to save data\n";
        return false;
    }


    for (const auto& b : books) {
        file << b.ID << ","
             << b.Title << ","
             << b.Author << ","
             << b.year << ","
             << b.copies << "\n";
    }
    return true;
}



int main (){
    vector<Book> books;
    loadmem("library.txt", books);
    while(true) {
        cout << "\n1. Add Book\n"
     << "2. Display Books\n"
     << "3. Search by ID\n"
     << "4. Search by Title\n"
     << "5. Delete by ID\n"
     << "6. Update by ID\n"
     << "7. Exit\n";

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
            del(books);
            break;
        case 6:
            update(books);
            break;
        case 7:
            savemem("library.txt", books);
            cout << "Exiting program\n";
            return 0;
            
        
        default:
            cout << " enter the correct option";
            break;
        }
      


    }
}
    
    
