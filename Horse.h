#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse() : Mammals() {
		//m_type = new char[strlen("Unknown") + 1];
		//strcpy(m_type, "Unknown");
		m_type = NULL;
	}
	Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) : Mammals(color, childs, avgLifetime, preg, milk)
	{
		m_type = new char[strlen(type) + 1];
		strcpy(m_type,type);
	}

    Horse(ifstream& in_file) : Mammals(in_file){

        // Read the Horse-specific properties
        char type[100];
        in_file >> type;
        SetType(type);


    }

	virtual ~Horse() {
		delete[] m_type;
	}

public:

	// Access // 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* GetType() const { return m_type; }//return the type of the horse
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Getters // 
	void SetType(char* type)
	{
		delete[] m_type;
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual Animal* clone() const override {
		return new Horse(*this);
	}




	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Override pure virtual functions from the base class
    virtual void printInfo() const override {
        cout << "Horse Info:" << endl;
        cout << "Color: " << GetColor() << endl;
        cout << "Child Count: " << GetChildCount() << endl;
        cout << "Average Lifetime: " << GetLifetime() << endl;
        cout << "Pregnancy Time: " << GetPregnanceTime() << endl;
        cout << "Milk Liters: " << GetMilk() << endl;
        cout << "Type: " << GetType() << endl;
    }

    virtual void save(ofstream& out_file) const override {
        out_file << "Horse" << endl;
        out_file << GetColor() << endl;
        out_file << GetChildCount() << endl;
        out_file << GetLifetime() << endl;
        out_file << GetPregnanceTime() << endl;
        out_file << GetMilk() << endl;
        out_file << GetType() << endl;
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

        float pregnancyTime;
        in_file >> pregnancyTime;
        SetPregnanceTime(pregnancyTime);

        float milkLiters;
        in_file >> milkLiters;
        SetMilkLiters(milkLiters);

        char type[100];
        in_file >> type;
        SetType(type);

        char end[100];
        in_file >> end;

    }



protected:
	char*	m_type;
};

#endif // ifndef