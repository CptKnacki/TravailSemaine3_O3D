
#include <iostream>
using namespace std;

#pragma region Class

class Vehicule
{
	private:
		string nameVehicule;
	public:
		Vehicule(){ nameVehicule = ""; }
		Vehicule(string _vehiculeName) { nameVehicule = _vehiculeName; }

		string GetName() { return nameVehicule; }
		void SetName(string _name) { nameVehicule = _name; }
};

class Voiture : public Vehicule
{
	private:
		int numberOfWheels;
		int horsePower;
	public:
		Voiture() 
		{
			SetName("average car");
			numberOfWheels = 4;
			horsePower = 115;
		}
		Voiture(string _carName, int _horsePower) 
		{
			SetName(_carName);
			numberOfWheels = 4;
			horsePower = _horsePower;
		}

		int GetNumberWheels() { return numberOfWheels; }
		int GetHorsePower() { return horsePower; }
};

class Avion : public Vehicule
{
	private:
		int numberOfWings;
		bool haveReactor;
	public:
		Avion()
		{
			SetName("average plane");
			numberOfWings = 2;
			haveReactor = false;
		}
		Avion(bool _haveReactor, string _planeName) 
		{
			SetName(_planeName);
			numberOfWings = 2;
			haveReactor = _haveReactor;
		}

		bool GetHaveReactor() { return haveReactor; }
		int GetNumberOfWings() { return numberOfWings; }
};

#pragma endregion

int main()
{
	// Déclaration //
	Voiture voiture1("Toyota Supra mk4", 320);
	Voiture voiture2("Lotus Elise S", 220);

	Avion avion1(true, "Boeing747");
	Avion avion2(false, "MesserSchmittBF109");

	// Affichage //

	string phrase1 = (avion1.GetHaveReactor()) ? "" : " no";
	cout << "The " << avion1.GetName() << " has " << avion1.GetNumberOfWings() << " wings and" << phrase1 << " reactors." << endl << endl;

	string phrase2 = (avion2.GetHaveReactor()) ? "have" : "have no";
	cout << "The " << avion2.GetName() << " has " << avion2.GetNumberOfWings() << " wings and" << phrase2 << " reactors." << endl << endl;

	cout << "The " << voiture1.GetName() << " has " << voiture1.GetNumberWheels() << " wheels" << " and " << voiture1.GetHorsePower() << "hp" << endl << endl;
	cout << "The " << voiture2.GetName() << " has " << voiture2.GetNumberWheels() << " wheels" << " and " << voiture2.GetHorsePower() << "hp" << endl << endl;

}
