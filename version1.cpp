#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addbooks(const string& filename);
void display(const string& filename);
void search(const string& filename);
void searcht(const string& filename);


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


void   search(const string& filename) {
    ifstream file(filename);
    if(!file){
        cout << "There is no file we can't do the search operation";
        return;
    }else{
        string line;
        int ID = intInput("Enter the Id to search:-");
        while(getline(file,line)){
            size_t pos = line.find(',');
            if (pos == string::npos) continue;
            int fileID = stoi(line.substr(0, pos));
            if (fileID == ID){
            cout << "Book found: " << line << endl;
            return;
            }


        }
        cout << "with that ID i can't find a book";
    }
    
    
}
void searcht(const string& filename) {
    
    ifstream file(filename);
    if(!file){
        cout << "File not found. Please add books first.\n";
        return;
    }
    else{
        string title =   str("Enter the title to check the book :-");
        string line;
        while(getline(file,line)){
            size_t first = line.find(',');
            if (first == string::npos) continue;
            size_t second = line.find(',', first + 1);
            if (second == string::npos) continue;
            string extractedTitle = line.substr(first + 1, second - first - 1);
            if(extractedTitle == title){
                cout << line <<endl;
                return;
            }

        }
    }
    cout << "BOOk Not found with that title" << endl;
    
}
void display(const string& filename){
    ifstream file(filename);
    if(!file){
        cout << "There is no file we can't do the dispaly operation";
        return;
    }else{
        string line;
        while(getline(file,line)){
            cout << line <<endl;
        }

    }
}
void addbooks(const string& filename) {
    cout << "We are adding the books so please enter the details "<<endl;
    ofstream file(filename, ios::app);
    Book b1;
    b1.ID = intInput(" Enter the book ID :-");
    b1.Title = str( "Enter the book Title :-");
    b1.Author = str( "Enter the book Author :-");
    b1.year = intInput("Enter the book year :-");
    file << b1.ID <<","
        << b1.Title <<","
        << b1.Author <<","
        << b1.year <<endl;

}

int main (){
    string input;
    while(true) {
        cout << "\n1. Add Book\n2. Display Books\n3. Search by ID\n4. Search by Title\n5. Exit\n";
        int num = intInput("Enter the case for the switch :-");
        switch (num)
        {
        case 1:
            addbooks("library.txt");
            break;
        case 2:
            display("library.txt");
            break;
        case 3:
            search("library.txt");
            break;
        case 4:
            searcht("library.txt");
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
    
    
