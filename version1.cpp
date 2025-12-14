#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

struct book {
        int ID;
        string Title;
        string Author;
        
    };

int main (){
    int n;
    vector<book> books;
    cout <<"enter the number of book's u want" << endl;
    cin >> n ;
    for ( int i = 0; i < n; i++){
        book b1;
        cin >> b1.ID;
        cin >> b1.Title;
        cin >> b1.Author;
        books.push_back(b1);
    }
    for(auto it: books){
        cout << it.ID << "|" 
        << it.Title << " " 
        << it.Author << endl;
    }


}