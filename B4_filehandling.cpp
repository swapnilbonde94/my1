/*B4: Write a C++ program that creates an output file, writes information to it, closes the file and opens it again as 
an input file and read the information from the file. */


#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;
#define max 100;

class student                                      //defining student class
{
    string name, adress, year;             //objects of string class
    string lic, dob, bldgrp;                                      
    char div;
    int roll_no;
    long mob;
    static int cnt;                           //static variable declaration

public:
    void create();
    void file(int );                     //to create database
    void display();                      //to display database
    inline static void inccnt()
    {
        cnt++;
    }
    inline static void showcnt()                      //inline static function
    {
        cout << "\nTOTAL NO OF RECORDS ARE : " << cnt << endl;
    }
    student();                                    //default constructor
    student(student &);                        //copy constructor of student class
    ~student()                                 //destructor of student class
    {
        cout << "\nDESTRUCTOR IS CALLED!!!!" << endl
             << "RECORD DELETED SUCCESFULLY";
    }
};
int student::cnt;                                 //definition of static member
student::student(){                                 //constructor definition
    name="Swapnil Bonde";
    adress="SR NO.81 BABBAR SOLANKI \nDIGHI, PUNE";
    year="SE COMPUTER";
    div='A';
    roll_no=21042;
    mob=999897969;

}
student::student(student &obj)                   //definition of copy constructor
{
    this->name = obj.name;                        //this is the pointer
    this->adress = obj.adress;
    this->year = obj.year;
    this->div = obj.div;
    this->roll_no = obj.roll_no;
    this->mob = obj.mob;
}
void student::create()                       //creation of database
{
    cout << "\nNAME : " << endl;
    cin >> name;
    cout << "\nADDRESS : " << endl;
    cin >> adress;
    cout << "\nDATE OF BIRTH : " << endl;
    cin >> dob;
    cout << "\nYEAR : " << endl;
    cin >> year;
    cout << "\nDIVISION : " << endl;
    cin >> div;
    cout << "\nROLL NUMBER : " << endl;
    cin >> roll_no;
    cout << "\nBLOOD GROUP : " << endl;
    cin >> bldgrp;
    cout << "\nLICENSE NUMBER: " << endl;
    cin >> lic;
    cout << "\nPHONE NUMBER: " << endl;
    cin >> mob;
}
void student::file(int n)                 //to feed data in file
{
    ofstream f;
    
    f.open("student.txt",ios::app);
    f <<"\nInformation of Student : "<<endl;
    f << "\n*****" << endl;
    f << "\nNAME OF STUDENT : " << name << endl;
    f << "\nADDRESS OF STUDENT : " << adress << endl;
    f << "\nDATE OF BIRTH : " << dob << endl;
    f << "\nYEAR : " << year << endl;
    f << "\nDIVISION : " << div << endl;
    f << "\nROLL NO : " << roll_no << endl;
    f << "\nBLOOD GROUP : " << bldgrp << endl;
    f << "\nLICENSE NUMBER : " << lic << endl;
    f << "\nPHONE NUMBER : " << mob << endl;
    f << "\n*****" << endl;
    f.close();
    
}

void student::display(){                     //display the data stored in file
    char line[100];
    ifstream in;
    in.open("student.txt");
    cout<<"Student Database"<<endl;
    while (!in.eof())
    {
        in.getline(line,100);
        cout<<line<<endl;
    }
    in.close();
}




int main()
{
    int n;
    int ch;
    char ans;
    string st;
    string result;
    student stdobj;
    cout<<"Enter the number of students : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
    stdobj.create();
    stdobj.inccnt();
    stdobj.file(n);
    stdobj.display();       
    }
    
    return 0;
}