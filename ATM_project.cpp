#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <windows.h>
#include <set>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//------------------------------------------------------SHOW TIME--------------------------------------------------------------------
string store_time()
{
    time_t now=time(0);
    char*timeString = ctime(&now);
    return timeString;
}
// -------------------------------------------------SET COLOUR FUNCTION-------------------------------------------------------------

int col(int a)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h,a);
}
//-----------------------------------------------------------------------------------------------------------------------------------
class Store_data
{
private:
    int crd_no;
    char name[100];
    int amount;
    int pin;
    int cvv;
public:
    void get_data();
    void put_data();
    void put_all_data();

    int random()
    {
        set<int> numbers; // to store generated numbers
        int num;
        srand(time(NULL)); // initialize random seed

        // loop until a unique 3-digit number is generated
        do
        {
            num = rand() % 900 + 100; // generate a random number between 100 and 999
        } while (numbers.count(num)); // check if the number is already in the set

        numbers.insert(num); // add the unique number to the set
        return num;
    }

    void update_data(int ,int );
    void update_data(char[100]);
    void card_function_master(int z)
    {
        fstream file;
        Store_data store;
        string b=to_string(z);
        col(2);
        cout << "Your Master card have been approved" << endl;
            cout << "\n";
            string e;
            string d = b + "45";
            col(1);
            cout << "Please enter the last Unique four Digits " << endl;
            cin >> e;
            int no_dig = e.length();
            if (no_dig == 4)
            {
                string f = d + e;
                int g = stoi(f);
                crd_no=g;
                int flag=0;
                file.open("main.dat", ios::in | ios::binary);
                if (!file)
                {
                    col(4);
                    cout << "File not open" << endl;
                    exit(0);
                }
                else
                {
                    file.read((char *)&store, sizeof(store));
                    while (!file.eof())
                    {
                        if (crd_no == store.get_card())
                        {
                            flag = 1;
                            col(4);
                            cout << "--------------------------------------------------------------------" << endl;
                            cout << "|     THE UNIQUE NUMBER WHICH YOU WANT HAVE ALREADY BEEN TAKEN     |" << endl;
                            cout << "|           PLEASE TRY AGAIN WITH ANOTHER UNIQUE NUMBER            |" << endl;
                            cout << "--------------------------------------------------------------------" << endl;
                        }
                        file.read((char *)&store, sizeof(store));
                    }
                    if (flag == 0)
                    {
                        string num;
                        col(5);
                        cout << "Enter the Four digit pin of your card" << endl;
                        cin >> num;
                        int pin_ln = num.length();
                        int pin_no = stoi(num);
                        cvv = store.random();
                        pin = pin_no;
                        if (pin_ln == 4)
                        {
                            col(7);
                            cout << "Enter Card holder Name" << endl;
                            cin >> name;
                            col(3);
                            cout << "Enter the amount you want to deposit in your bank " << endl;
                            cin >> amount;
                            col(2);
                            cout << "Your ATM has been created" << endl;
                            cout << "\n";
                            col(6);
                            cout << "ATM card number is :- " << crd_no << endl;
                            cout << "ATM card pin is :-    " << pin << endl;
                            cout << "CVV number is :-      " << cvv << endl;
                        }
                        else
                        {
                            col(4);cout << "The pin number you entered is not valid " << endl;
                        }
                    }
                }
                file.close();
            }
            else
            {
                col(4);
                cout << "--------------------------------------------------------------------" << endl;
                cout << "|          THE NO OF DIGITS YOU ENTERED IN NOT UPTO MARK           |" << endl;
                cout << "|           PLEASE TRY AGAIN WITH ANOTHER UNIQUE NUMBER            |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
    }
    void card_function_rupay(int x)
    {
        fstream file;
        Store_data store;
        string b=to_string(x);
        string e;
            string d = b + "69";
            col(2);
            cout << "Your RuPay card have been approved" << endl;
            col(1);
            cout << "Please enter the last Unique four Digits " << endl;
            cin >> e;
            int no_dig = e.length();
            if (no_dig == 4)
            {
                string f = d + e;
                int g = stoi(f);
                crd_no = g;
                int flag = 0;
                file.open("main.dat", ios::in | ios::binary);
                if (!file)
                {
                    col(4);
                    cout << "File not open" << endl;
                    exit(0);
                }
                else
                {
                    file.read((char *)&store, sizeof(store));
                    while (!file.eof())
                    {
                        if (crd_no == store.get_card())
                        {
                            flag = 1;
                            col(4);
                            cout << "--------------------------------------------------------------------" << endl;
                            cout << "|     THE UNIQUE NUMBER WHICH YOU WANT HAVE ALREADY BEEN TAKEN     |" << endl;
                            cout << "|           PLEASE TRY AGAIN WITH ANOTHER UNIQUE NUMBER            |" << endl;
                            cout << "--------------------------------------------------------------------" << endl;
                        }
                        file.read((char *)&store, sizeof(store));
                    }
                    if (flag == 0)
                    {
                        string num;
                        col(5);
                        cout << "Enter the Four digit pin of your card" << endl;
                        cin >> num;
                        int pin_ln = num.length();
                        int pin_no = stoi(num);
                        cvv = store.random();
                        pin = pin_no;
                        if (pin_ln == 4)
                        {
                            col(7);
                            cout << "Enter Card holder Name" << endl;
                            cin >> name;
                            col(3);
                            cout << "Enter the amount you want to deposit in your bank " << endl;
                            cin >> amount;
                            col(2);
                            cout << "Your ATM has been created" << endl;
                            cout << "\n";
                            col(6);
                            cout << "ATM card number is :- " << crd_no << endl;
                            cout << "ATM card pin is :-    " << pin << endl;
                            cout << "CVV number is :-      " << cvv << endl;
                        }
                        else
                        {
                           col(4); cout << "The pin number you entered is not valid " << endl;
                        }
                    }
                }
                file.close();
            }
            else
            {
                col(4);
                cout << "--------------------------------------------------------------------" << endl;
                cout << "|          THE NO OF DIGITS YOU ENTERED IN NOT UPTO MARK           |" << endl;
                cout << "|           PLEASE TRY AGAIN WITH ANOTHER UNIQUE NUMBER            |" << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
    }
    int get_pin()
    {
        return pin;
    }
    int get_card()
    {
        return crd_no;
    }
    int increase_balance(int num)
    {
        amount = amount + num;
        return 0;
    }
    int decrease_balance(int num)
    {
        amount = amount - num;
        return 0;
    }
};
class Transation:private Store_data
{
    private:
    string money_transfer;
    string time_of_transfer;

    public:
    int money_add(int num , string clock)
    {
        string n= to_string(num);
        money_transfer="+"+n;
        time_of_transfer=clock;
        return 0;
    }
    int money_sub(int num)
    {
        string n= to_string(num);
        money_transfer="-"+n;
        time_of_transfer=store_time();
        return 0;
    }
    void show_transation();
};
//-------------------------------------------SET TIME PASSWORD----------------------------------------------
int time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    struct std::tm* ptm = std::localtime(&current_time);
    
    int hours = ptm->tm_hour;
    int minutes = ptm->tm_min;
    int sum=hours*100+minutes;
    return sum;
}

//-----------------------------------------SET COLOUR FUNCTION----------------------------------------------
void persons_detail();
void delete_card();
void search_card();
void show_all_card();
void change_amt();
void bank_update_data();
void change_balance(int);
void change_balance(int,int);
void change_balance(int,int,int);
void change_balance_normal(int , int);
//----------------------------------------------to show transation---------------------------------------------------------------------
void Transation :: show_transation()
{
    col(6);
    // cout<<"\t\t\t\t"<<money_transfer<<"\t|\t"<<time_of_transfer<<"|"<<endl;
    // cout << "\t\t----------------------------------------------------------------------"<<endl;

}
// -------------------------------------------to change the saved data-------------------------------------------------------------------
void Store_data ::update_data(int chg_pin,int chg_cvv)
{
    pin=chg_pin;
    cvv=chg_cvv;
}
void Store_data ::update_data(char namee[100])
{
    name[100]=namee[100];
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Store_data ::put_all_data()
{
    col(2);
    cout << "\t\t|--------------------------------------------------------------------------------------------------------|" << endl;
    cout << "\t\t|"<<crd_no << setw(30) << name << setw(24) << amount << setw(16) << pin << setw(20);
    cout << cvv <<"     |"<< endl;
    
}
//----------------------------------------------------------------------------------------------------------------------------------------
void Store_data ::put_data()
{
    col(2);
    cout << "\t\t|"<<crd_no << setw(30) << name << setw(20) << amount << "       |" << endl;
    cout << "\t\t|------------------------------------------------------------------|"<<endl;

}
//------------------------------------------------------------------------------------------------------------------------------------------
void Store_data ::get_data()
{
    Store_data store;
    fstream file;
    col(8);
    cout << "\t\t\t\t|=========================================================|" << endl;
    cout << "\t\t\t\t|    ";col(3);cout<<"   In which bank you want to open your account  ";col(8);cout<<"     |" << endl;
    cout << "\t\t\t\t|                                                         |" << endl;
    cout << "\t\t\t\t|                 ";col(2);cout<<"              [1] Bank of India   ";col(8);cout<<"      |" << endl;
    cout << "\t\t\t\t|                                                         |" << endl;
    cout << "\t\t\t\t|                ";col(2);cout<<"               [2] Bank of Baroda    ";col(8);cout<<"    |" << endl;
    cout << "\t\t\t\t|                                                         |" << endl;
    cout << "\t\t\t\t|                ";col(2);cout<<"               [3] State Bank of India  ";col(8);cout<<" |" << endl;
    cout << "\t\t\t\t|                                                         |" << endl;
    cout << "\t\t\t\t|                 ";col(2);cout<<"              [4] Punjab National Bank ";col(8);cout<<" |" << endl;
    cout << "\t\t\t\t|=========================================================|" << endl;
    cout << "\t\t\t\t|             ";col(2);cout<<"       CHOOSE YOUR OPTION       ";col(8);cout<<"            |" << endl;
    cout << "\t\t\t\t|=========================================================|" << endl;
    cout << "\n";
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        col(3);
        cout << "Your Bank have been approved" << endl;
        cout << "\n";
        int  j = 456;
        col(6);
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                  ";col(5);cout<<"                [1] Master Card   ";col(6);cout<<"     |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                    ";col(5);cout<<"              [2] RuPay card      ";col(6);cout<<"   |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|          ";col(5);cout<<"    CHOOSE THE CARD TYPE YOU WANT      ";col(6);cout<<"        |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\n";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            card_function_master(j);
            break;
        }
        case 2:
        {
            card_function_rupay(j);
            break;
        }

        default:
            cout << "Wrong choice" << endl;
        }
        break;
    }
        // starting of csae 2

    case 2:
    {
        int j=856;
        col(3);
        cout << "Your Bank have been approved" << endl;
        cout << "\n";
        col(6);
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                  ";col(5);cout<<"                [1] Master Card   ";col(6);cout<<"     |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                    ";col(5);cout<<"              [2] RuPay card      ";col(6);cout<<"   |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|          ";col(5);cout<<"    CHOOSE THE CARD TYPE YOU WANT      ";col(6);cout<<"        |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\n";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            card_function_master(j);
            break;
        }

        case 2:
        {
            card_function_rupay(j);
            break;
        }

        default:
            cout << "Wrong choice" << endl;
        }
        break;
    }
        // starting of case 3

    case 3:
    {
        int j=625;
        col(3);
        cout << "Your Bank have been approved" << endl;
        cout << "\n";
        col(6);
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                  ";col(5);cout<<"                [1] Master Card   ";col(6);cout<<"     |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                    ";col(5);cout<<"              [2] RuPay card      ";col(6);cout<<"   |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|          ";col(5);cout<<"    CHOOSE THE CARD TYPE YOU WANT      ";col(6);cout<<"        |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\n";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            card_function_master(j);
            break;
        }

        case 2:
        {
            card_function_rupay(j);
            break;
        }

        default:
            cout << "Wrong choice" << endl;
        }
        break;
    }
        // starting of case 4

    case 4:
    {
        int j=729;
        col(3);
        cout << "Your Bank have been approved" << endl;
        cout << "\n";
        col(6);
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                  ";col(5);cout<<"                [1] Master Card   ";col(6);cout<<"     |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|                    ";col(5);cout<<"              [2] RuPay card      ";col(6);cout<<"   |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|          ";col(5);cout<<"    CHOOSE THE CARD TYPE YOU WANT      ";col(6);cout<<"        |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\n";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            card_function_master(j);
            break;
        }

        case 2:
        {
            card_function_rupay(j);
            break;
        }

        default:
           col(4); cout << "Wrong choice" << endl;
        }
        break;
    }

    default:
        col(4);cout << "Wrong choice" << endl;
    }
}

// starting of main function

Store_data store;
Transation trans;
fstream file;

int main()
{

    int option;
    char choice = 'y';
    system("cls");
    do
    {
        col(3);
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|    ";col(6);cout<<"                Welcome To ATM              ";col(3);cout<<"         |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\n";
        cout << "\n";
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|          ";col(6);cout<<"                     [1] User Access   ";col(3);cout<<"        |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|          ";col(6);cout<<"                     [2] Bank Manager Access ";col(3);cout<<"  |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|         ";col(6);cout<<"          CHOOSE YOUR OPTION      ";col(3);cout<<"              |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout<<" \n";
        col(7);
        cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\n";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            col(2);
            int opt;
            cout << "\t\t\t\t|=========================================================|" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|            ";col(3);cout<<"                 [1] Open New Account     ";col(2);cout<<"   |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|             ";col(3);cout<<"                [2] Check Account Balance ";col(2);cout<<"  |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|             ";col(3);cout<<"                [3] Close your Account    ";col(2);cout<<"  |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|              ";col(3);cout<<"               [4] Withdrawal OR Add Money ";col(2);cout<<"|" << endl;
            cout << "\t\t\t\t|=========================================================|" << endl;
            cout << "\t\t\t\t|            ";col(3);cout<<"        CHOOSE YOUR OPTION         ";col(2);cout<<"          |" << endl;
            cout << "\t\t\t\t|=========================================================|" << endl;
            cin >> opt;
            switch (opt)
            {
            case 1:
            {
                persons_detail();
                break;
            }
            case 2:
            {
                search_card();
                break;
            }
            case 3:
            {
                delete_card();
                break;
            }
            case 4:
            {
                change_amt();
                break;
            }
            default:
            {
                col(4);
                cout << "Wrong choice pls recheck try again" << endl;
            }
            }
            break;
        }

        case 2:
        {
            col(6);
            cout<<"\t\t\t\t\t";cout<<store_time()<<endl;
            int x=time();
            int pass;
            col(2);
            cout << "Please Enter Password to access " << endl;
            cin >> pass;

            if(x==pass)
            {
                col(5);
                int press;
                cout << "\t\t\t\t|=========================================================|" << endl;
                cout << "\t\t\t\t|                                                         |" << endl;
                cout << "\t\t\t\t|         ";col(6);cout<<"                    [1] Display all card  ";col(5);cout<<"      |" << endl;
                cout << "\t\t\t\t|          ";col(6);cout<<"                            detail     ";col(5);cout<<"        |" << endl;
                cout << "\t\t\t\t|                                                         |" << endl;
                cout << "\t\t\t\t|           ";col(6);cout<<"                  [2] Update account detail   ";col(5);cout<<"|" << endl;
                cout << "\t\t\t\t|                                                         |" << endl;
                cout << "\t\t\t\t|             ";col(6);cout<<"                [3] Delete any Account  ";col(5);cout<<"    |" << endl;
                cout << "\t\t\t\t|                                                         |" << endl;
                cout << "\t\t\t\t|=========================================================|" << endl;
                cout << "\t\t\t\t|           ";col(6);cout<<"         CHOOSE YOUR OPTION    ";col(5);cout<<"               |" << endl;
                cout << "\t\t\t\t|=========================================================|" << endl;

                cin >> press;
                switch (press)
                {
                case 1:
                {
                    show_all_card();
                    cout<<"\t\t|--------------------------------------------------------------------------------------------------------|"<<endl;
                    cout<<"\n";
                    break;
                }
                case 2:
                {
                    show_all_card();
                    cout<<"\t\t|--------------------------------------------------------------------------------------------------------|"<<endl;
                    cout<<"\n";
                    bank_update_data();
                    break;
                }
                case 3:
                {
                    show_all_card();
                    char che='y';
                    cout<<"\t\t|--------------------------------------------------------------------------------------------------------|"<<endl;
                    cout<<"\n";
                    do{
                    delete_card();
                    col(6);
                    cout<<"Press Y if you want to delete more account"<<endl;
                    cin>>che;
                    }while (che=='y'||che=='Y');
                    
                    break;
                }
                default:
                {
                    col(4);cout << "Wrong choice" << endl;
                }
                }
                break;
            }
            else 
            {
                col(4);
                cout<<"Wrong Password Please try again"<<endl;
            }
            break;
        }
        }
        col(6);
        cout << "Do you want to do another operation y or n" << endl;
        cin >> choice;
    } while (choice == 'y');
}

void persons_detail()
{

    char ch = 'y';
    file.open("main.dat", ios::app | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        store.get_data();
        file.write((char *)&store, sizeof(store));
        col(2);
        cout << "For adding more account records press y or n" << endl;
        cin >> ch;
    }
    file.close();
}
void delete_card()
{
    int no;
    col(6);
    cout << "Enter the card number you want to delete" << endl;
    cin >> no;
    ofstream file2;
    file2.open("new.dat", ios::out | ios::binary);
    file.open("main.dat", ios::in | ios::binary);
    if (!file)
    {
        col(4);cout << "File doesn't exists" << endl;
    }
    else
    {
        file.read((char *)&store, sizeof(store));
        while (!file.eof())
        {
            if (no != store.get_card())
            {
                file2.write((char *)&store, sizeof(store));
                
            }
            file.read((char *)&store, sizeof(store));
        }
        file2.close();
        file.close();
        col(4);
        cout << "Account have been deleted" << endl;
        remove("main.dat");
        rename("new.dat", "main.dat");
    }
}
void search_card()
{
    int no;
    col(6);
    cout << "Enter the card number to search in record" << endl;
    cin >> no;
    int flag = 0;
    file.open("main.dat", ios::in | ios::binary);
    if (!file)
    {
        col(4);cout << "File not open" << endl;
        exit(0);
    }
    else
    {
        file.read((char *)&store, sizeof(store));
        while (!file.eof())
        {
            if (no == store.get_card())
            {
                flag = 1;
                col(9);
                cout << "\t\t--------------------------------------------------------------------" << endl;
                cout << "\t\t|Card number\t|\tAccount holder name\t|\tBalance    |" << endl;
                cout << "\t\t--------------------------------------------------------------------" << endl;
                store.put_data();
                trans.show_transation();
            }
            file.read((char *)&store, sizeof(store));
        }
        if (flag == 0)
        {
            col(4);cout << "Card not found";
        }
    }
    file.close();
}
void show_all_card()
{
    file.open("main.dat", ios::in | ios::binary);
    if (!file)
    {
        col(4);cout << "Account does not open" << endl<< "Please open your account" << endl;
        exit(0);
    }
    else
    {
        file.read((char *)&store, sizeof(store));
        col(9);
        cout << "\t\t|--------------------------------------------------------------------------------------------------------|" << endl;
        cout << "\t\t|Card number\t|\tAccount holder name\t|\tBalance   |\t    PIN  \t|\t CVV\t |" << endl;
        while (!file.eof())
        {
            store.put_all_data();
            file.read((char *)&store, sizeof(store));
        }
    }
    file.close();
}

void bank_update_data()
{
    int no;
    char namee[100];
    int chg_pin;
    int chg_cvv;
    int chg_card;
    cout<<"Enter your card number"<<endl;
    cin>>no;
    file.open("main.dat",ios::in|ios::out|ios::binary);
    if(!file)
    {
       cout<<"File not found"<<endl;
    }
    while(file.read((char*)&store,sizeof(store)))
    {
        if(store.get_card()==no)
        {
            // cout<<"Enter the new name"<<endl;
            // cin>>namee;
            cout<<"Enter the new PIN  :- "<<endl;
            cin>>chg_pin;
            cout<<"Enter the new CVV  :- "<<endl;
            cin>>chg_cvv;
            store.update_data(chg_pin,chg_cvv);
            //store.update_data(namee);
            int pos=sizeof(store);
            file.seekp(-pos,ios::cur);
            file.write((char*)&store,sizeof(store));
        }
    }
    file.close();
}

void change_amt()
{
    int no;
    int no_card;
    col(1);
    cout << "Enter the card no you want to use"
         << "\n";
    cin >> no;
    int count = 1;
    int no_of_digit = 0;
    int temp = no;
    int temp1 = no;
    int temp2 = no;

    // For checking the number of digits entered by the user

    for (int i = 1; i <= temp; i++)
    {
        if (temp == 0)
        {
            break;
        }
        temp = temp / 10;
        count++;
    }
    if (count == 9)
    {
        col(5);
        cout << "Your card is of ";
        no_of_digit = temp1 / 1000000;

        // For checking the type of bank
        if (no_of_digit == 456) // 456 for Bank of India
        {
            cout << "Bank of India"  << endl;
        }
        else if (no_of_digit == 856) // 856 for Bank of Baroda
        {
            cout << "Bank of Baroda" << endl;
        }
        else if (no_of_digit == 625) // 625 for State Bank of India
        {
            cout << "State Bank of India" << endl;
        }
        else if (no_of_digit == 729) // 729 for Panjab National Bank
        {
            cout << "Punjab National Bank" << endl;
        }
        else
        {
            col(4);cout << "Wrong number" << endl;
        }

        // For checking the type of card (Master card, RuPay)

        int remov_dig = temp2 % 1000000;
        int last_dig = remov_dig / 10000;
        col(2);
        cout << "Your card type is ";
        if (last_dig == 45)
        {
            cout << "Master card" << endl;
        }
        else if (last_dig == 69)
        {
            cout << "RuPay" << endl;
        }
        col(6);
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|        ";col(3);cout<<"             Welcome To ATM       ";col(6);cout<<"               |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|          ";col(5);cout<<"       [1] Withdrawal  Money      ";col(6);cout<<"             |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|          ";col(5);cout<<"       [2] Add Money in Account   ";col(6);cout<<"             |" << endl;
        cout << "\t\t\t\t|                                                         |" << endl;
        cout << "\t\t\t\t|           ";col(5);cout<<"      [3] Transfer money to Another Account  ";col(6);cout<<" |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        cout << "\t\t\t\t|           ";col(5);cout<<"         CHOOSE YOUR OPTION        ";col(6);cout<<"           |" << endl;
        cout << "\t\t\t\t|=========================================================|" << endl;
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            int num;
            col(2);
            cout << "Enter the balance you want to withdrawal" << endl;
            cin >> num;
            if(num>50000)
            {
            int tempt = num;
            int a = tempt % 2000;
            int b = tempt / 2000;
            int c = a % 500;
            int d = a / 500;
            int e = c % 200;
            int f = c / 200;
            int g = e % 100;
            int h = e / 100;
            col(1);
            cout << "\t\t\t\t|=========================================================|" << endl;
            cout << "\t\t\t\t|        ";col(6);cout<<"          Your transaction is in process     ";col(1);cout<<"    |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|         ";col(4);cout<<"                      [1] For Rs 2000 Note    ";col(1);cout<<"  |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|          ";col(4);cout<<"                     [2] For Rs 500 Note    ";col(1);cout<<"   |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|           ";col(4);cout<<"                    [3] For Rs 200 Note   ";col(1);cout<<"    |" << endl;
            cout << "\t\t\t\t|                                                         |" << endl;
            cout << "\t\t\t\t|             ";col(4);cout<<"                  [4] For Rs 100 Note     ";col(1);cout<<"  |" << endl;
            cout << "\t\t\t\t|=========================================================|" << endl;
            cout << "\t\t\t\t|          ";col(4);cout<<"           CHOOSE YOUR OPTION            ";col(1);cout<<"      |" << endl;
            cout << "\t\t\t\t|=========================================================|" << endl;
            int m;
            cin >> m;
            switch (m)
            {
            case 1:
            {
                int l = num;
                int note_no = l / 2000;
                change_balance( note_no, num, no);
                break;
            }
            case 2:
            {
                int l = num;
                int note_no = l / 500;
                change_balance( note_no, num, no);
                break;
            }
            case 3:
            {
                int l = num;
                int note_no = l / 200;
                change_balance( note_no, num, no);
                break;
            }
            case 4:
            {
                int l = num;
                int note_no = l / 100;
                change_balance( note_no, num, no);
                break;
            }
            break;
            }
            }
            else
            {
                change_balance_normal(num, no);
            }
            break;
        }

        case 2:
        {
            change_balance(no);
            break;
        }
        case 3:
        {
            //  transfer money from one account to another account
            cout << "Enter the card in which you want to transfer money" << endl;
            cin >> no_card;
            change_balance(no,no_card);
        }
        break;
        default:
            col(4);cout << "Wrong choice" << endl;
        }
    }
    else
    {
        col(4);cout << "Card number is not proper"
             << "\n"
             << "Please check the number of digits you entered"
             << "\n";
    }
}
// to withdrawl money

void change_balance(int note_no, int num, int no)
{
    file.open("main.dat", ios::in | ios::out | ios::binary);
                if (!file)
                {
                    col(4);cout << "File not found";
                }
                
                while (file.read((char *)&store, sizeof(store)))
                {
                    if (store.get_card() == no)
                    {
                        int pin_no;
                        cout<<"ENTER YOUR PIN TO WITHDRAWL MONEY"<<endl;
                        cin>>pin_no;
                        if(store.get_pin()==pin_no)
                        {
                            store.decrease_balance(num);
                            int pos = sizeof(store);
                            file.seekp(-pos, ios::cur);
                            file.write((char *)&store, sizeof(store));

                            col(6);
                            cout << "You will receive " << note_no <<" notes"<< endl;
                            col(2);
                            cout << "\t\t\t\t|==========================================|" << endl;
                            cout << "\t\t\t\t|       YOUR TRANSACTION IS DONE             " << endl;
                            cout << "\t\t\t\t|                                           " << endl;
                            cout << "\t\t\t\t|     " << num << " has been debited          " << endl;
                            cout << "\t\t\t\t|==========================================|" << endl;
                            cout<<"\n";
                            col(6);cout<<"\t\t\tTIME OF TRANSACTION"<<"\t\t";cout<<store_time()<<endl;
                        }
                        else
                        {
                            col(4);
                            cout << "\t\t\t\t|==========================================|" << endl;
                            cout << "\t\t\t\t|       WRONG PIN NUMBAR TRY AGAIN         |" << endl;
                            cout << "\t\t\t\t|==========================================|" << endl;
                            cout<<"\n";
                        }
                        
                    }
                }
                file.close();
}

// add money function

void change_balance(int no)
{
    Transation trans;
    int num;
    
    cout << "Enter the balance you want to Add to your account" << endl;
            cin >> num;
            file.open("main.dat", ios::in | ios::out | ios::binary);
            if (!file)
            {
                col(4);cout << "File not found";
            }
            col(2);
                cout << "\t\t\t\t|==========================================|" << endl;
                cout << "\t\t\t\t|       YOUR TRANSACTION IS DONE             " << endl;
                cout << "\t\t\t\t|                                           " << endl;
                cout << "\t\t\t\t|       " << num << " has been debited          " << endl;
                cout << "\t\t\t\t|==========================================|" << endl;
                string clock=store_time();
                trans.money_add(num,clock);

                cout<<"\n";
                col(6);
                cout<<"\t\t\tTIME OF TRANSACTION"<<"\t\t";store_time();cout<<store_time()<<endl;
            while (file.read((char *)&store, sizeof(store)))
            {
                if (store.get_card() == no)
                {
                    store.increase_balance(num);
                    int pos = sizeof(store);
                    file.seekp(-pos, ios::cur);
                    file.write((char *)&store, sizeof(store));
                }
            }
            file.close();
}

// to transfer money from one atm account to another
void change_balance(int no,int no_card)
{
    int num;
    cout << "Enter the balance you want to Transfer" << endl;
            cin >> num;
            file.open("main.dat", ios::in | ios::out | ios::binary);
            if (!file)
            {
                col(4);cout << "File not found";
            }
            while (file.read((char *)&store, sizeof(store)))
            {
                if (store.get_card() == no)
                {
                    store.decrease_balance(num);
                    int pos = sizeof(store);
                    file.seekp(-pos, ios::cur);
                    file.write((char *)&store, sizeof(store));
                }

                // for taking the second card number and adding the amount in it

                if (store.get_card() == no_card)
                {
                    store.increase_balance(num);
                    int pos = sizeof(store);
                    file.seekp(-pos, ios::cur);
                    file.write((char *)&store, sizeof(store));
                    col(2);
                    cout << "\t\t\t\t|==========================================|" << endl;
                    cout << "\t\t\t\t|        YOUR TRANSACTION IS DONE           |" << endl;
                    cout << "\t\t\t\t|==========================================|" << endl;
                    cout<<"\n";
                    col(6);
                    cout<<"\t\t\tTIME OF TRANSACTION"<<"\t\t";cout<<store_time()<<endl;
                }
            }
            file.close();
}

void change_balance_normal( int num, int no)
{
    file.open("main.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        col(4);cout << "File not found";
    }
                
    while (file.read((char *)&store, sizeof(store)))
    {
        if (store.get_card() == no)
        {
            int pin_no;
            cout<<"ENTER YOUR PIN TO WITHDRAWL MONEY"<<endl;
            cin>>pin_no;
            if(store.get_pin()==pin_no)
            {
                store.decrease_balance(num);
                int pos = sizeof(store);
                file.seekp(-pos, ios::cur);
                file.write((char *)&store, sizeof(store));
                col(2);
                cout << "\t\t\t\t|==========================================|" << endl;
                cout << "\t\t\t\t|       YOUR TRANSACTION IS DONE             " << endl;
                cout << "\t\t\t\t|                                           " << endl;
                cout << "\t\t\t\t|     " << num << " has been debited          " << endl;
                cout << "\t\t\t\t|==========================================|" << endl;
                cout<<"\n";
                col(6);cout<<"\t\t\tTIME OF TRANSACTION"<<"\t\t";cout<<store_time()<<endl;
            }
            else
            {
                col(4);
                cout << "\t\t\t\t|==========================================|" << endl;
                cout << "\t\t\t\t|       WRONG PIN NUMBAR TRY AGAIN         |" << endl;
                cout << "\t\t\t\t|==========================================|" << endl;
                cout<<"\n";
            }
                        
        }
    }
    file.close();
}