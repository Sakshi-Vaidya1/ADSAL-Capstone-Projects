#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Contact structure to store contact information
struct Contact {
    string name;
    string phone;
    // string email;
};

// Global vector to store contacts
vector<Contact> contacts;
const string FILENAME = "phonebook.txt";

// Function to save contacts to file
void saveContactsToFile() {
    ofstream outFile(FILENAME);
    if (!outFile) {
        cout << "Error: Could not open file for writing!" << endl;
        return;
    }
    
    for (const auto& contact : contacts) {
        outFile << contact.name << "|" << contact.phone << "|"<< endl;  
    }
    
    outFile.close();
    cout << "Contacts saved to file successfully!" << endl;
}

// Function to load contacts from file
void loadContactsFromFile() {
    ifstream inFile(FILENAME);
    if (!inFile) {
        cout << "No existing phonebook file found. Starting fresh." << endl;
        return;
    }
    
    contacts.clear();
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos) {
            Contact contact;
            contact.name = line.substr(0, pos1);
            contact.phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
            contacts.push_back(contact);
        }
    }
    
    inFile.close();
    cout << "Contacts loaded from file successfully!" << endl;
}

// DIVIDE AND CONQUER: Merge Sort for sorting contacts by name
void merge(vector<Contact>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<Contact> leftArr(n1);
    vector<Contact> rightArr(n2);
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i].name <= rightArr[j].name) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function (Divide and Conquer)
void mergeSort(vector<Contact>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array
        int mid = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to sort contacts by name using merge sort
void sortContacts() {
    if (contacts.empty()) {
        cout << "No contacts to sort!" << endl;
        return;
    }
    
    mergeSort(contacts, 0, contacts.size() - 1);
    cout << "Contacts sorted by name successfully!" << endl;
    saveContactsToFile();
}

// DIVIDE AND CONQUER: Binary Search for searching contacts
int binarySearch(const vector<Contact>& arr, const string& key, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the key is present at mid
        if (arr[mid].name == key) {
            return mid;
        }
        
        // If key is smaller, search in left subarray
        if (arr[mid].name > key) {
            return binarySearch(arr, key, left, mid - 1);
        }
        
        // If key is larger, search in right subarray
        return binarySearch(arr, key, mid + 1, right);
    }
    
    // Key not found
    return -1;
}

// Function to search contact by name
void searchContact() {
    if (contacts.empty()) {
        cout << "No contacts available to search!" << endl;
        return;
    }
    
    string searchName;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, searchName);
    
    // Sort contacts before binary search
    mergeSort(contacts, 0, contacts.size() - 1);
    
    int index = binarySearch(contacts, searchName, 0, contacts.size() - 1);
    
    if (index != -1) {
        cout << "\nContact Found!" << endl;
        cout << "Name: " << contacts[index].name << endl;
        cout << "Phone: " << contacts[index].phone << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}

// Function to add a new contact
void addContact() {
    Contact newContact;
    
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    
    contacts.push_back(newContact);
    
    // Auto-save to file when contact is added
    saveContactsToFile();
    
    cout << "Contact added successfully!" << endl;
}

// Function to display all contacts
void displayAllContacts() {
    if (contacts.empty()) {
        cout << "No contacts available!" << endl;
        return;
    }
    
    cout << "\n" << setw(30) << left << "Name" 
         << setw(15) << left << "Phone" << endl;
    cout << string(75, '-') << endl;
    
    for (const auto& contact : contacts) {
        cout << setw(30) << left << contact.name 
             << setw(15) << left << contact.phone << endl;
    }
}

// Function to delete a contact
void deleteContact() {
    if (contacts.empty()) {
        cout << "No contacts available to delete!" << endl;
        return;
    }
    
    string deleteName;
    cout << "Enter name of contact to delete: ";
    cin.ignore();
    getline(cin, deleteName);
    
    bool found = false;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == deleteName) {
            contacts.erase(it);
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "Contact deleted successfully!" << endl;
        saveContactsToFile();
    } else {
        cout << "Contact not found!" << endl;
    }
}

// Function to update a contact
void updateContact() {
    if (contacts.empty()) {
        cout << "No contacts available to update!" << endl;
        return;
    }
    
    string updateName;
    cout << "Enter name of contact to update: ";
    cin.ignore();
    getline(cin, updateName);
    
    bool found = false;
    for (auto& contact : contacts) {
        if (contact.name == updateName) {
            found = true;
            
            cout << "Enter new name (or press Enter to keep current): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                contact.name = newName;
            }
            
            cout << "Enter new phone (or press Enter to keep current): ";
            string newPhone;
            getline(cin, newPhone);
            if (!newPhone.empty()) {
                contact.phone = newPhone;
            }
            
            cout << "Contact updated successfully!" << endl;
            saveContactsToFile();
            break;
        }
    }
    
    if (!found) {
        cout << "Contact not found!" << endl;
    }
}

// Function to display menu
void displayMenu() {
    cout << "\n===== PHONEBOOK MANAGEMENT SYSTEM =====" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Display All Contacts" << endl;
    cout << "3. Search Contact" << endl;
    cout << "4. Delete Contact" << endl;
    cout << "5. Update Contact" << endl;
    cout << "6. Sort Contacts" << endl;
    cout << "7. Save Contacts to File" << endl;
    cout << "8. Load Contacts from File" << endl;
    cout << "9. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Load contacts from file at startup
    loadContactsFromFile();
    
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayAllContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                updateContact();
                break;
            case 6:
                sortContacts();
                break;
            case 7:
                saveContactsToFile();
                break;
            case 8:
                loadContactsFromFile();
                break;
            case 9:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 9);
    
    return 0;
}