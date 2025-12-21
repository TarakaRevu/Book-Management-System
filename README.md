# 📚 Book Management System (C++)

A console-based **Book Management System** built in C++ to practice real-world programming concepts step by step.

This project is developed incrementally from **basic C++** to more **advanced design concepts**.

---

---

## 🚀 Version 7 – Object-Oriented Design (Library System)

### 🔹 Overview
Version 7 focuses on **design improvement** rather than adding new features.

The application is refactored using **Object-Oriented Programming (OOP)** by introducing a central **Library** class that manages all books, operations, and file handling.

This makes the code more **structured, maintainable, and scalable**.

---

## 🧱 Key Improvements

### 🏛️ Library Class
- Introduced a **Library** class that represents the whole system
- The Library class:
  - Owns the book collection
  - Handles add, delete, update, search, and display
  - Manages file loading and saving

---

### 🔐 Encapsulation
- The book list is now **private** inside the Library class
- `main()` cannot directly access or modify book data
- All interactions happen through Library methods

---

### 🧠 Abstraction
- `main()` no longer knows how books are stored or processed
- It only calls high-level operations like:
  - Add book
  - Search book
  - Delete book

---

### 🎛️ Simplified Main Function
- `main()` is responsible only for:
  - Displaying the menu
  - Taking user input
  - Calling Library functions
- Business logic is fully removed from `main()`

---
## ✨ Features

### ➕ Add Book
Add a new book with:
- **Book ID**
- **Title**
- **Author**
- **Publication Year**
- **Number of Copies**

If a book with the same **ID already exists**:
- Copies are increased instead of creating a duplicate record

---

### 📚 Display Books
- Displays all books stored in memory
- Shows:
  - **ID | Title | Author | Year | Copies**

---

### 🔍 Search
- Search by **Book ID**
- Search by **Book Title**

---

### 🗑️ Delete Book (ID-based)
- If **copies > 1** → decreases copy count
- If **copies == 1** → removes the book completely

---

### ✏️ Update Book (ID-based)
Allows updating:
- **Title**
- **Author**
- **Publication Year**
- **Copies**

---

### 💾 Persistent Storage
- Books are loaded from file at program start
- All changes are saved back to file on exit
- File format:
