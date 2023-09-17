#include <iostream>
#include <string>
#include <map>

// User database to store usernames and passwords (for demonstration purposes)
std::map<std::string, std::string> userDatabase;

// Function to register a new user
void registerUser() {
    std::string username, password;
    
    std::cout << "Enter a new username: ";
    std::cin >> username;
    
    if (userDatabase.find(username) != userDatabase.end()) {
        std::cout << "Username already exists. Try again with a different username.\n";
        return;
    }

    std::cout << "Enter a password: ";
    std::cin >> password;
    
    userDatabase[username] = password;
    std::cout << "Registration successful!\n";
}

// Function to authenticate a user
bool authenticateUser(const std::string& username, const std::string& password) {
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        return true;
    }
    return false;
}

int main() {
    int choice;
    std::string username, password;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Register a new user\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                if (authenticateUser(username, password)) {
                    std::cout << "Login successful!\n";
                } else {
                    std::cout << "Login failed. Invalid username or password.\n";
                }
                break;
            case 3:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
