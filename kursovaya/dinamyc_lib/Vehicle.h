#pragma once
#include <iostream>
#ifdef DINAMLIBRACE_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif
class Vehicle
{
public:
	MATHPOWERLIBRARY_API virtual const std::string get_name();
	MATHPOWERLIBRARY_API virtual int race(double dis);
};