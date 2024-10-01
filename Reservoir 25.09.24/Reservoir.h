#pragma once
class Reservoir
{
	char* type;
	char* name;
	int depth;
	int width;
	int length;
public:
	explicit Reservoir();
	explicit Reservoir(const char* t, const char* n, int d, int w, int l);
	Reservoir(const Reservoir& other);
	~Reservoir();

	int Volume() const;
	int Area() const;
	bool TypeComparison(const Reservoir& other) const;
	bool SameTypeAreaComparison(const Reservoir& other) const;

	void SetType(const char* t);
	void SetName(const char* n);
	void SetDepth(int d);
	void SetWidth(int w);
	void SetLengh(int l);

	const char* GetType() const;
	const char* GetName() const;
	int GetDepth() const;
	int GetWidth() const;
	int GetLengh() const;

	void Display() const;


};

