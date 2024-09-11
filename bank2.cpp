#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <ctime> // Import the ctime library

using namespace std;

class BANKMANAGEMENT{
    protected:
        // infor private
        int id,age;
        string name,dob,address,position, gender,start_to_work,contact;
        float salary;
        // username and password
        string username,password;
    public:
        // getter
        int getId(){ return id;}
        int getAge(){ return age;}
        string getStartToWork(){ return start_to_work;}
        string getName(){ return name;}
        string getDob(){ return dob;}
        string getAddress(){ return address;}
        string getPosition(){ return position;}
        string getGender(){ return gender;}
        string getUsername(){ return username;}
        string getPasswrd(){ return password;}
        string getContact(){ return contact;}
        float getSalary(){ return salary;}

        // setter

        void setId(int Id){ this->id = Id;}
        void setAge(int Age){ this->age = Age;}
        void setStartToWork(string SstartToWork){ this->start_to_work = SstartToWork;}
        void setName(string Name){ this->name = Name;}
        void setDob(string Dob){ this->dob = Dob;}
        void setAddress(string Address){ this->address = Address;}
        void setPosition(string Position){ this->position = Position;}
        void setGender(string Gender){ this->gender = Gender;}
        void setSalary(float Salary){ this->salary = Salary;}
        void setContact(string Contact){ this->contact = Contact;}

        void CreateUserNamePasSword();
        void showUserNamePasSword();
};

class APP : public BANKMANAGEMENT{
    protected:

        double internet,tv,other_payment;
        string accountNumber;
        string RandomNew;

        long double total_Balance_us = 0;
        long double total_Balance_kh = 0;
        long double amount = 0;
        long double other_account = 0;
  
        string contact;

    public:

        double water,electric;
        string Time[100];
		int choice;

        void RandomAccNumber();

        // getter

        string getTime(){
            int t = 0;
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            return Time[t] = asctime(&datetime);
            t++;
        }
		string getAccNumber(){return accountNumber;}


		double Amount();
        void myAccount(double total_Balance_us,long total_Balance_kh);
		void ManuDeposit();
		void MenuWithdraw();
		void MenuTransferOwnAcc();
		void TranserOtherOwnAcc(long double amTf, char ccTf);
		void MenuPayment();

		void PaymentWater();
		void PaymentElectric();
		void PaymentInternet();
		void PaymentTv();
		void PaymentOther();

		void massageInfo(string TypAmt, string simbol,string currencySimb,string tsf,
						 string riciver, string crAcc_dDt,string crAcc_rCv);
		

};

class STAFF : public APP{
    public:

        void insertInfoPriavte();
        void insertinfoStaffWordk();
        void diplayStaff();
};

class CUSTOMER : public STAFF {
    public:

        void insertInfoCustomer() {
            insertInfoPriavte();
            cout << "\nEnter contact          : "; cin >> contact;
        }
        void dispayCustomer();
};
 
class RUNCODE : public CUSTOMER{
    private:

        STAFF staff[10];
        CUSTOMER custom[10];

    public:

        long n_Index_Staff = 0, n_Index_Customer = 0;

        int choice;
        int i,num;
        int newId,newAge;
        int idSearch,idUpdate,idDelete;
		char tsf;

        bool isfound;
        float newSalary;

        string new_name,newGender,newDob,newAddress,newPosition,newStartToWork,newContact;
        string nameSearch;
        string usernameLog,passwordLog;

        RUNCODE();

        void ManuAdmin();
        void ManageStaff();
        void MenuStaff();
        void MenuCustomer();
        void MenuUser();
        void MenuApp();


        void AddInformationtStaff();
		void DisplayInformationStaff();
		void SearchInformationStaff();
		void UpdateInformationStaff();
		void DeleteInformationStaff();

        void CreateAccountCustomer();
		void DisplayAcountCustomer();
		void SearchAccountCustomer();
		void UpdateAccoutnCustomer();
		void DeleteAccounttCustomer();
		
		void transtertoOtherAccRv(long double amount, char currency);
		void Atm();

        void StaffLogin();

};

//DESIGN

void headerCheckAccUser(){
	cout << "\n";
    cout << "+----------------------+---------------------+-------------+-------------------------+------------------------+----------------------+\n";
    cout << "|      Acc Nmber       |        Name         |      ID     |    Total Balance US     |      Total Balance KH  |           Dob        |\n";
    cout << "+----------------------+---------------------+-------------+-------------------------+------------------------+----------------------+\n";
}

void headerUsPwdCus(){
	cout << "\n";
    cout << "                                 +-----------------------+-----------------------+-----------------------+\n";
    cout << "                                 |           Name        |        Username       |        Password       |\n";
    cout << "                                 +-----------------------+-----------------------+-----------------------+\n";
}

void headerStaffDisplay(){
	cout << "\n";
	cout << "+-----------------+----------------+------------+-------------+-------------------+----------------------+----------------------+---------------------+--------------------+\n";
	cout << "|        Name     |     Gender     |     Id     |      Age    |      Address      |           Dob        |       Position       |        Salary       |    Start_to_work   |\n";
	cout << "+-----------------+----------------+------------+-------------+-------------------+----------------------+----------------------+---------------------+--------------------+\n";
}

void headerUserDisplay(){
	cout << "\n";
    cout << "+-----------------+----------------+------------+-------------+-------------------+----------------------+----------------------+-------------------------+------------------------+\n";
    cout << "|        Name     |     Gender     |     Id     |      Age    |      Address      |           Dob        |       Contact        |    Total Balance US     |      Total Balance KH  |\n";
    cout << "+-----------------+----------------+------------+-------------+-------------------+----------------------+----------------------+-------------------------+------------------------+\n";
}

void MenuCurrency(){
	cout << "====================         ====================         ==============\n";
	cout << "=  [1] Account US  =         =  [2] Account KH  =         =  [0] Exit  =\n";
	cout << "====================         ====================         ==============\n\n";
}

void doubleRuler(){
	for(int row = 0; row < 2; row++){
		for(int col = 0; col < 100; col++){
			if(col == 0 || col == 1 || col == 98 || col == 99)
				cout << "+";
			else
				cout << "-";
		}
		cout << "\n";
	}
}

void Color8(){
    int choice;
    // while(choice!=0){
        cout << "+-------------+-------------------+--------------------+-------------------+------------+---------------------+---------------------+--------------------+\n";
        cout << "|  [1]. GRAY  |  [2]. LIGHT BLUE  |  [3]. LIGHT GREEN  |  [4]. LIGHT AQUA  |  [5]. RED  |  [6]. LIGHT PURPLE  |  [7]. LIGHT YELLOW  |  [8]. LIGHT WHILE  |\n";
        cout << "+-------------+-------------------+--------------------+-------------------+------------+---------------------+---------------------+--------------------+\n\n";
        cout << "PLEASE CHOICE: ";cin >> choice;
        switch(choice){
            case 1:system("color 8");break;
            case 2:system("color 9");break;
            case 3:system("color A");break;
            case 4:system("color B");break;
            case 5:system("color C");break;
            case 6:system("color D");break;
            case 7:system("color E");break;
            case 8:system("color F");break;
        }
    // }
	system("cls");
}


// BANK MANAGEMENT

void BANKMANAGEMENT::CreateUserNamePasSword(){
    cout << "\nSet Username: "; cin >> username;
    cout << "\nSet Password: "; cin >> password;
}
void BANKMANAGEMENT::showUserNamePasSword(){
    cout << setw(34) << "|" << setw(20) << name << "   |" << setw(20) << username << "   |" << setw(20) << password << "   |\n" ;
	cout << "                                 +-----------------------+-----------------------+-----------------------+\n";
}

// APP

void APP::RandomAccNumber(){
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            accountNumber += to_string((rand() % (i + 1)) * (i * j));
            if(accountNumber[i]==accountNumber[j+1]){
                RandomNew = to_string(rand() % (100+i));
                accountNumber.replace(0, 3, RandomNew);
            }
        }
        accountNumber += " ";
        RandomNew = to_string(rand() % 101);
    }
    if (accountNumber != "000 000 000 ")
    {
        this->accountNumber;
    }
    else
    {
        accountNumber.replace(8, 3, RandomNew);
        this->accountNumber;
    }
}
void APP::myAccount(double total_Balance_us,long total_Balance_kh){
	cout << "\n\t---------> ["<<name<<"] Account <----------\n\n";
	cout << "\tbalance US: " << total_Balance_us << " $\n";
	cout << "\tbalance KH: " << total_Balance_kh << " ៛\n";
}
double APP::Amount(){
	cout << "\n\t----------> Deoposit Account US <------------\n\n";
	cout << "Enter amount: ";
	cin >> amount;
	if(amount > 0){
		return amount;
	}else {
		cout << "\tInvalid amount!\n";
		return amount = 0;
	}
}
void APP::ManuDeposit(){
	cout << "\n============== DEPOSIT =============\n\n";
	MenuCurrency();
	cout << "Enter Choice: ";cin >> choice;
	switch(choice){
		case 1:
			total_Balance_us += Amount();
			massageInfo("Deposit","+"," $","n", "y", " "," (US) ");
		break;
		case 2:
			total_Balance_kh += Amount();
			massageInfo("Deposit","+"," R","n","y"," "," (KH) ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::MenuWithdraw(){
	cout << "\n============== WITHDRAW =============\n\n";
	MenuCurrency();
	cout << "Enter Choice: ";cin >> choice;
	switch(choice){
		case 1:
			total_Balance_us -= Amount();
			massageInfo("Withdraw","-"," $","n","n"," (US) "," ");
		break;
		case 2:
			total_Balance_kh -= Amount();
			massageInfo("Withdraw","-"," R","n","n"," (KH) "," ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::TranserOtherOwnAcc(long double amTf, char ccTf){
	if(ccTf == 'U')
		total_Balance_us -= other_account;
	else if(ccTf == 'K')
		total_Balance_kh -= other_account;
}
void APP::MenuTransferOwnAcc(){
	cout << "=============== Choose Account to Recive ================\n\n";
	MenuCurrency();
	cout << "Enter Choice: ";cin >> choice;
	switch(choice){
		case 1:
			total_Balance_kh -= Amount();
			total_Balance_us += (amount / 4000);
			massageInfo("Transfer"," "," R","t","y"," (KH) "," (US) ");
		break;
		case 2:
			total_Balance_us -= Amount();
			total_Balance_kh += (amount * 4000);
			massageInfo("Transfer"," "," $","t","y"," (US) "," (KH) ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}

void RUNCODE::transtertoOtherAccRv(long double amount, char currency){
	again:
	system("cls");
	cout << "Enter Id's riciver: "; cin >> idSearch;
	for(i = 0; i < n_Index_Customer; i++){
		if(idSearch == custom[i].getId()){
			cout << "Name           : " << custom[i].getName() << endl;
			cout << "Account Number : " << custom[i].getAccNumber() << endl;
			if(currency == 'U')
				total_Balance_us += amount;
			else if(currency == 'K')
				total_Balance_kh += amount;
			isfound = 1;
			cout << "Transfer success!\n";
			break;
		}
	}
	if(isfound != 1){
		cout << "The id [ " << idSearch <<" ] incorrect!\n";
		cout << "Do you want search again (Y or press any key): "; cin >> tsf;
		if(tsf == 'Y')
			goto again;
	}
	system("pause");
}

void APP::MenuPayment(){
	cout << "\t                                                   +---------+\n";
	cout << "\t                                                   | PAYMENT |\n";
	cout << "\t                                                   +---------+\n\n";
	cout << "\t================        ==================        ==================        ============        =======================\n";
	cout << "\t{ _[1]_ WATER  }        { _[2]_ ELECTRIC }        { [3] _INTERNET_ }        { [4] _TV_ }        { [5] _OTHER PAYMENT_ }\n";
	cout << "\t================        ==================        ==================        ============        =======================\n\n";
	cout << "________________________________________________________________________________________________________________________________\n";
	cout << "SELECT YOUR PAYMENT ON: ";cin >> choice;
	switch(choice){
		case 1:
			PaymentWater();
		break;
		case 2:
			PaymentElectric();
		break;
		case 3:
			PaymentInternet();
		break;
		case 4:
			PaymentTv();
		break;
		case 5:
			PaymentOther();
		break;
	}
}
void APP::PaymentWater(){
	cout << "=============== PAYMENT WATER ==============\n";
	MenuCurrency();
	cout << "SELECT CHOICE: ";cin >> choice;
	switch(choice){
		case 1:
			cout << "Enter Amout Water: "; cin >> water;
			total_Balance_us -= water;
			massageInfo("Water","-"," $","n","n"," (US) "," ");
		break;
		case 2:
			cout << "Enter Amout Water: "; cin >> water;
			total_Balance_kh -= water;
			massageInfo("Water","-"," R","n","n"," (KH) "," ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::PaymentElectric(){
	cout << "=============== PAYMENT Electric ==============\n";
	MenuCurrency();
	cout << "SELECT CHOICE: ";cin >> choice;
	switch(choice){
		case 1:
			cout << "Enter Amout Electric: "; cin >> electric;
			total_Balance_us -= electric;
			massageInfo("Electric","-"," $","n","n"," (US) "," ");
		break;
		case 2:
			cout << "Enter Amout Electric: "; cin >> electric;
			total_Balance_kh -= electric;
			massageInfo("Electric","-"," R","n","n"," (KH) "," ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::PaymentInternet(){
	cout << "=============== PAYMENT INTERNET ==============\n";
	MenuCurrency();
	cout << "SELECT CHOICE: ";cin >> choice;
	switch(choice){
		case 1:
			cout << "Enter Amout Internet: "; cin >> internet;
			total_Balance_us -= internet;
			massageInfo("Internet","-"," $","n","n"," (US) "," ");
		break;
		case 2:
			cout << "Enter Amout Internet: "; cin >> internet;
			total_Balance_kh -= internet;
			massageInfo("Internet","-"," R","n","n"," (KH) "," ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::PaymentTv(){
	cout << "=============== PAYMENT TY ==============\n";
	MenuCurrency();
	cout << "SELECT CHOICE: ";cin >> choice;
	switch(choice){
		case 1:
			cout << "Enter Amout Tv: "; cin >> tv;
			total_Balance_us -= tv;
			massageInfo("TV","-"," $","n","n"," (US) "," ");
		break;
		case 2:
			cout << "Enter Amout Tv: "; cin >> tv;
			total_Balance_kh -= tv;
			massageInfo("TV","-"," R","n","n"," (KH) "," ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::PaymentOther(){
	cout << "=============== PAYMENT OTHER ==============\n";
	MenuCurrency();
	cout << "SELECT CHOICE: ";cin >> choice;
	switch(choice){
		case 1:
			cout << "Enter Amout Other: "; cin >> other_payment;
			total_Balance_us -= other_payment;
			massageInfo("Other","-"," $","n","n"," (US) "," ");
		break;
		case 2:
			cout << "Enter Amout Other: "; cin >> other_payment;
			total_Balance_kh -= other_payment;
			massageInfo("Other","-"," R","n","n"," (KH) "," ");
		break;
	}
	myAccount(total_Balance_us,total_Balance_kh);
}
void APP::massageInfo(  string TypAmt, // dps, wd, dedution , water, elec, inter, tv, other
                        string simbol, // +, -
                        string currencySimb,
                        string tsf,
                        string riciver, 
                        string crAcc_dDt,
                        string crAcc_rCv ){
    system("cls");
    cout << "\n\n                       __Successfuly__                 \n\n";
    cout << "  -----------------------------------------------------------\n\n";
    cout << "     Amount"<< setw(18) << TypAmt<<" : "<<simbol<<" "<< amount << currencySimb <<"\n";
    if(tsf == "t"){
        cout << "     Account deduction amount : " << name << crAcc_dDt <<"\n";
    }
    cout << "  \n  ------------------------------------------------------------\n\n";
    if(riciver == "y"){
        cout << "     Account recive           : " << name << crAcc_rCv <<"\n";
    }
    else{
        cout << "     Account deduction amount : " << name << crAcc_dDt <<"\n";
    }
    cout << "     Account number           : " << accountNumber << "\n";
    cout << "     Date                     : " << getTime() << "\n";
    cout << "\n\n___________________________________________________________________\n";
}
void RUNCODE::Atm(){
	if(n_Index_Customer <= 0){
		cout << "Don't has any account in system!\n";
		cout << "Please create account first!!!\n";
	}else{
		cout << "++=====================================================++\n";
		cout << "||                     USER LOGIN                     ||\n";
		cout << "++=====================================================++\n\n";
		cout << "Enter Username: "; cin >> usernameLog;
		cout << "\nEnter Password: "; cin >> passwordLog;
		for(i = 0; i < n_Index_Customer; i++){
			if(usernameLog == custom[i].getUsername() && passwordLog == custom[i].getPasswrd()){
				cout << "\nLogin Success!\n\n";
				do{
					system("cls");
					cout << "|========================================================|\n";
					cout << "|/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\|\n";
					cout << "|========================================================|\n";
					cout << "\n\n\t1 <=====  M-Y  A-C-C-O-U-N-T\n\n";
					cout << "\t2 <=====  D-E-P-O-S-I-T\n\n";
					cout << "\t3 <=====  W-I-T-H-D-R-A-W\n\n";
					cout << "\t4 <=====  T-R-A-N-S-F-E-R-S\n\n";
					cout << "\t5 <=====  P-A-Y-M-E-N-T\n\n";
					cout << "\t0 <=====  B-A-C-K\n\n\n";
					cout << "|========================================================|\n";
					cout << "|/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\|\n";
					cout << "|========================================================|\n";
					cout << "\n\nPlease choose option: ";
					cin >> choice;
					switch(choice){
						case 1:
							custom[i].myAccount(total_Balance_us,total_Balance_kh);
							system("pause");
						break;
						case 2:
							custom[i].ManuDeposit();
							system("pause");
						break;
						case 3:
							custom[i].MenuWithdraw();
							system("pause");
						break;
						case 4:
							// MenuTransfer;
							if(n_Index_Customer <= 1){
								cout << "Can't Trasfer Because has only your account in the system!\n";
							}else{
								cout << "\n============== TRANSFER =============\n\n";
								cout << "[1].TRANSFER TO OWN ACCOUNT\n\n";
								cout << "[2].TRANSFER TO OTHER ACCOUNT\n\n";
								cout << "Enter Choice: ";cin >> choice;
								switch(choice){
									case 1:
										custom[i].MenuTransferOwnAcc();
									break;
									case 2:	
										MenuCurrency();
										cout << "Enter Choice: ";cin >> choice;
										switch(choice){
											case 1:
												cout << "Enter Acount: "; cin >> other_account;
												custom[i].TranserOtherOwnAcc(other_account, 'U');
												transtertoOtherAccRv(other_account, 'U');
												massageInfo("Transfer to Other"," "," $","t","y"," (US) "," (KH) ");
											break;
											case 2:
												cout << "Enter Amount: "; cin >> other_account;
												custom[i].TranserOtherOwnAcc(other_account, 'K');
												transtertoOtherAccRv(other_account, 'K');
												massageInfo("Transfer"," "," R","t","y"," (KH) "," (US) ");
											break;
										}
										custom[i].myAccount(total_Balance_us,total_Balance_kh);
									break;
									}
								}
							system("pause");
						break;
						case 5:
							custom[i].MenuPayment();
							system("pause");
						break;
					}
				}while(choice != 0) ;
				isfound = 1;
				break;
			}
		}if(!isfound){cout << "\n\nInvalid Username or Password Please try again!\n";}
	}
	system("pause");
}


// STAFF

void STAFF::insertInfoPriavte() {
    cout << "\nEnter name         : "; cin.ignore(); getline(cin,name);
    cout << "\nEnter gender       : "; cin >> gender;
    cout << "\nEnter id           : "; cin >> id;
    cout << "\nEnter age          : "; cin >> age;
    cout << "\nEnter adress       : "; cin.ignore();getline(cin,address);
    cout << "\nEnter date of birth: "; cin >> dob;
}
void STAFF::insertinfoStaffWordk(){
    cout << "\nEnter position     : "; cin.ignore();getline(cin,position);
    cout << "\nEnter salary       : $"; cin >> salary;
    cout << "\nEnter start to work: ";cin >> start_to_work;
}
void STAFF::diplayStaff(){
    cout 
    << "|"
    << setw(15) << name
    << "  |" << setw(12) << gender
    << "    |" << setw(9) << id
    << "   |" << setw(9) << age
    << "    |" << setw(17) << address
    << "  |" << setw(19) << dob

    << "   |" << setw(19) << position
    << "   |" << setw(18) <<salary
    << " $ |" << setw(18) << start_to_work << "  |" << endl;
    cout << "+-----------------+----------------+------------+-------------+-------------------+----------------------+----------------------+---------------------+--------------------+\n";
}

// CUSTOMER 
void CUSTOMER::dispayCustomer(){
    cout 
    << "|"
    << setw(15) << name
    << "  |" << setw(12) << gender
    << "    |" << setw(9) << id
    << "   |" << setw(9) << age
    << "    |" << setw(17) << address
    << "  |" << setw(19) << dob
    
    << "   |" << setw(19) << contact
    << "   |" << setw(21) << total_Balance_us
    << " $  |" << setw(21) << total_Balance_kh << "៛​  |" << endl;
    cout << "+-----------------+----------------+------------+-------------+-------------------+----------------------+----------------------+-------------------------+------------------------+\n";
}

//RUNCODE

RUNCODE::RUNCODE(){
	do{
		system("cls");
		cout << fixed << showpoint << setprecision(2);
		cout << "====================================================\n\n";
		cout << "                   __L O G I N__             \n\n";
		cout << "====================================================\n\n\n\n";
		cout << "\t[1] <---- A D M I N \n\n";
		cout << "\t[2] <---- U S E R \n\n";
		cout << "\t[3] <---- S T A F F  \n\n";
		cout << "\t[4] <---- C L O S E   P R O G R A M \n\n\n\n";
		cout <<"______________________________________________________\n\n";
		cout << "Please choose: "; cin >> choice;
		switch (choice) {
			case 1:
				// Admin
				system("cls");
				ManuAdmin();
			break;
			case 2:
				// User
				system("cls");
				MenuUser();
			break;
			case 3:
				// Stuff
				system("cls");
				StaffLogin();
			break;
		}
		system("cls"); 
	}while(choice !=4);
}
void RUNCODE::ManuAdmin(){
    do{
        doubleRuler();
        cout << "\n||                                 __B A N K  M A N A G E M E N T__                               ||\n\n";
        doubleRuler();
        cout << "\n||  \t\t\t\t\t[1]. STAFF                                                ||\n\n";
        cout << "||  \t\t\t\t\t[2]. CUSTOMER                                             ||\n\n";
        cout << "||  \t\t\t\t\t[3]. APP                                                  ||\n\n";
        cout << "||  \t\t\t\t\t[4]. COLOR                                                ||\n\n";
        cout << "||  \t\t\t\t\t[5]. EXIT                                                 ||\n\n";
        cout << "||  \t\t\t\t\t[0]. BACK                                                 ||\n\n";
        doubleRuler();
        cout << "\n\nSelect one: ";cin >> choice;
        switch(choice){
            case 1:
                // STAFF MANAGE
                MenuStaff();
            break;
            case 2:
                system("cls");
                MenuCustomer();
            break;
            case 3:
            // APP
                system("cls");
                MenuApp();
            break;
            case 4:
                system("cls");
                Color8();
            break;				
            case 5:exit(0);break;				
        }
        system("cls");
	}while(choice != 0);
}
void RUNCODE::ManageStaff(){
	do{
		system("cls");
		cout << "\n+----------------------------+            +-----------------------+           +-------------+              +------------+\n";
		cout << "|  [1]-VIEW OWN INFORMATION  |            |  [2]-MANAGE CUSTOMER  |           |  [3]-COLOR  |              |  [0]-BACK  |\n";
		cout << "+----------------------------+            +-----------------------+           +-------------+              +------------+\n\n";
		cout << "ENTER OPTION: ";cin >> choice;
		switch(choice){
			case 1:
				system("cls");
				// VIEW OWN INFORMATION
				SearchInformationStaff();
			break;
			case 2:
				system("cls");
				// Manage User
				MenuCustomer();
			break;
			case 3:
				system("cls");
				Color8();
			break;
		}
	}while(choice!=0);
}
void RUNCODE::MenuStaff(){
    do{
        system("cls");
        cout << "                         S-T-A-F-F  M-A-N-A-G-E-R         \n";
        cout << "_____________________________________________________________________________\n\n";
        cout << "\n\t[1]                ---<o>---   INSERT   ---<o>--- \n";
        cout << "\n\t[2]                ---<o>---   DISPLAY  ---<o>--- \n";
        cout << "\n\t[3]                ---<o>---   SEARCH   ---<o>--- \n";
        cout << "\n\t[4]                ---<o>---   UPDATE   ---<o>--- \n";
        cout << "\n\t[5]                ---<o>---   DELETE   ---<o>--- \n";
        cout << "\n\t[0]                ---<o>---   BACK     ---<o>--- \n";
        cout << "\n\nChoose: ";cin >> choice;
        switch(choice){
            case 1:
                system("cls");
                AddInformationtStaff();
                break;
            case 2:
                system("cls");
                DisplayInformationStaff();
                break;
            case 3:
                system("cls");
                SearchInformationStaff();
                break;
            case 4:
                system("cls");
                UpdateInformationStaff();
                break;
            case 5:
                system("cls");
                DeleteInformationStaff();
            break;
        }
        system("cls");
    }while(choice != 0);
}
void RUNCODE::MenuCustomer(){
    do{
		system("cls");
		cout << "=========================== CUSTOMer MANAGE ===========================\n\n";
		cout << "\t[1] <-- CREATE ACCOUNT\n\n";
		cout << "\t[2] <-- DISPLAY\n\n";
		cout << "\t[3] <-- SEARCH\n\n";
		cout << "\t[4] <-- UPDATE\n\n";
		cout << "\t[5] <-- DELETE\n\n";
		cout << "\t[6] <-- EXIT\n\n";
		cout << "\t[0] <-- BACK\n\n\n";
		cout <<"______________________________________________________________________________\n\n";
		cout << "SELECT: ";cin >> choice;
		switch(choice){
			case 1:
				system("cls");
				CreateAccountCustomer();
			break;
			case 2:
				system("cls");
				DisplayAcountCustomer();
			break;
			case 3:
				system("cls");
				SearchAccountCustomer();
			break;
			case 4:
				system("cls");
				UpdateAccoutnCustomer();
			break;
			case 5:
				system("cls");
				DeleteAccounttCustomer();
			break;
			case 6:exit(0);break;
		}
	}while(choice != 0);
}
void RUNCODE::MenuUser(){
    do{
		system("cls");
		cout << "===========================================================\n\n";
		cout << "                    A C L E D A  B A N K                 \n\n";
		cout << "===========================================================\n\n\n\n";
		cout << "\t1 <----  CREATE ACCOUNT\n\n";
		cout << "\t2 <----  SIGN IN\n\n";
		cout << "\t3 <----  COLOR\n\n";
		cout << "\t4 <----  EXIT\n\n";
		cout << "\t0 <----  BACK\n\n\n\n\n";
		cout << "____________________________________________________________\n\n";
		cin >> choice;
		system("cls");
		switch(choice){
			case 1:
				system("cls");
				CreateAccountCustomer();
			break;
			case 2:  
                system("cls");
                Atm();
			break;
			case 3:
				system("cls");
                Color8();
				break;
			case 4:exit(0);break;
		}
	}while(choice != 0);
}
void RUNCODE::MenuApp(){
    do{
		system("cls");
		cout << "\n";
		cout << "                     +===============================================================================+\n";
		cout << "                     |                                        APP                                    |\n";
		cout << "                     +===============================================================================+\n\n\n";
		cout << "+------------------------+                +-------------------------+             +----------------------+              +------------+              +------------+\n";
		cout << "|  [1] ACCOUNT CUSTOMER  |                |  [2] PASSWORD CUSTOMER  |             |  [3] PASSWORD STAFF  |              |  [4] EXIT  |              |  [0] BACK  |\n";
		cout << "+------------------------+                +-------------------------+             +----------------------+              +------------+              +------------+\n\n";
		cout << "ENTER CHOICE: ";cin >> choice;
		switch(choice){
			case 1:
				DisplayAcountCustomer();
			break;
			case 2:
				headerUsPwdCus();
				for(i = 0; i < n_Index_Customer; i++){
					custom[i].showUserNamePasSword();
				}
				system("pause");
			break;
			case 3:
				headerUsPwdCus();
				for(i = 0; i < n_Index_Staff; i++ ){
					staff[i].showUserNamePasSword();
				}
				system("pause");
			break;
			case 4:exit(0);break;
		}
	}while(choice!=0);
}
void RUNCODE::AddInformationtStaff(){
    cout << "                          ENTER INFORMATION STAFF               \n";
	cout << "------------------------------------------------------------------------\n\n";
	cout << "How many staff do you want input: ";
	cin >> num;
	for(i = 0; i < num;i++){
		cout << "\nNo: " << n_Index_Staff + 1 << "\n";
		staff[n_Index_Staff].insertInfoPriavte();
		staff[n_Index_Staff].insertinfoStaffWordk();
		staff[n_Index_Staff].CreateUserNamePasSword();
		n_Index_Staff++;
	}
}
void RUNCODE::DisplayInformationStaff(){
    cout <<"                                                                        DISPLAY INFORMATION STAFF                  \n";
	cout << "                                            ---------------------------------------------------------------------\n\n";
	if(n_Index_Staff > 0)
		headerStaffDisplay();
	else
		cout << "Please Input infor staff first!\n";
	
	for(i = 0; i < n_Index_Staff;i++){
		staff[i].diplayStaff();
		isfound = 1;
	}
	if(isfound==0){
		cout << "NO INFORMATION STAFF IN LIST PLEASE ENTER INFOR FIRST!\n\n";
	}
    system("pause");
}
void RUNCODE::SearchInformationStaff(){
    cout << "                                SEARCH INFORMATION STAFF                         \n";
	cout << "----------------------------------------------------------------------------------\n\n";
	cout << "[1] <--- Search by id\n";
	cout << "\n[2] <--- Search by name\n\n";
	cout << "Enter: ";
	cin >> choice;
	switch(choice){
		case 1:
			system("cls");
			cout << "                                   SEARCH BY ID                        \n";
			cout << "-------------------------------------------------------------------------\n\n";
			cout << "Enter id to search: ";
			cin >> idSearch;
			headerStaffDisplay();
			for(i = 0;i < n_Index_Staff; i++){
				if(idSearch == staff[i].getId()){
					staff[i].diplayStaff();
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 2:
			system("cls");
			cout << "                              SEARCH BY NAME                           \n";
			cout << "--------------------------------------------------------------------------\n\n";
			cout << "Enter name to search: ";
			cin.ignore();getline(cin ,nameSearch);
			cout << "\n";
			headerStaffDisplay();
			for(i = 0;i < n_Index_Staff; i++){
				if(nameSearch == staff[i].getName()){
					staff[i].diplayStaff();
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
            system("pause");
		break;
	}
}
void RUNCODE::UpdateInformationStaff(){
    cout << "                                UPDATE INFORMATION STAFF                  \n";
	cout << "___________________________________________________________________________________\n\n\n";
	cout << "\t1 <---- Update Name\n";
	cout << "\n\t2 <---- Update Id\n";
	cout << "\n\t3 <---- Update Age\n";
	cout << "\n\t4 <---- Update Gender\n";
	cout << "\n\t5 <---- Update Dob\n";
	cout << "\n\t6 <---- Update Address\n";
	cout << "\n\t7 <---- Update Start to work\n";
	cout << "\n\t8 <---- Update Salary\n";
	cout << "\n\t9 <---- Update Position\n";
	cout << "\n\t10 <---- Update All\n";
	cout << "\n\t0 <---- Back\n\n";
	cout << "Enter: ";
	cin >> choice;
	switch(choice){
		case 1:
			system("cls");
			isfound = 0;
			cout << "                      UPDATE NAME STAFF                   \n";
			cout << "--------------------------------------------------------------\n\n";
			cout << "Enter id to update name: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nName: " << staff[i].getName() << endl;
					cout << "\nEnter New Name: ";
					cin.ignore();getline(cin,new_name);
					staff[i].setName(new_name);
					cout << "\nName Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound = 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 2:
			system("cls");
			isfound = 0;
			cout << "                             UPDATE ID STAFF                       \n";
			cout << "-------------------------------------------------------------------------\n\n";
			cout << "Enter id to update id: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nId: " << staff[i].getId() << endl;
					cout << "\nEnter New Id: "; 
					cin >> newId;
					staff[i].setId(newId);
					cout << "\nId Update Comepleted!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 3:
			system("cls");
			isfound = 0;
			cout << "                           UPDATE AGE STAFF                   \n";
			cout << "-------------------------------------------------------------------\n\n";
			cout << "Enter id to update Age: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nAge: " << staff[i].getAge() << endl;
					cout << "\nEnter New Age: ";
					cin >> newAge;
					staff[i].setAge(newAge);
					cout << "\nAge Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id serch not found!\n";
			}
			system("pause");
		break;
		case 4:
			system("cls");
			isfound = 0;
			cout << "                                 UPDATE GENDER STAFF                       \n";
			cout << "-------------------------------------------------------------------------------------\n\n";
			cout << "Enter id to update Gender: ";
			cin >> idUpdate;		
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "Gender: " << staff[i].getGender() << endl;
					cout << "Enter New Gender: ";
					cin >> newGender;
					staff[i].setGender(newGender);
					cout << "Gender Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 5:
			system("cls");
			isfound = 0;
			cout << "----------> UPDATE DOB STAFF <----------\n\n";
			cout << "Enter id to update Date of birth: ";
			cin >> idUpdate;		
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nGender: " << staff[i].getDob() << endl;
					cout << "\nEnter New Date of brith: ";
					cin >> newDob;
					staff[i].setDob(newDob);
					cout << "\nDob Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 6:
		system("cls");
			isfound = 0;
			cout << "                                        UPDATE ADDRESS STAFF                          \n";
			cout << "-------------------------------------------------------------------------------------------\n\n";
			cout << "Enter id to update Address: ";
			cin >> idUpdate;		
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nAddress: " << staff[i].getAddress() << endl;
					cout << "\nEnter New Address: ";
					cin >> newAddress;
					staff[i].setAddress(newAddress);
					cout << "\nAddress Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 7:
			system("cls");
			isfound = 0;
			cout << "                                  UPDATE START TO WORK STAFF                        \n";
			cout << "----------------------------------------------------------------------------------------\n\n";
			cout << "Enter id to update Start to work: ";
			cin >> idUpdate;		
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nStart To Work: " << staff[i].getStartToWork() << endl;
					cout << "\nEnter New Day Start To Work: ";
					cin >> newStartToWork;
					staff[i].setStartToWork(newStartToWork);
					cout << "\nDay Start To Work Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 8:
			system("cls");
			isfound = 0;
			cout << "                                       UPDTE SALARY STAFF               \n";
			cout << "----------------------------------------------------------------------------------------\n\n";
			cout << "Enter id to update Salary: ";
			cin >> idUpdate;		
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nSalary: " << staff[i].getSalary() << endl;
					cout << "\nEnter New Salary: ៛";
					cin >> newSalary;
					staff[i].setSalary(newSalary);
					cout << "\nSalary Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 9:
			system("cls");
			isfound = 0;
			cout << "                                          UPDATE POSSITION STAFF                      \n";
			cout << "----------------------------------------------------------------------------------------\n\n";
			cout << "Enter id to update Position: ";
			cin >> idUpdate;		
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					cout << "\nPosition: " << staff[i].getPosition() << endl;
					cout << "\nEnter New Position: ";
					cin >> newPosition;
					staff[i].setPosition(newPosition);
					cout << "\nPosition Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 10:
			system("cls");
			isfound = 0;
			cout << "                                        UPDATE ALL STAFF                              \n";
			cout << "----------------------------------------------------------------------------------------\n\n";
			cout << "Enter id to update All: ";
			cin >> idUpdate;		
			headerStaffDisplay();
			for(i = 0; i < n_Index_Staff; i++){
				if(idUpdate == staff[i].getId()){
					staff[i].diplayStaff();
					staff[i].insertInfoPriavte();
					staff[i].insertinfoStaffWordk();
					cout << "\nAll Information Update Completed!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 0:exit(0);
	}
}
void RUNCODE::DeleteInformationStaff(){
	cout << "                                      DELETE INFORMAITON STAFF                           \n";
	cout << "----------------------------------------------------------------------------------------\n\n";
	cout << "Enter id to delete information staff: ";
	cin >> idDelete;
	for(i = 0; i < n_Index_Staff; i++){
		if(idDelete == staff[i].getId()){
			staff[i] = staff[i+1];
			n_Index_Staff--;
			isfound = 1;
			cout << "\nThis Information Staff deleted!\n";
			break;
		}
	}
	if(isfound != 1){
		cout << "\n\nThis id search not found!\n";
	}
	system("pause");
}
void RUNCODE::CreateAccountCustomer(){
    cout << "                                   CREATE ACCOUNT CUSTOMER                     \n";
	cout << "-----------------------------------------------------------------------------------\n\n";
	cout << "How many customer that you insert: ";
	cin >> num;
	for(i = 0; i < num; i++){
		cout << "\nCustomer: " << n_Index_Customer + 1 << "\n";
		custom[n_Index_Customer].insertInfoCustomer();
		system("cls");
		custom[n_Index_Customer].RandomAccNumber();
		custom[n_Index_Customer].CreateUserNamePasSword();
		n_Index_Customer++;
    }
}
void RUNCODE::DisplayAcountCustomer(){
    cout << "                                                              DISPLAY CUSTOMER                \n";
	cout << "\n";
	headerUserDisplay();
	for(i = 0; i < n_Index_Customer; i++){
		custom[i].dispayCustomer();
		isfound=1;
	}
	if(isfound == 0){
		cout << "NO INFORMATION IN LIST PLEASE ADD INFORMATION FIRST!\n\n";
	}
    system("pause");
}
void RUNCODE::SearchAccountCustomer(){
    cout << "\n1 <---- SEARCH BY ID\n";
	cout << "\n2 <---- SEARCH BY NAME\n";
	cout << "\nENTER: ";
	cin >> choice;
	switch(choice){
		case 1:
			system("cls");
			isfound = 0;
			cout << "                            SEARCH BY ID                \n";
			cout << "-----------------------------------------------------------------\n\n";
			cout << "Enter id to search: ";
			cin >> idSearch;
			headerUserDisplay();
			for(i = 0; i < n_Index_Customer; i++){
				if(idSearch == custom[i].getId()){
					custom[i].dispayCustomer();
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 2:
			system("cls");
			isfound = 0;
			cout << "                         SEARCH BY NAME              \n";
			cout << "--------------------------------------------------------------\n\n";
			cout << "Enter name to search: ";
			cin.ignore();getline(cin, nameSearch);
			headerUserDisplay();
			for(i = 0; i < n_Index_Customer; i++){
				if(nameSearch == custom[i].getName()){
					custom[i].dispayCustomer();
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis name search not found!\n";
			}
			system("pause");
		break;
	}
}
void RUNCODE::UpdateAccoutnCustomer(){
    cout << "=================================================================\n\n";
	cout << "                       UPDATE CUSTOMER                       \n\n";
	cout << "=================================================================\n\n\n\n";
	cout << "\n\t1 <----  UPDATE NAME\n";
	cout << "\n\t2 <----  UPDATE ID\n";
	cout << "\n\t3 <----  UPDATE AGE\n";
	cout << "\n\t4 <----  UPDATE GENDER\n";
	cout << "\n\t5 <----  UPDATE ADDRESS\n";
	cout << "\n\t6 <----  UPDATE CONTACT\n";
	cout << "\n\t7 <----  UPDATE DATE OF BIRTH\n";
	cout << "\n\t8 <----  UPDATE All\n";
	cout << "\n\t0 <----  BACK\n\n\n";
	cout << "\n\n__________________________________________________________________\n\n\n";
	cout << "ENTER: ";
	cin >> choice;
	switch(choice){
		case 1:
			system("cls");
			isfound = 0;
			cout << "================== UPDATE NAME CUSTOMER ================\n\n";
			cout << "Enter id to update name: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer Name : " << custom[i].getName() << endl;
					cout << "\nEnter new name: ";
					cin.ignore();getline(cin, new_name);
					custom[i].setName(new_name);
					cout << "\n\nCustomer Name Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 2:
			system("cls");
			isfound = 0;
			cout << "                               UPDATE ID CUSTOME                 \n";
			cout << "__________________________________________________________________________\n\n";
			cout << "Enter id to update: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer Id: " << custom[i].getId() << endl;
					cout << "\nEnter new Id: ";
					cin >> newId;
					custom[i].setId(newId);
					cout << "\nCustomer Id Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 3:
			isfound = 0;
			cout << "                               UPDATE AGE CUSTOMER                    \n";
			cout << "___________________________________________________________________________\n\n";
			cout << "Enter id to update: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer Age: " << custom[i].getAge() << endl;
					cout << "\nEnter new Age: ";
					cin >> newAge;
					custom[i].setAge(newAge);
					cout << "\nCustomer Age Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 4:
			system("cls");
			isfound = 0;
			cout << "                            UPDATE GENDER CUSTOMER              \n";
			cout << "_________________________________________________________________________\n\n";
			cout << "Enter id to update: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer Gender: " << custom[i].getGender() << endl;
					cout << "\nEnter new Gender: ";
					cin >> newGender;
					custom[i].setGender(newGender);
					cout << "\nCustomer Gender Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 5:
			system("cls");
			isfound = 0;
			cout << "                                 UPDATE ADDRESS CUSTOMER                   \n";
			cout << "______________________________________________________________________________________\n\n";
			cout << "Enter id to update: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer Address: " << custom[i].getAddress() << endl;
					cout << "\nEnter new Address: ";
					cin >> newAddress;
					custom[i].setAddress(newAddress);
					cout << "\nCustomer Address Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 6:
			system("cls");
			isfound = 0;
			cout << "                                 UPDATE CONTACT CUSTOMER               \n";
			cout << "______________________________________________________________________________________\n\n";
			cout << "Enter id to update: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer contact: " << custom[i].getContact() << endl;
					cout << "\nEnter new contact: ";
					cin >> newContact;
					custom[i].setContact(newContact);
					cout << "\nCustomer contact Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 7:
			system("cls");
			isfound = 0;
			cout << "                               UPDATE DATE OF BIRTH CUSTOMER                  \n";
			cout << "_________________________________________________________________________________________\n\n";
			cout << "Enter id to Dob: ";
			cin >> idUpdate;
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					cout << "\nCustomer Date of birth: " << custom[i].getDob() << endl;
					cout << "\nEnter new Date of birth: ";
					cin >> newDob;
					custom[i].setDob(newDob);
					cout << "\nCustomer Date of birth Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 8:
			system("cls");
			isfound = 0;
			cout << "                                    UPDATE ALL CUSTOMER                   \n";
			cout << "________________________________________________________________________________\n\n";
			cout << "Enter id to update: ";
			cin >> idUpdate;
			headerUserDisplay();
			for(i = 0; i < n_Index_Customer; i++){
				if(idUpdate == custom[i].getId()){
					custom[i].dispayCustomer();
					custom[i].insertInfoCustomer();
					cout << "\nCustomer All Updated!\n";
					isfound = 1;
					break;
				}
			}
			if(isfound == 0){
				cout << "\n\nThis id search not found!\n";
			}
			system("pause");
		break;
		case 0:exit(0);break;
	}
}
void RUNCODE::DeleteAccounttCustomer(){
    cout << "                                          DELETE CUSTOMER                            \n";
	cout << "_________________________________________________________________________________________\n\n";
	cout << "Enter id to delete customer: ";
	cin >> idDelete;
	for(i = 0; i < n_Index_Customer; i++){
		if(idDelete == custom[i].getId()){
			custom[i] = custom[i+1];
			n_Index_Customer--;
			isfound = 1;
			cout << "\nThis customer deleted!\n";
			break;
		}
	}
	if(isfound == 0){
		cout << "\n\nThis id search not found!\n";
	}
    system("pause");
}
void RUNCODE::StaffLogin(){
		cout << "++=====================================================++\n";
		cout << "||                     STAFF LOGIN                     ||\n";
		cout << "++=====================================================++\n\n";
		cout << "Enter Username: "; cin >> usernameLog;
		cout << "\nEnter Password: "; cin >> passwordLog;
		for(i = 0; i < n_Index_Staff; i++){
			if(usernameLog == staff[i].getUsername() && passwordLog == staff[i].getPasswrd()){
				cout << "\nLogin Success!\n\n";
				ManageStaff();
				isfound = 1;
				break;
			}
		}
		if(!isfound){
			cout << "\n\n\nInvalid Please try again or Create new Account \n\n";
		}
		system("pause");
}


int main(){
	RUNCODE();
    return 0;
}