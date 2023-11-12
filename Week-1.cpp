#include <iostream>
#include <vector>
using namespace std;

class items {
public:
	string Category;
	string description;
	double price;
	string itemCode;

	void makeObj(items* obj, int code, int selection) {
		switch (selection) {
		case 1:
			obj->Category = "Case";

			switch(code){
			case 1:
				obj->description = "Compact";
				obj->price = 75;
				obj->itemCode = "A1";
				break;
			
			case 2:
				obj->description = "Tower";
				obj->price = 150;
				obj->itemCode = "A2";
				break;
			}
			break;
		case 2:
			obj->Category = "RAM";

			switch (code) {
			case 1:
				obj->description = "8 GB";
				obj->price = 79.99;
				obj->itemCode = "B1";
				break;

			case 2:
				obj->description = "16 GB";
				obj->price = 149.99;
				obj->itemCode = "B2";
				break;

			case 3:
				obj->description = "32 GB";
				obj->price = 299.99;
				obj->itemCode = "B3";
				break;
			}
			break;
		case 3:
			obj->Category = "Main HDD";

			switch (code) {
			case 1:
				obj->description = "1TB HDD";
				obj->price = 49.99;
				obj->itemCode = "C1";
				break;

			case 2:
				obj->description = "2TB HDD";
				obj->price = 89.99;
				obj->itemCode = "C2";
				break;

			case 3:
				obj->description = "4TB HDD";
				obj->price = 129.99;
				obj->itemCode = "C3";
				break;
			}
			break;
		case 4:
			obj->Category = "SSD";

			cout << "1) 240 GB SSD" << endl << "2) 480 GB SSD" << endl << endl << "Enter:";

			//validating input
			do {
				cin >> code;

				if (code < 1 || code >2)
					cout << "invalid!" << endl << "Enter: " ;

			} while (code < 1 || code >2);

			switch (code) {
			case 1:
				obj->description = "240GB SSD";
				obj->price = 59.99;
				obj->itemCode = "D1";
				break;

			case 2:
				obj->description = "480GB SSD";
				obj->price = 119.99;
				obj->itemCode = "D2";
				break;
			}
			break;
		case 5:
			obj->Category = "Secondary HDD";

			cout << "1) 1TB HDD" << endl << "2) 2TB HDD" << endl << "3) 4TB HDD" << endl << endl << "Enter:";

			//validating input
			do {
				cin >> code;

				if (code < 1 || code >3)
					cout << "invalid!" << endl << "Enter: " ;

			} while (code < 1 || code >3);

			switch (code) {
			case 1:
				obj->description = "1TB HDD";
				obj->price = 49.99;
				obj->itemCode = "E1";
				break;

			case 2:
				obj->description = "2TB HDD";
				obj->price = 89.99;
				obj->itemCode = "E2";
				break;

			case 3:
				obj->description = "4TB HDD";
				obj->price = 129.99;
				obj->itemCode = "E3";
				break;
			}
			break;
		case 6:
			obj->Category = "Optical Drive";

			cout << "1) DVD/Blu-Ray Player" << endl << "2) DVD/Blue-Ray Re-writer" << endl << endl << "Enter:";

			//validating input
			do {
				cin >> code;

				if (code < 1 || code >2)
					cout << "invalid!" << endl << "Enter: " ;

			} while (code < 1 || code >2);

			switch (code) {
			case 1:
				obj->description = "DVD/Blue-Ray Player";
				obj->price = 50;
				obj->itemCode = "F1";
				break;

			case 2:
				obj->description = "DVD/Blue-Ray Re-writer";
				obj->price = 100;
				obj->itemCode = "F2";
				break;
			}
			break;
		case 7:
			obj->Category = "Operating System";

			cout << "1) Standard Version" << endl << "2) Professional Version" << endl << endl << "Enter:";

			//validating input
			do {
				cin >> code;

				if (code < 1 || code >2)
					cout << "invalid!" << endl << "Enter: " ;

			} while (code < 1 || code >2);

			switch (code) {
			case 1:
				obj->description = "Standard Version";
				obj->price = 100;
				obj->itemCode = "G1";
				break;

			case 2:
				obj->description = "Professional Version";
				obj->price = 175;
				obj->itemCode = "G2";
				break;
			}
			break;
		}
	}

};
class Computer {
public:

	vector<items*> itemsArray;

	void display() {
		for (int i = 0; i < itemsArray.size(); i++) {
			items* display = this->itemsArray[i];
			cout << "\t" << display->Category << " | ";
			cout << display->itemCode << " | ";
			cout << display->description << " | ";
			cout << display->price << "$" << endl;
		}
		cout << endl;
	}
};

void clrscr() {
	system("cls");
}

void addItem(items* Obj, int givenCode, int menuSelection, double& Total_price, Computer& computer) {
	//filling object with details
	Obj->makeObj(Obj, givenCode, menuSelection);
	
	//calculating Total Price
	Total_price += Obj->price;

	//pushing object to the dynamic array
	computer.itemsArray.push_back(Obj);
}

string Discount(int additionalItemsCount) {
	if (additionalItemsCount == 0) {
		return "0%";
	}
	else if (additionalItemsCount == 1) {
		return "5%";
	}
	else {
		return "10%";
	}
}

void exit(double TotalBill, Computer comp, int additionalItemsCount) {
	cout << "***********************************************************************" << endl;
	cout << "***********************************************************************" << endl;
	cout << "*********************Thank You For The Purchase************************" << endl;
	cout << "***********************************************************************" << endl;
	cout << "***********************************************************************" << endl << endl;
	cout << "Your Total Bill is: " << TotalBill << "$" << "\t(Discount applied to the Total Bill: " << Discount(additionalItemsCount) << ")" << endl;
	
	//calculating discount
	if (additionalItemsCount == 1)
		TotalBill -= (TotalBill * 5) / 100;
	else if (additionalItemsCount > 1)
		TotalBill -= (TotalBill * 10) / 100;

	cout << "Your Bill after Discount is: " << TotalBill  << "$" << endl << endl;
	cout << "Your Receipt:" << endl;
	comp.display();

}

int main() {

	double Total_price = 0;
	int additionalItemsCount=0;
	int givenCode;
	int menuSelection;
	char yesORno;
	Computer computer;
	items* Obj;

	//Choosing Case (Compulsory)
	Obj = new items();
	cout << "which Case would you like?" << endl << "1) Compact" << endl << "2) Tower" << endl << endl << "Enter:";
	menuSelection = 1;

	//validating input
	do {
		cin >> givenCode;

		if (givenCode < 1 || givenCode >2)
			cout << "invalid!" << endl << "Enter: " ;

	} while (givenCode < 1 || givenCode > 2);

	addItem(Obj, givenCode, menuSelection, Total_price, computer);
	clrscr();
		
	//Choosing RAM (Compulsory)
	Obj = new items();
	cout << "which RAM would you like?" << endl << "1) 8GB" << endl << "2) 16GB" << endl << "3) 32GB" << endl << endl << "Enter:";
	menuSelection = 2;

	//validating input
	do {
		cin >> givenCode;

		if (givenCode < 1 || givenCode >3)
			cout << "invalid!" << endl << "Enter: " ;

	} while (givenCode < 1 || givenCode > 3);

	addItem(Obj, givenCode, menuSelection, Total_price, computer);
	clrscr();
		
	//Choosing Main HDD (Compulsory)
	Obj = new items();
	cout << "which Main HDD would you like?" << endl << "1) 1TB HDD" << endl << "2) 2TB HDD" << endl << "3) 4TB HDD" << endl << endl << "Enter:";
	menuSelection = 3;

	//validating input
	do {
		cin >> givenCode;

		if (givenCode < 1 || givenCode >3)
			cout << "invalid!" << endl << "Enter: " ;

	} while (givenCode < 1 || givenCode > 3);

	addItem(Obj, givenCode, menuSelection, Total_price, computer);
	clrscr();

	cout << "Do you want to add additional items? (y/n)" << endl << endl << "Enter: ";
	
	//validating input
	do {
		cin >> yesORno;

		if (yesORno != 'y' && yesORno != 'n')
			cout << "invalid!" << endl << "Enter: " ;

	} while (yesORno != 'y' && yesORno != 'n');

	clrscr();

	if (yesORno == 'y') {

		while(menuSelection != 8 ) {

			//making object at runtime
			Obj = new items();

			//additional items
				cout << "select additional items you want to add (optional):" << endl;
				cout << "1) SSD" << endl << "2) Secondary HDD" << endl << "3) Optical Drive" << endl << "4) Operating System" << endl << "5) Confirm and Finalize purchase" << endl << endl << "Enter: ";
			
			//validating input
			do {
				cin >> menuSelection;
				cout << endl;
				menuSelection += 3;

				if (menuSelection < 4 || menuSelection >8)
					cout << "invalid!" << endl << endl << "Enter: " ;

			} while (menuSelection < 4 || menuSelection > 8);

			if (menuSelection != 8) {

				addItem(Obj, givenCode, menuSelection, Total_price, computer);
				additionalItemsCount++;
				
				clrscr();

				cout << "Your Total Bill: " << Total_price << "$" << endl;
				cout << "Discount to be applied on this purchase: " << Discount(additionalItemsCount) << endl << endl;

				//displaying all the items
				cout << "Your Current Items in cart: " << endl;
				computer.display();

			}
		}
	}

	clrscr();
	exit(Total_price, computer, additionalItemsCount);

	//emptying the RAM
	while (!computer.itemsArray.empty()) {

		// pointing to, and deleting every item in the vector
		items* deleter;
		deleter = computer.itemsArray.at(computer.itemsArray.size() - 1);
		delete deleter;

		computer.itemsArray.pop_back();
	}

	return 0;
}