#pragma once
#include "AES.h"

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

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
	private: System::Windows::Forms::Button^  Button_decrypt;
	private: System::Windows::Forms::TextBox^  textBox_Key;
	private: System::Windows::Forms::Button^  button_KeySet;
	private: System::Windows::Forms::Label^  label_KeyStatus;
	public:
		AES^ aes;
	private: System::Windows::Forms::Label^  label_description;
	public:
	private:
		String^ key;

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  Button_encrypt;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->Button_encrypt = (gcnew System::Windows::Forms::Button());
			this->Button_decrypt = (gcnew System::Windows::Forms::Button());
			this->textBox_Key = (gcnew System::Windows::Forms::TextBox());
			this->button_KeySet = (gcnew System::Windows::Forms::Button());
			this->label_KeyStatus = (gcnew System::Windows::Forms::Label());
			this->label_description = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 62);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 139);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"asdfqwerzxcvtgbn";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 225);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(249, 139);
			this->textBox2->TabIndex = 1;
			// 
			// Button_encrypt
			// 
			this->Button_encrypt->Location = System::Drawing::Point(285, 62);
			this->Button_encrypt->Name = L"Button_encrypt";
			this->Button_encrypt->Size = System::Drawing::Size(75, 23);
			this->Button_encrypt->TabIndex = 2;
			this->Button_encrypt->Text = L"Encrypt";
			this->Button_encrypt->UseVisualStyleBackColor = true;
			this->Button_encrypt->Click += gcnew System::EventHandler(this, &MainForm::Button_encrypt_Click);
			// 
			// Button_decrypt
			// 
			this->Button_decrypt->Location = System::Drawing::Point(285, 91);
			this->Button_decrypt->Name = L"Button_decrypt";
			this->Button_decrypt->Size = System::Drawing::Size(75, 23);
			this->Button_decrypt->TabIndex = 3;
			this->Button_decrypt->Text = L"Decrypt";
			this->Button_decrypt->UseVisualStyleBackColor = true;
			this->Button_decrypt->Click += gcnew System::EventHandler(this, &MainForm::Button_decrypt_Click);
			// 
			// textBox_Key
			// 
			this->textBox_Key->Location = System::Drawing::Point(12, 12);
			this->textBox_Key->Name = L"textBox_Key";
			this->textBox_Key->Size = System::Drawing::Size(249, 22);
			this->textBox_Key->TabIndex = 4;
			// 
			// button_KeySet
			// 
			this->button_KeySet->Location = System::Drawing::Point(285, 12);
			this->button_KeySet->Name = L"button_KeySet";
			this->button_KeySet->Size = System::Drawing::Size(75, 23);
			this->button_KeySet->TabIndex = 5;
			this->button_KeySet->Text = L"Key Set";
			this->button_KeySet->UseVisualStyleBackColor = true;
			this->button_KeySet->Click += gcnew System::EventHandler(this, &MainForm::button_KeySet_Click);
			// 
			// label_KeyStatus
			// 
			this->label_KeyStatus->AutoSize = true;
			this->label_KeyStatus->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label_KeyStatus->Location = System::Drawing::Point(314, 38);
			this->label_KeyStatus->Name = L"label_KeyStatus";
			this->label_KeyStatus->Size = System::Drawing::Size(41, 12);
			this->label_KeyStatus->TabIndex = 6;
			this->label_KeyStatus->Text = L"No Key";
			// 
			// label_description
			// 
			this->label_description->AutoSize = true;
			this->label_description->Location = System::Drawing::Point(12, 38);
			this->label_description->Name = L"label_description";
			this->label_description->Size = System::Drawing::Size(0, 12);
			this->label_description->TabIndex = 7;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 389);
			this->Controls->Add(this->label_description);
			this->Controls->Add(this->label_KeyStatus);
			this->Controls->Add(this->button_KeySet);
			this->Controls->Add(this->textBox_Key);
			this->Controls->Add(this->Button_decrypt);
			this->Controls->Add(this->Button_encrypt);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/**
	*  将一个char字符数组转化为二进制
	*  存到一个 byte 数组中
	*/
	void charToByte(byte out[16], const char s[16])
	{
		for (int i = 0; i < 16; ++i)
			for (int j = 0; j < 8; ++j)
				out[i][j] = ((s[i] >> j) & 1);
	}

	/**
	 *  将连续的128位分成16组，存到一个 byte 数组中
	 */
	void divideToByte(byte out[16], bitset<128>& data)
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
	bitset<128> mergeByte(byte in[16])
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
	private: string GetKey(String^ s)
	{
		return	(const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer();
	}

	private: System::Void Button_encrypt_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//byte key[16] = {0x2b, 0x7e, 0x15, 0x16,
		//				0x28, 0xae, 0xd2, 0xa6,
		//				0xab, 0xf7, 0x15, 0x88,
		//				0x09, 0xcf, 0x4f, 0x3c};
		//
		//byte plain[16] = { 0x32, 0x88, 0x31, 0xe0,
		//				0x43, 0x5a, 0x31, 0x37,
		//				0xf6, 0x30, 0x98, 0x07,
		//				0xa8, 0x8d, 0xa2, 0x34 };
		//// 输出密钥
		//cout << "密钥是：";
		//for (int i = 0; i < 16; ++i)
		//	cout << hex << key[i].to_ulong() << " ";
		//cout << endl;
		//
		//word w[4 * (Nr + 1)];
		//aes->KeyExpansion(key, w);
		//
		//// 输出待加密的明文
		//cout << endl << "待加密的明文：" << endl;
		//for (int i = 0; i < 16; ++i)
		//{
		//	cout << hex << plain[i].to_ulong() << " ";
		//	if ((i + 1) % 4 == 0)
		//		cout << endl;
		//}
		//cout << endl;
		//
		//// 加密，输出密文
		//aes->encrypt(plain, w);
		//cout << "加密后的密文：" << endl;
		//for (int i = 0; i < 16; ++i)
		//{
		//	cout << hex << plain[i].to_ulong() << " ";
		//	if ((i + 1) % 4 == 0)
		//		cout << endl;
		//}
		//cout << endl;
		//
		//// 解密，输出明文
		//aes->decrypt(plain, w);
		//cout << "解密后的明文：" << endl;
		//for (int i = 0; i < 16; ++i)
		//{
		//	cout << hex << plain[i].to_ulong() << " ";
		//	if ((i + 1) % 4 == 0)
		//		cout << endl;
		//}
		//cout << endl;
		//return;

		if (String::IsNullOrEmpty(this->key))
		{
			label_description->Text = String::Format("No keys now");
			return;
		}

		//string keyStr = "abcdefghijklmno";
		string keyStr = this->GetKey(this->key);
		byte key[16];
		charToByte(key, keyStr.c_str());
		// 密钥扩展
		word w[4 * (Nr + 1)];
		aes->KeyExpansion(key, w);

		String^ text = this->textBox1->Text;
		const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text)).ToPointer();

		byte plain[16];
		charToByte(plain, chars);
		aes->encrypt(plain, w);

		bitset<128> data = mergeByte(plain);

		string s = data.to_string();
		String^ outString2 = gcnew String(s.c_str());
		this->textBox2->Text = outString2;


		//byte plain2[16];
		//divideToByte(plain2, data);
		//aes->decrypt(plain2, w);
		//
		//const char* outChar = reinterpret_cast<const char*>(plain2);
		//string d;
		//for (int i = 0; i < 16; i++)
		//{
		//	d.push_back(*outChar);
		//	outChar+=4;
		//}
		//String^ outString = gcnew String(d.c_str());
		//this->textBox2->Text = outString;
		

		//bitset<128> data;
		//byte plain[16];
		//// 将文件 flower.jpg 加密到 cipher.txt 中
		//ifstream in;
		//ofstream out;
		//in.open("D://flower.jpg", ios::binary);
		//out.open("D://cipher.txt", ios::binary);
		//while (in.read((char*)&data, sizeof(data)))
		//{
		//	divideToByte(plain, data);
		//	encrypt(plain, w);
		//	data = mergeByte(plain);
		//	out.write((char*)&data, sizeof(data));
		//	data.reset();  // 置0
		//}
		//in.close();
		//out.close();
		//
		//// 解密 cipher.txt，并写入图片 flower1.jpg
		//in.open("D://cipher.txt", ios::binary);
		//out.open("D://flower1.jpg", ios::binary);
		//while (in.read((char*)&data, sizeof(data)))
		//{
		//	divideToByte(plain, data);
		//	decrypt(plain, w);
		//	data = mergeByte(plain);
		//	out.write((char*)&data, sizeof(data));
		//	data.reset();  // 置0
		//}
		//in.close();
		//out.close();

	}
	private: System::Void Button_decrypt_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (String::IsNullOrEmpty(this->key))
		{
			label_description->Text = String::Format("No keys now");
			return;
		}

		//string keyStr = "abcdefghijklmno";
		string keyStr = this->GetKey(this->key);
		byte key[16];
		charToByte(key, keyStr.c_str());
		//// 密钥扩展
		word w[4 * (Nr + 1)];
		aes->KeyExpansion(key, w);

		String^ text = this->textBox1->Text;
		const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(text)).ToPointer();
		//byte plain[16];
		//charToByte(plain, chars);

		//bitset<128> data = mergeByte(plain);
		bitset<128> data(chars);

		byte plain[16];
		divideToByte(plain, data);
		aes->decrypt(plain, w);

		const char* outChar = reinterpret_cast<const char*>(plain);
		string d;
		for (int i = 0; i < 16; i++)
		{
			d.push_back(*outChar);
			outChar += 4;
		}
		String^ outString = gcnew String(d.c_str());
		this->textBox2->Text = outString;
	}

	private: System::Void button_KeySet_Click(System::Object^  sender, System::EventArgs^  e)
	{
		label_KeyStatus->Text = "Setting...";
		if (this->textBox_Key->Text->Length != 16)
		{
			if (String::IsNullOrEmpty(this->key))
			{
				label_description->Text = String::Format("No keys now");
			}
			label_KeyStatus->Text = "Set Fail";
			return;
		}
		this->key = this->textBox_Key->Text;
		label_description->Text = String::Format("Now key is : {0}", this->key);
		label_KeyStatus->Text = "OK";
	}
};
}
