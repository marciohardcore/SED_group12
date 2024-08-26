class User
{
private:
    string userName, password, fullName, phoneNumber, email;
    int creditPoints = 10;

public:
    User(string username, string pwd, string fullname, string phoneNum, string email)
    {
        this->userName = username;
        this->password = pwd;
        this->fullName = fullname;
        this->phoneNumber = phoneNum;
        this->email = email;
    }
    
    void viewProfile()
    {
        cout << "Your user name: " << userName << endl
             << "Your Password: " << password << endl
             << "Your full name: " << fullName << endl
             << "Your phone number: " << phoneNumber << endl
             << "Your email: " << email << endl;
    };
    void updateProfile()
    {
        
        // PASSWORD FILE NEEDED
        if (oldpwd == password)
        {
            
            cout << "\n"
                 << "************************"
                 << "\n\n";
            cout << "Your user name: " << userName << endl
                 << "Your Password: " << password << endl
                 << "Your full name: " << fullName << endl
                 << "Your phone number: " << phoneNumber << endl
                 << "Your email: " << email << endl;
        }
        else
        {
            cerr << "Wrong password, cannot do this action!";
        }
    };
    void addCreditPoints() 
    {
        int addCre;
        cout << "Please enter how many credit points do you want to add(1$ = 1p): ";
        cin >> addCre;
        creditPoints += addCre;
        cout << "Adding successfully! Your total credit points: " << creditPoints;
        
    };
};
