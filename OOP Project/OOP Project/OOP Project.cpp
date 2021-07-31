#include<iostream>
#include<string>
using namespace std;

class human{
public:
	int age;
	string name;

	void human_info(){
		cout<<"Name "<<name<<endl<<"Age "<<age<<endl;

	}

};

//Inheritance
class employee : public human{
public:
	int id, salary;

	void set_id(int x){
		id = x;}

	void set_salary(int y){
		salary = y;}


};

//Inheritance
class sales : public employee{
public:
	float total_sales, total_income;
	int workers_salary;
	
	//constructor
	sales(){
		total_sales = 0;
		workers_salary = 0;
		
	}



	void income(){
		total_income = total_sales - workers_salary;

	}

};

//Inheritance
class item : public sales{
public:
	int price, quantity;
	string item_name;

	//constructor
	item(){
		quantity = 0;
	}
	//to buy an item if it ends
	void buy(int x){
		quantity += x;
		total_sales -= x*price*0.6;
	}
	//to sell items for customers
	void sell(int y){
		if(quantity < y)
			cout<<"there's not enough quantity"<<endl<<"There's only "<<quantity<<endl;

		else{
			quantity -= y;
			total_sales += y*price;}


	}

};


void main(){
	int size, enumber;
	//to let the user decide how many employees he has
	cout<<"Enter the number of employees"<<endl;
	cin>>size;
	employee *employees = new employee[size];
	enumber = size;
	//for loop to make the user enter the informations of the employees
	for(int i=0 ; i<size ; i++){
		//auto employee ID
		employees[i].id = i+1;
		cout<<"Enter employee number "<<employees[i].id<<" name"<<endl;
		cin>>employees[i].name;
		cout<<"Enter "<<employees[i].name<<" age"<<endl;
		cin>>employees[i].age;
		cout<<"Enter "<<employees[i].name<<" salary"<<endl;
		cin>>employees[i].salary;

	}

	sales tsales;
	//letting the user decide how many items the market has
	cout<<"Enter the number of items the Supermarket has"<<endl;
	cin>>size;
	int inumber = size;
	item *items = new item[size];
	//for loop to fill the items informations
	for(int i=0 ; i<size ; i++){
		cout<<"Enter item number "<<i+1<<" name"<<endl;
		cin>>items[i].item_name;
		cout<<"Enter "<<items[i].item_name<<" price"<<endl;
		cin>>items[i].price;
		cout<<"Enter the current quantity of "<<items[i].item_name<<" in the Supermarket"<<endl;
		cin>>items[i].quantity;
	}
	//an example of how to buy an item if the quantity isn't enough
	int h=0,x;
	float z=0;
	while(h == 0){
	cout<<"Enter the item's number you want to buy and the number of pieces to buy"<<endl;
	cin>>size>>x;
	items[size-1].buy(x);
	cout<<"if you want to buy something else type 0 if not type any number"<<endl;
	cin>>h;
	
	}
	h=0;
	//an example of how to sell an item for a customer
	while(h==0){
	cout<<"Enter the item's number you want to sell and the number of pieces to sell"<<endl;
	cin>>size>>x;
	items[size-1].sell(x);
	cout<<"if you want to sell something else type 0 if not type any number"<<endl;
	cin>>h;
	}
	for(int i=0 ; i<inumber ; i++)
		z += items[i].total_sales;

	tsales.total_sales = z;
	

	//sum of the workers salary
	for(int i=0 ; i < enumber ; i++)
		tsales.workers_salary += employees[i].salary;

	//total income
	tsales.income();

	//a report about the supermarket
	cout<<"                 Supermarket Report"<<endl<<endl<<endl;
	cout<<"Total sales = "<<tsales.total_sales<<endl;
	cout<<"Workers salary = "<<tsales.workers_salary<<endl;
	cout<<"The total income = "<<tsales.total_income<<endl;
	if(tsales.total_income <= 0 )
		cout<<"The supermarket is currently losing money"<<endl;
	else
		cout<<"The supermarket is currently winning money"<<endl;

	system("pause");
}