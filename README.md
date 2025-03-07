# 🌳 DSDB - Tree-Based Indexing System  

A **lightweight database system (DSDB)** that stores structured data using **B-Trees, AVL Trees, and Red-Black Trees** for indexing. The system supports **efficient search, update, delete, and range queries** for large datasets stored in multiple files.

---

## 📌 Features  

✅ **Supports B-Tree, AVL Tree, and Red-Black Tree Indexing**  
✅ **Efficient Data Retrieval and Modification**  
✅ **Handles Duplicate Entries with Linked Lists**  
✅ **Range-Based Searching**  
✅ **File-Based Data Storage and Indexing**  
✅ **CLI-Based User Interaction**  

---

## 🏛 Project Overview  

DSDB is designed to efficiently store, retrieve, and manage **structured data** stored in text files. It indexes data fields (such as ID, Year, State, Deaths, etc.) using **three different tree-based indexing structures**:

- **AVL Tree** 🟢 - Self-balancing binary search tree for quick lookups  
- **Red-Black Tree** 🔴⚫ - Balanced binary search tree ensuring fast insertions & deletions  
- **B-Tree** 📂 - Optimized for disk-based storage with large datasets  

The dataset used in DSDB consists of **leading causes of death in different U.S. states**, stored across multiple files.

---

## 🚀 How to Run  

### **1️⃣ Compile the Program**  
Use the following command to compile the DSDB system:  
g++ -o dsdb Menu.cpp AVLTree.h BTree.h RBTree.h -std=c++11
### 2️⃣ Run the System
./dsdb
### 3️⃣ Select a Tree-Based Indexing System
Once the program starts, select the indexing system:
1. AVL Tree
2. Red-Black Tree
3. B-Tree
### 4️⃣ Perform Data Operations
You can insert, search, update, delete, and perform range queries using indexed fields.

---

## 📜 Supported Operations
🟢 Create Index - Choose tree type & indexing field
🔍 Search Data - Find entries using key-based lookup
📊 Range Search - Retrieve records within a range
✏️ Update Data - Modify existing record fields
❌ Delete Record - Remove specific records

---

## 🛠 Technologies Used
Programming Language: C++
Data Structures: B-Trees, AVL Trees, Red-Black Trees
File Handling: Indexed Storage on Disk
CLI-Based Interface: Interactive Menu for User Input

---

## 📌 Future Enhancements
✅ Implement Multi-Level Indexing for faster retrieval
✅ Optimize Memory Management for large-scale datasets
✅ Add Graphical User Interface (GUI) for better interaction
✅ Extend Support for Dynamic File Imports

---

## 🤝 Contribution
🚀 Want to contribute? Fork the repository and submit pull requests!

---
