#ifndef CAR_H
#define CAR_H

using namespace std;

class Car {
public:
	Car(const std::string& brand, const std::string& model, int year)
		: _brand(brand), _model(model), _year(year) {
	}

	std::string GetBrand() const {
		return _brand;
	}

	std::string GetModel() const {
		return _model;
	}

	int GetYear() const {
		return _year;
	}

private:
	std::string _brand;
	std::string _model;
	int _year;
};

#endif // !CAR_H