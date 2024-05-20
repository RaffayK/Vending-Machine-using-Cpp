#include<iostream>
using namespace std;
struct node {
	int quantity;
	int price;
	string productName;
	node* next;
}*lays, * oreo, * cheetos, * wavy, * pringle, * pepsi, * dew, * kurkure, * redbull, * sting;
int depart;
string item[10];
int items = 0;
int total = 0;
int grandTotal = 0;
int change = 0;
int amount = 0;
node* insertAtEnd(int data, string name, node* Node, int  quantity) {
	struct node* ptr, * tempnode;
	tempnode = new node();
	tempnode->price = data;
	tempnode->productName = name;
	ptr = Node;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = tempnode;
	tempnode->quantity = quantity;
	tempnode->next = NULL;
	return Node;
}
node* Delete(node* Node) {
	node* tempNode = Node;
	Node = Node->next;
	free(tempNode);
	return Node;
}
node* Remove(node* Node) {
	if (Node->quantity < 1) {
		cout << "No items available" << endl;
		return Node;
	}
	Node = Delete(Node);
	item[items] = Node->productName;
	items++;
	total += Node->price;
	return Node;
}
node* createNode(int size, string name, int price, node* Node) {

	struct node* temp;
	temp = new node();
	for (int i = 0; i <= size; i++) {
		if (Node == NULL) {

			temp->productName = name;
			temp->price = price;
			temp->quantity = size;
			temp->next = NULL;
			Node = temp;
		}
		else {
			--size;
			Node = insertAtEnd(price, name, Node, size);
		}
	}
	return Node;
}

node* adminAdd(string name, int price, node* Node, int size) {
	//insertAtEnd(price,name, Node);
	Node = createNode(size, name, price, Node);
	return Node;
}

void calculateChange(int price, int coins) {
	cout << "Enter amount to buy items: ";
	cin >> coins;
	if (coins < total) {
		cout << "Amount you entered is less than amount payable" << endl;
	}
	else {
		cout << endl;
		change = coins - total;
		cout << "Your change is: ";
		cout << change << endl;
		cout << "ThankYou for shopping with us!!" << endl;
	}
}
void Traverse() {
	cout << "==========================================================\n";
	cout << "S.No        Product Name         Price          Quantity          " << endl;
	cout << "==========================================================\n";

	if (lays->quantity < 1) {
		cout << "Lays Not available" << endl;
	}
	else {
		cout << "1) " << "\t \t" << lays->productName << "\t \t  " << lays->price << "\t \t  " << lays->quantity;
	}
	cout << endl;
	if (oreo->quantity < 1) {
		cout << oreo->productName << " Not available" << endl;
	}
	else {
		cout << "2) " << "\t \t" << oreo->productName << "\t \t  " << oreo->price << "\t \t  " << oreo->quantity;
	}
	cout << endl;
	if (cheetos->quantity < 1) {
		cout << cheetos->productName << " Not available" << endl;
	}
	else {
		cout << "3) " << "\t \t" << cheetos->productName << "\t \t  " << cheetos->price << "\t \t  " << cheetos->quantity;
	}
	cout << endl;
	if (wavy->quantity < 1) {
		cout << "wavy Not available" << endl;
	}
	else {
		cout << "4) " << "\t \t" << wavy->productName << "\t \t  " << wavy->price << "\t \t  " << wavy->quantity;
	}
	cout << endl;
	if (pringle->quantity < 1) {
		cout << "pringle Not available" << endl;
	}
	else {
		cout << "5) " << "\t \t" << pringle->productName << "\t \t  " << pringle->price << "\t \t  " << pringle->quantity;
	}
	cout << endl;
	if (pepsi->quantity < 1) {
		cout << "pepsi Not available" << endl;
	}
	else {
		cout << "6) " << "\t \t" << pepsi->productName << "\t \t  " << pepsi->price << "\t \t  " << pepsi->quantity;
	}
	cout << endl;
	if (dew->quantity < 1) {
		cout << "dew Not available" << endl;
	}
	else {
		cout << "7) " << "\t \t" << dew->productName << "\t \t  " << dew->price << "\t \t  " << dew->quantity;
	}
	cout << endl;
	if (kurkure->quantity < 1) {
		cout << "kurkure Not available" << endl;
	}
	else {
		cout << "8) " << "\t \t" << kurkure->productName << "\t \t  " << kurkure->price << "\t \t  " << kurkure->quantity;
	}
	cout << endl;
	if (redbull->quantity < 1) {
		cout << "pringle Not available" << endl;
	}
	else {
		cout << "9) " << "\t \t" << redbull->productName << "\t \t  " << redbull->price << "\t \t  " << redbull->quantity;
	}
	cout << endl;
	if (sting->quantity < 1) {
		cout << "sting Not available" << endl;
	}
	else {
		cout << "10) " << "\t \t" << sting->productName << "\t \t  " << sting->price << "\t \t  " << sting->quantity;
	}
	cout << endl;
}

void MainMenu() {
	system("cls");
	cout << endl;
	cout << endl;
	cout << "          " << "   ================================================================================" << endl;
	cout << "          " << "					VENDING MACHINE                    " << endl;
	cout << "             ================================================================================ " << endl;
	cout << "                                    " << "      ============================ " << endl;
	cout << "                                    " << "      " << "  | 01. Admin Portal     |" << endl;
	cout << "                                    " << "      " << "  | 02. User Portal      |" << endl;
	cout << "                                    " << "      " << "  | 03. Exit             |" << endl;
	cout << "                                    " << "      ============================ " << endl;
	cout << "                                    " << '\n';
	cout << "                                      Please Select Your Option (1/2/3) : ";
	cin >> depart;
}

int main() {
	int AddItem;
	int AddQuant;
	string pass;
	int AdminSelection;
	int UserSelection;
	char choice = 'y';

	lays = createNode(10, "Lays", 50, lays);
	oreo = createNode(10, "oreo", 25, oreo);
	cheetos = createNode(10, "Cheetos", 50, cheetos);
	wavy = createNode(10, "Wavy", 100, wavy);
	pepsi = createNode(10, "pepsi", 60, pepsi);
	pringle = createNode(10, "pringle", 250, pringle);
	dew = createNode(10, "Dew", 60, dew);
	kurkure = createNode(10, "Kurkure", 30, kurkure);
	redbull = createNode(10, "Redbull", 300, redbull);
	sting = createNode(10, "Sting", 70, sting);
label1:
	MainMenu();
	system("cls");

	if (depart == 1) {
		cout << " Enter Admin Portal Password : ";
		cin >> pass;

		if (pass == "dsaproject") {
			system("cls");
			cout << endl;
			cout << endl;
			cout << "            " << "   =============== " << endl;
			cout << "            " << "    Welcome Admin   " << endl;
			cout << "            " << "   =============== " << endl;
			cout << "        ============================================ " << endl;
			cout << "        " << "  | 01. See Items In the Machine     | " << endl;
			cout << "        " << "  | 02. Add Items In the Machine     | " << endl;
			cout << "        " << "  | 03. Go Back To Main Menu         | " << endl;
			cout << "        ============================================ " << endl;
			cout << '\n';
			do {

				cout << "    Please Select Your Option (1/2/3) : ";
				cin >> AdminSelection;

				if (AdminSelection == 2) {
					cout << endl;
					cout << endl;
					cout << "Which item you want to add?, enter numeric values according to list: ";
					cin >> AddItem;
					switch (AddItem) {
					case 1: if (lays->quantity < 6) {

						lays = createNode(10, "Lays", 50, lays);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 2: if (oreo->quantity < 6) {

						oreo = createNode(10, "oreo", 25, oreo);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 3: if (cheetos->quantity < 6) {

						cheetos = createNode(10, "Cheetos", 50, cheetos);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 4: if (wavy->quantity < 6) {

						wavy = createNode(10, "Wavy", 50, wavy);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 5: if (pepsi->quantity < 6) {

						pepsi = createNode(10, "pepsi", 60, pepsi);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 6: if (pringle->quantity < 6) {

						pringle = createNode(10, "pringle", 250, pringle);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 7: if (dew->quantity < 6) {

						dew = createNode(10, "Dew", 60, dew);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 8: if (kurkure->quantity < 6) {

						kurkure = createNode(10, "Kurkure", 30, kurkure);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 9: if (redbull->quantity < 6) {

						redbull = createNode(10, "Redbull", 300, redbull);
						cout << "Item added" << endl;
					}
						  else { cout << "No need to enter" << endl; }
						  break;
					case 10: if (sting->quantity < 6) {

						sting = createNode(10, "sting", 70, sting);
						cout << "Item added" << endl;
					}
						   else { cout << "No need to enter" << endl; }
					}
				}
				else if (AdminSelection == 1) {
					cout << endl;
					Traverse();
				}
				else if (AdminSelection == 3) {
					cout << endl;


					goto label1;

				}
				cout << endl;
			} while (choice != 'N' && choice != 'n');
		}
		else {
			cout << "Wrong password Please try again\n " << endl;
			system("pause");
			goto label1;
		}
	}
	else if (depart == 2) {
		system("cls");
		cout << endl;
		cout << endl;
		cout << "          " << "   =============== " << endl;
		cout << "          " << "     Welcome User   " << endl;
		cout << "          " << "   =============== " << endl;
		cout << "      ============================================================ " << endl;

		cout << "      " << "  | 01. Add Items In Cart                            | " << endl;
		cout << "      " << "  | 02. Display Items in Cart                        | " << endl;
		cout << "      " << "  | 03. Calculate Amount of Items you Buy            | " << endl;
		cout << "      " << "  | 04. Go Back To Main Menu                         | " << endl;
		cout << "      ============================================================ " << endl;
		cout << '\n';
		Traverse();
		do {

			cout << "    Please Select Your Option (1/2/3/4) : ";
			cin >> UserSelection;

			if (UserSelection == 1) {

				cout << "Enter your choice : ";
				cin >> UserSelection;
				switch (UserSelection) {
				case 1: lays = Remove(lays);
					break;
				case 2: oreo = Remove(oreo);
					break;
				case 3: cheetos = Remove(cheetos);
					break;
				case 4: wavy = Remove(wavy);
					break;
				case 5: pringle = Remove(pringle);
					break;
				case 6: pepsi = Remove(pepsi);
					break;
				case 7: dew = Remove(dew);
					break;
				case 8: kurkure = Remove(kurkure);
					break;
				case 9: redbull = Remove(redbull);
					break;
				case 10: sting = Remove(sting);
					break;
				}
			}

			else if (UserSelection == 4) {
				goto label1;
			}
			else if (UserSelection == 3) {
				cout << "========================\n";
				cout << "Total amount payable is: ";
				cout << total << " Rupees " << endl;
				cout << "========================\n";
				calculateChange(total, amount);
			}
			else if (UserSelection == 2) {
				cout << "Your items: ";
				for (int i = 0; i < items; i++) {
					cout << item[i] << " , ";
				}
				cout << endl;
			}
		} while (choice != 'N' && choice != 'n');
	}

	else if (depart == 3) {

		return 0;
	}
}

