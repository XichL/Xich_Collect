#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace ALG_Tools;

[STAThreadAttribute]
int main()
{
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// 建立主視窗並執行
	Application::Run(gcnew MyForm());
	return 0;
}

MyForm::MyForm()
{
	InitializeComponent();
	//
	//TODO:  在此加入建構函式程式碼
	LoadFilePath = IO::Path::GetDirectoryName(Application::ExecutablePath) + "\\Log.txt";
	readDelayTime = 2000;
	threadRun = false;
	//
}

MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}
