#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace ALG_Tools;

[STAThreadAttribute]
int main()
{
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �إߥD�����ð���
	Application::Run(gcnew MyForm());
	return 0;
}

MyForm::MyForm()
{
	InitializeComponent();
	//
	//TODO:  �b���[�J�غc�禡�{���X
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
