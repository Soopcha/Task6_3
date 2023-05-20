#include <iostream> 
using namespace std;

struct Dessert
{
	char Case;
	union // Различающиеся элементы вариантов:   тортики и морожено
	{
		struct { char Smell[15], Filling[10]; long Layers; } Cake; //filling - начинка
		struct { char Taste[40]; int numOfBalls; } IceCream;
	};
	char Name[40];
};
// Ввод информации о дессерте : 
Dessert addDessert(char cs)
{
	Dessert dessert;
	if (dessert.Case = cs)
	{ // Вводим элементы варианта для мороженка: 
		cout << "Taste: "; cin >> dessert.IceCream.Taste;
		cout << "Nomber of balls: "; cin >> dessert.IceCream.numOfBalls;
	}
	else // Вводим элементы для тортика 
	{
		cout << "Smell: "; cin >> dessert.Cake.Smell;
		cout << "Filling: "; cin >> dessert.Cake.Filling;
		cout << "Layers: "; cin >> dessert.Cake.Layers;
	} // Вводим общие элементы вариантов: название дессерта
	cout << "Name: "; cin >> dessert.Name;
	return dessert;
}

// Вывод информации о десерте: 
void printDessert(Dessert dessert)
{
	if (dessert.Case) // Вариант - морожено. 
	{
		cout << dessert.IceCream.Taste << " |";
		cout << dessert.IceCream.numOfBalls<< " ";

	} // Вариант - торт. 
	else cout << dessert.Cake.Smell << ' ' << dessert.Cake.Filling << " | " << dessert.Cake.Layers << " ";
	cout << dessert.Name << endl;
}


void main()
{
	Dessert DataBase[10], // База данных. 
		dessert = { 0, {"", "", 0}, "", }; // Пустая структура. 
	int i, j; // Очистка базы данных. 
	for (i = 0; i < sizeof(DataBase) / sizeof(Dessert); i++)
		DataBase[i] = dessert;
	while (1)
	{
		cout << " MENU:" << endl
			<< "1. Data entry." << endl
			<< "2. Output of information about the dessert." << endl
			<< "3. Output of all desserts." << endl
			<< "4. Delete information about the dessert." << endl
			<< "5. Search of failings." << endl
			<< "6. End program." << endl
			<< ">";
		cin >> i;
		switch (i)
		{
		case 1: cout << "Number of desserts: "; cin >> i;
			cout << "Choise (0-Ice cream, 1-Cake): "; cin >> j;
			DataBase[i] = addDessert(j); break;
		case 2: cout << "Number of dessert: "; cin >> i;
			printDessert(DataBase[i]); break;
		case 3: for (i = 0; i < sizeof(DataBase) / sizeof(Dessert); i++)
			if (DataBase[i].Name[0])
			{
				cout << "Number №" << i << ':' << endl;
				printDessert(DataBase[i]);
			}
			  break;
		case 4:
			cout << "Choise number dessert: "; cin >> j;
			if (j < sizeof(DataBase) / sizeof(Dessert)) {
				DataBase[j] = { 0, {"", "", 0}, "", };
			}
			else {
				cout << "ERROR!";
			}
		case 5: for (i = 0; i < sizeof(DataBase) / sizeof(Dessert); i++)
			/*if ((DataBase + i)->IceCream.mark < 3)
				printDessert(DataBase[i]);
			break;
			*/
			printDessert(DataBase[i]);
			
		case 6: return;
		default: cout << "Repeat the input." << endl;
		}
	}
}