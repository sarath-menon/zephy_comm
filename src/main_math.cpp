#include <zephyr.h>
#include <sys/printk.h>
#include <math.h>
#include <stdio.h>
#include <matrix/math.hpp>

// #include <iostream>

using namespace matrix;

int main()
{
	float roll = 0.1f;
	float pitch = 0.2f;
	float yaw = 0.3f;
	Eulerf euler(roll, pitch, yaw);

	// convert to quaternion from euler
	Quatf q_nb(euler);

	// convert to DCM from quaternion
	Dcmf dcm(q_nb);

	// you can assign a rotation instance that already exist to another rotation instance, e.g.
	dcm = euler;

	// you can also directly create a DCM instance from euler angles like this
	dcm = Eulerf(roll, pitch, yaw);

	// do some kalman filtering
	const size_t n_x = 5;
	const size_t n_y = 3;

	// define matrix sizes
	SquareMatrix<float, n_x> P;
	Vector<float, n_x> x;
	Vector<float, n_y> y;
	Matrix<float, n_y, n_x> C;
	SquareMatrix<float, n_y> R;
	SquareMatrix<float, n_y> S;
	Matrix<float, n_x, n_y> K;

	x.setZero();

	return 0;
}