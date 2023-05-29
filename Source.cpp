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


int main() {
	std::vector <Client*> clients;
	Client* client = new Client("John", 20, clients);
	Client* client2 = new Client("Alex", 15, clients);
	Client* client3 = new Client("Bob", 32, clients);
	//client->ShowClient();
	//client2->ShowClient();
	//client3->ShowClient();
	
	//client->ShowClients();

	//Client::ShowClients(clients);	// Вызов метода без объекта

	client->ShowClients(clients);

	return 0;
}