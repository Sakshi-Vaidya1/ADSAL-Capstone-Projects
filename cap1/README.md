# Phonebook Management System in C++

## 📌 Project Overview

The **Phonebook Management System** is a console-based application developed using C++. It allows users to manage contact information, including names and phone numbers. The system provides features to add, display, search, delete, update, and sort contacts.

It uses **Merge Sort** and **Binary Search**, which are based on the Divide and Conquer technique, to sort contacts alphabetically and search for contacts efficiently. The application also uses file handling to store contact information permanently in a text file.

## 🎯 Objectives

- To create a simple and user-friendly phonebook management system.
- To perform basic contact management operations.
- To implement the Divide and Conquer technique using Merge Sort and Binary Search.
- To store and retrieve contact information using file handling.
- To improve searching and sorting efficiency.

## ✨ Features

1. **Add Contact:** Add a new contact with a name and phone number.
2. **Display All Contacts:** Display all saved contacts in a formatted table.
3. **Search Contact:** Search for a contact by name using Binary Search.
4. **Delete Contact:** Delete an existing contact by name.
5. **Update Contact:** Update the name or phone number of an existing contact.
6. **Sort Contacts:** Sort contacts alphabetically using Merge Sort.
7. **Save Contacts:** Save contact information to a text file.
8. **Load Contacts:** Load previously saved contacts from a text file.
9. **Automatic File Handling:** Save changes after adding, updating, deleting, or sorting contacts.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Algorithms:** Merge Sort and Binary Search
- **Data Structure:** Vector
- **File Handling:** `ifstream` and `ofstream`
- **Libraries:** `iostream`, `fstream`, `string`, `vector`, `algorithm`, and `iomanip`

## 🧠 Algorithms Used

### 1. Merge Sort

Merge Sort is a Divide and Conquer sorting algorithm that arranges contacts alphabetically by name.

**Working:**
1. Divide the list of contacts into two halves.
2. Recursively sort each half.
3. Merge the sorted halves into one sorted list.

**Time Complexity:**
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

### 2. Binary Search

Binary Search is used to find a contact by name. Before searching, the contacts are sorted alphabetically using Merge Sort.

**Working:**
1. Find the middle contact in the sorted list.
2. Compare its name with the search name.
3. If the names match, return the contact's position.
4. If the search name is smaller, search the left half.
5. Otherwise, search the right half.
6. Repeat until the contact is found or the search range becomes empty.

**Time Complexity:**
- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(log n)

**Note:** Since the program sorts the contacts before searching, the total search operation takes O(n log n) time in the worst case, including sorting.

## 📂 Project Structure

```text
Phonebook-Management-System/
│
├── phonebook.cpp
├── phonebook.txt
└── README.md
```

- `phonebook.cpp` — Contains the complete C++ source code.
- `phonebook.txt` — Stores contact information and is created when contacts are saved.
- `README.md` — Provides project documentation.

## ⚙️ Requirements

- A C++ compiler, such as GCC or MinGW.
- A code editor or IDE, such as Visual Studio Code, Code::Blocks, or Dev-C++.
- Basic knowledge of C++ programming.

## 🚀 How to Run the Project

### Step 1: Clone the Repository

```bash
git clone <your-repository-url>
```

### Step 2: Open the Project Folder

```bash
cd Phonebook-Management-System
```

### Step 3: Compile the Program

If you are using GCC, run:

```bash
g++ phonebook.cpp -o phonebook
```

### Step 4: Execute the Program

**On Windows:**

```bash
phonebook.exe
```

**On Linux/macOS:**

```bash
./phonebook
```

## 💻 Sample Output

```text
===== PHONEBOOK MANAGEMENT SYSTEM =====
1. Add Contact
2. Display All Contacts
3. Search Contact
4. Delete Contact
5. Update Contact
6. Sort Contacts
7. Save Contacts to File
8. Load Contacts from File
9. Exit
========================================
Enter your choice: 1

Enter name: Sakshi
Enter phone number: 9876543210

Contacts saved to file successfully!
Contact added successfully!
```

### Display Contacts

```text
Name                          Phone
---------------------------------------------------------------------------
Sakshi                        9876543210
```

### Search Contact

```text
Enter name to search: Sakshi

Contact Found!
Name: Sakshi
Phone: 9876543210
```

## 💾 File Storage

The system stores contacts in `phonebook.txt`. Each contact is stored on a separate line using the following format:

```text
Sakshi|9876543210|
Rahul|9876501234|
```

When the program starts, it attempts to load previously saved contacts from the file. Changes made to contacts can be saved so that the information remains available in subsequent executions.

## 📊 Complexity Analysis

Let `n` represent the number of contacts.

| Operation | Time Complexity |
|---|---|
| Add Contact | O(1) average |
| Display Contacts | O(n) |
| Search Contact, including sorting | O(n log n) |
| Delete Contact | O(n) |
| Update Contact | O(n) |
| Sort Contacts | O(n log n) |
| Save Contacts to File | O(n) |
| Load Contacts from File | O(n) |

*Note: File operations depend on the size of the stored data, and adding a contact to a vector can occasionally take O(n) time when reallocation occurs.*

## 🔮 Future Enhancements

- Add email addresses and other contact details.
- Validate phone numbers and prevent invalid entries.
- Prevent duplicate contacts.
- Support case-insensitive searching.
- Improve searching by retaining the sorted list between operations.
- Add a graphical user interface (GUI).
- Add password protection for contact privacy.

## 🎓 Learning Outcomes

Through this project, we learn how to:

- Implement Divide and Conquer algorithms in C++.
- Use Merge Sort and Binary Search.
- Work with vectors and structures.
- Perform file input and output operations.
- Implement CRUD operations (Create, Read, Update, and Delete).
- Analyze the time complexity of algorithms.

## 📝 Conclusion

The Phonebook Management System demonstrates how C++ programming, file handling, data structures, and Divide and Conquer algorithms can be combined to build a practical application. Merge Sort organizes contacts alphabetically, while Binary Search provides an efficient way to locate contacts in a sorted list. File handling enables contact information to be saved and retrieved across program executions.

This project provides practical experience in algorithm design, problem-solving, and application development.

## 👩‍💻 Author

**Sakshi Vaidya**

B.Tech Computer Engineering

Sanjivani College of Engineering, Kopargaon
