#include <iostream>
#include "Dense"
#include <vector>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

MatrixXd CalculateJacobian(const VectorXd& x_state);

int main() {

	/*
	 * Compute the Jacobian Matrix
	 */

	//predicted state  example
	//px = 1, py = 2, vx = 0.2, vy = 0.4
	VectorXd x_predicted(4);
	x_predicted << 1, 2, 0.2, 0.4;

	MatrixXd Hj = CalculateJacobian(x_predicted);

	cout << "Hj:" << endl << Hj << endl;

	return 0;
}

MatrixXd CalculateJacobian(const VectorXd& x_state) {

	MatrixXd Hj(3,4);
	//recover state parameters
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);

	//TODO: YOUR CODE HERE 

	//check division by zero
	if ( px == 0 && py == 0 ) {                  // If the age is less than 100
        cout << "CalculateJacobian () - Error - Division by Zero" << endl;
        return Hj;
    }
	
	//compute the Jacobian matrix
    Hj(0, 0) = px / sqrt( px*px + py*py );
    Hj(0, 1) = py / sqrt( px*px + py*py );
    Hj(1, 0) = -py / ( px*px + py*py );
    Hj(1, 1) = px / ( px*px + py*py );
    Hj(2, 0) = py * ( vx*py - vy*px ) / pow( px*px + py*py , 3/2 );
    Hj(2, 1) = px * ( vy*px - vx*py ) / pow( px*px + py*py , 3/2 );
    Hj(2, 2) = px / sqrt( px*px + py*py );
    Hj(2, 3) = py / sqrt( px*px + py*py );

	return Hj;
}