#pragma once

namespace Algorithm
{
#pragma region SPLine
	public ref class CubicEquationSolution
	{
	public:
		CubicEquationSolution(const int &count)
		{
			a = gcnew array<double>(count);
			b = gcnew array<double>(count);
			c = gcnew array<double>(count);
			d = gcnew array<double>(count);
		}

	public:

		array<double>^ a;
		array<double>^ b;
		array<double>^ c;
		array<double>^ d;
	};

	enum _CubicSplineMode
	{
		CUBIC_NATURAL,    // Natural
		CUBIC_CLAMPED,    // TODO: Clamped 
		CUBIC_NOT_A_KNOT  // TODO: Not a knot 
	};

	enum _SplineFilterMode
	{
		CUBIC_WITHOUT_FILTER, // without filter
		CUBIC_MEDIAN_FILTER  // median filter
	};

	public enum class SplineFilterMode
	{
		CUBIC_WITHOUT_FILTER, // without filter
		CUBIC_MEDIAN_FILTER  // median filter
	};
#pragma endregion

	private ref class Algorithm_Math
	{
#pragma region SPLineFuncPrivate
	internal:
		void setSPLineXData(array<double>^ SPLineXData);
		bool calCubicSplineSolution(std::vector<double> &input_x,
			std::vector<double> &input_y, CubicEquationSolution ^%cubicCoeffs,
			_SplineFilterMode filterMode);
		void cubicSplineITPL(CubicEquationSolution ^%cubicCoeffs,
			std::vector<double> &input_x, std::vector<double> &output_x,
			std::vector<double> &output_y);
		void cubicSplineITPL2(CubicEquationSolution ^%cubicCoeffs,
			std::vector<double> &input_x, double &x, double &y);

	private:
		array<double>^ SPLineXData;
		bool calTridiagonalMatric(cv::Mat_<double> &input_a,
			cv::Mat_<double> &input_b, cv::Mat_<double> &input_c,
			cv::Mat_<double> &input_d, cv::Mat_<double> &output_x);
		/* Calculate the curve index interpolation belongs to */
		int getITPLIndex(double &pt, std::vector<double> &input_x);
		/* median filtering */
		void cubicMedianFilter(std::vector<double> &input, const int filterSize/* = 5*/);
		double cubicSort(std::vector<double> &input);
#pragma endregion
	};
}