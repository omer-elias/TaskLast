#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals : public virtual Animal
{
public:

	// C'tors //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Mammals() : Animal() {
		m_pregnancyTime = 0.0f;
		m_milkLiters = 0.0f;
	}
	Mammals(const char* color, int childs, float avgLifetime, float preg, float milk) : Animal(color, childs, avgLifetime)
	{
		this->m_pregnancyTime = preg;
		this->m_milkLiters = milk;
	}

	Mammals(float preg, float milk) : Animal()
	{
		this->m_pregnancyTime = preg;
		this->m_milkLiters = milk;
	}

	Mammals(ifstream& in_file) : Animal(in_file) {
		char color[100];
		in_file >> color;
		SetColor(color);

		int childCount;
		in_file >> childCount;
		SetChildCount(childCount);

		float avgLifetime;
		in_file >> avgLifetime;
		SetavgLifeTime(avgLifetime);

		// Read the Mammals properties
		in_file >> m_pregnancyTime;
		in_file >> m_milkLiters;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual ~Mammals() {};

public:

	// Access // 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetPregnanceTime() const { return m_pregnancyTime; }//return the pregnance time of the animal
	float		GetMilk() const { return m_milkLiters; };//return the milk liters of the animal
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



	//Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetPregnanceTime(float pregnancyTime)
	{
		this->m_pregnancyTime = pregnancyTime;
	}
	void SetMilkLiters(float milkLiters)
	{
		this->m_milkLiters = milkLiters;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	virtual Animal* clone() const override {
		return new Mammals(*this);
	}

	// Ensure it wont be a abstract class //
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Override pure virtual functions from the base class
	virtual void printInfo() const override {
		cout << "Color: " << GetColor() << endl;
		cout << "Child Count: " << GetChildCount() << endl;
		cout << "Average Lifetime: " << GetLifetime() << endl;
		cout << "Pregnancy Time: " << GetPregnanceTime() << endl;
		cout << "Milk Liters: " << GetMilk() << endl;
	}

	virtual void save(ofstream& out_file) const override {
		out_file << GetColor() << endl;
		out_file << GetChildCount() << endl;
		out_file << GetLifetime() << endl;
		out_file << GetPregnanceTime() << endl;
		out_file << GetMilk() << endl;
		out_file << "END" << '\n';  // Add the "END" marker


	}

	virtual void load(ifstream& in_file) override {
		char color[100];
		int childCount;
		float avgLifetime, pregnancyTime, milkLiters;

		in_file >> color;
		in_file >> childCount;
		in_file >> avgLifetime;
		in_file >> pregnancyTime;
		in_file >> milkLiters;

		SetColor(color);
		SetChildCount(childCount);
		SetavgLifeTime(avgLifetime);
		SetPregnanceTime(pregnancyTime);
		SetMilkLiters(milkLiters);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef