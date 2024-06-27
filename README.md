# Courier Management System

This Courier Management System is a simple console-based C program designed to manage parcel deliveries. It includes functionality for both administrators and clients to add, update, search, and display parcels, as well as manage postman details.

## Table of Contents
- [Courier Management System](#courier-management-system)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [File Structure](#file-structure)
  - [Function Descriptions](#function-descriptions)
    - [Main Functions](#main-functions)
    - [Administrator Functions](#administrator-functions)
    - [Client Functions](#client-functions)
  - [Data Structures](#data-structures)
  - [How to Use](#how-to-use)

## Features
1. User login for administrators and clients.
2. Add new parcels.
3. Update parcel details.
4. Search for parcels.
5. Display all parcels.
6. Mark parcels as delivered.
7. Manage postman details.

## File Structure
- `main.c`: Contains the source code for the Courier Management System.

## Function Descriptions

### Main Functions
- `int main()`: The entry point of the program. It calls the `login` function.

### Administrator Functions
- `void login()`: Handles the login process for users. It checks the username and password and determines if the user is an administrator or a client.
- `int menuadministrator()`: Displays the administrator menu and handles the selection of different functionalities available to administrators.
- `void addParcel()`: Allows the administrator to add a new parcel.
- `void updateParcels()`: Allows the administrator to update the details of an existing parcel.
- `void searchParcel()`: Allows the administrator to search for a parcel by ID.
- `void displayParcels()`: Displays all parcels in the system.
- `void markplaced()`: Allows the administrator to mark a parcel as delivered.
- `void postman()`: Manages postman details including adding new postmen and displaying existing postmen.

### Client Functions
- `int menuclient()`: Displays the client menu and handles the selection of different functionalities available to clients.
- `void addParcel()`: Allows the client to add a new parcel.
- `void searchParcel()`: Allows the client to search for a parcel by ID.
- `void displayParcels()`: Displays all parcels in the system.

## Data Structures
- `struct Parcel`: A structure to store parcel details.
  - `int id`: Parcel ID.
  - `char sender_name[50]`: Sender's name.
  - `char receiver_name[50]`: Receiver's name.
  - `char sender_address[100]`: Sender's address.
  - `char receiver_address[100]`: Receiver's address.
  - `char status[20]`: Status of the parcel (e.g., "NOT DELIVERED", "DELIVERED").

- `struct postman`: A structure to store postman details.
  - `int id`: Postman ID.
  - `char name[50]`: Postman's name.
  - `long int mobno`: Postman's mobile number.

## How to Use
1. **Compile the Code**:
   Use a C compiler to compile the code. For example, using GCC:
   ```bash
   gcc -o courier_system main.c
   ```

2. **Run the Program**:
   Execute the compiled binary:
   ```bash
   ./courier_system
   ```
   or simply download the file and run in C compiler.
   
4. **Login**:
   - Enter the username and password.
   - The program will determine if you are an administrator or a client based on the entered credentials.

5. **Use the Menu**:
   - Follow the menu options to add, update, search, display parcels, mark parcels as delivered, or manage postman details.

6. **Exit**:
   - Select the exit option from the menu to quit the program.

### Default Credentials
- **Administrator**:
  - Username: `9876543210`
  - Password: `2345`

- **Client**:
  - Username: `1234567890`
  - Password: `1234`

Note: Ensure to handle the data file (`Postman.txt`) appropriately if managing postman details. The file will be created and updated by the program as needed.
