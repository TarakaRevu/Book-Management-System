# 📚 **LIBRARY MANAGEMENT SYSTEM (C++)**

**A console-based Library Management System built in C++, designed to practice modern C++ concepts through a real-world style project.**

**This project evolves from basic C++ to a fully object-oriented system using RAII, STL, and smart pointers.**

---

## 🚀 **VERSION 8 – FINAL (RAII, SMART POINTERS & STUDENTS)**

### 🔹 **OVERVIEW**

**Version 8 is the final version of the project.**

**It introduces student management, a book issuing system, RAII-based persistence, smart pointer ownership, and clean OOP architecture.**

**The application now behaves like a real library system, not just a sample program.**

---

## ✨ **FEATURES**

### 📘 **BOOK MANAGEMENT**

**Add books with:**
- **Book ID**
- **Title**
- **Author**
- **Publication Year**
- **Number of Copies**

**Update book details.**

**Delete books:**
- **Decreases copy count**
- **Removes book when copies reach zero**

**Search books:**
- **By ID**
- **By Title**

**Display all books.**

---

### 👨‍🎓 **STUDENT MANAGEMENT**

**Add students with:**
- **Student ID**
- **Name**
- **Section**
- **Year**

**Delete students.**

**Display student details.**

**View how many books a student has taken.**

---

### 📖 **BOOK ISSUING SYSTEM**

**Issue books to students.**

**Automatically reduces available copies.**

**Tracks issued books using `std::unique_ptr`.**

**Safely models Book ↔ Student relationships.**

**Prevents memory leaks and ownership issues.**

---

### 💾 **PERSISTENT STORAGE (RAII)**

**All data is handled automatically using RAII.**

| **DATA TYPE** | **FILE** |
|--------------|----------|
| **Books** | **library.txt** |
| **Students** | **students.txt** |
| **Issued Records** | **In-memory (extendable)** |

**Data is loaded in the Library constructor.**

**Data is saved in the Library destructor.**

**Main never handles file I/O directly.**

---

## 🧠 **CONCEPTS USED**

### **CORE C++**
- **Functions and control flow**
- **Input validation**
- **File handling (ifstream, ofstream)**

### **OBJECT-ORIENTED PROGRAMMING**
- **Classes and encapsulation**
- **Constructors and destructors**
- **Clear separation of responsibilities**

### **STL**
- **vector**
- **Iterators**
- **Algorithms**
- **emplace_back**

### **RAII**
- **Resource ownership through object lifetime**
- **Automatic loading and saving**
- **No manual cleanup**

### **SMART POINTERS**
- **std::unique_ptr**
- **Safe dynamic memory usage**
- **Clear ownership semantics**

---

## 🏁 **PROJECT STATUS**

✅ **COMPLETED – VERSION 8 (FINAL)**

**This version represents a complete, modern C++ learning project with real-world design practices.**

---

> **OOP • STL • RAII • SMART POINTERS • FILE PERSISTENCE • SYSTEM DESIGN**

**This is not beginner-level code and reflects solid intermediate C++ skills.**
