/*THIS COMPLETE CODE IS BEEN WRITTEN BY SYED HASSAAN AHMED & M.AHMAR WAQAR
©. COPYRIGHT 2017.ALL RIGHTS RESERVED.
*/
#include<iostream>
#include<string.h>
#include<time.h>
#include<cstring>
#include<Windows.h>
using namespace std;
struct productNode {
	int id;
	static int i;
	char name[100];
	int price;
	int qty;
	int tprice;
	char date[20];
	char unit[50];
	productNode* next;
	productNode() {
		next = NULL;
		id = i;
		i++;
		name[0] = '\0';
		unit[0] = '\0';
		_strdate_s(date);
		price = 0;
		tprice = 0;
		qty = 1;
	}
};
struct user_accounts {
	int reg;
	int monthlyincome;
	static int rg;
	char name[100];
	char password[100];
	user_accounts* next;
	user_accounts() {
		next = NULL;
		reg = rg;
		name[0] = '\0';
		password[0] = '\0';
		rg++;
	}
};
int productNode::i = 0;
int user_accounts::rg = 0;
productNode* producthead = NULL;
user_accounts* userhead = NULL;
void signup()
{
top:
	cout << "\t\t\tSIGNUP HERE!\n\n";
	char password[100];
	user_accounts* user = new user_accounts;
	cout << "\t\tNAME: "; cin >> user->name; cout << endl;
	cout << "\t\tPASSWORD: "; cin >> user->password; cout << endl;
	cout << "\t\tENTER AGAIN: "; cin >> password; cout << endl;

	if (strcmp(user->password, password) == 0)
	{
		cout << "\t\tPASSWORD MATCHED!\n\n";
	}
	else {
		cout << "PASSWORD DIDNT MATCHED\n";
		goto top;
	}
	cout << "\t\tENTER YOUR MONTHLY INCOME TO MAKE YOUR RECORDS: "; cin >> user->monthlyincome;
	if (userhead == NULL)
	{
		userhead = user;
	}
	else
	{
		user_accounts* temp = userhead;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = user;
		user->next = NULL;
	}
}
int login()
{
	cout << "\t\tLOGIN HERE\n\n";
	user_accounts* temp = userhead;
	char password[100];
	char name[100];
	cout << "\t\tENTER USERNAME\n";
	cin >> name;
	cout << "\t\tENTER PASSWORD\n";
	cin >> password;
	if (strcmp(name, "admin") == 0 && strcmp(password, "admin") == 0)
	{
		cout << "\t\tlogged in\n\n";
		return 1;
	}
	else if (temp == NULL)
	{
		cout << "\t\tYOU DONT HAVE ACCOUNT\n\n";
		system("pause");

	}
	else
	{
		while (temp != NULL)
		{
			if ((strcmp(temp->name, name) == 0 && strcmp(temp->password, password) == 0))
			{
				cout << "\t\tlogged in\n\n";
				return 1;
			}

			temp = temp->next;

		}
	}
}
void savings()
{
	cout << "\t\t\tSAVINGS\n\n";
	productNode* temp = producthead;
	user_accounts* u = userhead;
	int saving = 0;
	int expenses = 0;
	if (temp == NULL && u->monthlyincome > 0)
	{
		cout << "YOU HAVENT BUYED ANYTHING THIS MONTH\n";
	}
	else if (temp == NULL)
	{
		cout << "YOUR LIST IS EMPTY\n";
	}
	else
	{
		while (temp != NULL)
		{
			expenses += temp->tprice;
			temp = temp->next;
		}
		cout << "YOUR MONTHLY INCOME WAS: " << u->monthlyincome << endl << endl;
		cout << "YOUR EXPENSES: " << expenses << endl << endl;
		saving = u->monthlyincome - expenses;
		if (saving < 0)
		{
			cout << "YOUR SAVINGS: " << endl << endl;;
			cout << "YOU HAVENT SAVED ANYTHING\n";
		}
		else {
			cout << "YOUR SAVINGS: " << saving << endl;
		}

	}
}
void insertNODE() {
	productNode* node = new productNode;
	cout << "ENTER PRODUCT NAME(place @ at the end of product-name)\n";
	cin.getline(node->name, 100, '@');
	cout << "ENTER QUANTITY\n";
	cin >> node->qty;
	cout << "ENTER UNIT\n";
	cin >> node->unit;
	cout << "ENETER PRICE\n";
	cin >> node->price;
	node->tprice = node->qty * node->price;
	if (producthead == NULL)
	{
		producthead = node;
		node->next = NULL;
	}
	else
	{
		productNode* temp = producthead;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
		node->next = NULL;
	}
}
void update()
{
	int tempid;
	productNode* temp = producthead;
	if (temp == NULL)
	{
		cout << "THE LIST IS EMPTY\n";
	}
	else
	{
		cout << "ENTER PRODUCT ID OF YOUR RECORD\n";
		cin >> tempid;
		while (temp != NULL)
		{
			if (temp->id == tempid)
			{
				cout << "ENTER NEW NAME OF PRODUCT(place @ at the end of product-name)\n";
				cin.getline(temp->name, 100, '@');
				cout << "ENTER NEW QTY\n";
				cin >> temp->qty;
				cout << "ENTER UNIT\n";
				cin >> temp->unit;
				cout << "ENTER NEW PRICE\n";
				cin >> temp->price;
				temp->tprice = temp->price * temp->qty;

			}

			temp = temp->next;

		}


		cout << "PARTICULAR RECORD DOESNT EXIST\n";

	}
}
void deleter()
{
	int tempid;
	productNode* curr = producthead;
	productNode* pre = producthead;
	if (producthead == NULL)
	{
		cout << "YOUR LIST IS EMPTY\n";
	}

	cout << "ENTER ID OF RECORD YOU WANT TO DELETE\n";
	cin >> tempid;
	while (curr != NULL && curr->id != tempid)
	{
		pre = curr;
		curr = curr->next;

	}
	if (curr == NULL)
	{
		cout << "RECORD NOT FOUND\n";
		return;
	}
	if (curr == producthead)
	{
		producthead = producthead->next;
		cout << "RECORD DELELTED\n";
	}
	else
	{
		pre->next = curr->next;
		if (curr->next == NULL)
		{
			curr = pre;
		}
		cout << "RECORD DELELTED\n";
	}
	delete(curr);


}
void showProducts()
{
	cout << "\t\t\tYOUR PRODUCTS\n\n";
	productNode* temp;
	temp = producthead;
	if (temp == NULL)
	{
		cout << "EMPTY\n";
	}
	else
	{
		cout << "--------------------------------------------------------------------------------------------------\n";
		cout << "NAME|\t\tID#|\t\tQTY|\t\tPRICE|\t\tTOTAL PRICE|\t\tDATE|\n";
		cout << "--------------------------------------------------------------------------------------------------\n";
		while (temp != NULL)
		{
			cout << temp->name << "\t";
			cout << temp->id << "\t";
			cout << temp->qty << "\t";
			cout << temp->price << "\t";
			cout << temp->tprice << "\t\t";
			cout << temp->date << "\t\n";
			cout << "--------------------------------------------------------------------------------------------\n";
			temp = temp->next;
		}
	}
}
void search()
{
	productNode* temp;
	temp = producthead;
	int reg;
	cout << "ENTER THE RECORD ID YOU WANT TO SEARCH\n";
	cin >> reg;
	if (temp == NULL)
	{
		cout << "\t\tEMPTY\n";
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->id == reg)
			{
				cout << "--------------------------------------------------------------------------------------------------\n";
				cout << "NAME|\tID#|\tQTY|\tPRICE|\tTOTAL PRICE|\tDATE|\n";
				cout << "--------------------------------------------------------------------------------------------------\n";
				cout << temp->name << "\t";
				cout << temp->id << "\t";
				cout << temp->qty << "\t";
				cout << temp->price << "\t";
				cout << temp->tprice << "\t\t";
				cout << temp->date << "\t\n";
				cout << "--------------------------------------------------------------------------------------------\n";
			}
			temp = temp->next;

		}
	}
}
int main()
{
	system("color F0");
	int option;
	char choice;
	int loginstatus;
	while (true)
	{
	back:
		cout << "\t\t\t\t\t\t\t\t\t\tcopyright.BIIT\n";
		cout << "\t\t\t\t\tBUDGET MANAGER\n\n\n\n";
		cout << "KINDLY SIGN IN TO PROCEED\n\n";
		cout << "PRESS S/s TO SIGHN IN\n\n";
		cout << "IF YOU DONT HAVE ACCOUNT PRESS N/n\n\n";
		cout << "PRESS E/e TO EXIT\n";
		cin >> choice;
		switch (choice)
		{
		case 's':
			loginstatus = login();
			if (loginstatus == 1)
			{
				system("cls");
				goto menue;
				system("cls");
			}
			break;
		case 'S':
			loginstatus = login();
			if (loginstatus == 1)
			{
				system("cls");
				goto menue;
				system("cls");
			}
			break;
		case 'n':
			system("cls");
			signup();
			break;
		case 'N':
			system("cls");
			signup();
			break;
		case 'e':
			return 0;
			break;
		case 'E':
			return 0;
			break;
		default:
			system("cls");
			cout << "\t\aENTER VALID INPUT\n\n";
			break;
		}
	}
	while (true)
	{
	menue:
		cout << "\t\t\t\t\tBUDGET MANAGER\n\n\n\n";
		cout << "\t\t\tPRESS 0 TO search YOUR RECORD\n";
		cout << "\t\t\tPRESS 1 TO INSERT YOUR RECORD\n";
		cout << "\t\t\tPRESS 2 TO UPDATE PARTICULAR RECORD\n";
		cout << "\t\t\tPRESS 3 TO DISPALY ALL RECORDS\n";
		cout << "\t\t\tPRESS 4 TO EXIT \n";
		cout << "\t\t\tPRESS 5 TO LOGOUT\n";
		cout << "\t\t\tPRESS 6 TO DELETE PARTICUALR RECORD\n";
		cout << "\t\t\tPRESS 7 to CHECK YOUR SAVINGS\n";
		cin >> option;
		switch (option)
		{
		case 0:
			system("cls");
			search();
			break;
		case 1:
			system("cls");
			insertNODE();
			break;
		case 2:
			system("cls");
			update();
			break;
		case 3:
			system("cls");
			showProducts();
			break;
		case 4:
			return 0;
			break;
		case 5:
			system("cls");
			goto back;
			break;
		case 6:
			system("cls");
			deleter();
			break;
		case 7:
			system("cls");
			savings();
			break;
		default:
			system("pause");
			cout << "\t\aENTER VALID INPUT\n\n";
			break;
		}
	}
	system("pause");
}