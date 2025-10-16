#include "Square.h"
#include "Point.h"

Point::Point(int px, int py)
{
	x = px;
	y = py;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int px)
{
	x = px;
}

void Point::setY(int py)
{
	y = py;
}
Square::Square(const string name, int px, int py, unsigned int side) : Point(px, py)
{
	setName(name);
	setSide(side);
	setArea(side);
}

unsigned int Square::getSide() const
{
	return side;
}

unsigned int Square::getArea() const
{
	return side * side;
}

string Square::getName() const
{
	return name;
}

void Square::setSide(unsigned int side)
{
	this->side = side;
}

void Square::setArea(unsigned int side)
{
	this->area = pow(side, 2);
}

void Square::setName(string n)
{
	name = n;
}

int main() {
	int n;
	cin >> n;
	string name;
	int x, y;
	unsigned int side;
	vector<Square> v;
	for (int i = 0; i < n; i++) {
		cin >> name >> x >> y >> side;
		v.push_back(Square(name, x, y, side));
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (v[j].getArea() > v[j + 1].getArea()) {
				Square temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	cout << "\nSquares in increasing order of area\n";
	for (int i = 0; i < n; i++) {
		cout << v[i].getName() << "(" << v[i].getX() << ", " << v[i].getY() 
			<< ") side=" << v[i].getSide() << ", area=" << v[i].getArea() << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			int jMax1 = v[j].getX() + v[j].getSide();
			int jMax2 = v[j + 1].getX() + v[j + 1].getSide();
			if (jMax1 > jMax2) {
				Square temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	cout << "\nSquares in increasing order of max x-coordinate" << endl;
	for (int i = 0; i < n; i++) {
		int maxX = v[i].getX() + v[i].getSide();
		cout << v[i].getName() << "(" << maxX << ", " << v[i].getY()
			<< ") side=" << v[i].getSide()
			<< ", area=" << v[i].getArea() << endl;
	}
	cout << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			int jMaxY = v[j].getY() + v[j].getSide();
			int j1MaxY = v[j + 1].getY() + v[j + 1].getSide();
			if (jMaxY > j1MaxY) {
				Square temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}

	cout << "Squares in increasing order of max y-coordinate" << endl;
	for (int i = 0; i < n; i++) {
		int maxY = v[i].getY() + v[i].getSide();
		cout << v[i].getName() << "(" << v[i].getX() << ", " << maxY
			<< ") side=" << v[i].getSide()
			<< ", area=" << v[i].getArea() << endl;
	}

	return 0;
}