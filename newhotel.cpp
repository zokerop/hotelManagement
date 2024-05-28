#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;
class hotel_taj
{
private:
    int quantity;

    int Qroom=10, Qpasta=10, Qsamosa=10, Qshake=10, Qchicken_roll=10;
    int Sroom = 0, Spasta = 0, Ssamosa = 0, Sshake = 0, Schicken_roll = 0;
    int Proom = 0, Ppasta = 0, Psamosa = 0, Pshake = 0, Pchicken_roll = 0;

public:
    void menu();
    void login();
    void registration();
    void enter();
    void administrator();
    void old();
    void adminichoice();
};

void hotel_taj::old(){
    cout<<"Quantity of room"<<Qroom<<endl;
    cout<<"Quantity of pasta"<<Qpasta<<endl;
    cout<<"Quantity of samosa"<<Qsamosa<<endl;
    cout<<"Quantity of shake"<<Qshake<<endl;
    cout<<"Quantity of chicken roll"<<Qchicken_roll<<endl;
}
void hotel_taj::enter()
{
    system("cls");
    cout << "Enter the NO.OF Room\n";
    cin >> Qroom;
    cout << "Enter the NO.OF Pasta\n";
    cin >> Qpasta;
    cout << "Enter the NO.OF Shake\n";
    cin >> Qshake;
    cout << "Enter the NO.OF Chicken\n";
    cin >> Qchicken_roll;
    cout << "Enter the NO.OF Samosa\n";
    cin >> Qsamosa;

}
void hotel_taj::adminichoice(){
cout<<"HI ADMINISTRATOR"<<endl;
int choice;
cout<<"WILL YOU CHANGE QUANTITY OF PRODUCT PRESS '1' OR TO SEE THE PRODUCT '2' "<<endl;

cin>>choice;
switch (choice)
{
case 1:
    enter();
    adminichoice();
    break;
case 2:
  old();
  menu();

default:
adminichoice();
    break;
}
}
void hotel_taj::administrator()
{
    system("cls");

    string id, pass;
    cout << "Enter the Email id\n";
    cin >> id;
    cout << "Enter the Password id\n";
    cin >> pass;
    if (id == "abhic12@gmail.com" && pass == "abhi")
    {
        adminichoice();
        menu();
    }
    else
    {
        cout << "invalide\n";
        menu();
    }
}

void hotel_taj::menu()
{

  system("cls");
 
    cout << "-------------------->\t\tWelcome TO Our Hotel Taj\t\t<--------------------------\n\n";
    cout << "                           1.For Old User(IF YOU ARE REGISTER) \n";
    cout << "                           2.For Registration\n";
    cout << "                           3.For Administrator\n";
    int choice;
    cout << "Please Enter Your Choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        administrator();
        break;
    default:
        cout << "Please Enter Valid Input\n";
        menu();
        break;
    }
}
void hotel_taj::registration()
{
system("cls");
    string Remail_id, Rpassword, Rusername;
cout<<"Registration menu:::-->>\n";
 cout<<"Enter The Username\n";
 cin>>Rusername;
    cout << "Enter The Email_id\n";
    cin >> Remail_id;

    cout << "Enter The Password\n";
    cin >> Rpassword;

    ofstream R("Register.txt", ios::app);

    R << Remail_id << "  " << Rpassword <<"       "<<Rusername<< endl;
    system("cls");
    R.close();
    menu();
    
}

void hotel_taj::login()
{
    int count = 0;
    
    string Lemail_id, Lpassword, Lemail, Lpass;
    cout << "Enter the Email Id\n";
    cin >> Lemail_id;

    cout << "Enter the Password\n";
    cin >> Lpassword;
    ifstream input("Register.txt");

    while (input >> Lemail >> Lpass)
    {
        if (Lemail_id == Lemail && Lpassword == Lpass)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "NOW YOU ARE LOGIN       \n\n";
             a:
        cout << "\n-------------------->Welcome To Hotel Taj Here Our Menu<------------------" << endl;
        cout << "                            1.FOR BOOKING ROOM\n";
        cout << "                            2.FOR PASTA\n";
        cout << "                            3.FOR Samosa\n";
        cout << "                            4.FOR SHAKE\n";
        cout << "                            5.FOR CHICKEN ROLL\n";
        cout << "                            6.*FOR SEE YOUR TOTAL BILL* \n";
        cout << "                            7.FOR EXIT\n";
        cout<<"-------------------------------------------------------------------------------\n";
        int choice;
        cout << "PLEASE CHOOSH ANY ONE\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        system("cls");
            cout << "PLEASE ENTER THE NUMBER OF ROOMS YOU WANT\n";
            cin >> quantity;

            if (Qroom - Sroom >= quantity)
            {
                Proom = Proom + (quantity * 2000);
                Sroom = Sroom + quantity;
                cout << "WE ARE ALLOTED \t" << quantity << "\t YOU ROOMS AND PRICE OF ROOMS IS\t" << Proom << endl;

            }
            else
            {
                cout << "SOORY WE HAVE TOTAL ROOMS\t" << Qroom << "\tAND REMAINING ROOMS IS \t" << Qroom - Sroom;
            }
            break;

        case 2:
        system("cls");
            cout << "PLEASE ENTER THE QUANTITY OF PASTA YOU WANT\n";
            cin >> quantity;

            if (Qpasta - Spasta >= quantity)
            {
                Ppasta = Ppasta + (quantity * 200);
                Spasta = Spasta + quantity;
                cout << "YOU PURCHASE OF PASTA IS \t" << quantity << "\t AND PRICE OF PASTA IS\t" << Ppasta << endl;
            }
            else
            {
                cout << "SOORY! WE HAVE QUATTITY OF PASTA IS \t" << Qpasta << "\tAND REMAINING PASTA IS \t" << Qpasta - Spasta << endl;
            }
            break;

        case 3:
        system("cls");
            cout << "PLEASE ENTER THE QUANTITY OF SAMOSA YOU WANT\n";
            cin >> quantity;

            if (Qsamosa - Ssamosa >= quantity)
            {
                Psamosa = Psamosa + (quantity * 120);
                Ssamosa = Ssamosa + quantity;
                cout << "YOU PURCHASE OF SAMOSA IS \t" << quantity << "\t AND PRICE OF  IS\t" << Psamosa << endl;
            }
            else
            {
                cout << "SOORY! WE HAVE QUATTITY OF SAMOSA IS \t" << Qpasta << "\tAND REMAINING BURBEG IS \t" << Qsamosa - Ssamosa << endl;
            }
            break;

        case 4:
        system("cls");
            cout << "PLEASE ENTER THE GLASS OF SHAKE YOU WANT\n";
            cin >> quantity;

            if (Qshake - Sshake >= quantity)
            {
                Pshake = Pshake + (quantity * 250);
                Sshake = Sshake + quantity;
                cout << "YOU PURCHASE OF SHAKE IS \t" << quantity << "\t AND PRICE OF  IS\t" << Pshake << endl;
            }
            else
            {
                cout << "SOORY! WE HAVE GLASS OF SHAKE IS \t" << Qpasta << "\tAND REMAINING SHAKE IS \t" << Qshake - Sshake << endl;
            }
            break;

        case 5:
        system("cls");
            cout << "PLEASE ENTER THE QUANTITY OF CHICKEN ROLL YOU WANT\n";
            cin >> quantity;

            if (Qchicken_roll - Schicken_roll >= quantity)
            {
                Pchicken_roll = Pchicken_roll + (quantity * 350);
                Schicken_roll = Schicken_roll + quantity;
                cout << "YOU PURCHASE OF CHICKEN ROLL IS \t" << quantity << "\t AND PRICE OF  IS\t" << Pchicken_roll << endl;
            }
            else
            {
                cout << "SOORY! WE HAVE QUATTITY OF CHICKEN ROLL IS \t" << Qchicken_roll << "\tAND REMAINING CHICKEN ROLL IS \t" << Qchicken_roll - Schicken_roll << endl;
            }
            break;

        case 6:
        system("cls");
            cout << "YOUR's ROOMS IS PRICE IS\t" << Proom << endl;
            cout << "YOUR OF BURGER IS PRICE IS\t" << Psamosa << endl;
            cout << " Your Pasta  is price \t" << Ppasta << endl;
            cout << "YOUR SHAKE IS PRICE IS\t" << Pshake << endl;
            cout << "YOUR CHICKENROLL IS PRICE IS\t" << Pchicken_roll << endl;

            cout << "**********TOTAL BILL IS\t" << Proom + Ppasta + Pshake + Pchicken_roll + Psamosa << "\t********" << endl;
            break;

        case 7:
        system("cls");
            cout << "THANKS YOU SO MUCH";
            exit(0);
            break;
        default:
        system("cls");
            cout << "****INVALIDE INPUT TRY AGAIN****\n";
            break;
        }
        goto a;
    }

    else
    {

        cout << "YOU ARE NOT REGISTER\n";
        menu();
    }
}

int main(int argc, char const *argv[])
{
    class hotel_taj a;
    a.menu();
    getchar();
    return 0;
}
