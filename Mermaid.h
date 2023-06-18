#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public:
	Mermaid() : MammalsFish() {
	/*	m_firstName = new char[strlen("Unknown") + 1];
		strcpy(m_firstName, "Unknown");
		m_lastName = new char[strlen("Unknown") + 1];
		strcpy(m_lastName, "Unknown");*/
		m_firstName = NULL;
        m_lastName = NULL;

	};
	Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
	{
		m_firstName = new char[strlen(firstName) + 1];
		strcpy(m_firstName, firstName);
		m_lastName = new char[strlen(lastName) + 1];
		strcpy(m_lastName, lastName);
	}
    Mermaid(ifstream& in_file) : MammalsFish(in_file) {
        char firstName[100];
        in_file >> firstName;
        SetFirstName(firstName);

        char lastName[100];
        in_file >> lastName;
        SetLastName(lastName);
        in_file.ignore();
    }


    virtual ~Mermaid() {};

public:

	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* GetFirstName() const { return m_firstName; }//return the first name of the mermaid
	const char* GetLastName() const { return m_lastName; }//return the last name of the mermaid
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	virtual Animal* clone() const override {
		return new Mermaid(*this);
	}

	
	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetFirstName(char* firstname) {
		m_firstName = new char[strlen(firstname) + 1];
		strcpy(m_firstName, firstname);
	}
	void SetLastName(char* lastname) {
		m_lastName = new char[strlen(lastname) + 1];
		strcpy(m_lastName, lastname);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Override pure virtual functions from the base class
   virtual void printInfo() const override {
        cout << "Mermaid Info:" << endl;
        cout << "Color: " << GetColor() << endl;
        cout << "Child Count: " << GetChildCount() << endl;
        cout << "Average Lifetime: " << GetLifetime() << endl;
        cout << "Pregnancy Time: " << GetPregnanceTime() << endl;
        cout << "Milk Liters: " << GetMilk() << endl;
        cout << "Fin Count: " << GetFinCount() << endl;
        cout << "Gills Count: " << GetGillsCount() << endl;
        cout << "First Name: " << GetFirstName() << endl;
        cout << "Last Name: " << GetLastName() << endl;
    }

    virtual void save(ofstream& out_file) const override {
        out_file << "Mermaid" << endl;
        out_file << GetColor() << endl;
        out_file << GetChildCount() << endl;
        out_file << GetLifetime() << endl;
        out_file << GetPregnanceTime() << endl;
        out_file << GetMilk() << endl;
        out_file << GetFinCount() << endl;
        out_file << GetGillsCount() << endl;
        out_file << GetFirstName() << endl;
        out_file << GetLastName() << endl;
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

        int finCount;
        in_file >> finCount;
        SetFinCount(finCount);

        int gillsCount;
        in_file >> gillsCount;
        SetGillsCount(gillsCount);

        char firstName[100];
        in_file >> firstName;
        SetFirstName(firstName);

        char lastName[100];
        in_file >> lastName;
        SetLastName(lastName);
    }

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef