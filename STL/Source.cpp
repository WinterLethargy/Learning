#include <iostream>
#include<vector>
#include<list>
#include<algorithm>


int main() {
	int arr1[] = { 1, 2, 3, 5 };
	int arr2[] = { 3, 4, 5, 6 };
	int arr3[8];
	std::vector<int> int_vfa1(arr1, arr1 + 4);	// вектор из массива
	std::vector<int> int_vfa2(arr2, arr2 + 4);

	std::list<int> int_lfa1(arr1, arr1 + 4);	// список из массива
	std::list<int> int_lfa2(arr2, arr2 + 4);

	std::list<int> int_lfv1(int_vfa1.begin(), int_vfa1.end());	// список из вектора
	std::list<int> int_lfv2(int_vfa2.begin(), int_vfa2.end());

	std::vector<int> int_vfl1(int_lfa1.begin(), int_lfa1.end()); // вектор из списка
	std::vector<int> int_vfl2(int_lfa2.begin(), int_lfa2.end());

	std::ostream_iterator<int> out(std::cout, ", ");
	std::cout << "Vector from aray:\n";
	std::copy(int_vfa1.begin(), int_vfa1.end(), out);
	std::cout << "\nList from aray:\n";
	std::copy(int_lfa1.begin(), int_lfa1.end(), out);
	std::cout << "\nVector from list:\n";
	std::copy(int_vfl1.begin(), int_vfl1.end(), out);
	std::cout << "\nList from vector:\n";
	std::copy(int_lfv1.begin(), int_lfv1.end(), out);

	std::vector<int> int_vmerg;
	std::list<int> int_lmerg;

	std::list<int> int_;
	//std::merge(int_vfa1.begin(), int_vfa1.end(), int_vfa2.begin(), int_vfa2.end(), int_vmerg.begin());
	// слияние векторов приводит к ошибке

	//std::merge(int_lfa1.begin(), int_lfa1.end(), int_lfa2.begin(), int_lfa2.end(), int_lmerg.begin());
	// не понимаю почему не работает

	std::merge(arr1, arr1 + 4, arr2, arr2 + 4, arr3);
	std::cout << "\nMerge arr1 and arr2 to arr3\n";
	std::copy(arr3, arr3 + 8, out);

	//std::merge(arr1, arr1 + 4, arr2, arr2 + 4, int_vmerg.begin());
	/*std::vector<int>::iterator int_Vmerg_begin;
	int_Vmerg_begin = int_vmerg.begin();
	std::merge(arr1, arr1 + 4, arr2, arr2 + 4, int_Vmerg_begin);*/
	//std::cout << "\nMerge arr1 and arr2 to vector";
	//std::copy(int_vmerg.begin(), int_vmerg.end(), out);
	// не получается запись в вектор

	int_lmerg.merge(int_lfa1);
	// не работает если массив неотсортирован
	std::cout << "\nMerge 1, 2, 3, 5 and empty\n";
	std::copy(int_lmerg.begin(), int_lmerg.end(), out);

	std::cout << "\nMerge 1, 2, 3, 5 and 3, 4, 5, 6\n";
	int_lmerg.merge(int_lfa2);
	std::copy(int_lmerg.begin(), int_lmerg.end(), out);
}