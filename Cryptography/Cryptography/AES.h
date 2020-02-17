#pragma once
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

typedef bitset<8> byte;
typedef bitset<32> word;

const int Nr = 10;  // AES-128需要 10 轮加密
const int Nk = 4;   // Nk 表示输入密钥的 word_2 个数

namespace AES_PROGRESS
{
	public ref class AES
	{
		/**********************************************************************/
		/*                                                                    */
		/*                              AES算法实现                           */
		/*                                                                    */
		/**********************************************************************/

		/******************************下面是加密的变换函数**********************/
		/***  S盒变换 - 前4位为行号，后4位为列号*/
	public:
		void SubBytes(byte mtx[4 * 4]);
		void ShiftRows(byte mtx[4 * 4]);
		byte GFMul(byte a, byte b);
		void MixColumns(byte mtx[4 * 4]);
		void AddRoundKey(byte mtx[4 * 4], word k[4]);

		/**************************下面是解密的逆变换函数***********************/
		/***  逆S盒变换*/
		void InvSubBytes(byte mtx[4 * 4]);
		void InvShiftRows(byte mtx[4 * 4]);
		void InvMixColumns(byte mtx[4 * 4]);

		/******************************下面是密钥扩展部分***********************/
		/*** 将4个 bitset<8> 转换为一个 bitset<32>.*/
		word Word(byte& k1, byte& k2, byte& k3, byte& k4);
		word RotWord(word& rw);
		word SubWord(word& sw);
		void KeyExpansion(byte key[4 * Nk], word w[4 * (Nr + 1)]);

		/******************************下面是加密和解密函数**************************/
		/***  加密*/
		void encrypt(byte in[4 * 4], word w[4 * (Nr + 1)]);
		/***  解密*/
		void decrypt(byte in[4 * 4], word w[4 * (Nr + 1)]);
	};
}