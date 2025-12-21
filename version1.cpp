#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
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
 class Issued{
    public:
        int bookID;
        int studentID;
        Issued(int b, int s) : bookID(b), studentID(s) {}
 };
 class Student{
    public:
        int sID;
        string name;
        string section;
        int year;
        Student() : sID(0), year(0) {}

        Student(int id, const string& n, const string& sec, int y)
        : sID(id), name(n), section(sec), year(y) {}
        
 };

class Library{
    private:
        vector<Book>books;
        vector<Student> st;
        vector<unique_ptr<Issued>> l;


    public:
        Library(){
            ifstream file("library.txt");
            if(!file){
                cout << " The file is not there" << endl;
            
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
            }
            ifstream sfile("students.txt");
            if (sfile) {
                string line;
                while (getline(sfile, line)) {
                    if (line.empty()) continue;

                    size_t p1 = line.find(',');
                    size_t p2 = line.find(',', p1 + 1);
                    size_t p3 = line.find(',', p2 + 1);

                    if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
                        continue;

                    Student s(
                        stoi(line.substr(0, p1)),
                        line.substr(p1 + 1, p2 - p1 - 1),
                        line.substr(p2 + 1, p3 - p2 - 1),
                        stoi(line.substr(p3 + 1))
                    );

                    st.push_back(s);
                }
            }


        }
            void del() {
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
        void addbooks() {
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
        void searcht() {
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

        void   search() {
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

        void display(){
            for(auto &it: books){
                cout << it.ID << "|" 
                << it.Title << " " 
                << it.Author << " "
                << it.year << " " 
                << it.copies << endl;
            }
        }
        

        void update(){
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
        void sdel() {
            int ID = intInput("Enter the student ID to delete :-");

            for (auto it = st.begin(); it != st.end(); ++it) {
                if (it->sID == ID) {
                    st.erase(it);
                    return;
                }
                
            }
            
            cout << "Student not found\n";
        }
        void sadd() {
            cout << "We are adding the student so please enter the details "<<endl;
            int id = intInput(" Enter the student ID :-");
            for (auto& it : st) {
                if (it.sID == id) {
                    cout << "Already added\n";
                    return;
                }
            }
            Student s1;
            s1.sID = id;
            s1.name = str( "Enter the student name :-");
            s1.section = str( "Enter the student sec :-");
            s1.year = intInput("Enter the student year :-");
            st.push_back(s1);
        }
        void taken(){
            int ID = intInput("Enter the book ID to Update :-") ;
            int sID = intInput("Enter the student ID to Update :-") ;
            for(auto &i:st){
                if(i.sID == sID){
                    for(auto &it : books){
                        if(it.ID == ID){
                            if(it.copies>=1){
                                it.copies--;
                                l.push_back(make_unique<Issued>(ID, sID));
                                cout << " You have taken  a book\n";
                                return;
                            }else{
                                cout << "There is no copies present" <<endl;
                                return;
                            }
                            
                        }
                    }
                    cout << "The book ID is not present\n";

                }
                }cout  << " The student ID is not present\n";
                return;
        }
        void sdisplay() {
            int sID = intInput("Enter the student ID :- ");
            for (const auto& s : st) {
                if (s.sID == sID) {
                    cout << "\nStudent Details:\n";
                    cout << "ID: " << s.sID << "\n"
                        << "Name: " << s.name << "\n"
                        << "Section: " << s.section << "\n"
                        << "Year: " << s.year << "\n";

                    int count = 0;
                    cout << "Books Taken: ";

                    for (const auto& issue : l) {
                        if (issue->studentID == sID) {
                            cout << issue->bookID << " ";
                            count++;
                        }
                    }

                    if (count == 0) {
                        cout << "None";
                    }

                    cout << "\nTotal Books Taken: " << count << "\n";
                    return;
                }
            }

            cout << "Student not found\n";
        }

            
            ~Library() {
            ofstream file("library.txt",ios::out | ios::trunc );
            if (!file) {
                cout << "Failed to save data\n";

            }
            for (const auto& b : books) {
                file << b.ID << ","
                    << b.Title << ","
                    << b.Author << ","
                    << b.year << ","
                    << b.copies << "\n";
            }
            ofstream sfile("students.txt", ios::trunc);
            if (sfile) {
            for (const auto& s : st) {
                sfile << s.sID << ","
                        << s.name << ","
                        << s.section << ","
                        << s.year << "\n";
            }
            }

            
        }

};





int main () {
    Library lib;

    while (true) {
        cout << "\n===== Library Management System =====\n"
             << "1. Add Book\n"
             << "2. Display Books\n"
             << "3. Search Book by ID\n"
             << "4. Search Book by Title\n"
             << "5. Update Book\n"
             << "6. Delete Book\n"
             << "-----------------------------------\n"
             << "7. Add Student\n"
             << "8. Delete Student\n"
             << "-----------------------------------\n"
             << "9. Issue Book to Student\n"
             << "10. DISPLAY student taken books\n"
             << "11. Exit\n";


        int num = intInput("Enter your choice :- ");

        switch (num) {
        case 1:
            lib.addbooks();
            break;

        case 2:
            lib.display();
            break;

        case 3:
            lib.search();
            break;

        case 4:
            lib.searcht();
            break;

        case 5:
            lib.update();
            break;

        case 6:
            lib.del();
            break;

        case 7:
            lib.sadd();
            break;

        case 8:
            lib.sdel();
            break;

        case 9:
            lib.taken();
            break;
        case 10:
            lib.sdisplay();
            break;

        case 11:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}
