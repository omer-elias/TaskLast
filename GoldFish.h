#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public:
	GoldFish() : MammalsFish() {
		m_avgWeight = 0.0f;
		m_avgLength = 0.0f;
	};
	GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
	{
		m_avgWeight = 0.0f;
		m_avgLength = 0.0f;
	}
	GoldFish(ifstream& in_file) : MammalsFish(in_file) {
		// Read the GoldFish properties


	}
	virtual ~GoldFish() {};

public:

	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetWeight() const { return m_avgWeight; }//return the avg weight of the gold fish
	float		GetLength() const { return m_avgLength; };//return the avg length of the gold fish
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetWeight(float avgWeight)
	{
		this->m_avgWeight = avgWeight;
	}
	void SetLength(float length)
	{
		this->m_avgLength = length;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



	virtual Animal* clone() const override {
		return new GoldFish(*this);
	}


	virtual void printInfo() const override {
		MammalsFish::printInfo();
		cout << "Average Weight: " << m_avgWeight << endl;
		cout << "Average Length: " << m_avgLength << endl;
	}

	virtual void save(ofstream& out_file) const override {
		MammalsFish::save(out_file);
		out_file.write(reinterpret_cast<const char*>(&m_avgWeight), sizeof(m_avgWeight));
		out_file.write(reinterpret_cast<const char*>(&m_avgLength), sizeof(m_avgLength));
		out_file << "END" << '\n';  // Add the "END" marker

	}





protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef