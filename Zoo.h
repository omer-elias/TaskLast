#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Horse.h"
#include "Birds.h"
#include "Fish.h"
#include "Flamingo.h"
#include "GoldFish.h"
#include "Mammals.h"
#include "MammalsFish.h"
#include "Mermaid.h"
class Zoo
{
public:
	Zoo() : m_name(NULL), m_address(NULL), m_ticketPrice(0.0f), m_openHours(NULL), m_closeHours(NULL), m_numOfAnimals(0), m_animals(NULL) {};//default c'tor  - all to 0 or null
	Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
	{
		this->m_name = new char[strlen(name)+1];
		strcpy(this->m_name, name);

		this->m_address = new char[strlen(address) + 1];
		strcpy(this->m_address, address);

		this->m_ticketPrice = ticket;

		this->m_openHours = new char[strlen(open) + 1];
		strcpy(this->m_address, open);

		this->m_closeHours = new char[strlen(close) + 1];
		strcpy(this->m_closeHours, close);

		m_numOfAnimals = 0;

		this->m_animals = new  Animal * [m_numOfAnimals];;

	}
	Zoo(ifstream& in_file) {
		// Read the basic Zoo properties
		char temp[100];  // Adjust the size as needed

		in_file.getline(temp, 99);
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);

		in_file.getline(temp, 99);
		m_address = new char[strlen(temp) + 1];
		strcpy(m_address, temp);

		in_file >> m_ticketPrice;
		in_file.ignore();  // Ignore the newline character

		in_file.getline(temp, 99);
		m_openHours = new char[strlen(temp) + 1];
		strcpy(m_openHours, temp);

		in_file.getline(temp, 99);
		m_closeHours = new char[strlen(temp) + 1];
		strcpy(m_closeHours, temp);

		in_file >> m_numOfAnimals;
		in_file.ignore();  // Ignore the newline character

		// Read each Animal
		m_animals = new Animal * [m_numOfAnimals];
		for (int i = 0; i < m_numOfAnimals; ++i) {
			// Read the type identifier
			in_file.getline(temp, 99);
			string type(temp);

			// Create an instance of the correct type
			if (type == "Horse") {
				m_animals[i] = new Horse(in_file);
			}
			else if (type == "GoldFish") {
				m_animals[i] = new GoldFish(in_file);
			}
			else if (type == "Fish") {
				m_animals[i] = new Fish(in_file);
			}
			else if (type == "Birds") {
				m_animals[i] = new Birds(in_file);
			}
			else if (type == "Flamingo") {
				m_animals[i] = new Flamingo(in_file);
			}
			else if (type == "Mammals") {
				m_animals[i] = new Mammals(in_file);
			}
			else if (type == "MammalsFish") {
				m_animals[i] = new MammalsFish(in_file);
			}
			else if (type == "Mermaid") {
				m_animals[i] = new Mermaid(in_file);
			}
		

			// Add more else if statements for each type of Animal
			// You'll need to add a constructor in each of these classes that takes an ifstream& as a parameter
		}
	}
	virtual ~Zoo()
	{

		delete[] m_name;
		delete[] m_address;
		delete[] m_openHours;
		delete[] m_closeHours;


		// Deallocate each Animal object
		for (int i = 0; i < m_numOfAnimals; ++i) {
			delete m_animals[i];
		}

		// Deallocate the array of Animal pointers
		delete[] m_animals;

	};//d'tor

public:

	// Getters //
	const char* GetName() const { return m_name; }//return the name of the zoo
	const char*		GetAddress() const { return m_address; };//return the address of the zoo
	float			GetTicketPrice() const { return m_ticketPrice; };//return the ticket price of the zoo
	const char*		GetOpenHour() const { return m_openHours; };//return the open hour of the zoo
	const char* GetCloseHour() const  { return m_closeHours; } ;//return the close hour of the zoo
	int				GetNumOfAnimals() const { return m_numOfAnimals; };//return the num of animals in the zoo

	Animal** GetAnimals() const {
		return m_animals;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



public:

	//TODO
	void AddAnimal(Animal* an) {
		// Create a new array with one more slot
		Animal** newAnimals = new Animal * [m_numOfAnimals + 1];

		// Copy the existing animal pointers to the new array
		for (int i = 0; i < m_numOfAnimals; ++i) {
			newAnimals[i] = m_animals[i];
		}

		// Add the new animal to the end of the new array
		newAnimals[m_numOfAnimals] = an->clone();

		// Delete the old array
		delete[] m_animals;

		// Update the animals array and the number of animals
		m_animals = newAnimals;
		m_numOfAnimals++;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetName(const char* name)
	{
		delete[] m_name;
		this->m_name = new char[strlen(name) + 1];
		strcpy(this->m_name, name);
	}
	void SetAddress(const char* address)
	{
		delete[] m_address;
		this->m_address = new char[strlen(address) + 1];
		strcpy(this->m_address, address);
	}
	
	void setTicketPrice(float ticketprice)
	{
		this->m_ticketPrice = ticketprice;
	}

	void SetOpenHours(const char* openinghours)
	{
		delete[] m_openHours;
		this->m_openHours = new char[strlen(openinghours) + 1];
		strcpy(this->m_openHours, openinghours);
	}

	void SetCloseHours(const char* closinhours)
	{
		delete[] m_closeHours;
		this->m_closeHours = new char[strlen(closinhours) + 1];
		strcpy(this->m_closeHours, closinhours);
	}

	void setNumAnimals(float numanimals)
	{
		this->m_numOfAnimals = numanimals;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:

	Zoo& operator+(Animal* an)
	{
		// Create a new array to hold the updated animals
		Animal** updatedAnimals = new Animal * [m_numOfAnimals + 1];

		// Copy existing animal pointers to the updated array
		for (int i = 0; i < m_numOfAnimals; ++i) {
			updatedAnimals[i] = m_animals[i];
		}

		// Add the new animal pointer at the end of the updated array
		updatedAnimals[m_numOfAnimals] = an;

		// Increment the number of animals
		m_numOfAnimals++;

		// Deallocate the old m_animals array
		delete[] m_animals;

		// Assign the updated array to m_animals
		m_animals = updatedAnimals;

		// Return a reference to this Zoo object
		return *this;
	}

	Zoo operator+(const Zoo& other) const
	{
		// Create a new Zoo object to hold the merged properties
		Zoo mergedZoo(*this);  // Copy the properties of 'this' Zoo

		// Add animals from 'other' Zoo to the mergedZoo
		Animal** otherAnimals = other.GetAnimals();
		int numOtherAnimals = other.GetNumOfAnimals();

		for (int i = 0; i < numOtherAnimals; ++i) {
			mergedZoo.AddAnimal(otherAnimals[i]->clone());  // Deep copy each animal
		}

		// Return the mergedZoo
		return mergedZoo;
	}
	
	Zoo& operator+=(Animal* animal) {
		AddAnimal(animal);
		return *this;
	}



public:
	friend ofstream& operator<<(ofstream& out, const Zoo& z) {
		out << z.m_name << '\n';
		out << z.m_address << '\n';
		out << z.m_ticketPrice << '\n';
		out << z.m_openHours << '\n';
		out << z.m_closeHours << '\n';
		out << z.m_numOfAnimals << '\n';
		out << "END" << '\n';  // Add the "END" marker

		// Write each Animal
		for (int i = 0; i < z.m_numOfAnimals; ++i) {
			z.m_animals[i]->save(out);
		}

		return out;
	};

	//operator to write the zoo to a text file
//operator to read the zoo from a text file
	friend ifstream& operator >> (ifstream& in, Zoo& z)
	{
		// Read the basic Zoo properties
		char temp[100];  // Adjust the size as needed

		in.getline(temp, 99);
		z.m_name = new char[strlen(temp) + 1];
		strcpy(z.m_name, temp);

		in.getline(temp, 99);
		z.m_address = new char[strlen(temp) + 1];
		strcpy(z.m_address, temp);

		in >> z.m_ticketPrice;

		//CHECK TO COMMENT
		in.ignore();  // Ignore the newline character

		in.getline(temp, 99);
		z.m_openHours = new char[strlen(temp) + 1];
		strcpy(z.m_openHours, temp);

		in.getline(temp, 99);
		z.m_closeHours = new char[strlen(temp) + 1];
		strcpy(z.m_closeHours, temp);

		in >> z.m_numOfAnimals;
		//CHECK TO COMMENT

		in.ignore();  // Ignore the newline character



		// Read each Animal
		z.m_animals = new Animal * [z.m_numOfAnimals];


		// Ignore the first "END" which is from Zoo
		char line[100];  // Adjust the size as needed
		while (in.getline(line, 99) && strcmp(line, "END") != 0) {
			// Ignore all lines until we find the "END" marker
		}


		for (int i = 0; i < z.m_numOfAnimals; ++i) {
			// Read until we find the "END" marker
			char line[100];  // Adjust the size as needed
		
			// The next line should be the type of the next animal
			string type;
			in >> type;

			// Create an instance of the correct type
			if (type == "Horse") {
				z.m_animals[i] = new Horse(in);
			}
			else if (type == "Birds") {
				z.m_animals[i] = new Birds(in);
			}
			else if (type == "Mammals") {
				z.m_animals[i] = new Mammals(in);
			}
			else if (type == "MammalsFish") {
				z.m_animals[i] = new MammalsFish(in);
			}
			else if (type == "Mermaid") {
				z.m_animals[i] = new Mermaid(in);
			}
			else if (type == "Fish") {
				z.m_animals[i] = new Fish(in);
			}
			else if (type == "Flamingo") {
				z.m_animals[i] = new Flamingo(in);
			}
			else if (type == "GoldFish") {
				z.m_animals[i] = new GoldFish(in);
			}
			while (in.getline(line, 99) && strcmp(line, "END") != 0) {
				// Ignore all lines until we find the "END" marker
			}
		}

		return in;
	}

public:
	void Save(ofstream& ofs) const {
		ofs << *this;
	};
	
	//method to save the info to a text file
	void Load(ifstream& ifs)
	{
		ifs >> *this;
	};
	//method to load the info from a text file
	void SaveBin(ofstream& ofs) const
	{
		ofs.write(reinterpret_cast<const char*>(&m_name), sizeof(m_name));
		ofs.write(reinterpret_cast<const char*>(&m_address), sizeof(m_address));
		ofs.write(reinterpret_cast<const char*>(&m_ticketPrice), sizeof(m_ticketPrice));
		ofs.write(reinterpret_cast<const char*>(&m_openHours), sizeof(m_openHours));
		ofs.write(reinterpret_cast<const char*>(&m_closeHours), sizeof(m_closeHours));
		ofs.write(reinterpret_cast<const char*>(&m_numOfAnimals), sizeof(m_numOfAnimals));

		// Write each Animal
		for (int i = 0; i < m_numOfAnimals; ++i) {
			m_animals[i]->save(ofs);
		}
	};//method to save the info to a binary file

private:
	char*		m_name;
	char*		m_address;
	float		m_ticketPrice;
	char*		m_openHours;
	char*		m_closeHours;
	int			m_numOfAnimals;
	Animal**	m_animals;
};


#endif // ifndef