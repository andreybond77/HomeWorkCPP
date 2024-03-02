#pragma once
class HouseBuilder;


class Builder {
public:
	void virtual setType_of_building(string type_of_building) = 0;
	void virtual setGarden(string garden) = 0;
	void virtual setSwimming_pool(string swimming_pool) = 0;
	void virtual setGarage(string garage) = 0;
	void virtual setBarbecue(string barbecue) = 0;
};

class House {
private:
	friend class HouseBuilder;
	string type_of_building = "";
	string garden = "";
	string swimming_pool = "";
	string garage = "";
	string barbecue = "";
public:
	void show() {
		cout<< type_of_building<< " : "
			<< garden << " : "
			<< swimming_pool << " : "
			<< garage << " : "
			<<barbecue << endl;
	}
};

class HouseBuilder : public Builder {
	House house;
public:
	void setType_of_building(string type_of_building) {
		house.type_of_building = type_of_building;
	}
	void setGarden(string garden) {
		house.garden = garden;
	}
	void setSwimming_pool(string swimming_pool) {
	house.swimming_pool = swimming_pool;
	}
	void setGarage(string garage) {
		house.garage = garage;
	}
	void setBarbecue(string barbecue) {
		house.barbecue = barbecue;
	}
	House getResult() {
		return house;
	}
};
