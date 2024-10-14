#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string DATA_FILE = "userdata.txt";

struct User
{
    string username;
    string password;
    string email;
    int age;
};

// Function to parse a single user record from a string (CSV format)
User parseUser(const string &line)
{
    User user;
    size_t pos = 0;
    string temp = line;

    // Extract username
    pos = temp.find(',');
    user.username = temp.substr(0, pos);
    temp.erase(0, pos + 1);

    // Extract password
    pos = temp.find(',');
    user.password = temp.substr(0, pos);
    temp.erase(0, pos + 1);

    // Extract email
    pos = temp.find(',');
    user.email = temp.substr(0, pos);
    temp.erase(0, pos + 1);

    // Extract age
    user.age = stoi(temp);

    return user;
}

// Function to read all users from file
vector<User> readUsersFromFile()
{
    vector<User> users;
    ifstream file(DATA_FILE);
    string line;
    while (getline(file, line))
    {
        users.push_back(parseUser(line));
    }
    file.close();
    return users;
}

// Function to write a user to the file
void writeUserToFile(const User &user)
{
    ofstream file(DATA_FILE, ios::app);
    file << user.username << "," << user.password << "," << user.email << "," << user.age << endl;
    file.close();
}

// Function to display user information
void displayUserInfo(const User &user)
{
    cout << "User Information:" << endl;
    cout << "Username: " << user.username << endl;
    cout << "Email: " << user.email << endl;
    cout << "Age: " << user.age << endl;
}

// Function to register a new user
void registerUser()
{
    User user;

    cout << "Registering..." << endl;
    cout << "Enter a new username: ";
    cin >> user.username;
    cout << "Enter a new password: ";
    cin >> user.password;
    cout << "Enter your email: ";
    cin >> user.email;
    cout << "Enter your age: ";
    cin >> user.age;

    writeUserToFile(user);

    cout << "Registration successful!" << endl;
    cout << "Welcome " << user.username << "!, to my Auth Platform." << endl;
}

// Function to display the dashboard
void displayDashboard(const User &loggedInUser)
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
        displayUserInfo(loggedInUser);
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

// Function to handle user login
void loginUser()
{
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    vector<User> users = readUsersFromFile();
    for (const User &user : users)
    {
        if (user.username == username && user.password == password)
        {
            displayDashboard(user);
            return;
        }
    }

    cout << "Invalid username or password!" << endl;
}

// Main program loop
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
