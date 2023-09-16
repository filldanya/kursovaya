#pragma once
#include <iostream>
#include "Air.h"
#ifdef DINAMLIBRACE_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif
class Broomstick : public Air
{
private:
	int speed;
	std::string name;
public:
	MATHPOWERLIBRARY_API Broomstick(int speed, std::string name);
	MATHPOWERLIBRARY_API std::string const get_name() override;
	MATHPOWERLIBRARY_API int race(double dis) override;
};