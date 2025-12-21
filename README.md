# 📚 Book Management System (C++)

A console-based **Book Management System** built in C++ to practice real-world programming concepts step by step.

This project is developed incrementally from **basic C++** to more **advanced design concepts**.

---

## 🚀 Version 6 – Full CRUD with Copies Management

### 🔹 Overview
Version 6 completes the core functionality of the application by adding **Delete** and **Update** operations and introducing **copies management** for each book.

The system now behaves like a **real library or inventory application**.

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
