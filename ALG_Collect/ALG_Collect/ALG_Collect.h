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
		ALG();
		~ALG();

		Algorithm::Algorithm_Math^ algMath;
		array<double>^ SPLineXData;
		Algorithm::CubicEquationSolution^ ALG_cubicCoeffs;
		bool bHaveCubicCoeffs;

	public:
#pragma region SPLine
		bool SPLineCalculate(array<double>^ src_x, array<double>^ src_y,
			array<double>^ input_x,
			array<double>^%output_x, array<double>^%output_y);

		bool SPLineCalculate_ACC_cubic(array<double>^ src_x, array<double>^ src_y);

		void SPLineCalculate_ACC(array<double>^ input_x,
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