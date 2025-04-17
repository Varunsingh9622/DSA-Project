#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to hold contact information
typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact phonebook[MAX];
int count = 0;

// Function to add a contact
void addContact() {
    if (count >= MAX) {
        printf("Phonebook is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", phonebook[count].name);
    printf("Enter phone: ");
    scanf(" %[^\n]", phonebook[count].phone);

    printf("Contact added successfully.\n");
    count++;
}

// Function to display all contacts
void displayContacts() {
    if (count == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name  : %s\n", phonebook[i].name);
        printf("Phone : %s\n", phonebook[i].phone);
        printf("----------------------\n");
    }
}

// Function to search a contact by name
void searchContact() {
    char name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name  : %s\n", phonebook[i].name);
            printf("Phone : %s\n", phonebook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to update a contact
void updateContact() {
    char name[50];
    int found = 0;

    printf("Enter name of contact to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Enter new phone: ");
            scanf(" %[^\n]", phonebook[i].phone);
            printf("Contact updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void deleteContact() {
    char name[50];
    int found = 0;

    printf("Enter name of contact to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            // Shift remaining contacts left
            for (int j = i; j < count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            count--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Exiting Phonebook. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}