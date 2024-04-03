#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;


void registerUser();
void userLogin();
void menu();
bool openDatabaseFile();
void forgetPassword();
bool isUsernameExists(const string& username);
string PassTextToStar();

int main()
{
    menu();
    return 0;
}

void menu()
{
    char choice;
    do
    {
        cout <<"" <<endl;
        cout << "  |----------------------------------------------------------Welcome to Registration System----------------------------------------------------------------------" << endl;
        cout << "  |<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><" <<endl;
		cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |                _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _                     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
        cout << "  |                _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_(-Instructions Menu-)_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
        cout << "  |" <<endl;
        cout << "  |" <<endl ;
        cout << "  |--------------------------------------" << endl;
        cout << "  | Enter Option 1 to Register          -" << endl;
        cout << "  |--------------------------------------" << endl;
		cout << "  |" <<endl;
        cout << "  |--------------------------------------" << endl;
        cout << "  | Enter Option 2 to Login             -" << endl;
        cout << "  |--------------------------------------" << endl;
        cout << "  |--------------------------------------" << endl;
        cout << "  | Forget Password? Enter Option 3     -" <<endl;
        cout << "  |--------------------------------------" << endl;
		cout << "  |" <<endl;
        cout << "  |--------------------------------------" << endl;
        cout << "  | Enter Option 4 to open database file-" << endl;
        cout << "  |--------------------------------------" << endl;
		cout << "  |" <<endl;
        cout << "  |--------------------------------------" << endl;
        cout << "  | Enter Option 5 to exit.             -" << endl;
        cout << "  |--------------------------------------" << endl;

        cout << "__|___________________________________________________________________________________________________________________________________________________________________" << endl;

        cout << "  |--------------------" << endl;
        cout << "  | Enter your choice -: ";
        cin >> choice;
        cout << "  |--------------------" << endl;
        cout << ""<< endl;

        switch (choice)
        {
        case '1':
            registerUser();
            break;
        case '2':
            userLogin();
            break;
        case '3':
         	forgetPassword();
             break;
        case '4':
            openDatabaseFile();
            break;
        case '5':
            cout << "Exiting...(-Thank you for using our Registration System-)" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != '5');
}


void registerUser()
{

	system("cls"); 
    string reguserId, regUserPassword, rid, rpass;
	cout << "  |" << endl;
    cout << "  |              _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _                       _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "  |              _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ ( Registration Form ) _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ " << endl;
    cout << "  |" << endl;
    cout << "  |" <<endl;
    cout << "  |---------------------------------------" << endl;
    cout << "  | Enter username (at least 4 characters): ";cin >> reguserId;
    cout << "  |---------------------------------------" << endl;

    if (reguserId.length() < 4)
    {
    cout << "  |	_______________________________________________  												  ___________________________________________" << endl;
    cout << "  | 	_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_(	Username must be at least 4 characters long.) _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*	" << endl;
        return;
    }
    

    if (isUsernameExists(reguserId))
    {
    cout << "  |" << endl;
     cout << " |      ______________________________________________											     ______________________________________________" << endl;
    cout << "  |      _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_( Username exists Please try another username )_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
        return;
    }

    cout << "  | Enter password (at least 6 characters): ";
    regUserPassword = PassTextToStar();
    cout << "  |--------------------------------------" << endl;

    if (regUserPassword.length() < 6)
    {
    cout << "  |" << endl;
    cout << "  |      ______________________________________________											 ________________________________________________" << endl;
    cout << "  |      _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_Password must be at least 6 characters long_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
    cout << "  |" << endl;
        return;
    }
    
	
    ofstream database("database.txt", ios::app);
    database << "Username " <<reguserId <<endl;
	database << "Password " <<regUserPassword << endl;
    database.close();
    system("cls");
    cout << "  |"<< endl;
	cout << "  |----------------------------- * * * * * * * * * * * * * * * * * * * * * * * * * * * * * -----------------------------" << endl;
    cout << "  |----------------------------- *   Registration successful! You are now able to login  * ---" << endl;
    cout << "  |----------------------------- * * * * * * * * * * * * * * * * * * * * * * * * * * * * * -----------------------------" << endl;
    cout << "  |"<< endl;
    cout << "  |"<< endl;
}


void userLogin()
{

    system("cls");
   
    cout << "  |" << endl;
    cout << "  |              _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _                _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "  |              _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ ( Login Form ) _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
    cout << "  |" << endl;
	
	int check;
    string userId, password, id, pass;

    cout << "  |------------------------------" << endl;
    cout << "  | Please Enter Your Username : ";cin >> userId;
    cout << "  |------------------------------" << endl;
    cout << "  |------------------------------" << endl;
    cout << "  | Please Enter Your password : "; password = PassTextToStar();
    cout << "  |------------------------------" << endl;

    ifstream input("database.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            check = 1;
            system("cls");
        }
    }
    input.close();	

    if (check == 1)
    {
    cout << "  |"<< endl;
    cout << "  |----------------------------- * * * * * * * * * * * * * * * * -----------------------------" << endl;
    cout << "  |----------------------------- *  	( Login successful! )   * -----------------------------" << endl;
    cout << "  |----------------------------- * * * * * * * * * * * * * * * * -----------------------------" << endl;
	cout << "  |"<< endl;
    }
    else
    {
    cout << ""<< endl;
    cout << "  |----------------------------- ------------------------------------------------------------------------------------" << endl;
    cout << "  |-----------------------------( Login failed. Please check your username and password ).---------------------------" << endl;
    cout << "  |----------------------------- -------------------------------- ---------------------------------------------------" << endl;
    cout << "" << endl;
    }
}

bool openDatabaseFile()
{
    string filename = "database.txt";
    system(("start " + filename).c_str());
    return true;
}

string PassTextToStar()
    {
        string password;
        char ch;
        while ((ch = _getch()) != '\r') 
        {
            password += ch;
            cout << "*"; 
        }
        cout << "" <<endl; 
        return password;
    }

void forgetPassword()
{

    system("cls");
    cout << "  |" << endl;
    cout << "  |              _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _                        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "  |              _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_( Forget Password Form )_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
    cout << "" << endl;
    

    string username, newPassword;
    
    bool userFound = false;
	cout << "  |----------------------" << endl;
    cout << "  | Enter your username  :";  cin >> username; 
    cout << "  |----------------------" << endl;
   

    ofstream tempFile("temp.txt");

    ifstream input("database.txt");
    string id, pass;

    while (input >> id >> pass)
    {
        if (id == username)
    {
    userFound = true;
    cout << "  |------------------------" << endl;
    cout << "  | Enter Your new password : "; newPassword = PassTextToStar();
    cout << "  |------------------------" << endl;
    cout << "" <<endl;
    tempFile << id << " " << newPassword << endl;
    } else{	
    tempFile << id << " " << pass << endl;
    }
    }

    input.close();
    tempFile.close();

    remove("database.txt");
    rename("temp.txt", "database.txt");
	system("cls");

    if (userFound)
    {
    cout << "  |" << endl;
    cout << "  |             --------------------------------                                                                         ------------" << endl;
    cout << "  |             --------------------------------( Password reset successful. You can now log in with your new password. )------------" << endl;
    cout << "  |             --------------------------------                                                                         ------------" << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
    }
    else
    {
    cout << "  |" << endl;
    cout << "  |              -----------------------------------------                                               -------------------------" << endl;
    cout << "  |              -----------------------------------------( Username not found. Please check your username. )---------------------" << endl;
    cout << "  |              -----------------------------------------                                               -------------------------" << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
    cout << "  |" <<endl;
    }
}

bool isUsernameExists(const string& username)
{
    ifstream input("database.txt");
    string id;

    while (input >> id)
    {
        if (id == username)
        {
            return true;
        }
    }
    return false;
}

