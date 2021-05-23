#include<iomanip>
#include<conio.h>
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
class book{       //book of name book
	int isbn_no;
	int university_rollno, date_of_issue, month_of_issue, year_of_issue; // user data
	string bookcategory, bookpubcom, bookname, authorname;     ///Members of Class book///
	friend class library;
	public:
		book(){
			date_of_issue = 0;
		}
};
class library{
	book books[1000];		//array of book
	int n = 0;                   //variable for number of records
	public:
	void gotoxy(short , short );
	void display(); //display function
	void add();     //add function
	void issue();	//issue function
	void return_book();	//return_book function
	void search();  //search function
	void sort();    //sort function
	void del();     //delete function
	void modify();  //modify function
	void sbyname(); //search by name
	void sbyid();   //search by id
	void sbycategory();  //search by category
	void sbypubcom();    //search by publication company
	void sbyauthor();    //search by author
	void sortas();     //sort in ascending order
	void sortds();     //sort in descending order
	void sortasname(); //sort in ascending order by name
	void sortasid();   //sort in ascending order by id
	void sortascategory();  //sort in ascending order by category
	void sortaspubcom();   //sort in ascending order by publication company
	void sortasauthor();  //sort in ascending order by author
	void sortdsname();   //sort in descending order by name
	void sortdsid();     //sort in descending order by id
	void sortdscategory();  //sort in descending order by category
	void sortdspubcom();    //sort in descending order by publication company
	void sortdsauthor();    //sort in descending order by author
	void dbyname();    //delete by name
	void dbyid();      //delete by id
	void dbycategory();  //delete by category
	void dbypubcom();    //delete by publication company
	void dbyauthor();    //delete by author
	void mbyname();      //modify by name
	void mbyid();        //modify by id
	void mbycategory();  //modify by cateory
	void mbypubcom();    //modify by publication company
	void mbyauthor();    //modify by author
};
bool ps(string a, string b){			// check if a is in b or not
	int n = a.size(), m = b.size(), c = 0;
	for(int i = 0; i < m; i++){
		if(a[0] == b[i]){
			int l = 0;
			while(i < m && l < n){
				if(a[l] == b[i]){
					l++;
					i++;
				}
				else{
					i++;
				}
				if(l == n){
					c++;
					break;
				}
			}
		}
		if(c > 0){
			return true;
		}
	}
	return false;
}
void library::display(){
	system("cls");
	cout<< "In display function\n";
	cout<<"________________________________________________________________________________________________________________________________________________________________________"<<endl;
	for(int i=0;i<n;i++){
		cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
		if(books[i].date_of_issue != 0){
			cout<<"\nUniversity Roll No:"<<books[i].university_rollno<<endl<<"Date of issue: "<<books[i].date_of_issue<<"-"<<books[i].month_of_issue<<"-"<<books[i].year_of_issue<<endl;
		}
		cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}

void library::add(){
	char ch, id1[6], year[4];
	do
	{
		system("cls");
		cout<<endl;
		cout<< "In ADD function\n";
		cout<<"Enter Book Name: ";
		cin>>books[n].bookname;
		cout<<"Enter Book ID: ";
		cin>>books[n].isbn_no;
		cout<<"Enter Author Name: ";
		cin>>books[n].authorname;
		cout<<"Enter Book Category: ";
		cin>>books[n].bookcategory;
		cout<<"Enter Publication Company Name: ";
		cin>>books[n].bookpubcom;
		n++;
	cout<<"Do you want to add more books? [y/n]";
	ch=getch();
	}
	while(ch!='n'&& ch!='N');
}
void library::search(){
	system("cls");

	cout <<setw(30)<< "In Search Function"<<endl
		<< setw( 52 )<< "Please choose one of the options below: "

		<< endl << setw( 71 )

		<< "--------------------------------------------------------------"

		<< endl << endl

		<< setw( 31 ) << "( N ) Search by name" << endl << endl

		<< setw( 29 ) << "( I ) Search by Id" << endl << endl

		<< setw( 38 ) << "( T ) Search by author name" << endl << endl

		<< setw( 35 ) << "( C ) Search by Category" << endl << endl

		<< setw( 46 ) << "( P ) Search by Publication Company" << endl << endl

		<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
		gotoxy(30,14);

	switch(getche())
	{
		case 'n':
		case 'N':sbyname();break;

		case 'i':
		case 'I': sbyid();break;

		case 't':
		case 'T': sbyauthor();break;

		case 'c':
		case 'C':sbycategory();break;

		case 'p':
		case 'P':sbypubcom();break;

		default:
	puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
	getch();
	search();
	getch();
	}
}
void library::sbyname(){
	string name;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Searching by name of book\n";
	cout<<"Enter the name of book you want to search: ";
	cin>>name;
	for(int i = 0;i<n;i++)
	{
		if(books[i].bookname == name)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			break;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
		cout<<"Do want partial search if yes enter 1 else 0\n";
		int k;
		cin>>k;
		if(k){
			for(int i = 0;i<n;i++){
				if(ps(name, books[i].bookname)){
					loc=i;
					found = 1;
					cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
					cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
					cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
				}
			}		
		}
		if(found == 0){
			cout<<"Record still not Found"<<endl;
		}
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
void library::sbyauthor(){
	string author;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Searching by author of book\n";
	cout<<"Enter the author of book you want to search: ";
	cin>>author;
	for(int i = 0;i<n;i++)
	{
		if(books[i].authorname == author)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			break;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}
void library::sbyid(){
	int id, loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Searching by Id of book\n";
	cout<<"Enter the id of book you want to search: ";
	cin>>id;
	for(int i = 0;i<n;i++)
	{
		if(books[i].isbn_no==id)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			break;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}
void library::sbycategory(){
	string category;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Searching by category of book\n";
	cout<<"Enter the category of book you want to search: ";
	cin>>category;
	for(int i = 0;i<n;i++)
	{
		if(books[i].bookcategory == category)
		{
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			break;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}
void library::sbypubcom(){
	string company;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Searching by publication company of book\n";
	cout<<"Enter the publicaton company of book you want to search: ";
	cin>>company;
	for(int i = 0;i<n;i++){
		if(books[i].bookpubcom == company){
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			break;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
void library::sort(){
	system("cls");
	cout <<setw( 27 )<< "In Sort Function"<<endl
		<< setw( 52 )<< "Please choose one of the options below: "

		<< endl << setw( 71 )

		<< "--------------------------------------------------------------"

		<< endl << endl

		<< setw( 40 ) << "( A ) Sort in Ascending Order" << endl << endl

		<< setw( 41 ) << "( D ) Sort in Descending Order" << endl << endl

		<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
		gotoxy(30,8);
	switch(getche())
	{
		case 'a':
		case 'A':sortas();break;

		case 'd':
		case 'D': sortds();break;

		default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		sort();
		getch();
	}
}
void library::return_book(){
	int id, loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Enter the id of book you want to return: ";
	cin>>id;
	for(int i = 0;i<n;i++)
	{
		if(books[i].isbn_no == id && books[i].date_of_issue != 0){
			loc=i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBOOK RETURNED";
			books[i].date_of_issue = 0;
			break;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}
void library::sortas(){
	system("cls");
	cout <<setw( 27 )<< "In Sort Function"<<endl
		<< setw( 52 )<< "Please choose one of the options below: "

		<< endl << setw( 71 )

		<< "--------------------------------------------------------------"

		<< endl << endl

		<< setw( 29 ) << "( N ) Sort by name" << endl << endl

		<< setw( 27 ) << "( I ) Sort by Id" << endl << endl

		<< setw( 36 ) << "( T ) Sort by author name" << endl << endl

		<< setw( 33 ) << "( C ) Sort by Category" << endl << endl

		<< setw( 44 ) << "( P ) Sort by Publication Company" << endl << endl

		<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
		gotoxy(30,14);

	switch(getche()){
		case 'n':
		case 'N':sortasname();break;

		case 'i':
		case 'I': sortasid();break;

		case 't':
		case 'T': sortasauthor();break;

		case 'c':
		case 'C':sortascategory();break;

		case 'p':
		case 'P':sortaspubcom();break;

		default:
	puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
	getch();
	sortas();
	getch();
	}
}
void library::sortds(){
	system("cls");

	cout <<setw( 27 )<< "In Sort Function"<<endl
		<< setw( 52 )<< "Please choose one of the options below: "

		<< endl << setw( 71 )

		<< "--------------------------------------------------------------"

		<< endl << endl

		<< setw( 29 ) << "( N ) Sort by name" << endl << endl

		<< setw( 27 ) << "( I ) Sort by Id" << endl << endl

		<< setw( 36 ) << "( T ) Sort by author name" << endl << endl

		<< setw( 33 ) << "( C ) Sort by Category" << endl << endl

		<< setw( 44 ) << "( P ) Sort by Publication Company" << endl << endl

		<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
		gotoxy(30,14);
	switch(getche())
	{
		case 'n':
		case 'N':sortdsname();break;

		case 'i':
		case 'I': sortdsid();break;

		case 't':
		case 'T': sortdsauthor();break;

		case 'c':
		case 'C':sortdscategory();break;

		case 'p':
		case 'P':sortdspubcom();break;

		default:
	puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
	getch();
	sortds();
	getch();
	}
}
void library::issue(){
	int id, loc,found = 0;
	system("cls");
	cout<<endl;
	cout<<"Enter the id of book you want to search: ";
	cin>>id;
	for(int i = 0; i < n; i++){
		if(books[i].isbn_no == id && books[i].date_of_issue == 0){
			loc = i;
			found = 1;
			cout<< "Record Found!"<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<" Enter date :";
			cin>>id;
			books[i].date_of_issue = id;
			cout<<"\n Enter month :";
			cin>>id;
			books[i].month_of_issue = id;
			cout<<"\n Enter year :";
			cin>>id;
			books[i].year_of_issue = id;
			cout<<"\n Enter university roll no :";
			cin>>id;
			books[i].university_rollno = id;
			cout<<"\n.....BOOK ISSUED\n";
			break;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"\nPress enter to goto main menu.....";
	getch();
}
void library::sortasid(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Ascending Order by Id\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].isbn_no > books[pi].isbn_no){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].isbn_no < books[lci].isbn_no) {
				mi = lci;
			}
			if(rci < size && books[rci].isbn_no > books[mi].isbn_no) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

void library::sortdsid(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Descending Order by Id\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].isbn_no < books[pi].isbn_no){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].isbn_no > books[lci].isbn_no) {
				mi = lci;
			}
			if(rci < size && books[rci].isbn_no < books[mi].isbn_no) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Ascending order by name///////

void library::sortasname(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Ascending Order by Name\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].bookname > books[pi].bookname){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].bookname < books[lci].bookname) {
				mi = lci;
			}
			if(rci < size && books[rci].bookname > books[mi].bookname) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Descending order by name///////

void library::sortdsname(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Descending Order by Name\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].bookname < books[pi].bookname){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].bookname > books[lci].bookname) {
				mi = lci;
			}
			if(rci < size && books[rci].bookname < books[mi].bookname) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Ascending order by author///////

void library::sortasauthor(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Ascending Order by Author\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].authorname > books[pi].authorname){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].authorname < books[lci].authorname) {
				mi = lci;
			}
			if(rci < size && books[rci].authorname > books[mi].authorname) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Descending order by author///////

void library::sortdsauthor(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Descending Order by Author\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].authorname < books[pi].authorname){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].authorname > books[lci].authorname) {
				mi = lci;
			}
			if(rci < size && books[rci].authorname < books[mi].authorname) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Ascending order by category///////

void library::sortascategory(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Ascending Order by Category\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].bookcategory > books[pi].bookcategory){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].bookcategory < books[lci].bookcategory) {
				mi = lci;
			}
			if(rci < size && books[rci].bookcategory > books[mi].bookcategory) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Descending order by category///////

void library::sortdscategory(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Descending Order by Category\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].bookcategory < books[pi].bookcategory){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].bookcategory > books[lci].bookcategory) {
				mi = lci;
			}
			if(rci < size && books[rci].bookcategory < books[mi].bookcategory) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Ascending order by company///////

void library::sortaspubcom(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Ascending Order by Publication Company\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].bookpubcom > books[pi].bookpubcom){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].bookpubcom < books[lci].bookpubcom) {
				mi = lci;
			}
			if(rci < size && books[rci].bookpubcom > books[mi].bookpubcom) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

///////Sort in Descending order by company///////

void library::sortdspubcom(){
	int i,j;
	book temp;
	system("cls");
	cout<<endl;
	cout<< "Sorting in Descending Order by Publication Company\n";
	for(int i = 1; i < n; i++){
		int ci = i;
		while(ci > 0){
			int pi = (ci - 1) / 2;
			if(books[ci].bookpubcom < books[pi].bookpubcom){
				temp = books[ci];
				books[ci] = books[pi];
				books[pi] = temp;
			}
			else{
				break;
			}
			ci = pi;
		}
	}
	int size = n;
	while(size > 1){
		temp = books[0];
		books[0] = books[size - 1];
		books[size-1] = temp;
		size--;
		int pi = 0;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		while(lci < size) {
			int mi = pi;
			if(books[mi].bookpubcom > books[lci].bookpubcom) {
				mi = lci;
			}
			if(rci < size && books[rci].bookpubcom < books[mi].bookpubcom) {
				mi = rci;
			}
			if(mi == pi) {
				break;
			}
			temp = books[mi];
			books[mi] = books[pi];
			books[pi] = temp;
			pi = mi;
			lci = 2 * pi + 1;
			rci = 2 * pi + 2;
		}
	}
	display();
}

////////////Delete//////////////////////

void library::del(){
	system("cls");

	cout <<setw( 29 )<< "In Delete Function"<<endl
		<< setw( 52 )<< "Please choose one of the options below: "

		<< endl << setw( 71 )

		<< "--------------------------------------------------------------"

		<< endl << endl

		<< setw( 31 ) << "( N ) Delete by name" << endl << endl

		<< setw( 29 ) << "( I ) Delete by Id" << endl << endl

		<< setw( 38 ) << "( T ) Delete by author name" << endl << endl

		<< setw( 35 ) << "( C ) Delete by Category" << endl << endl

		<< setw( 46 ) << "( P ) Delete by Publication Company" << endl << endl

		<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
		gotoxy(30,14);
	switch(getche())
	{
		case 'n':
		case 'N':dbyname();break;

		case 'i':
		case 'I': dbyid();break;

		case 't':
		case 'T': dbyauthor();break;

		case 'c':
		case 'C':dbycategory();break;

		case 'p':
		case 'P':dbypubcom();break;

		default:
	puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
	getch();
	del();
	getch();
	}
}

///////Delete by name///////

void library::dbyname(){
	string name;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Deleting by name of book\n";
	cout<<"Enter the name of book you want to delete: ";
	cin>>name;
	for(int i = 0;i<n;i++)
	{
		if(books[i].bookname == name)
		{
			loc=i;
			found = 1;
			for (i = loc;i<n-1;i++)
			{
				books[i]=books[i+1];
			}
			n--;
			cout<<"\n BOOK DELETED\n";
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}

///////Delete by author///////

void library::dbyauthor(){
	string author;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Deleting by author of book\n";
	cout<<"Enter the author of book you want to delete: ";
	cin>>author;
	for(int i = 0;i<n;i++)
	{
		if(books[i].authorname == author)
		{
			loc=i;
			found = 1;
			for (i = loc;i<n-1;i++)
			{
				books[i]=books[i+1];
			}
			cout<<"\n BOOK DELETED\n";
			n--;
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}

///////Delete by id///////

void library::dbyid(){
	int id, loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Deleting by Id of book\n";
	cout<<"Enter the id of book you want to delete: ";
	cin>>id;
	for(int i = 0;i<n;i++)
	{
		if(books[i].isbn_no==id)
		{
			loc=i;
			found = 1;
			for (i = loc;i<n-1;i++)
			{
				books[i]=books[i+1];
			}
			n--;
			cout<<"\n BOOK DELETED\n";
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}

///////Delete by category///////

void library::dbycategory(){
	string category;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Deleting by category of book\n";
	cout<<"Enter the category of book you want to delete: ";
	cin>>category;
	for(int i = 0;i<n;i++)
	{
		if(books[i].bookcategory == category)
		{
			loc=i;
			found = 1;
			for (i = loc;i<n-1;i++)
			{
				books[i]=books[i+1];
			}
			n--;
			cout<<"\n BOOK DELETED\n";
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}
///////Delete by company///////
void library::dbypubcom(){
	string company;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Deleting by publication company of book\n";
	cout<<"Enter the publicaton company of book you want to delete: ";
	cin>>company;
	for(int i = 0;i<n;i++)
	{
		if(books[i].bookpubcom == company)
		{
			loc=i;
			found = 1;
			for (i = loc;i<n-1;i++)
			{
				books[i]=books[i+1];
			}
			n--;
			cout<<"\n BOOK DELETED\n";
		}
	}
	if(found == 0)
		cout<<"Record not Found"<<endl;
	cout<<"Press enter to goto main menu.....";
	getch();
}
///////////Modify//////////////////////
void library::modify(){
	system("cls");
	cout <<setw( 29 )<< "In Modify Function"<<endl
		<< setw( 52 )<< "Please choose one of the options below: "

		<< endl << setw( 71 )

		<< "--------------------------------------------------------------"

		<< endl << endl

		<< setw( 31 ) << "( N ) Modify by name" << endl << endl

		<< setw( 29 ) << "( I ) Modify by Id" << endl << endl

		<< setw( 38 ) << "( T ) Modify by author name" << endl << endl

		<< setw( 35 ) << "( C ) Modify by Category" << endl << endl

		<< setw( 46 ) << "( P ) Modify by Publication Company" << endl << endl

		<<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
		gotoxy(30,14);
	switch(getche()){
		case 'n':
		case 'N':mbyname();break;

		case 'i':
		case 'I': mbyid();break;

		case 't':
		case 'T': mbyauthor();break;

		case 'c':
		case 'C': mbycategory();break;

		case 'p':
		case 'P': mbypubcom();break;

		default:
	puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
	getch();
	modify();
	getch();
	}
}
///////Modify by name///////
void library::mbyname(){
	string name;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Modifying by name of book\n";
	cout<<"Enter the name of book you want to modify: ";
	cin>>name;
	for(int i = 0;i<n;i++){
		if(books[i].bookname == name){
			loc=i;
			found = 1;
			char ch;char id1[6],year[4];
			system("cls");
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<endl;
			cout<< "In Modify function\n";
			cout<<"Enter new Book Name: ";
			cin>>books[loc].bookname;
			cout<<"MODIFIED!"<<endl;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
///////Modify by author///////
void library::mbyauthor(){
	string author;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Modifying by author of book\n";
	cout<<"Enter the author of book you want to modify: ";
	cin>>author;
	for(int i = 0;i<n;i++){
		if(books[i].authorname == author){
			loc=i;
			found = 1;
			char ch;char id1[6],year[4];
			system("cls");
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<endl;
			cout<< "In Modify function\n";
			cout<<"Enter new Author Name: ";
			cin>>books[loc].authorname;
			cout<<"MODIFIED!"<<endl;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
///////Modify by id///////
void library::mbyid(){
	int id, loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Modifying by Id of book\n";
	cout<<"Enter the id of book you want to modify: ";
	cin>>id;
	for(int i = 0;i<n;i++){
		if(books[i].isbn_no==id){
			loc=i;
			found = 1;
			char ch;char id1[6],year[4];
			system("cls");
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<endl;
			cout<< "In Modify function\n";
			cout<<"Enter new Book ID: ";
			cin>>books[loc].isbn_no;
			cout<<"MODIFIED!"<<endl;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
///////Modify by category///////
void library::mbycategory(){
	string category;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Modifying by category of book\n";
	cout<<"Enter the category of book you want to modify: ";
	cin>>category;
	for(int i = 0;i<n;i++){
		if(books[i].bookcategory == category){
			loc=i;
			found = 1;
			char ch;char id1[6],year[4];
			system("cls");
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<endl;
			cout<< "In Modify function\n";
			cout<<"Enter new Book Category: ";
			cin>>books[loc].bookcategory;
			cout<<"MODIFIED!"<<endl;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
///////Modify by company///////
void library::mbypubcom(){
	string company;
	int loc,found=0;
	system("cls");
	cout<<endl;
	cout<<"Modifying by publication company of book\n";
	cout<<"Enter the publicaton company of book you want to modify: ";
	cin>>company;
	for(int i = 0;i<n;i++){
		if(books[i].bookpubcom == company){
			loc=i;
			found = 1;
			char ch;char id1[6],year[4];
			system("cls");
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<"\nBook : "<<books[i].isbn_no<<"\nBook Name : "<<books[i].bookname<<"\nAuthor Name : "<<books[i].authorname<<"\nCategory : "<<books[i].bookcategory<<"\nPublication : "<<books[i].bookpubcom<<endl;
			cout<<"__________"<<"______________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			cout<<endl;
			cout<< "In Modify function\n";
			cout<<"Enter new Publication Company Name: ";
			cin>>books[loc].bookpubcom;
			cout<<"MODIFIED!"<<endl;
		}
	}
	if(found == 0){
		cout<<"Record not Found"<<endl;
	}
	cout<<"Press enter to goto main menu.....";
	getch();
}
/////////////////gotoxy //////////////////////////
void library::gotoxy(short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
///////////////////main///////////////
int main(){
	system("Color 71");
	cout<<"\e[1m";
	char ch1;
	library l;
	while (1){
		system("cls");
		cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl

          << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 25 ) << "( A ) Add Book" << endl << endl

          << setw( 31 ) << "( O ) Sort all Books" << endl << endl

          << setw( 33 ) << "( S ) Search all Books" << endl << endl

          << setw( 34 ) << "( D ) Display all Books" << endl << endl

		  << setw( 29 ) << "( I ) Issue a Book" << endl << endl

		  << setw( 30 ) << "( R ) Return a Book" << endl << endl

          << setw( 30 ) << "( T ) Delete a Book" << endl << endl

          << setw( 40 ) << "( M ) Update Book Information" << endl << endl

		  << setw( 21 ) << "( Q ) Quit" << endl << endl
		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			l.gotoxy(30,25);

		switch(getche()){
			case 'a':
		 	case 'A':
				l.add();
				break;

			case 'd':
		 	case 'D':
				l.display();
				break;

		 	case 'S':
		 	case 's':
				l.search();
				break;

		 	case 't':
		 	case 'T':
				l.del();
				break;

		 	case 'O':
		 	case 'o':
				l.sort();
				break;

		 	case 'm':
		 	case 'M':
				l.modify();
				break;

			case 'i':
		 	case 'I':
				l.issue();
				break;

			case 'r':
		 	case 'R':
				l.return_book();
				break;

		 	case 'q':
		 	case 'Q':
				exit(0);
				break;

		 	default:
				puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
			getch();
        } //end switch
    }//end while
	system("pause");
}
///////////////////END OF CODE////////////////////
