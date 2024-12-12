#include <iostream>
#include <fstream>
using namespace std;
class StudentInfo
{
int Rollno;
char Name[30];
char Div;
char Address[30];
public:
void Accept()
{
cout << "\nEnter Roll no : ";
cin >> Rollno;
cout << "\nEnter Name : ";
cin >> Name;
cout << "\nEnter Div : ";
cin >> Div;
cout << "\nEnter Address : ";
cin >> Address;
}
void Display()
{
cout << "\n"<< Rollno << "\t" << Name << "\t" << Div << "\t" << Address << "\n";
}
int getdata()
{
return Rollno;
}
};
void adddata()
{
int n;
StudentInfo s;
ofstream out("student.txt");
cout << "\nEnter the no of Students data You want to insert : ";
cin >> n;
for (int i = 0; i < n; i++)
{
s.Accept();
out.write((char *)&s, sizeof(s));
}
out.close();
}
void addrecord()
{
StudentInfo s;
ofstream out("student.txt", ios::app);
s.Accept();
out.write((char *)&s, sizeof(s));
out.close();
cout << "Data Added Successfully.........";
}
void DisplayInfo()
{
StudentInfo s;
ifstream inf("student.txt");
while (inf.read((char *)&s, sizeof(s)))
{
s.Display();
}
inf.close();
}
void SearchStud(int Rollno)
{
StudentInfo s;
ifstream inf("student.txt");
int flag = 0;
while (inf.read((char *)&s, sizeof(s)))
{
if (s.getdata() == Rollno)
{
flag = 1;
s.Display();
break;
}
}
if (flag == 0)
{
cout << "Data Entry not found ! ";
}
inf.close();
}
void UpRec(int Rollno)
{
ifstream inf("student.txt");
ofstream out("temp.txt");
int flag = 0;
StudentInfo s;
while (inf.read((char *)&s, sizeof(s)))
{
if (s.getdata() == Rollno)
{
flag = 1;
s.Accept();
out.write((char *)&s, sizeof(s));
cout << "\n Record updated.....";
}
else
{
out.write((char *)&s, sizeof(s));
}
}
if (flag == 0)
{
cout << "Record not found !";
}
out.close();
inf.close();
remove("student.txt");
rename("temp.txt", "student.txt");
}
void DelRec(int Rollno)
{
ifstream inf("student.txt");
ofstream out("temp.txt");
int flag = 0;
StudentInfo s;
while (inf.read((char *)&s, sizeof(s)))
{
if (s.getdata() == Rollno)
{
flag = 1;
cout << "\n Record deleted......";
continue;
}
else
{
out.write((char *)&s, sizeof(s));
}
}
if (flag == 0)
{
cout << "Record not found !";
}
out.close();
inf.close();
remove("student.txt");
rename("temp.txt", "student.txt");
}
int main()
{
int ch;
do
{
cout << "\n----------------Choices----------------";
cout << "\n1.Add Student data to database ";
cout << "\n2.Add new Record";
cout << "\n3.Display Record";
cout << "\n4.Search Record";
cout << "\n5.Update record";
cout << "\n6.Delete Record";
cout << "\n7.Exit";
cout << "\n Enter choice ";
cin >> ch;
switch (ch)
{
case 1:
adddata();
break;
case 2:
addrecord();
break;
case 3:
cout << "Display the information of Students ....\n";
DisplayInfo();
break;
case 4:
cout << "\nEnter the Roll no to search the student Data :";
int a;
cin >> a;
SearchStud(a);
break;
case 5:
cout << "\nEnter the Roll no to Update the student Data :";
int b;
cin >> b;
UpRec(b);
break;
case 6:
cout << "\nEnter the Roll no to Delete the student Data :";
int c;
cin >> c;
DelRec(c);
break;
case 7:
break;
}
} while (ch != 7);
return 0;
}