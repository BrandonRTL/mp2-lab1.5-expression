#include <iostream>
#include <string>
#include <vector>
using namespace std;
static int Count = 0;
class Animal
{
private:
	string Name;
	int ID;
public:
	void Set_Name(string _Name)
	{
		Name = _Name;
	}
	void Set_ID()
	{
		ID = Count;
	}
	int Get_ID()
	{
		return ID;
	}
	Animal(string _Name)
	{
		Set_Name(_Name);
		Set_ID();
		Count++;
	}
	virtual ~Animal() // если деструктор не виртуальный, то второй кот плохо удаляется, да (5)
	{
		cout << "RIP Animal" << endl;
	}
	virtual void say() = 0;
};
class Bird : public Animal
{
public:
	Bird(string _Name) :Animal(_Name) {}
};
class Cockrel : public Bird
{
public:
	Cockrel(string _Name) :Bird(_Name) {}
	void say()
	{
		cout << "FUS-KU-DAH" << endl;
	}
};
class Sparrow : public Bird
{
public:
	Sparrow(string _Name) :Bird(_Name) {}
	void say()
	{
		cout << "Captain" << endl;
	}
};
class Mammal : public Animal
{
public:
	Mammal(string _Name) :Animal(_Name) {}
	~Mammal()
	{
		cout << "RIP Mammal" << endl;
	}
};
class Cat : public Mammal
{
public:
	Cat(string _Name) : Mammal(_Name) {}
	void say()
	{
		cout << "MEOW" << endl;
	}
	~Cat()
	{
		cout << "RIP Cat :c" << endl;
	}
};
class Fox : public Mammal
{
public:
	Fox(string _Name) : Mammal(_Name) {}
	void say()
	{
		cout << "Ring-ding-ding-ding-dingeringeding??!!?" << endl;
	}
};
class Dog : public Mammal
{
public:
	Dog(string _Name) : Mammal(_Name) {}
	void say()
	{
		cout << "Ne lublu sobak." << endl;
	}
};
class Zoo
{
private:
	vector<Animal *> animals;
public:
	void Append(Animal* Anml) //(3)
	{
		animals.push_back(Anml);
	}
	void Listen()
	{
		for (int i = 0; i <= (animals.size() - 1); i++)
			animals[i]->say();
	}
	void Remove(int _Id) // (3)
	{
		for (int i = 0; i < animals.size(); i++)
		{
			if (_Id == animals[i]->Get_ID())
			{
				animals.erase(animals.begin() + i);
			}
		}
	}
	int Counter() // (4)
	{
		int _Count = 0;
		for (int i = 0; i < animals.size(); i++)
		{
			Bird* _Bird = dynamic_cast<Bird*>(animals[i]);
			if (_Bird)
				_Count++;
		}
		return _Count;
	}
};

int main()
{
	Zoo MyFirstZoo;
	int a;
	Fox A("Cat");
	Cat B("Dog");
	Dog C("Cat");
	Cat D("Cat");
	Cockrel H("Petuch");
	Cockrel G("Petuch");
	MyFirstZoo.Append(&B);
	MyFirstZoo.Append(&A);
	MyFirstZoo.Append(&C);
	MyFirstZoo.Append(&H);
	MyFirstZoo.Append(&D);
	MyFirstZoo.Append(&G);
	cout << Count << endl;
	MyFirstZoo.Listen();
	cout << endl;
	MyFirstZoo.Remove(2);
	MyFirstZoo.Listen();
	cout << endl;
	a = MyFirstZoo.Counter();
	Cat* cat = new Cat("Barsik");
	delete cat;
	Animal* _cat = new Cat("Barsik");
	cout << endl;
	delete _cat;
	cout << a;
	cin >> a;
	return 0;
}