#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class link {
public:
	link(int d = 0) : data(d), next(nullptr)
	{	}
	int32_t data;
	link* next;	// у последнего линка списка равен nullptr
};

class linklist {
private:
	link* first;
public:
	linklist() : first(nullptr)
	{	}
	void additem(int d) {
		if (!first) {						// необходимо, потому что first изначально не указывает на объект, чтобы обращаться к его полям
			first = new link(d);
			return;
		}
		link* auxiliary = first;			// создаю вспомогательный указатель
		while (auxiliary->next) {			// прохожу по полям next линков пока auxiliary не последний элекмент
			auxiliary = auxiliary->next;
		}
		auxiliary->next = new link(d);		// помещаю в next последнего линка указатель на новый линк
	}
	void displist() {
		link* auxiliary = first;
		while (auxiliary) {
			cout << auxiliary->data << endl;
			auxiliary = auxiliary->next;
		}
	}
	void outfile() {						// запись очереди в файл
		ofstream outf("LinkList.txt", ios::binary);
		link* auxiliary = first;
		while (auxiliary) {
			outf.write(reinterpret_cast<char*>(&(auxiliary->data)), sizeof(int32_t));
			auxiliary = auxiliary->next;
		}
		outf.close();
	}
	void infile(const char* name = "LinkList.txt") {			// создание очереди из файла
		ifstream infile(name, ios::binary);
		first = new link;
		infile.read(reinterpret_cast<char*>(&(first->data)), sizeof(int32_t));
		link* auxiliary = first;
		while (true) {
			int32_t temp;
			infile.read(reinterpret_cast<char*>(&temp), sizeof(int32_t));
			if (infile) {
				auxiliary->next = new link;
				auxiliary->next->data = temp;
				auxiliary = auxiliary->next;
			}
			else {
				infile.close();
				break;
			}
		}
		//while (!infile.eof()) {				//флаг eof устанавливается при провале попытки считать, а не при достижении конца
		//	auxiliary->next = new link;
		//	infile.read(reinterpret_cast<char*>(&(auxiliary->next->data)), sizeof(int32_t));
		//	auxiliary = auxiliary->next;
		//}
	}
	~linklist() {

		if (!first) return;

		link* last, * predlast;
		while (first) {
			predlast = first;
			last = first->next;
			if (last) {
				while (last->next) {
					last = last->next;
					predlast = predlast->next;
				}
				delete last;
				predlast->next = nullptr;
			}
			else {
				delete predlast;
				first = nullptr;
			}
		}
	}
};

int main() {
	linklist* link1 = new linklist;
	char choise;
	do {
		cout << "what do you want?\n1. Add item - a.\n2. Display queue - d\n3. Record in file. - i\n4. Read from file. - f\n";
		choise = cin.get();
		switch (choise) {
			case 'a':
			case 'A':
				int32_t item;
				cout << "Enter the number: ";
				cin >> item;
				link1->additem(item);
				break;
			case 'd':
			case 'D':
				link1->displist();
				break;
			case 'i':
			case 'I':
				link1->outfile();
				break;
			case 'f':
			case 'F':
				delete link1;
				cout << "LinkList was deleted\n";
				link1 = new linklist;
				cout << "New linklist was created.\n";
				link1->infile();
				break;
		}
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	} while (choise != '\n');
}