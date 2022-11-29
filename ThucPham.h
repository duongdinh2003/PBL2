#ifndef THUCPHAM_H
#define THUCPHAM_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Food {
private:
	string idFood;
	string name;
	double mass;
	double price;
	string Date_sold;
public:
	Food()
	{
		this->mass = this->price = 0;
		this->idFood = this->name = this->Date_sold = "";
	}
	Food(string, string, double, double, string);
	Food(const Food&);
	~Food();
	friend istream& operator >> (istream& in, Food&);
	friend ostream& operator << (ostream& out, const Food&);
	void Input(/*ifstream&*/);
	void Output(ofstream&);
	void Display();
	string getIdFood();
	void setIdFood(string);
	string getName();
	void setName(string);
	double getMass();
	void setMass(double);
	double getPrice();
	void setPrice(double);
	string getDate_Sold();
	void setDate_Sold(string);
};
#endif