
# Simple Authentication System - Text Version

This project is a console-based user authentication system written in C++. It allows users to register and log in using a username, password, email, and age. The user data is stored in a `.txt` file (`userdata.txt`), which is used to manage multiple user accounts.

## Features

- **User Registration**: New users can register by providing a username, password, email, and age.
- **User Login**: Registered users can log in by entering their username and password.
- **User Dashboard**: After logging in, users can view their information (username, email, and age).
- **Data Persistence**: User data is stored in a `.txt` file (`userdata.txt`), allowing users to log in again after restarting the program.

## Getting Started

### Prerequisites

To run this project, you need the following:

- A C++ compiler (e.g., GCC, Clang, MSVC)

### Running the Project

1. **Clone the repository**:

   ```bash
   git clone https://github.com/Akins20/simple-authentication-system-cpp.git
   cd simple-authentication-system-cpp
   ```

2. **Compile the project**:

   ```bash
   g++ -o auth_system auth_system.cpp
   ```

3. **Run the compiled program**:

   ```bash
   ./auth_system
   ```

## File Structure

```
.
├── auth_system.cpp       # Main source code for the authentication system
├── userdata.txt          # TXT file storing user data (created when users register)
└── README.md             # This README file
```

## How the System Works

### User Data Storage

The system stores user data in a `.txt` file (`userdata.txt`). Each line in the file represents a user and contains their information in the following format:

```
username,password,email,age
```

For example:

```
john_doe,password123,john@example.com,25
jane_doe,securePass,jane@example.com,30
```

### Features in Detail

#### User Registration

During registration, the user enters their username, password, email, and age. The system appends this information as a new line in the `userdata.txt` file.

#### User Login

The login process reads the `userdata.txt` file line-by-line to check if the entered username and password match any registered user. If a match is found, the user is logged in and presented with the dashboard.

#### Dashboard

After a successful login, users are taken to the dashboard where they can:

- **View their information**: This displays their username, email, and age.
- **Logout**: Log out and return to the main menu.

## Example Output

### User Registration

```
Registering...
Enter a new username: john_doe
Enter a new password: password123
Enter your email: john@example.com
Enter your age: 25
Registration successful!
Welcome john_doe!, to my Auth Platform.
```

### User Login

```
Enter a username: john_doe
Enter a password: password123
Login successful!
Welcome!, to my Auth Platform.

Dashboard
1. View User Information
2. Logout
3. Back to Menu
Enter your choice: 1

User Information:
Username: john_doe
Email: john@example.com
Age: 25
```

## Future Enhancements

- **Password Encryption**: Use hash functions to store passwords securely.
- **Email Validation**: Add input validation to check for valid email formats.
- **Improved Error Handling**: Handle edge cases like file I/O errors and invalid inputs more gracefully.

## Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/new-feature`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature/new-feature`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

Feel free to contact me via [ogunbiye@gmail.com](mailto:ogunbiye@gmail.com) if you have any questions or suggestions.

