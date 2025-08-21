#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Book {
    string id;
    string title;
    string author;
    bool isIssued;
};

Book books[MAX];
int bookCount = 0;

// Function declarations
void AlreadyBooks();
void addBook();
void deleteBook();
void updateBook();
void viewBooks();
void clearBooks();
void countBooks();
void countStatus();
void sortBooks();
void searchByID();
void searchByTitle();
void searchByAuthor();
void borrowBook();
void returnBook();
void viewBorrowed();
void adminMenu();
void StudentMenu();
void guestMenu();
void mainMenu();

// Main function
int main() {
	int password;
	do{
	cout<<"Enter Password: ";cin>>password;
	if(password==123){
		AlreadyBooks();
   	    mainMenu();
	}
	else{
		cout<<"Invalid Password."<<endl;
	}
}while(password !=123);
	
    return 0;
}

void mainMenu() {
    char choice;
    do {
        cout << " \n============ MAIN MENU ============= \n";
        cout << "1. Admin \n2. Student \n3. Guest \n0. Exit \nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case '1': adminMenu(); break;
            case '2': StudentMenu(); break;
            case '3': guestMenu(); break;
            case '0': cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != '0');
}

// Admin Menu
void adminMenu() {
		int password;
	do{
	cout<<"Enter Password: ";cin>>password;
	if(password==123){
    char choice;
    do {
        cout << "\n            Admin Menu              ";
		cout << "\n===================================\n";
        cout << "1. Add Book\n2. Delete Book\n3. Update Book Info\n4. View All Books\n5. Clear All Books\n";
        cout << "6. Count All Books\n7. Count Available/Issued\n8. Sort Books\n9. Search by ID\n0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case '1': addBook(); break;
            case '2': deleteBook(); break;
            case '3': updateBook(); break;
            case '4': viewBooks(); break;
            case '5': clearBooks(); break;
            case '6': countBooks(); break;
            case '7': countStatus(); break;
            case '8': sortBooks(); break;
            case '9': searchByID(); break;
            case '0': cout << "Logging out...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != '0');
}
	else{
		cout<<"Invalid Password."<<endl;
	}
}while(password !=123);

}

// User Menu
void StudentMenu() {
	int password;
	do{
	cout<<"Enter Password: ";cin>>password;
	if(password==123){
    char choice;
    do {
        cout << "\n            User Menu              ";
		cout << "\n===================================\n";
        cout << "1. View All Books\n2. Borrow Book\n3. Return Book\n4. View Borrowed Books\n";
        cout << "5. Search by Title\n6. Search by Author\n0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case '1': viewBooks(); break;
            case '2': borrowBook(); break;
            case '3': returnBook(); break;
            case '4': viewBorrowed(); break;
            case '5': searchByTitle(); break;
            case '6': searchByAuthor(); break;
            case '0': cout << "Logging out...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != '0');
    }
	else{
		cout<<"Invalid Password."<<endl;
	}
}while(password !=123);
    
}




// Guest Menu
void guestMenu() {
    char choice;
    do {
        cout << "\n            Guest Menu              ";
		cout << "\n===================================\n";
        cout << "1. View All Books\n2. Search by Title\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case '1': viewBooks(); break;
            case '2': searchByTitle(); break;
            case '0': cout << "Exiting guest mode...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != '0');
}

// Book Functions

void addBook() {
	cout<<"===============Add Book==============\n";
    if (bookCount >= MAX) {
        cout << "Library full!\n";
        return;
    }
    cin.ignore();
    cout << "Enter Book ID: "; getline(cin, books[bookCount].id);
    cout << "Enter Title: "; getline(cin, books[bookCount].title);
    cout << "Enter Author: "; getline(cin, books[bookCount].author);
    books[bookCount].isIssued = false;
    bookCount++;
    cout << "Book added.\n";
}

void deleteBook() {
	cout<<"===============Delete Book==============\n";
    string id;
    cin.ignore();
    cout << "Enter Book ID to delete: ";getline(cin,id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++)
                books[j] = books[j + 1];
            bookCount--;
            cout << "Book deleted.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void updateBook() {
	cout<<"===============Update Book Info==============\n";
    string id;
    cin.ignore();
    cout << "Enter Book ID to update: ";getline(cin,id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            cin.ignore();
            cout << "Enter new Title: "; getline(cin, books[i].title);
            cout << "Enter new Author: "; getline(cin, books[i].author);
            cout << "Book updated.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void viewBooks() {
	cout<<"************************View Books****************************\n\n\n";
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }
    for (int i = 0; i < bookCount; i++) {
    	cout<<"==============================================================\n";
        cout << books[i].id << " - " << books[i].title << " by " << books[i].author;
        cout << " [" << (books[i].isIssued ? "Issued" : "Available") << "]\n";
        cout<<"_________________________=("<<i+1<<")=________________________________\n\n\n";
    }
}

void clearBooks() {
	cout<<"==============Clear Books=============\n";
    bookCount = 0;
    cout << "All books cleared.\n";
}

void countBooks() {
	cout<<"===============Count Books==============\n";
    cout << "Total books: " << bookCount << "\n";
}

void countStatus() {
	cout<<"===============Count Status==============\n";
    int issued = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isIssued) issued++;
    }
    cout << "Issued: " << issued << ", Available: " << bookCount - issued << "\n";
}

void sortBooks() {
	cout<<"===============Sort Books==============\n";
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].title > books[j].title) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    cout << "Books sorted by title.\n";
}

void searchByID() {
	cout<<"===============Search By ID==============\n";
    string id;
    cin.ignore();
    cout << "Enter Book ID to search: ";getline(cin,id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            cout << books[i].title << " by " << books[i].author;
            cout << " [" << (books[i].isIssued ? "Issued" : "Available") << "]\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchByTitle() {
	cout<<"===============Search By Title==============\n";
    string title;
    cin.ignore();
    cout << "Enter title to search: ";getline(cin,title);
    for (int i = 0;i < bookCount;i++) {
        if (books[i].title == title) {
            cout << books[i].title << " by " << books[i].author;
            cout << " [" << (books[i].isIssued ? "Issued" : "Avaliable") << "]\n";
            return;
        }
    }
    cout << "Book not found.";
}

void searchByAuthor(){
	cout<<"================Search By Author=============\n";
    string author;
    cin.ignore();
    cout << "Enter Author Name to search: ";getline(cin, author);
    for (int i = 0;i < bookCount;i++) {
        if (books[i].author == author) {
            cout << books[i].title << " by " << books[i].author;
            cout << " [" << (books[i].isIssued ? "Issued" : "Avaliable") << "]\n";
            return;
        }
    }
    cout << "Book not found.";
}

void borrowBook() {
	cout<<"===============Borrow Book==============\n";
    string id;
    cin.ignore();
    cout << "Enter Book ID to borrow: ";getline(cin,id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id && !books[i].isIssued) {
            books[i].isIssued = true;
            cout << "Book borrowed.\n";
            return;
        }
    }
    cout << "Book not available or already issued.\n";
}

void returnBook() {
	cout<<"===============Return Book==============\n";
    string id;
    cin.ignore();
    cout << "Enter Book ID to return: ";getline(cin,id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id && books[i].isIssued) {
            books[i].isIssued = false;
            cout << "Book returned.\n";
            return;
        }
    }
    cout << "Invalid return.\n";
}

void viewBorrowed() {
	cout<<"==============View Borrowed===============\n";
    bool any = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isIssued) {
            cout << books[i].id << " - " << books[i].title << " by " << books[i].author << "\n";
            any = true;
        }
    }
    if (!any) cout << "No borrowed books.\n";
}
// Library Allreadybooks
void AlreadyBooks(){


books[0]={"101","Physic","Halliday",false};
books[1]={"102","Chemistry","Atkins",false};
books[2]={"103","Introduction to Algorithms","Thomas H.Cormen",false};
books[3]={"104","The Study of Language","George Yule",false};
books[4]={"105","Steve Jobs","Walter Isaacson",false};
	bookCount=5;
	
}
