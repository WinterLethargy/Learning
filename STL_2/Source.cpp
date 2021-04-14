#include<iostream>
#include<map>
#include <string>

int main() {
	std::string prep[] = { "Veshkin", "Prosutinski", "Zazbibina" };
	std::string obj[] = { "TOE", "Machine", "CROWN" };

	std::pair<std::string, std::string> kaf_pair[3];
	for (int i = 0; i < 3; i++) {
		kaf_pair[i] = std::pair<std::string, std::string>(prep[i], obj[i]);
	}

	std::map<std::string, std::string, std::less<std::string>> kafedra(kaf_pair, kaf_pair+3);
	std::map<std::string, std::string, std::less<std::string>>::iterator iter_kaf;

	iter_kaf = kafedra.begin();
	while (iter_kaf != kafedra.end()) {
		std::cout << (*iter_kaf++).first << ' ' << (*iter_kaf).second << '\n';
	}
}