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
	std::cout << "1. ������� ���������" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "3. �������" << std::endl;
	std::cout << "4. �������" << std::endl;
	std::cout << "5. ����" << std::endl;
	std::cout << "6. �������-���������" << std::endl;
	std::cout << "7. �����-�������" << std::endl;
	std::cout << "0. ��������� �����������" << std::endl;
	std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
}
void registration_vehicle(int size, std::string* arr, Vehicle* vehicle, int* t, std::string* arrr, int* x)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == vehicle->get_name())
		{
			std::cout << "������������ �������� " << vehicle->get_name() << " ��� ����������������" << std::endl;
			*t = 1;
		}
	}
	if (*t != 1)
	{
		arrr = check_vehicle(vehicle, arr, x);
		std::cout << "������������ �������� " << vehicle->get_name() << " ������� ����������������" << std::endl;
		std::cout << "������������������ ������������ ��������: ";
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
		std::cout << arrr[i] << ". �����: " << arr[i] << std::endl;
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
	std::cout << "����� ���������� � �������� ���������!" << std::endl;
	while (out)
	{
		std::string* arr = new std::string[size];
		std::string* arrr = new std::string[size];
		int* ar = new int[size];
		std::cout << "1. ����� ��� ��������� ����������" << std::endl;
		std::cout << "2. ����� ��� ���������� ����������" << std::endl;
		std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
		std::cout << "�������� ��� �����: ";
		int type = 0;
		std::cin >> type;
		if (type != 1 && type != 2 && type != 3)
		{
			type = 0;
		}
		while (!type)
		{
			std::cout << "����� ����� ������ ���� ����� 1, 2 ��� 3. ������� ����� ��������: ";
			std::cin >> type;
			if (type != 1 && type != 2 && type != 3)
			{
				type = 0;
			}
		}
		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		int distance = 0;
		std::cin >> distance;
		while (!distance)
		{
			std::cout << "��������� ������ ���� �������������. ������� ����� ��������: ";
			std::cin >> distance;
			if (distance <= 0)
			{
				distance = 0;
			}
		}
		std::cout << "������ ���� ���������������� ���� �� 2 ������������ �������� " << std::endl;
		std::cout << "1. ���������������� ��������� " << std::endl;
		std::cout << "�������� ��������: ";
		int action = 0;
		std::cin >> action;
		int a = 1;
		while (a)
		{
			switch (type)
			{
			case 1:
			{
				std::cout << "����� ��� ��������� ����������. ����������: " << distance << std::endl;
				print_choose();
				int choose = 0;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					All_terrain_boots boots(6, 60, "������� ���������");
					ar[x] = boots.race(distance);
					registration_vehicle(size, arr, &boots, &t, arrr, &x);
					break;
				}
				case 2:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 3:
				{
					Camel camel(10, 30, "�������");
					ar[x] = camel.race(distance);
					registration_vehicle(size, arr, &camel, &t, arrr, &x);
					break;
				}
				case 4:
				{
					Centaur centaur(15, 8, "�������");
					ar[x] = centaur.race(distance);
					registration_vehicle(size, arr, &centaur, &t, arrr, &x);
					break;
				}
				case 5:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 6:
				{
					Fast_camel fast_camel(40, 10, "�������-���������");
					ar[x] = fast_camel.race(distance);
					registration_vehicle(size, arr, &fast_camel, &t, arrr, &x);
					break;
				}
				case 7:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 0:
				{
					std::cout << "1. ���������������� ��������� " << std::endl;
					std::cout << "2. ������ ����� " << std::endl;
					std::cin >> a;
					if (a == 1)
					{
						a = 1;
					}
					if (a == 2)
					{
						if (x < 2)
						{
							std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������. ���������� �����������!" << std::endl;
							a = 1;
						}
						else
						{
							int quit = 0;
							sort(ar, x, arr);
							print_race(ar, x, arr);
							std::cout << "1. �������� ��� ���� �����" << std::endl;
							std::cout << "2. ����� �� ���������" << std::endl;
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
				std::cout << "����� ��� ���������� ����������. ����������: " << distance << std::endl;
				print_choose();
				int choose = 0;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 2:
				{
					Broomstick broomstick(20, "�����");
					ar[x] = broomstick.race(distance);
					registration_vehicle(size, arr, &broomstick, &t, arrr, &x);
					break;
				}
				case 3:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 4:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 5:
				{
					Eagle eagle(8, "����");
					ar[x] = eagle.race(distance);
					registration_vehicle(size, arr, &eagle, &t, arrr, &x);
					break;
				}
				case 6:
				{
					std::cout << "�������� ��� ������������� ��������!" << std::endl;
					break;
				}
				case 7:
				{
					Magic_carpet magic_carpet(10, "�����-�������");
					ar[x] = magic_carpet.race(distance);
					registration_vehicle(size, arr, &magic_carpet, &t, arrr, &x);
					break;
				}
				case 0:
				{
					std::cout << "1. ���������������� ��������� " << std::endl;
					std::cout << "2. ������ ����� " << std::endl;
					std::cin >> a;
					if (a == 1)
					{
						a = 1;
					}
					if (a == 2)
					{
						if (x < 2)
						{
							std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������. ���������� �����������!" << std::endl;
							a = 1;
						}
						else
						{
							int quit = 0;
							sort(ar, x, arr);
							print_race(ar, x, arr);
							std::cout << "1. �������� ��� ���� �����" << std::endl;
							std::cout << "2. ����� �� ���������" << std::endl;
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
				std::cout << "����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;
				print_choose();
				int choose = 0;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					All_terrain_boots boots(6, 60, "������� ���������");
					ar[x] = boots.race(distance);
					registration_vehicle(size, arr, &boots, &t, arrr, &x);
					break;
				}
				case 2:
				{
					Broomstick broomstick(20, "�����");
					ar[x] = broomstick.race(distance);
					registration_vehicle(size, arr, &broomstick, &t, arrr, &x);
					break;
				}
				case 3:
				{
					Camel camel(10, 30, "�������");
					ar[x] = camel.race(distance);
					registration_vehicle(size, arr, &camel, &t, arrr, &x);
					break;
				}
				case 4:
				{
					Centaur centaur(15, 8, "�������");
					ar[x] = centaur.race(distance);
					registration_vehicle(size, arr, &centaur, &t, arrr, &x);
					break;
				}
				case 5:
				{
					Eagle eagle(8, "����");
					ar[x] = eagle.race(distance);
					registration_vehicle(size, arr, &eagle, &t, arrr, &x);
					break;
				}
				case 6:
				{
					Fast_camel fast_camel(40, 10, "�������-���������");
					ar[x] = fast_camel.race(distance);
					registration_vehicle(size, arr, &fast_camel, &t, arrr, &x);
					break;
				}
				case 7:
				{
					Magic_carpet magic_carpet(10, "�����-�������");
					ar[x] = magic_carpet.race(distance);
					registration_vehicle(size, arr, &magic_carpet, &t, arrr, &x);
					break;
				}
				case 0:
				{
					std::cout << "1. ���������������� ��������� " << std::endl;
					std::cout << "2. ������ ����� " << std::endl;
					std::cin >> a;
					if (a == 1)
					{
						a = 1;
					}
					if (a == 2)
					{
						if (x <= 2)
						{
							std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������. ���������� �����������!" << std::endl;
							a = 1;
						}
						else
						{
							int quit = 0;
							sort(ar, x, arr);
							print_race(ar, x, arr);
							std::cout << "1. �������� ��� ���� �����" << std::endl;
							std::cout << "2. ����� �� ���������" << std::endl;
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
