#include <iostream>
class Ground
{
public:
	virtual std::string get_name()
	{
		return "name";
	}
	virtual int race(int dis)
	{
		return 0;
	}
};
class Air
{
public:
	virtual std::string get_name()
	{
		return "name";
	}
	virtual int race(double dis)
	{
		return 0;
	}
};
class Camel : public Ground
{
private:
	int speed = 10;
	int rest = 30;
	std::string name = "Верблюд";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(int dis) override
	{
		int time = 0;
		time = dis / speed;
		if (time > rest)
		{
			int a = time / rest;
			if (time % rest != 0)
			{
				a++;
			}
			for (int i = 0; i < a - 1; i++)
			{
				if (a == 1)
				{
					time += 5;
					return time;
				}
				{

					if (a != 1)
					{
						if (i == 0)
						{
							time += 5;
						}
						else
						{
							time += 8;
						}
					}
				}
			}
		}
		return time;
	}
};
class Fast_camel : public Ground
{
private:
	int speed = 40;
	int rest = 10;
	std::string name = "Верблюд-быстроход";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(int dis) override
	{
		int time = 0;
		time = dis / speed;
		if (time > rest)
		{
			int a = time / rest;
			if (time % rest != 0)
			{
				a++;
			}
			for (int i = 0; i < a - 1; i++)
			{
				if (a == 1)
				{
					time += 5;
					return time;
				}
				if (a == 2)
				{
					if (i == 0)
					{
						time += 5;
					}
					else
					{
						time += 6, 5;
					}
				}
				{

					if (a >= 3)
					{
						if (i == 0)
						{
							time += 5;
						}
						else if (i == 1)
						{
							time += 6, 5;
						}
						else
						{
							time += 8;
						}
					}
				}
			}
		}
		return time;
	}
};
class Centaur : public Ground
{
private:
	int speed = 15;
	int rest = 8;
	std::string name = "Кентавр";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(int dis) override
	{
		int time = 0;
		time = dis / speed;
		if (time > rest)
		{
			int a = time / rest;
			if (time % rest != 0)
			{
				a++;
			}
			for (int i = 0; i < a - 1; i++)
			{
				time += 2;
			}
		}
		return time;
	}
};
class All_terrain_boots : public Ground
{
private:
	int speed = 6;
	int rest = 60;
	std::string name = "Ботинки-вездеходы";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(int dis) override
	{
		int time = 0;
		time = dis / speed;
		if (time > rest)
		{
			int a = time / rest;
			if (time % rest != 0)
			{
				a++;
			}
			for (int i = 0; i < a - 1; i++)
			{
				if (a == 1)
				{
					time += 10;
					return time;
				}
				{

					if (a != 1)
					{
						if (i == 0)
						{
							time += 10;
						}
						else
						{
							time += 5;
						}
					}
				}
			}
		}
		return time;
	}
};
class Magic_carpet : public Air
{
private:
	int speed = 10;
	std::string name = "Ковёр-самолёт";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(double dis) override
	{
		int time = 0;
		if (dis < 1000)
		{
			return time = dis / speed;

		}
		else if (dis >= 1000 && dis < 5000)
		{
			dis *= 0.97;
			return time = dis / speed;
		}
		else if (dis >= 5000 && dis < 10000)
		{
			dis *= 0.9;
			return time = dis / speed;
		}
		else
		{
			dis *= 0.95;
			return time = dis / speed;
		}
	}
};
class Eagle : public Air
{
private:
	int speed = 8;
	std::string name = "Орёл";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(double dis) override
	{
		int time = 0;
		dis *= 0.94;
		return time = time = dis / speed;;
	}
};
class Broomstick : public Air
{
private:
	int speed = 20;
	std::string name = "Метла";
public:
	std::string get_name() override
	{
		return name;
	}
	int race(double dis) override
	{
		int time = 0;
		int tmp = dis;
		double tmp_d = 0;
		tmp /= 1000;
		tmp_d = tmp / 100.0;
		dis *= 1 - tmp_d;
		return time = dis / speed;
	}
};
std::string* check_ground(Ground* ground, std::string* arr, int* x)
{
	arr[*x] = ground->get_name();
	(*x)++;
	return arr;
}
std::string* check_air(Air* air, std::string* arr, int* x)
{
	arr[*x] = air->get_name();
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
void registration_ground(int size, std::string* arr, Ground* ground, int* t, std::string* arrr, int* x)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == ground->get_name())
		{
			std::cout << "Транспортное средство " << ground->get_name() << " уже зарегестрировано" << std::endl;
			*t = 1;
		}
	}
	if (*t != 1)
	{
		arrr = check_ground(ground, arr, x);
		std::cout << "Транспортное средство " << ground->get_name() << " успешно зарегестрировано" << std::endl;
		std::cout << "Зарегестрированные транспортные средства: ";
		for (int i = 0; i < *x; i++)
		{
			std::cout << arrr[i] << ", ";
		}
		std::cout << std::endl;
	}
	*t = 0;
}
void registration_air(int size, std::string* arr, Air* air, int* t, std::string* arrr, int* x)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == air->get_name())
		{
			std::cout << "Транспортное средство " << air->get_name() << " уже зарегестрировано" << std::endl;
			*t = 1;
		}
	}
	if (*t != 1)
	{
		arrr = check_air(air, arr, x);
		std::cout << "Транспортное средство " << air->get_name() << " успешно зарегестрировано" << std::endl;
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
					All_terrain_boots boots;
					ar[x] = boots.race(distance);
					registration_ground(size, arr, &boots, &t, arrr, &x);
					break;
				}
				case 2:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 3:
				{
					Camel camel;
					ar[x] = camel.race(distance);
					registration_ground(size, arr, &camel, &t, arrr, &x);
					break;
				}
				case 4:
				{
					Centaur centaur;
					ar[x] = centaur.race(distance);
					registration_ground(size, arr, &centaur, &t, arrr, &x);
					break;
				}
				case 5:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 6:
				{
					Fast_camel fast_camel;
					ar[x] = fast_camel.race(distance);
					registration_ground(size, arr, &fast_camel, &t, arrr, &x);
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
					Broomstick broomstick;
					ar[x] = broomstick.race(distance);
					registration_air(size, arr, &broomstick, &t, arrr, &x);
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
					Eagle eagle;
					ar[x] = eagle.race(distance);
					registration_air(size, arr, &eagle, &t, arrr, &x);
					break;
				}
				case 6:
				{
					std::cout << "Неверный тип транспортного средства!" << std::endl;
					break;
				}
				case 7:
				{
					Magic_carpet magic_carpet;
					ar[x] = magic_carpet.race(distance);
					registration_air(size, arr, &magic_carpet, &t, arrr, &x);
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
					All_terrain_boots boots;
					ar[x] = boots.race(distance);
					registration_ground(size, arr, &boots, &t, arrr, &x);
					break;
				}
				case 2:
				{
					Broomstick broomstick;
					ar[x] = broomstick.race(distance);
					registration_air(size, arr, &broomstick, &t, arrr, &x);
					break;
				}
				case 3:
				{
					Camel camel;
					ar[x] = camel.race(distance);
					registration_ground(size, arr, &camel, &t, arrr, &x);
					break;
				}
				case 4:
				{
					Centaur centaur;
					ar[x] = centaur.race(distance);
					registration_ground(size, arr, &centaur, &t, arrr, &x);
					break;
				}
				case 5:
				{
					Eagle eagle;
					ar[x] = eagle.race(distance);
					registration_air(size, arr, &eagle, &t, arrr, &x);
					break;
				}
				case 6:
				{
					Fast_camel fast_camel;
					ar[x] = fast_camel.race(distance);
					registration_ground(size, arr, &fast_camel, &t, arrr, &x);
					break;
				}
				case 7:
				{
					Magic_carpet magic_carpet;
					ar[x] = magic_carpet.race(distance);
					registration_air(size, arr, &magic_carpet, &t, arrr, &x);
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