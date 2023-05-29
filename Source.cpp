#include <iostream>
#include <vector>

class Client {
private:
	std::string _name;
	int _id;
	static std::vector <Client*> _clients;
	static int wdw;

	void ShowClient() {
		std::cout << "Name: " << _name << '\n';
		std::cout << "ID: " << _id << '\n';
	}
	
public:
	Client(std::string name, int id, std::vector <Client*> &clients): _name(name), _id(id) {
		//_clients.push_back(this);
		clients.push_back(this);
	}

	
	void ShowClients(std::vector <Client*>& clients) {	// Если метод статический, то объект для его вызова не нужен 
		for (const auto& it : _clients)
			it->ShowClient();
	}
		
};

//std::vector <Client*>Client::_clients;

// SOLID
// S - single responsibility principe (принцип единой ответственности)
// O - open-close principle 

class Animal {
private:
	std::string _type;
public:
	Animal(std::string type) : _type(type) { }
	virtual std::string GetSound() = 0;
};

class Cow : public Animal {
public:
	Cow(): Animal("Cow") { }
	std::string GetSound() override {
		return "MUUU";
	}
};

class Cat : public Animal {
public:
	Cat() : Animal("Cat")  { }
	std::string GetSound() override {
		return "MRR";
	}
};


class Dog : public Animal {
public:
	Dog() : Animal("Dog") { }
	std::string GetSound() override {
		return "Gav";
	}
};

// Функция открыта для расширения, закрыта для модификации (open-close principle)
void AnimalSound(Animal& animal) {
	std::cout << animal.GetSound() << "\n\n";
}

class Vector {
private:
	int _size;
	int* _massivPtr;
public:
	Vector() {
		_size = 0;
		_massivPtr = nullptr;
	}

	void Push_back(int element) {
		_size++;
		int* newMassiv = new int[_size];
		if (_massivPtr == nullptr) {
			newMassiv[0] = element;
			_massivPtr = newMassiv;
			return;
		}
		else
			for (int i = 0; i < _size - 1; ++i)
				newMassiv[i] = _massivPtr[i];
		
		newMassiv[_size - 1] = element;
		
		
		delete[] _massivPtr;
		_massivPtr = newMassiv;
	}

	void ShowElements() {
		for (int i = 0; i < _size; ++i)
			std::cout << "element: " << _massivPtr[i] << '\n';

	}
};


int main() {
	/*std::vector <Client*> clients;
	Client* client = new Client("John", 20, clients);
	Client* client2 = new Client("Alex", 15, clients);
	Client* client3 = new Client("Bob", 32, clients);*/
	//client->ShowClient();
	//client2->ShowClient();
	//client3->ShowClient();
	
	//client->ShowClients();

	//Client::ShowClients(clients);	// Вызов метода без объекта

	/*client->ShowClients(clients);*/

	/*Cat* cat = new Cat();
	Dog* dog = new Dog();
	Cow* cow = new Cow();

	AnimalSound(*cat);
	AnimalSound(*dog);
	AnimalSound(*cow);*/

	Vector* vector = new Vector();
	vector->Push_back(20);
	vector->Push_back(30);
	vector->Push_back(50);
	vector->Push_back(15);
	vector->Push_back(32);

	vector->ShowElements();


	return 0;
}