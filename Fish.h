#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public virtual Animal
{
public:
	Fish() : Animal()
	{
		m_finCount = 0;
		m_gillsCount = 0;
	};


	Fish(int fin, int gills)
		: Animal(), m_finCount(fin), m_gillsCount(gills)
	{
	}


	Fish(const char* color, int childs, float avgLifetime, int fin, int gills)
		: Animal(color, childs, avgLifetime)
	{
		m_finCount = fin;
		m_gillsCount = gills;
	}


	Fish(ifstream& in_file) : Animal(in_file) {
		// Read the Fish-specific properties
		in_file >> m_finCount;
		in_file >> m_gillsCount;
		in_file.ignore();
	}

	virtual ~Fish() {};

public:

	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int		GetFinCount() const { return m_finCount; };
	int		GetGillsCount() const {return m_gillsCount;}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetFinCount(int finCount)
	{
		this->m_finCount = finCount;
	}
	void SetGillsCount(int gillsCount)
	{
		this->m_gillsCount = gillsCount;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	virtual Animal* clone() const override {
		return new Fish(*this);
	}


	// Override pure virtual functions from the base class
	virtual void printInfo() const override {
		cout << "Color: " << GetColor() << endl;
		cout << "Child Count: " << GetChildCount() << endl;
		cout << "Average Lifetime: " << GetLifetime() << endl;
		cout << "Fin Count: " << GetFinCount() << endl;
		cout << "Gills Count: " << GetGillsCount() << endl;
	}

	virtual void save(ofstream& out_file) const override {
		out_file << GetColor() << endl;
		out_file << GetChildCount() << endl;
		out_file << GetLifetime() << endl;
		out_file << GetFinCount() << endl;
		out_file << GetGillsCount() << endl;
		out_file << "END" << '\n';  // Add the "END" marker

	}

	virtual void load(ifstream& in_file) override {
		char color[100];
		int childCount, finCount, gillsCount;
		float avgLifetime;

		in_file >> color;
		in_file >> childCount;
		in_file >> avgLifetime;
		in_file >> finCount;
		in_file >> gillsCount;

		SetColor(color);
		SetChildCount(childCount);
		SetavgLifeTime(avgLifetime);
		SetFinCount(finCount);
		SetGillsCount(gillsCount);
	}


protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef