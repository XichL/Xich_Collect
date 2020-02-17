#pragma once
#include "MainForm.h"

using namespace System;
using namespace System::IO;
using namespace DateUnlocker;

[STAThread]
void main()
{
	//Diagnostics::Process^ myProcess = gcnew Diagnostics::Process;

	try
	{
		Application::Run(gcnew MainForm());
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->ToString());
	}
}

DateUnlocker::MainForm::MainForm(void)
{
	InitializeComponent();
	//
	this->aes = gcnew AES();
	//
}
