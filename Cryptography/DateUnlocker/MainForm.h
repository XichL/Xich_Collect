#pragma once
#include "../Cryptography/AES.h"

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

#define String2string(a) (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(a)).ToPointer();

using namespace std;

namespace DateUnlocker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace AES_PROGRESS;


	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);
	private: System::Windows::Forms::Button^  Button_UnlockDatelock;
	public:




	public:
		AES^ aes;

	public:
	private:
		String^ key;
		String^ Password;
		String^ path = "Cyphertext.xml";

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox_Cyphertext;
	private: System::Windows::Forms::TextBox^  textBox_password;
	protected:

	protected:

	private: System::Windows::Forms::Button^  Button_GetCyphertext;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox_Cyphertext = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->Button_GetCyphertext = (gcnew System::Windows::Forms::Button());
			this->Button_UnlockDatelock = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_Cyphertext
			// 
			this->textBox_Cyphertext->Location = System::Drawing::Point(12, 12);
			this->textBox_Cyphertext->Multiline = true;
			this->textBox_Cyphertext->Name = L"textBox_Cyphertext";
			this->textBox_Cyphertext->Size = System::Drawing::Size(249, 139);
			this->textBox_Cyphertext->TabIndex = 0;
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(12, 174);
			this->textBox_password->Multiline = true;
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(249, 139);
			this->textBox_password->TabIndex = 1;
			// 
			// Button_GetCyphertext
			// 
			this->Button_GetCyphertext->Location = System::Drawing::Point(267, 12);
			this->Button_GetCyphertext->Name = L"Button_GetCyphertext";
			this->Button_GetCyphertext->Size = System::Drawing::Size(93, 23);
			this->Button_GetCyphertext->TabIndex = 2;
			this->Button_GetCyphertext->Text = L"Get Cyphertext";
			this->Button_GetCyphertext->UseVisualStyleBackColor = true;
			this->Button_GetCyphertext->Click += gcnew System::EventHandler(this, &MainForm::Button_GetCyphertext_Click);
			// 
			// Button_UnlockDatelock
			// 
			this->Button_UnlockDatelock->Location = System::Drawing::Point(267, 174);
			this->Button_UnlockDatelock->Name = L"Button_UnlockDatelock";
			this->Button_UnlockDatelock->Size = System::Drawing::Size(93, 23);
			this->Button_UnlockDatelock->TabIndex = 3;
			this->Button_UnlockDatelock->Text = L"Unlock Datelock";
			this->Button_UnlockDatelock->UseVisualStyleBackColor = true;
			this->Button_UnlockDatelock->Click += gcnew System::EventHandler(this, &MainForm::Button_UnlockDatelock_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 389);
			this->Controls->Add(this->Button_UnlockDatelock);
			this->Controls->Add(this->Button_GetCyphertext);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->textBox_Cyphertext);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	/**
	*  将一个char字符数组转化为二进制
	*  存到一个 byte 数组中
	*/
	private: void charToByte(byte out[16], const char s[16])
	{
		for (int i = 0; i < 16; ++i)
			for (int j = 0; j < 8; ++j)
				out[i][j] = ((s[i] >> j) & 1);
	}

	/**
	 *  将连续的128位分成16组，存到一个 byte 数组中
	 */
	private: void divideToByte(byte out[16], bitset<128>& data)
	{
		bitset<128> temp;
		for (int i = 0; i < 16; ++i)
		{
			temp = (data << 8 * i) >> 120;
			out[i] = temp.to_ulong();
		}
	}

	/**
	 *  将16个 byte 合并成连续的128位
	 */
	private: bitset<128> mergeByte(byte in[16])
	{
		bitset<128> res;
		res.reset();  // 置0
		bitset<128> temp;
		for (int i = 0; i < 16; ++i)
		{
			temp = in[i].to_ulong();
			temp <<= 8 * (15 - i);
			res |= temp;
		}
		return res;
	}

	///Random Number
	private: string createNum()
	{
		Random^ random = gcnew Random();
		int num = random->Next(10);
		char n = System::Convert::ToChar(num);
		string number(&n);
		return number;
	}

	///Random Captial Letter
	private: string createBigAbc()
	{
		//A-Z的 ASCII值為65-90

		Random^ random = gcnew Random();
		int num = random->Next(65, 91);
		char a = System::Convert::ToChar(num);
		string abc(&a);
		return abc;
	}

	///Random Small Letter
	private: string createSmallAbc()
	{
		//a-z的 ASCII值為97-122
		Random^ random = gcnew Random();
		int num = random->Next(97, 123);
		char a = System::Convert::ToChar(num);
		string abc(&a);
		return abc;
	}

	private: System::Void SetPassword(string pw)
	{
		this->Password = gcnew String(pw.c_str());
	}

	private: string CreatePassword()
	{
		string tmpPW;
		for (int i = 0; i < 16; i++)
		{
			Random^ random = gcnew Random();
			switch (random->Next(2))
			{
				//case 1:
				//	tmpPW += createBigAbc();
				//	break;
			case 0:
				tmpPW += createBigAbc();
				break;
			case 1:
				tmpPW += createSmallAbc();
			}
			_sleep(100);
		}
		SetPassword(tmpPW);
		return tmpPW;
	}

	private: System::Void CreateKey()
	{
		unsigned char wordKey[16];
		wordKey[0] = 'D';	wordKey[1] = 'A';	wordKey[2] = 'K'; wordKey[3] = 'U';
		wordKey[4] = 'M';	wordKey[5] = 'G';	wordKey[6] = 'H'; wordKey[7] = 'B';
		wordKey[8] = 'A';	wordKey[9] = 'M';	wordKey[10] = 'E'; wordKey[11] = 'E';
		wordKey[12] = 'L';	wordKey[13] = 'O';	wordKey[14] = 'L'; wordKey[15] = 'I';

		string s;
		for (int i = 0; i < 16; i++)
		{
			s.push_back(wordKey[i]);
		}
		this->key = gcnew String(s.c_str());
	}

	private: bool PasswordCheck(String^ in)
	{
		if (in == this->Password)
		{
			return true;
		}
		return false;
	}

	private: System::Void GetExpansionKey(word w[4 * (Nr + 1)])
	{
		///密鑰擴展，針對每包解鎖器有固定密鑰
		string keyStr = String2string(this->key);
		byte key[16];
		charToByte(key, keyStr.c_str());
		// 密钥扩展
		word w_t[4 * (Nr + 1)];
		aes->KeyExpansion(key, w_t);
		_sleep(100);//需要Sleep時間否則會算出錯誤的擴展密鑰
		memcpy(w, w_t, sizeof(w_t));
	}

	private: String^ GetNewPlainData()
	{
		//取得新PW並初始化加密用數值
		string tmpPW = this->CreatePassword();
		word w[4 * (Nr + 1)];
		GetExpansionKey(w);//取得擴展密鑰

		//將PW加密
		byte plain[16];
		const char* sd = tmpPW.c_str();
		charToByte(plain, sd);
		aes->encrypt(plain, w);
		bitset<128> data = mergeByte(plain);

		//將密文儲存到.xml中
		String^ PW = gcnew String(data.to_string().c_str());
		return PW;
	}

	private: System::Void Button_GetCyphertext_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!System::IO::File::Exists(this->path))
		{
			MessageBox::Show(this,
				"Cyphertext.txt is not exists.",
				"Warning",
				MessageBoxButtons::OK);
			this->~MainForm();
		}
		else
		{
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(this->path);
			this->textBox_Cyphertext->Text = sr->ReadLine();
			sr->Close();
		}
	}

	private: System::Void Button_UnlockDatelock_Click(System::Object^  sender, System::EventArgs^  e)
	{

		String^ InPW = this->textBox_password->Text;

		if (this->PasswordCheck(InPW))
		{
			MessageBox::Show(this,
				"Password correct",
				"Warning",
				MessageBoxButtons::OK);
			//---
			//String^ KeyName = "HKEY_CURRENT_USER\\SOFTWARE\\Basler\\Pylon .NET Preview";
			//String^ ValueName = "SamplesID";
			//Microsoft::Win32::Registry::SetValue(KeyName, ValueName, 1, Microsoft::Win32::RegistryValueKind::DWord);
			//---
		}
		else
		{
			MessageBox::Show(this,
				"Password incorrect",
				"Warning",
				MessageBoxButtons::OK);
		}

		//Create new password and Save
		System::IO::FileStream^ fs;
		System::Text::ASCIIEncoding^ asciiEncoding = gcnew System::Text::ASCIIEncoding;
		fs = gcnew System::IO::FileStream(this->path, System::IO::FileMode::Create);

		String^ writePW = GetNewPlainData();

		fs->Write(asciiEncoding->GetBytes(writePW), 0, asciiEncoding->GetBytes(writePW)->Length);
		fs->Close();
	}


	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//////////////////////////////////////////////
		//若無儲存密文的檔案，開啟程式時建立新的密文//
		//////////////////////////////////////////////
		System::IO::FileStream^ fs;
		System::Text::ASCIIEncoding^ asciiEncoding = gcnew System::Text::ASCIIEncoding;
		if (!System::IO::File::Exists(this->path))
		{
			fs = System::IO::File::Create(path);

			String^ writePW = GetNewPlainData();
			fs->Write(asciiEncoding->GetBytes(writePW), 0, asciiEncoding->GetBytes(writePW)->Length);
			fs->Close();
		}
		else
		{
			fs = gcnew System::IO::FileStream(this->path, System::IO::FileMode::Create);

			String^ writePW = GetNewPlainData();
			fs->Write(asciiEncoding->GetBytes(writePW), 0, asciiEncoding->GetBytes(writePW)->Length);
			fs->Close();
		}
	}
	};
}