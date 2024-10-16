#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string DATA_FILE = "userdata.txt";

bool isLoggedIn()
{
    string username, password;
    string un, pw;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(DATA_FILE); // Read file
    getline(read, un);        // Read stored username
    getline(read, pw);        // Read stored password

    if (un == username && pw == password)
    {
        return true;
    }
    return false;
}

void registerUser()
{
    string username, password;

    cout << "Registering..." << endl;
    cout << "Enter a new username: ";
    cin >> username;
    cout << "Enter a new password: ";
    cin >> password;

    ofstream file(DATA_FILE);
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
    cout << "Welcome " << username << "!, to my Auth Platform." << endl;
}

void displayDashboard()
{
    int choiceTwo;
    cout << "Login successful!" << endl;
    cout << "Welcome!, to my Auth Platform." << endl;
    cout << endl;
    cout << "Dashboard" << endl;
    cout << "1. View User Information" << endl;
    cout << "2. Logout" << endl;
    cout << "3. Back to Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choiceTwo;

    if (choiceTwo == 1) // View user information
    {
        system("clear");

        string un, pw;
        cout << "User Information:" << endl;
        ifstream read(DATA_FILE);
        getline(read, un);
        getline(read, pw);
        cout << "Username: " << un << endl;
        cout << "Password: " << pw << endl;
        cout << endl;
    }
    else if (choiceTwo == 2) // Logout
    {
        cout << "Logging out..." << endl;
        return;
    }
    else if (choiceTwo == 3) // Return to menu
    {
        return;
    }
}

void loginUser()
{
    bool status = isLoggedIn();
    if (!status)
    {
        system("clear");
        cout << "Invalid username or password!" << endl;
        cout << "Please try again." << endl;
    }
    else
    {
        displayDashboard(); // Call dashboard after successful login
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "Welcome to My Simple Authentication System!" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            loginUser();
        }
        else if (choice == 3)
        {
            cout << "Exiting the application..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
