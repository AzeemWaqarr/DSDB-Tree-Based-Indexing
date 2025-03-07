#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "AVLTree.h"
using namespace std;

///--------------------------------- FUNCTIONS -------------------------------------///

string getOriginal(string fname, int line)
{
	ifstream read;
	string data;
	//string path = "C:\\1. Kainat\\FAST\\3rd_Semester\\Data Structures\\Final Project\\datafiles\\";
	//path += fname;
	read.open(fname, ios::in);
	if (read.is_open())
		cout << "hello!";
	for (int i = 0; i < line; i++)
	{
		getline(read, data, '\n');
	}
	return data;
}

void searchData(treeNode<string>* r, string key)
{
	string data;
	string fname;
	int line_no = 0;
	AVL<string> bst;
	treeNode<string>* n;
	bst.root = r;
	n = bst.searchTree(key);
	fname = n->filename;
	string path = "";
	path += fname;
	//path += ".csv";
	line_no = n->line;
	data = getOriginal(path, line_no);
	cout << endl << endl << data << endl << endl;
}

string deleter(string fname, int line)
{
	ifstream read;
	string data;
	string temp;
	string path = "";
	path += fname;
	read.open(path);
	int i = 1;
	while (!read.eof())
	{
		if (i == line)
		{
			getline(read, temp);
			i++;
		}
		else
		{
			getline(read, temp);
			data += temp;
			data += "\n";
			i++;
		}
	}
	return data;
}

void writeFile(string fname, string data)
{
	fstream write;
	string path = "";
	path += fname;
	write.open(path);
	write << data;
}

void deleteData(treeNode<string>* r, string key)
{
	string data;
	string fname;
	int line_no = 0;
	AVL<string> bst;
	treeNode<string>* n;
	bst.root = r;
	n = bst.searchTree(key);
	fname = n->filename;
	line_no = n->line;
	data = deleter(fname, line_no);
	writeFile(fname, data);
}

string updater(string fname, int line)
{
	ifstream read;
	string data = "";
	string main_data;
	string temp;
	string original;
	original = getOriginal(fname, line);
	int choice;
	string input;

	cout << "Welcome to update menu:" << endl;
	cout << "Please choose the field you want to change" << endl;
	cout << "\t1. Year" << endl;
	cout << "\t2. 113 Cause Name" << endl;
	cout << "\t3. Cause Name" << endl;
	cout << "\t4. State" << endl;
	cout << "\t5. Deaths" << endl;
	cout << "\t6. Age-adjusted Death Rate" << endl << endl;
	cin >> choice;
	cout << endl << endl;
	int b = 0;
	for (int j = 0; j < choice; j++)
	{
		while (original[b] != ',' && original[b] != '\0')
		{
			data += original[b];
			b++;
		}
		data += original[b];
		b++;
	}
	cout << "Enter new value for this field: ";
	cin >> input;
	data += input;
	data += ',';
	while (original[b] != ',' && original[b] != '\0')
		b++;
	b++;
	while (original[b] != '\0')
	{
		data += original[b];
		b++;
	}
	data += "\0";

	string path = "";
	path += fname;
	read.open(path);
	int i = 1;
	while (!read.eof())
	{
		if (i == line)
		{
			getline(read, temp);
			main_data += data;
			main_data += "\n";
			i++;
		}
		else
		{
			getline(read, temp);
			temp += "\n";
			main_data += temp;
			i++;
		}
	}
	return main_data;
}

void update(treeNode<string>* r, string key)
{
	string data;
	string fname;
	int line_no = 0;
	AVL<string> bst;
	treeNode<string>* n;
	bst.root = r;
	n = bst.searchTree(key);
	fname = n->filename;
	line_no = n->line;
	data = updater(fname, line_no);
	writeFile(fname, data);
}

//-------------------------------------------------------
//   to store tree data in file in level order traversal
//-------------------------------------------------------
void insertInLevelOrder(AVL<string> idTree, string field) {
	ofstream DBfile;
	//---------------------------
	//    PATH TO dB FILE
	//---------------------------
	string pathToDB = "";
	pathToDB += field;
	pathToDB += "_DB.txt";
	DBfile.open(pathToDB.c_str(), ios::app);

	//---------------------------
	//Storing in level order form
	//---------------------------
	Queues<treeNode<string>*> q1;
	treeNode<string>* temp = idTree.root;
	q1.enqueue(temp);
	treeNode<string>* val;
	while (!q1.isEmpty()) {	//run while loop until queue is empty
		val = q1.dequeue()->data;
		DBfile << val->index << "," << val->filename << "," << val->line << endl;
		if (val->leftChild)
			q1.enqueue(val->leftChild);
		if (val->rightChild)
			q1.enqueue(val->rightChild);
	}
}

treeNode<string>* storeID(AVL<string> idTree, char filenum, char doubleDigitChar)
{
	ifstream file;
	ofstream filetostore;
	//-------------------------------
	// NAME OF FILE WE READING FROM
	//-------------------------------

	string fileName;
	if (filenum == '0') {
		fileName = "NCHS_-Leading_Causes_of_Death_United_States_1";
	}
	else {
		fileName = "NCHS_-Leading_Causes_of_DeathUnited_States";
		fileName += filenum;
	}
	fileName += ".csv";
	//-------------------------------------
	//PATH TO FILE WE ARE STORING DATA IN
	//-------------------------------------

	string pathtostore = "data";
	//pathtostore += filenum;
	//pathtostore += "\\";
	string currentpath = pathtostore;
	string extension = ".txt";

	string path1;
	if (filenum == '0') {
		path1 = "NCHS_-Leading_Causes_of_DeathUnited_States";
	}
	else {
		path1 = "NCHS_-Leading_Causes_of_DeathUnited_States";
	}
	path1 += filenum;
	path1 += ".csv";
	file.open(path1, ios::in);
	int count = 0;
	string headings[7];
	string word;

	//storing headings: ID, Year, 113 Cause Name, Cause Name, State, Deaths, Age-adjusted Death Rate
	while (file.good() && count < 7)
	{
		if (count < 6) {
			getline(file, word, ',');
			headings[count] = word;
			count++;
		}
		if (count == 6) {
			getline(file, word, '\n');
			headings[count] = word;
			count++;
		}
	}	//done storing headings in array

	//---------------------------------------------------------
	// STORING THE DATA OF EACH ID IN SEPARATE FILES AND TREE
	//---------------------------------------------------------
	count = 0;
	int line = 2;
	//DBfile.open(pathToDB.c_str());
	//reading from file to store data in AVL tree

	while (file.good())
	{
		if (count == 0) {	//meaning word contains ID
			getline(file, word, ',');
			idTree.root = idTree.AVLinsertion(word, fileName, line, idTree.root);
			currentpath += word;
			currentpath += ".txt";
			//filetostore.open(currentpath.c_str());			
			//filetostore << headings[count] << ": " << word << endl;			
			line++;
			count++;
		}
		else if (count == 2) {
			getline(file, word, ',');
			string dis;
			dis = word;
			int open = 0;
			int close = 0;
			int i = 0;
			while (word[i] != '\0')
			{
				if (word[i] == '(')
					open += 1;
				if (word[i] == ')')
					close += 1;
				i++;
			}
			if (close != open) {
				getline(file, word, ',');
				dis += word;
			}
			filetostore << headings[count] << ": " << dis << endl;
			count++;
		}
		else if (count < 6 && count > 0 && count != 2) {
			getline(file, word, ',');
			filetostore << headings[count] << ": " << word << endl;
			count++;
		}
		else if (count == 6) {	//meaning next line condistion
			getline(file, word, '\n');
			filetostore << headings[count] << ": " << word << endl;
			//resetting count after death rate
			filetostore.close();
			currentpath = pathtostore;
			count = 0;
		}
	}
	//-------------------------------------------------------------
	// DONE STORING THE DATA OF EACH ID IN SEPARATE FILES AND TREE
	//-------------------------------------------------------------

	return idTree.root;
}

treeNode<string>* ID_extractToTree(AVL<string>& idTree) {
	ifstream readlevelorder;
	string pathway = "id_DB.txt";
	readlevelorder.open(pathway, ios::in);		//opened file containing level order of IDs

	string arrOfIDnameLINE[3];
	int i = 0;
	while (readlevelorder.good()) {
		getline(readlevelorder, arrOfIDnameLINE[0], ',');
		getline(readlevelorder, arrOfIDnameLINE[1], ',');
		getline(readlevelorder, arrOfIDnameLINE[2], '\n');
		int i = 0;
		int line_num = 0;
		while (arrOfIDnameLINE[2][i] != '\0')
		{
			line_num = line_num * 10 + (arrOfIDnameLINE[2][i] - 48);
			i++;
		}
		if (arrOfIDnameLINE[1] != "NCHS_-Leading_Causes_of_Death_United_States_1.csv")
		{

		}
		idTree.root = idTree.AVLinsertion(arrOfIDnameLINE[0], arrOfIDnameLINE[1], line_num, idTree.root);
		i++;
	}
	readlevelorder.close();
	//idTree.levelTraversal();
	return idTree.root;
}

///---------------------------------------------------------------------------------///
