#include <iostream>
#include "Vehicle.h"
#include "Eagle.h"
#include "Broomstick.h"
#include "Magic_carpet.h"
#include "All_terrain_boots.h"
#include "Centaur.h"
#include "Fast_camel.h"
#include "Camel.h"
#include "Air.h"
#include "Ground.h"
std::string* check_vehicle(Vehicle* vehicle, std::string* arr, int* x)
{
	arr[*x] = vehicle->get_name();
	(*x)++;
	return arr;
}
void print_choose()
{
	std::cout << "1. Ботинки вездеходы" << std::endl;
	std::cout << "2. Метла" << std::endl;
	std::cout << "3. Верблюд" << std::endl;
	std::cout << "4. Кентавр" << std::endl;
	std::cout << "5. Орел" << std::endl;
	std::cout << "6. Верблюд-быстроход" << std::endl;
	std::cout << "7. Ковер-самолет" << std::endl;
	std::cout << "0. Закончить регистрацию" << std::endl;
	std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
}
void registration_vehicle(int size, std::string* arr, Vehicle* vehicle, int* t, std::string* arrr, int* x)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == vehicle->get_name())
		{
			std::cout << "Транспортное средство " << vehicle->get_name() << " уже зарегестрировано" << std::endl;
			*t = 1;
		}
	}
	if (*t != 1)
	{
		arrr = check_vehicle(vehicle, arr, x);
		std::cout << "Транспортное средство " << vehicle->get_name() << " успешно зарегестрировано" << std::endl;
		std::cout << "Зарегестрированные транспортные средства: ";
		for (int i = 0; i < *x; i++)
		{
			std::cout << arrr[i] << ", ";
		}
		std::cout << std::endl;
	}
	*t = 0;
}
void sort(int* arr, int x, std::string* arrr)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				std::swap(arrr[j], arrr[j + 1]);
			}
	}
}
void print_race(int* arr, int x, std::string* arrr)
{
	for (int i = 0; i < x; i++)
	{
		std::cout << arrr[i] << ". Время: " << arr[i] << std::endl;
	}
}
void del_arr(int* ar, std::string* arr, std::string* arrr, int* x)
{
	delete[] ar;
	delete[] arr;
	delete[] arrr;
	*x = 0;
}
int main()
{
	int out = 1;
	int t = 0;
	int size = 7;
	int x = 0;
	setlocale(LC_ALL, "RUS");
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	while (out)
	{
		std::string* arr = new std::string[size];
		std::string* arrr = new std::string[size];
		int* ar = new int[size];
		std::cout << "1. Гонка для наземного транспорта" << std::endl;
		std::cout << "2. Гонка для воздушного транспорта" << std::endl;
		std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
		std::cout << "Выберите тип гонки: ";
		int type = 0;
		std::cin >> type;
		if (type != 1 && type != 2 && type != 3)
		{
			type = 0;
		}
		while (!type)
		{
			std::cout << "Номер гонки должен быть равен 1, 2 или 3. Введите новое значение: ";
			std::cin >> type;
			if (type != 1 && type != 2 && type != 3)
			{
				type = 0;
			}
		}
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		int distance = 0;
		std::cin >> distance;
		while (!distance)
		{
			std::cout << "Дистанция должна быть положительной. Введите новое значение: ";
			std::cin >> distance;
			if (distance <= 0)
			{
				distance = 0;
			}
		}
		std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства " << std::endl;
		std::cout << "1. Зарегестрировать транспорт " << std::endl;
		std::cout << "Выберите действие: ";
		int action = 0;
		std::cin >> action;
		int a = 1;
		while (a)
		{
			switch (type)
			{
			case 1:
			{
				std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl;
				print_choose();
				int choose = 0;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					All_terrain_boots boots(6, 60, "Ботинки вездеходы");
					ar[x] = boots.race(distance);
					registration_vehicle(size, arr, &boots, &t, arrr, &x);
					break;
				}
				case 2:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 3:
				{
					Camel camel(10, 30, "Верблюд");
					ar[x] = camel.race(distance);
					registration_vehicle(size, arr, &camel, &t, arrr, &x);
					break;
				}
				case 4:
				{
					Centaur centaur(15, 8, "Кентавр");
					ar[x] = centaur.race(distance);
					registration_vehicle(size, arr, &centaur, &t, arrr, &x);
					break;
				}
				case 5:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 6:
				{
					Fast_camel fast_camel(40, 10, "Верблюд-быстроход");
					ar[x] = fast_camel.race(distance);
					registration_vehicle(size, arr, &fast_camel, &t, arrr, &x);
					break;
				}
				case 7:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 0:
				{
					std::cout << "1. Зарегестрировать транспорт " << std::endl;
					std::cout << "2. Начать гонку " << std::endl;
					std::cin >> a;
					if (a == 1)
					{
						a = 1;
					}
					if (a == 2)
					{
						if (x < 2)
						{
							std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства. Продолжите регистрацию!" << std::endl;
							a = 1;
						}
						else
						{
							int quit = 0;
							sort(ar, x, arr);
							print_race(ar, x, arr);
							std::cout << "1. Провести еще одну гонку" << std::endl;
							std::cout << "2. Выход из программы" << std::endl;
							del_arr(ar, arr, arrr, &x);
							std::cin >> quit;
							if (quit == 1)
							{
								out = 1;
								a = 0;
							}
							else
							{
								out = 0;
								a = 0;
							}

						}
					}
					break;
				}
				default:
					break;
				}
				break;
			}
			case 2:
			{
				std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
				print_choose();
				int choose = 0;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 2:
				{
					Broomstick broomstick(20, "Метла");
					ar[x] = broomstick.race(distance);
					registration_vehicle(size, arr, &broomstick, &t, arrr, &x);
					break;
				}
				case 3:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 4:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 5:
				{
					Eagle eagle(8, "Орел");
					ar[x] = eagle.race(distance);
					registration_vehicle(size, arr, &eagle, &t, arrr, &x);
					break;
				}
				case 6:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 7:
				{
					Magic_carpet magic_carpet(10, "Ковер-самолет");
					ar[x] = magic_carpet.race(distance);
					registration_vehicle(size, arr, &magic_carpet, &t, arrr, &x);
					break;
				}
				case 0:
				{
					std::cout << "1. Зарегестрировать транспорт " << std::endl;
					std::cout << "2. Начать гонку " << std::endl;
					std::cin >> a;
					if (a == 1)
					{
						a = 1;
					}
					if (a == 2)
					{
						if (x < 2)
						{
							std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства. Продолжите регистрацию!" << std::endl;
							a = 1;
						}
						else
						{
							int quit = 0;
							sort(ar, x, arr);
							print_race(ar, x, arr);
							std::cout << "1. Провести еще одну гонку" << std::endl;
							std::cout << "2. Выход из программы" << std::endl;
							del_arr(ar, arr, arrr, &x);
							std::cin >> quit;
							if (quit == 1)
							{
								out = 1;
								a = 0;
							}
							else
							{
								out = 0;
								a = 0;
							}

						}
					}
					break;
				}
				default:
					break;
				}
				break;
			}
			case 3:
			{
				std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << std::endl;
				print_choose();
				int choose = 0;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					All_terrain_boots boots(6, 60, "Ботинки вездеходы");
					ar[x] = boots.race(distance);
					registration_vehicle(size, arr, &boots, &t, arrr, &x);
					break;
				}
				case 2:
				{
					Broomstick broomstick(20, "Метла");
					ar[x] = broomstick.race(distance);
					registration_vehicle(size, arr, &broomstick, &t, arrr, &x);
					break;
				}
				case 3:
				{
					Camel camel(10, 30, "Верблюд");
					ar[x] = camel.race(distance);
					registration_vehicle(size, arr, &camel, &t, arrr, &x);
					break;
				}
				case 4:
				{
					Centaur centaur(15, 8, "Кентавр");
					ar[x] = centaur.race(distance);
					registration_vehicle(size, arr, &centaur, &t, arrr, &x);
					break;
				}
				case 5:
				{
					Eagle eagle(8, "Орел");
					ar[x] = eagle.race(distance);
					registration_vehicle(size, arr, &eagle, &t, arrr, &x);
					break;
				}
				case 6:
				{
					Fast_camel fast_camel(40, 10, "Верблюд-быстроход");
					ar[x] = fast_camel.race(distance);
					registration_vehicle(size, arr, &fast_camel, &t, arrr, &x);
					break;
				}
				case 7:
				{
					Magic_carpet magic_carpet(10, "Ковер-самолет");
					ar[x] = magic_carpet.race(distance);
					registration_vehicle(size, arr, &magic_carpet, &t, arrr, &x);
					break;
				}
				case 0:
				{
					std::cout << "1. Зарегестрировать транспорт " << std::endl;
					std::cout << "2. Начать гонку " << std::endl;
					std::cin >> a;
					if (a == 1)
					{
						a = 1;
					}
					if (a == 2)
					{
						if (x <= 2)
						{
							std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства. Продолжите регистрацию!" << std::endl;
							a = 1;
						}
						else
						{
							int quit = 0;
							sort(ar, x, arr);
							print_race(ar, x, arr);
							std::cout << "1. Провести еще одну гонку" << std::endl;
							std::cout << "2. Выход из программы" << std::endl;
							del_arr(ar, arr, arrr, &x);
							std::cin >> quit;
							if (quit == 1)
							{
								out = 1;
								a = 0;
							}
							else
							{
								out = 0;
								a = 0;
							}

						}
					}
					break;
				}
				default:
					break;
				}
			}
			break;
			}
		}
	}
	return 0;
}
