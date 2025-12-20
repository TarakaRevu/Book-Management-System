Version 4 – Book Management System (C++)
Overview

Version 4 adds file handling to the Book Management System.
Book data is now saved in a file so it is not lost when the program exits.
This version also improves input handling and program stability.

Features

Menu-driven console application

Add books and save them to a file (library.txt)

Display all books from the file

Search books by ID

Search books by title

Data persists between program runs

Safe input handling using getline and validation

Robust file parsing to avoid crashes

Clean program exit

Book Details Stored

Each book record contains:

Book ID

Title

Author

Publication Year

Concepts Used

File handling (ifstream, ofstream)

Input validation

String parsing with delimiters

Basic error handling

Foundation for RAII concepts

Summary

Version 4 moves the project from in-memory storage to file-based storage.
It makes the application more reliable and closer to a real-world program.
