#include "ThucPham.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Food::Food(string idFood, string name, double mass, double price, string Date_sold)
{
	this->idFood = idFood;
	this->name = name;
	this->mass = mass;
	this->price = price;
	this->Date_sold = Date_sold;
}
Food::Food(const Food& f)
{
	this->idFood = f.idFood;
	this->name = f.name;
	this->mass = f.mass;
	this->price = f.price;
	this->Date_sold = f.Date_sold;
}
Food::~Food()
{

}
istream& operator >> (istream& in, Food& f)
{
	cout << "Nhap ma thuc pham: ";
	cin.ignore();
	in >> f.idFood;
	cout << "Nhap ten thuc pham: ";
	in >> f.name;
	cout << "Nhap khoi luong thuc pham: ";
	in >> f.mass;
	cout << "Nhap gia tien thuc pham: ";
	in >> f.price;
	cout << "Nhap ngay ban: ";
	in >> f.Date_sold;
	return in;
}
ostream& operator << (ostream& out, const Food& f)
{
	out << "Ma thuc pham: " << f.idFood << endl;
	out << "Ten thuc pham: " << f.name << endl;
	out << "Khoi luong thuc pham: " << f.mass << endl;
	out << "Gia tien: " << f.price << endl;
	out << "Ngay ban: " << f.Date_sold << endl;
	return out;
}
void Food::Input(/*ifstream& filein*/)
{
	fstream filein;
//	filein.open("D://PBL2/PBL2/Food.txt", ios_base::in);
	filein.open("Food1.txt", ios_base::in);
	getline(filein, idFood, ',');
	filein.seekg(1, 1);
	getline(filein, name, ',');
//	filein.seekg(1, 1);
	filein >> mass;
	filein.seekg(2, 1);
	filein >> price;
	filein.seekg(2, 1);
	getline(filein, Date_sold);
	filein.close();
}
void Food::Display()
{
	cout << "Ma thuc pham: " << idFood << endl;
	cout << "Ten thuc pham: " << name << endl;
	cout << "Khoi luong thuc pham: " << mass << endl;
	cout << "Gia tien: " << price << endl;
	cout << "Ngay ban: " << Date_sold << endl;
}