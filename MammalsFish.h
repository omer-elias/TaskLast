#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish() :Mammals(),Fish() {};
	MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
		: Animal(color, childs, avgLifetime), Mammals(preg, milk), Fish(fin, gills)
	{
		// ...
	}

	MammalsFish(ifstream& in_file) : Mammals(in_file), Fish(in_file) {
		// No additional properties to read
	}
	virtual ~MammalsFish() {};




	virtual Animal* clone() const override {
		return new MammalsFish(*this);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Override pure virtual functions from the base class
	virtual void printInfo() const override {
		Mammals::printInfo();
		Fish::printInfo();
	}

	virtual void save(ofstream& out_file) const override {
		Mammals::save(out_file);
		Fish::save(out_file);

	}

	virtual void load(ifstream& in_file) override {
		Mammals::load(in_file);
		Fish::load(in_file);
	}


};

#endif // ifndef