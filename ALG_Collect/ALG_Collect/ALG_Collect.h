#pragma once

#ifdef NST_CameraImageTest_EXPORTS
#define NST_CameraImageTest_API __declspec(dllexport)
#else
#define NST_CameraImageTest_API __declspec(dllimport)
#endif

#include "Algorithm.h"

namespace ALG_Collect
{
	using namespace System;
	using namespace Algorithm;
	using namespace Threading;

	public ref class ALG
	{
	private:
		Algorithm::Algorithm_Math^ algMath = gcnew Algorithm::Algorithm_Math();
		array<double>^ SPLineXData;

	public:
#pragma region SPLine
		bool SPLineCalculate(array<double>^ src_x, array<double>^ src_y,
			array<double>^ input_x,
			array<double>^%output_x, array<double>^%output_y);

	private:
		bool CalculateSplineSolution(array<double>^ input_x,
			array<double>^ input_y, Algorithm::CubicEquationSolution ^%cubicCoeffs,
			Algorithm::SplineFilterMode filterMode);

		void getCubicSplineITPL(Algorithm::CubicEquationSolution ^%cubicCoeffs,
			array<double>^ input_x, array<double>^%output_x,
			array<double>^%output_y);

		void getCubicSplineITPL2(Algorithm::CubicEquationSolution ^%cubicCoeffs,
			array<double>^%input_x, double &x, double &y);
#pragma endregion
	};
}