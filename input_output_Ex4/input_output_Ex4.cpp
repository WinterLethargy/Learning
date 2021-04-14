#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class employee {
private:
	std::string Name;
	std::string Surname;
	uint32_t Number;
public:
	employee() {	}
	employee(std::string n, std::string sn, uint32_t num) : Name(n), Surname(sn), Number(num) {	}
	friend std::ofstream& operator<<(std::ofstream& s, employee& emp);
	friend std::ifstream& operator>>(std::ifstream& s, employee& emp);
	friend std::ostream& operator<<(std::ostream& s, employee& emp);
	friend std::istream& operator>>(std::istream& s, employee& emp);
};

std::ofstream& operator<<(std::ofstream& s, employee& emp) {
	s << '#' << emp.Name << '#' << emp.Surname << '#' << emp.Number;
	return s;
}

std::ifstream& operator>>(std::ifstream& s, employee& emp) {
	s.get();
	std::getline(s, emp.Name, '#');
	std::getline(s, emp.Surname, '#');
	s >> emp.Number;
	return s;
}

std::ostream& operator<<(std::ostream& s, employee& emp) {
	std::cout << "\nName: " << emp.Name << "\nSurname: " << emp.Surname << "\nNumber: " << emp.Number;
	return s;
}

std::istream& operator>>(std::istream& s, employee& emp) {
	std::cout << "\nName: ";
	std::cin.ignore(256, '\n');
	std::getline(s, emp.Name);
	std::cout << "Surname: ";
	std::getline(s, emp.Surname);
	std::cout << "Number: ";
	s >> emp.Number;
	return s;
}


int main() {
	//std::cin.putback('0');
	std::cin.putback('\n');


	std::ofstream outEmp("Employee.txt");
	if (!outEmp.is_open()) {
		exit(1);
	}
	char ch = '0';
	while (ch != 'n') {
		employee emp;
		std::cin >> emp;
		outEmp << emp;
		std::cout << "Continue? y/n\n";
		std::cin >> ch;
	}
	outEmp.close();

	std::cout << "\nOutputting file content:\n";
	std::ifstream inEmp("Employee.txt");
	int i = 1;
	while (!inEmp.eof()) {
		employee emp;
		inEmp >> emp;
		std::cout << "\nRecord " << i++ << ":\n" << emp;
	}
}