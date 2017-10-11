#include <iostream>

using namespace std;

/**
* integer matrix
*/
class MatrixInt
{
public:
	MatrixInt(int x = default_x, int y = default_y);
	~MatrixInt();
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	int get_element(int x, int y) const;
	void set_element(int x, int y, int elem);
	// constant elements
	static const int default_x = 3;
	static const int default_y = 3;
protected:
	int** cells;
	int x_size;
	int y_size;
};

MatrixInt::MatrixInt(int x, int y) :
	x_size(x), y_size(y) {
	cells = new int*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new int[y_size];
	}
}

MatrixInt::~MatrixInt() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

int MatrixInt::get_element(int x, int y) const {
	return (cells[x][y]);
}

void MatrixInt::set_element(int x, int y, int elem) {
	cells[x][y] = elem;
}

// end integer matrix definition


int main() {
	MatrixInt m(3, 4);
	m.set_element(2, 2, 8);
	cout << "element at 2,2 is " << m.get_element(2, 2) << "\n";


	return 0;
}