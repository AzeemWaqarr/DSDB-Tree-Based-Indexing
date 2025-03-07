//---------------------------------------------------------------------------------///
//		Data Structures Project
//		Group Members: 
//				Areeb Hayat, 21I-0435
//				Azeem Waqar, 21I-0679
//				Kainat Ali,  21I-2470
//---------------------------------------------------------------------------------///


#include <iostream>
#include <fstream>
#include <string>
#include "RB_implemented.h"
#include "RBTree.h"
#include "BTree.h"
#include "B_implemented.h"
#include "BTreeReading_Extraction.h"
#include "AVLTree.h"
#include "AVL_implemented.h"

using namespace std;

int main() {
	
	int tree_choice;
	cout << "\t\t\tWELCOME TO DATABASE SYSTEM\n\n\n";
	cout << "\tPlease select your choice of Tree: \n";
	cout << "1. AVL Tree\n2. Red-Black Tree\n3. B-Tree\n";
	cin >> tree_choice;
	
	while (tree_choice < 1 || tree_choice > 3)
	{
		cout << "Invalid Input, Please enter valid Tree type: ";
		cin >> tree_choice;
	}

	// AVL TREE
	if (tree_choice == 1)
	{
		AVL<string> idTree;
		int choice;
		cout << "Choose:\n1. Insertion\n2. Extraction\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			char num = '1';
			bool check = false;
			while (num <= '9' && check == false) {

				idTree.root = storeID(idTree, num, '1');
				if (num == '9')
				{
					num = '0';
					check = true;
					idTree.root = storeID(idTree, num, '1');
				}
				else
					num++;
			}
			cout << "done inserting!\n";
			insertInLevelOrder(idTree, "ID");
			cout << "done doing level order!";
			break;
		}//ending case of insertion for ID

		case 2:
		{

			ID_extractToTree(idTree);
			//idTree.levelTraversal();
			//idTree.levelTraversal();
			int q;
			cout << "\nQuery to address: ";
			cout << "\n1. Search field";
			cout << "\n2. Update field";
			cout << "\n3. Delete field data.\n";
			cin >> q;

			if (q == 1)
			{
				string field;
				cout << "Enter ID to Search: ";
				cin >> field;
				searchData(idTree.root, field);
			}

			else if (q == 2)
			{
				string field;
				cout << "Enter ID to Update: ";
				cin >> field;
				update(idTree.root, field);
			}
			else if (q == 3)
			{
				string field;
				cout << "Enter ID to Delete: ";
				cin >> field;
				deleteData(idTree.root, field);
			}

		}
		}
	}

	// RED-BLACK TREE
	else if (tree_choice == 2)
	{
		string field;
		int querry_choice;
		cout << "Please enter the field to base your tree upon: ";
		cin >> field;
		string path = "RBTree.txt";
		string fname = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";
		RBTree<string> RB;
		RBNode<string>* n;
		for (int i = 1; i <= 10; i++)
		{
			RB.root = RB_read(field, fname);
			RB_writingTree(RB.root, path);
			int j = 0;
			string temp_str;
			while (fname[j] < '1' || fname[j] > '9')
			{
				temp_str += fname[j];
				j++;
			}
			string temp = to_string(i);
			temp += ".csv";
			temp_str += temp;
			fname = temp_str;
		}
		RB_retrievingTree(path);
		cout << "\tData has been extracted and saved in File & in the Tree\n\n";
		bool cont = true;
		while (cont == true)
		{
			cout << "Please select your choice of actions: ";
			cout << "1. Search Data\n2. Delete Data\n3.Update Data\n4. Range Search\n";
			cin >> querry_choice;
			while (querry_choice < 1 || querry_choice > 4)
			{
				cout << "Invalid Input, Please enter valid Tree type: ";
				cin >> tree_choice;
			}
			if (querry_choice == 1)
			{
				string search;
				cout << "Enter the key you want to search: ";
				cin >> search;
				RB_searchData(RB.root, search);
			}
			else if (querry_choice == 2)
			{
				string del;
				cout << "Enter the key you want to delete: ";
				cin >> del;
				RB_deleteData(RB.root, del);
			}
			else if (querry_choice == 3)
			{
				string upd;
				cout << "Enter the key you want to update: ";
				cin >> upd;
				RB_update(RB.root, upd, field);
			}
			else if (querry_choice == 4)
			{
				string start;
				string end;
				cout << "Enter the key you want to start search from: ";
				cin >> start;
				cout << "Enter the key you want to end search at: ";
				cin >> end;
				RB_range(RB.root, start, end);
			}
			char cont_choice;
			cout << "Do you wish to perform another Querry (Y/N): ";
			cin >> cont_choice;
			while (cont_choice != 'Y' && cont_choice != 'y' && cont_choice != 'N' && cont_choice != 'n')
			{
				cout << "Invalid Input, Please enter Y/N: ";
				cin >> cont_choice;
			}
			if (cont_choice == 'Y' || cont_choice == 'y')
				cont_choice == true;
			else if (cont_choice == 'N' || cont_choice == 'n')
				cont_choice == false;
		}
	}

	//B-TREE
	else if (tree_choice == 3)
	{
		string choice;
		string field = "ID";
		string cont;
		string print1;
		int order = 0;

		cout << "\t\tBtree" << endl << endl;
		do
		{
			do
			{
				cout << "Enter 1 if you want to Create a Btree" << endl;
				cout << "Enter 2 if you want to Extract Tree From File to Perform Operations on It" << endl;
				getline(cin, choice);
			} while (choice != "1" && choice != "2");
			if (choice == "1")
			{
				cout << "Enter Field: ";
				getline(cin, field);
				string val;
				cout << "Enter Order of Btree" << endl;
				getline(cin, val);
				int value = 0;
				int i = 0;
				while (val[i] != '\0')
				{
					value = value * 10 + (val[i] - 48);
					i++;
				}
				BTreeRead(field, value, val);
				cout << "Tree has Generated and Saved in File" << endl;
			}
			if (choice == "2")
			{
				ifstream myFile;
				myFile.open("BTree.txt");
				string line2;
				getline(myFile, line2, '\n');
				getline(myFile, field, '\n');
				int i = 0;
				int line_num = 0;
				myFile.close();
				while (line2[i] != '\0')
				{
					line_num = line_num * 10 + (line2[i] - 48);
					i++;
				}
				BTree<string> b1(line_num);
				string query;
				BTree<string>* tree = BTreeExtract(b1);
				order = tree->order;
				cout << "Tree has Been Extracted From File" << endl;
				string keyval;
				string keyval1;

				cout << "Enter 1 for Search Query" << endl;
				cout << "Enter 2 for Range Query" << endl;
				cout << "Enter 3 for Update Query" << endl;
				cout << "Enter 4 for Delete Query" << endl;
				cout << "Your Choice: " << endl;
				getline(cin, query);
				if (query == "1")
				{
					cout << "Enter Key Value: ";
					getline(cin, keyval);
					BTreeSearchData(b1.root, keyval, order);
				}
				if (query == "2")
				{
					int val1 = 0;
					int val2 = 0;
					int i = 0;
					cout << "Enter Key Value for Start of Range: ";
					getline(cin, keyval);
					while (keyval[i] != '\0')
					{
						val1 = val1 * 10 + (keyval[i] - 48);
						i++;
					}
					i = 0;
					cout << "Enter Key Value for END of Range: ";
					getline(cin, keyval1);
					while (keyval1[i] != '\0')
					{
						val2 = val2 * 10 + (keyval1[i] - 48);
						i++;
					}
					val2 = val2 - val1;
					int temp = 0;
					int temp1 = 0;
					for (int i = 0; i <= val2; i++)
					{
						BTreeSearchData(b1.root, keyval, order);
						val1++;
						temp = val1;
						keyval = "\0";
						while (temp != 0)
						{
							temp1 = (temp1 * 10) + temp % 10;
							temp /= 10;
						}
						while (temp1 != 0)
						{
							keyval += (temp1 % 10) + 48;
							temp1 /= 10;
						}
					}
				}
				if (query == "3")
				{
					cout << "Enter Key Value: ";
					getline(cin, keyval);
					BTreeUpdate(b1.root, keyval, field, order);
				}
				if (query == "4")
				{
					cout << "Enter Key Value: ";
					getline(cin, keyval);
					BTreeDeleteData(b1.root, keyval, order);
					cout << endl << "Successfully Deleted" << endl;
				}
				cout << "Do you want to print it (Y/N): ";
				getline(cin, print1);
				if (print1 == "Y")
				{
					b1.root->traverse();

				}

			}

			cout << "Do You want to Perform another operation?" << endl << "Enter -1 to terminate: ";
			getline(cin, cont);
		} while (cont != "-1");
	}

	return 0;
}