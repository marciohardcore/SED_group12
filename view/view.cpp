#include <iostream>
#include <Windows.h>

#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

void introduction(){
    std::cout << BOLD << "\t \t SOFTWARE ENGINEERING DESIGN\n" << RESET;
    std::cout << BOLD << "\t \t Carpool Listing application\n" << RESET;
    std::cout << RED << "Instructor:" << BLUE << " Huo Chong Ling\n";
    std::cout << RED << "Group:" << BLUE << " 12\n";
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "s4026694"<< GREEN << " Le Nguyen Khuong Duy\n";
    std::cout << YELLOW << "s4026694"<< GREEN << " Vu Van Tuan\n";
    std::cout << YELLOW << "s4026694"<< GREEN << " Tran Thanh Lam\n";
    std::cout << YELLOW << "s4026694"<< GREEN << " Tran Tu Tam\n";
    std::cout << "\n" << RESET;
    system("pause");
}

void option(){
    int choice = 0;
    
    std::cout << BOLD << "\t \t Carpool Listing application\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Menu";
    std::cout << YELLOW << "1. Login";
    std::cout << YELLOW << "2. Register";
    std::cout << YELLOW << "3. View available carpool";
    std::cout << YELLOW << "4. Admin";
    std::cout << YELLOW << "5. Exit";
    std::cin >> choice;
    while (choice > 4 || choice < 1){
        std::cout << "Invalid input, please enter a number from 1 to 4\n";
        std::cin >> choice;
    }
    system("pause");

    //login
    if (choice == 1){

    
    }

    //register
    else if (choice == 2){

    }

    //view carpool
    else if (choice == 3){

    }

    //admin
    else if (choice == 4){

    }

    //exit
    else if (choice == 5){

    }
}
int main(){
    introduction();
    option();
}

//chon xong thi switch to controller
void profileManagement(){
    std::cout << YELLOW << "Profile Management";
    std::cout << YELLOW << "1. View profile";
    std::cout << YELLOW << "2. Update profile";
    std::cout << YELLOW << "3. Add credit point";
}