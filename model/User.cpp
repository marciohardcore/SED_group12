class User {
private:
    string userName;
    string password;
    string fullName;
    string phoneNumber;
    string email;
    string idType;
    string idNumber;
    int creditPoint = 10;

public:
    // Constructor
    User(string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits)
        : userName(uName), password(pwd), fullName(fName), phoneNumber(pNumber), email(mail), idType(idT), idNumber(idNum), creditPoint(credits) {}

    // Getters
    string getUserName() 
    { 
        return userName; 
    }
    string getPassword() 
    { 
        return password; 
    }
    string getFullName()
    {
        return fullName;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    string getEmail()
    {
        return email;
    }
    // Method to view the user profile
    void viewProfile() 
    {
        cout << "User Profile:\n";
        cout << "Your Username: " << userName << "\n";
        cout << "Your Full Name: " << fullName << "\n";
        cout << "Your Phone Number: " << phoneNumber << "\n";
        cout << "Your Email: " << email << "\n";
        cout << "Your Credit Points: " << creditPoint << "\n";
    }

    // Method to update the user profile

    void updateProfile(string newFullName, string newPhoneNumber, string newEmail) 
    {   

        fullName = newFullName;
        phoneNumber = newPhoneNumber;
        email = newEmail;
        cout << "Profile updated successfully.\n";
    }

    // Method to add credit points
    void addCreditPoints(int points) 
    {
        creditPoint += points;
        cout << points << " credit points added.\n";
    }

    // Getter for credit points
    int getCreditPoints() 
    {
        return creditPoint;
    }
};
