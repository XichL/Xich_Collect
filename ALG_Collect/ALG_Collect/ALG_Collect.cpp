#include "stdafx.h"
#include "ALG_Collect.h"

ALG_Collect::ALG::ALG()
{
	this->algMath = gcnew Algorithm::Algorithm_Math();
	this->bHaveCubicCoeffs = false;
}

ALG_Collect::ALG::~ALG() { ; }

bool ALG_Collect::ALG::SPLineCalculate(array<double>^ src_x, array<double>^ src_y, array<double>^ input_x, array<double>^% output_x, array<double>^% output_y)
{
	bool bRes = false;
	//-------------------------------------------------
	Algorithm::CubicEquationSolution ^cubicCoeffs;

	//找出SPLine三次方程式解
	bRes = CalculateSplineSolution(src_x, src_y, cubicCoeffs, Algorithm::SplineFilterMode::CUBIC_WITHOUT_FILTER);
	if (bRes)
	{
		this->ALG_cubicCoeffs = cubicCoeffs;
		this->bHaveCubicCoeffs = true;
	}

	//透過SPLine解算出各需求點對應Y點
	getCubicSplineITPL(cubicCoeffs, input_x, output_x, output_y);

	//-------------------------------------------------
	return bRes;
}

bool ALG_Collect::ALG::SPLineCalculate_ACC_cubic(array<double>^ src_x, array<double>^ src_y)
{
	bool bRes = false;
	//-------------------------------------------------
	//找出SPLine三次方程式解
	bRes = CalculateSplineSolution(src_x, src_y, ALG_cubicCoeffs, Algorithm::SplineFilterMode::CUBIC_WITHOUT_FILTER);
	if (bRes) { this->bHaveCubicCoeffs = true; }

	//-------------------------------------------------
	return bRes;
}

void ALG_Collect::ALG::SPLineCalculate_ACC(array<double>^ input_x, array<double>^% output_x, array<double>^% output_y)
{
	if (!this->bHaveCubicCoeffs)return;

	//透過SPLine解算出各需求點對應Y點
	getCubicSplineITPL(ALG_cubicCoeffs, input_x, output_x, output_y);
}

bool ALG_Collect::ALG::CalculateSplineSolution(array<double>^ input_x, array<double>^ input_y, Algorithm::CubicEquationSolution ^% cubicCoeffs, Algorithm::SplineFilterMode filterMode)
{
	bool bRes = false;
	//-------------------------------------------------

	//array to vector
	std::vector<double> input_x_v;
	std::vector<double> input_y_v;
	this->SPLineXData = gcnew array<double>(input_x->Length);

	int idx = 0;
	for each(double v in input_x)
	{
		input_x_v.push_back(v);
		this->SPLineXData[idx] = v;
		idx++;
	}
	for each(double v in input_y) { input_y_v.push_back(v); }

	algMath->setSPLineXData(this->SPLineXData);
	bRes = algMath->calCubicSplineSolution(input_x_v, input_y_v, cubicCoeffs, (Algorithm::_SplineFilterMode)filterMode);

	//-------------------------------------------------
	return bRes;
}

void ALG_Collect::ALG::getCubicSplineITPL(Algorithm::CubicEquationSolution ^% cubicCoeffs, array<double>^ input_x, array<double>^% output_x, array<double>^% output_y)
{
	//array to vector
	std::vector<double> input_x_v;
	std::vector<double> output_x_v;
	std::vector<double> output_y_v;

	for each(double v in input_x) { input_x_v.push_back(v); }

	algMath->cubicSplineITPL(cubicCoeffs, input_x_v, output_x_v, output_y_v);

	output_x = gcnew array<double>((int)output_x_v.size());
	for (int i = 0; i < (int)output_x_v.size(); i++)
	{
		output_x[i] = (int)output_x_v[i];
	}

	output_y = gcnew array<double>((int)output_y_v.size());
	for (int i = 0; i < output_y_v.size(); i++)
	{
		output_y[i] = output_y_v[i];
	}
}

void ALG_Collect::ALG::getCubicSplineITPL2(Algorithm::CubicEquationSolution ^% cubicCoeffs, array<double>^% input_x, double & x, double & y)
{
	//array to vector
	std::vector<double> input_x_v;

	for each(double v in input_x) { input_x_v.push_back(v); }

	algMath->cubicSplineITPL2(cubicCoeffs, input_x_v, x, y);
}

