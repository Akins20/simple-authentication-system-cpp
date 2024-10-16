#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <stdlib.h>

using namespace std;

const string DATA_FILE = "userdata.txt";

// Function to clear the console based on the operating system
void clearScreen()
{
#ifdef _WIN32
    system("CLS"); // Command for Windows
#else
    system("clear"); // Command for Linux/Unix
#endif
}

void userDashboard()
{
    clearScreen();
    cout << "Welcome to the dashboard!" << endl;
    cout << "1. View profile" << endl;
    cout << "2. Update profile" << endl;
    cout << "3. Change password" << endl;
    cout << "4. Logout" << endl;
    cout << "Enter your choice:";
}

void welcome()
{

    clearScreen();
    cout << "Welcome to Simple Auth System!" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice:";
}

void registerUser()
{
    clearScreen();
    string username, password;

    cout << "Registering new user..." << endl;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    ofstream file(DATA_FILE, ios::app);
    file << username << endl;
    file << password << endl;
    file.close();

    clearScreen();

    cout << "Registration successful!" << endl;
    cout << "Welcome " << username << "!" << endl;

    userDashboard();
}

// Function to return both username and password as a pair
pair<string, string> loginUser()
{
    string username, password;
    cout << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    return make_pair(username, password); // Return a pair of username and password
}

bool isLoggedIn()
{
    // Read the username and password from the file one by one and compare them with the inputted credentials
    clearScreen();
    string storedUsername, storedPassword;
    string inputtedUsername, inputtedPassword;
    auto creds = loginUser();
    ifstream file(DATA_FILE);

    // Loop through the file to find the matching username and password
    while (getline(file, storedUsername) && getline(file, storedPassword))
    {
        // Check for a match then return true
        inputtedUsername = creds.first;
        inputtedPassword = creds.second;
        if (inputtedUsername == storedUsername && inputtedPassword == storedPassword)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false; // Return false if no match is found
}

void handleLogin()
{
    bool loginSuccess = false;
    while (!loginSuccess)
    {
        if (isLoggedIn())
        {
            loginSuccess = true;
            userDashboard();
            return;
        }
        else
        {
            cout << "Invalid credentials. Please try again." << endl;
        }
    }
}

int main()
{
    int choice;
    welcome();
    cin >> choice;

    if (choice == 2)
    {
        registerUser();
    }
    else if (choice == 1)
    {
        cout << "Logging in..." << endl;
        handleLogin(); // Using a loop to handle login failures
    }
    else
    {
        cout << "Exiting the application..." << endl;
        return 0;
    }
}