#include<iostream>
#include<fstream>
#include<cstdlib>


using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;


class account_query
{
public:
    char account_number[20];
    char firstName[10];
    char lastName[10];
    float total_Balance;
    int Age;
    const  double i = 11.5;
    double phone;
    char address[10];
    void read_data();
    void show_data();
    void Deposit_rec();
    void withdrawal_rec();
    void check_rec();
    void write_rec();
    float withdrawal;
    float Deposit;
    float years;
    float interest;
    float Loan;
    float payyear5;
    float payyear4;
    float payyear3;
    float payyear2;
    float payyear1;
    float totaldebt;
    float money;
    float remaining;
    void payment_rec();
    void  interest_rec();
    void Loan_rec();
};
void account_query::read_data()
{
    cout << "-------------------------------" << endl;
    cout << "\nEnter Account Number: ";
    cin >> account_number;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Balance: ";
    cin >> total_Balance;
    cout << "Enter Age:";
    cin >> Age;
    cout << "Enter phone Number:";
    cin >> phone;
    cout << "Enter Address:";
    cin >> address;

    cout << "-------------------------------" << endl;

}
void account_query::show_data()
{
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "\n Account Number: " << account_number << endl;
    cout << "\nFirst Name: " << firstName << endl;
    cout << "\nLast Name: " << lastName << endl;
    cout << "\nCurrent Balance: Rs.  " << total_Balance << endl;
    cout << "\nAge:" << Age << endl;
    cout << "\nphone Number:" << phone << endl;
    cout << "\nAddress:" << address << endl;



    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
}


void account_query::Deposit_rec()
{

    cout << "Enter Account Number:";
    cin >> account_number;
    cout << "Deposit Amount:";
    cin >> Deposit;
    total_Balance = total_Balance + Deposit;

    cout << "Deposit Balance=" << total_Balance;

}
void account_query::Loan_rec()
{

    cout << "Enter Account Number:";
    cin >> account_number;
    cout << "Our dear customer, the bank does not allow repayment over 5 years" << endl;
    cout << "loan Amount:";
    cin >> Loan;
    payyear1 = Loan * 20 / 100;

    cout << "Payable in the first year=" << payyear1 << endl;
    payyear2 = (Loan * 4 / 5) * 20 / 100;
    cout << "Payable in the second year=" << payyear2 << endl;
    payyear3 = (Loan * 3 / 5) * 20 / 100;
    cout << "Payable in the Third year=" << payyear3 << endl;
    payyear4 = (Loan * 2 / 5) * 20 / 100;
    cout << "Payable in the Fourth year=" << payyear4 << endl;
    payyear5 = (Loan * 1 / 5) * 20 / 100;
    cout << "Payable in the Fifth year=" << payyear5 << endl;
    totaldebt = Loan + payyear5 + payyear4 + payyear3 + payyear2 + payyear1;
    cout << "Totaldebt=" << totaldebt << endl;
}
void account_query::interest_rec()
{

    cout << "Enter Account Number:";
    cin >> account_number;
    cout << "enter the number of a years";
    cin >> years;
    interest = total_Balance * i / 100 * years;

    cout << "interest Balance=" << interest;

}
void account_query::withdrawal_rec()
{


    cout << "Enter Account Number:";
    cin >> account_number;
    cout << "Enter withdrawal:";
    cin >> withdrawal;
    if (total_Balance > withdrawal)
    {
        total_Balance = total_Balance - withdrawal;
        cout << "\n The amount has been withdrawn =" << total_Balance;
    }
    else
        cout << "Your account does not have enough balance";
}
void account_query::check_rec()
{
    cout << "Enter Account Number:";
    cin >> account_number;
    cout << "\n  Balance =" << total_Balance;

    cout << "\n  Balance with intrerst=" << total_Balance + interest;
}
void account_query::payment_rec()
{
    cout << "Enter Account Number:";
    cin >> account_number;
    cout << "enter the money:";
    cin >> money;
    cout << "\n totaldebt  =" << totaldebt;
    remaining = totaldebt - money;
    cout << "\n  The remaining amount you have to pay=" << remaining;
}
void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary | ios::app);
    read_data();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

class record :public account_query
{



public:

    void read_rec();
    void search_rec();

};

void record::read_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    cout << "\n**Data from file**" << endl;
    while (!infile.eof())
    {
        if (infile.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            show_data();
        }
    }
    infile.close();
}
void record::search_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to Search: ";
    cin >> n;
    infile.seekg((n - 1) * sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}
class Modify :public account_query
{
public:



    void edit_rec();
    void delete_rec();
};

void Modify::edit_rec()
{
    int n;
    fstream iofile;
    iofile.open("record.bank", ios::in | ios::binary);
    if (!iofile)
    {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to edit: ";
    cin >> n;
    iofile.seekg((n - 1) * sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    show_data();
    iofile.close();
    iofile.open("record.bank", ios::out | ios::in | ios::binary);
    iofile.seekp((n - 1) * sizeof(*this));
    cout << "\nEnter data to Modify " << endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void Modify::delete_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to Delete: ";
    cin >> n;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out | ios::binary);
    infile.seekg(0);
    for (int i = 0; i < count; i++)
    {
        infile.read(reinterpret_cast<char*>(this), sizeof(*this));
        if (i == (n - 1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.bank");
    rename("tmpfile.bank", "record.bank");
}


int main()
{
    account_query A;

    record R;
    Modify M;
    int choice;
    cout << "================================" << endl;

    cout << "*Acount Information System*" << endl;

    cout << "================================" << endl;

    while (true)
    {
        cout << "\n *Select one option below* \n";

        cout << "\n\t1-->Add record to file";
        cout << "\n\t2-->Show record from file";
        cout << "\n\t3-->Search Record from file";
        cout << "\n\t4-->Deposit";
        cout << "\n\t5-->withdrawal";
        cout << "\n\t6-->interest";
        cout << "\n\t7-->Loan";
        cout << "\n\t8-->Update Record";
        cout << "\n\t9-->Delete Record";
        cout << "\n\t10-->payment";
        cout << "\n\t11-->Check Balance";
        cout << "\n\t12-->Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            R.read_rec();
            break;
        case 3:
            R.search_rec();
            break;
        case 4:
            A.Deposit_rec();
            break;
        case 5:

            A.withdrawal_rec();

            break;
        case 6:

            A.interest_rec();

            break;
        case 7:
            A.Loan_rec();
            break;
        case 8:
            M.edit_rec();
            break;
        case 9:
            M.delete_rec();
            break;
        case 10:
            A.payment_rec();
            break;
        case 11:
            A.check_rec();
            break;
        case 12:
            exit(0);
            break;
        default:
            cout << "\nEnter corret choice";
            exit(0);
        }

    }
    system("pause");
    return 0;
}