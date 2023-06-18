#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public virtual Animal
{
public:
	Birds() : Animal() {
		m_incubationTime = 0.0f;
	};
	Birds(const char* color, int childs, float avgLifetime, float incubation) : Animal(color,childs,avgLifetime)
	{
		this->m_incubationTime = incubation;
	}

	Birds(ifstream& in_file) : Animal(in_file) {
		// Read the Fish-specific properties

		
		in_file >> m_incubationTime;
	}
	virtual ~Birds() {};

public:


	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetIncubationTime() const {
		return m_incubationTime;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetIncubationTime(float incubationTime)
	{
		this->m_incubationTime = incubationTime;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	virtual Animal* clone() const override {
		return new Birds(*this);
	}


	  // Override pure virtual functions from the base class
	virtual void printInfo() const override {
		cout << "Bird Info:" << endl;
		cout << "Color: " << GetColor() << endl;
		cout << "Child Count: " << GetChildCount() << endl;
		cout << "Average Lifetime: " << GetLifetime() << endl;
		cout << "Incubation Time: " << GetIncubationTime() << endl;
	}

	virtual void save(ofstream& out_file) const override {
		out_file << "Bird" << endl;
		out_file << GetColor() << endl;
		out_file << GetChildCount() << endl;
		out_file << GetLifetime() << endl;
		out_file << GetIncubationTime() << endl;
		out_file << "END" << '\n';  // Add the "END" marker

	}

	virtual void load(ifstream& in_file) override {
		char color[100];
		in_file >> color;
		SetColor(color);

		int childCount;
		in_file >> childCount;
		SetChildCount(childCount);

		float lifetime;
		in_file >> lifetime;
		SetavgLifeTime(lifetime);

		float incubationTime;
		in_file >> incubationTime;
		SetIncubationTime(incubationTime);
	}

protected:
	float m_incubationTime;
};

#endif // ifndef