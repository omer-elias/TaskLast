#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public:
	Flamingo() : Birds()
	{
		m_avgHeight = 0.0f;
	}
	Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color,childs,avgLifetime,incubation)
	{
		this->m_avgHeight = avgHeight;
	}

    Flamingo(ifstream& in_file) : Birds(in_file) {

        // Read the Horse-specific properties
        char type[100];
        in_file >> type;
        setHeight(m_avgHeight);
        in_file.ignore();
    }


    virtual ~Flamingo() {};

public:
	// Getters // 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetHeight() const { return m_avgHeight; }//return the avg height of the flamingo
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setHeight(float avgHeight)
	{
		this->m_avgHeight = avgHeight;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
    // Override pure virtual functions from the base class
    virtual void printInfo() const override {
        cout << "Flamingo Info:" << endl;
        cout << "Color: " << GetColor() << endl;
        cout << "Child Count: " << GetChildCount() << endl;
        cout << "Average Lifetime: " << GetLifetime() << endl;
        cout << "Incubation Time: " << GetIncubationTime() << endl;
        cout << "Average Height: " << GetHeight() << endl;
    }

    virtual void save(ofstream& out_file) const override {
        out_file << "Flamingo" << endl;
        out_file << GetColor() << endl;
        out_file << GetChildCount() << endl;
        out_file << GetLifetime() << endl;
        out_file << GetIncubationTime() << endl;
        out_file << GetHeight() << endl;
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

        float avgHeight;
        in_file >> avgHeight;
        setHeight(avgHeight);
    }

	virtual Animal* clone() const override {
		return new Flamingo(*this);
	}


protected:
	float m_avgHeight;
};

#endif // ifndef