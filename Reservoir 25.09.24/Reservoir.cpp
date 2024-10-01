#include "Reservoir.h"
#include <string.h>
#include <iostream>
using namespace std;

Reservoir::Reservoir()
{
}

Reservoir::Reservoir(const char* t, const char* n, int d, int w, int l) : depth(d), width(w), length(l)
{
	if (t != nullptr) {
		type = new char[strlen(t) + 1];
		strcpy_s(this->type, strlen(t) + 1, t);
	}

	if (n != nullptr) {
		name = new char[strlen(n) + 1];
		strcpy_s(this->name, strlen(n) + 1, n);
	}
}

Reservoir::Reservoir(const Reservoir& other) : depth(other.depth), width(other.width), length(other.length)
{
	type = new char[strlen(other.type) + 1];
	strcpy_s(type, strlen(other.type) + 1, other.type);

	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
}

Reservoir::~Reservoir()
{
	delete[]type;
	delete[]name;
}

int Reservoir::Volume() const
{
	return width * length * depth;
}

int Reservoir::Area() const
{
	return width * length;
}

bool Reservoir::TypeComparison(const Reservoir& other) const
{
	return type == other.type;
}

bool Reservoir::SameTypeAreaComparison(const Reservoir& other) const
{
	setlocale(LC_ALL, "Russian");
	if (!TypeComparison(other)) {
		cout << "Водоемы разных типов, невозможно сравнить.\n";
		return false;
	}
	return Area() > other.Area();
}

void Reservoir::SetType(const char* t)
{
	const char* type = t;
}

void Reservoir::SetName(const char* n)
{
	const char* name = n;
}

void Reservoir::SetDepth(int d)
{
	depth = d;
}

void Reservoir::SetWidth(int w)
{
	width = w;
}

void Reservoir::SetLengh(int l)
{
	length = l;
}

const char* Reservoir::GetType() const
{
	return type;
}

const char* Reservoir::GetName() const
{
	return name;
}

int Reservoir::GetDepth() const
{
	return 0;
}

int Reservoir::GetWidth() const
{
	return 0;
}

int Reservoir::GetLengh() const
{
	return 0;
}

void Reservoir::Display() const
{
	setlocale(LC_ALL, "Russian");
	cout << "Название: " << name << "\n"
		<< "Тип: " << type << "\n"
		<< "Ширина: " << width << "\n"
		<< "Длина: " << length << "\n"
		<< "Глубина: " << depth << "\n"
		<< "Площадь: " << Area() << "\n"
		<< "Объем: " << Volume() << "\n";
}
