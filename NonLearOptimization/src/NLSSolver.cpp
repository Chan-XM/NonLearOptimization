#include "NLSSolver.hpp"

namespace nlssolver
{
	using namespace Eigen;
	using namespace std;


	bool NLSSolver::solveByGN()
	{
		cout << "Guss-Newton Solver processing..." << endl;
		int iter = 0;

		// 误差
		double current_squared_error;

		// 迭代步长的模
		double delta_norm;

		while (iter++ < maximumIterations_)
		{
			computeJacobianAndError();
			current_squared_error = error_.squaredNorm();

			if (vebose_)
			{
				cout << "--Current squared error:" << current_squared_error << endl;
			}

			computeHessianAndg();
			solveLinearSystem();

			delta_norm = delta_x_.norm();
			if (delta_norm < epsilon_)
			{
				break;
			}

			updateStates();
		}

		return false;
	}

	bool NLSSolver::solveByLM()
	{
		return false;
	}

	bool NLSSolver::solveByDogLeg()
	{
		return false;
	}

}