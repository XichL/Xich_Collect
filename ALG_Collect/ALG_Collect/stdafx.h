// stdafx.h : 可在此標頭檔中包含標準的系統 Include 檔，
// 或是經常使用卻很少變更的
// 專案專用 Include 檔案
#pragma once

//	在 /clr 下不支援 varargs
#pragma  warning(disable:4793)

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 從 Windows 標頭排除不常使用的成員
// Windows 標頭檔:
#include <windows.h>

// TODO: 在此參考您的程式所需要的其他標頭
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <wchar.h>
#include <map>
#include <vector>

#include "../3rdparty/include/Ry4S.h"

#include "../3rdparty/include/fftw3.h"

#include "../3rdparty/include/opencv.hpp"
#ifdef _WIN64
#pragma comment(lib,"../3rdparty/lib_x64/Ry4S.lib")
#pragma comment(lib,"../3rdparty/lib_x64/libfftw3-3.lib")
#ifdef _DEBUG
#pragma comment(lib,"../3rdparty/lib_x64/Debug/opencv_imgproc340D.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Debug/opencv_core340D.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Debug/opencv_imgcodecs340D.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Debug/opencv_highgui340D.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Debug/opencv_objdetect340D.lib")
#else
#pragma comment(lib,"../3rdparty/lib_x64/Release/opencv_imgproc340.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Release/opencv_core340.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Release/opencv_imgcodecs340.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Release/opencv_highgui340.lib")
#pragma comment(lib,"../3rdparty/lib_x64/Release/opencv_objdetect340.lib")
#endif
#else
#pragma comment(lib,"../3rdparty/lib_x86/Ry4S.lib")
#pragma comment(lib,"../3rdparty/lib_x86/libfftw3-3.lib")
#ifdef _DEBUG
#pragma comment(lib,"../3rdparty/lib_x86/Debug/opencv_imgproc340D.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Debug/opencv_core340D.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Debug/opencv_imgcodecs340D.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Debug/opencv_highgui340D.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Debug/opencv_objdetect340D.lib")
#else
#pragma comment(lib,"../3rdparty/lib_x86/Release/opencv_imgproc340.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Release/opencv_core340.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Release/opencv_imgcodecs340.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Release/opencv_highgui340.lib")
#pragma comment(lib,"../3rdparty/lib_x86/Release/opencv_objdetect340.lib")
#endif
#endif

#define _USB

typedef struct
{
	int x;	//!< X座標
	int y;	//!< Y座標
}OfCoordinate, OfPoint, OfVector;

typedef struct
{
	int x;
	int y;
	double value;
}OfTwoDPoint;

typedef struct
{
	int x;
	int y;
	int width;
	int height;
	double value;
}OfBlock;

typedef struct
{
	int x;
	int y;
	double value;
	int count;
}OfThreeDPoint;

#define MAXSTRLEN 512

#define PI 3.1415926535897932384626433832795
#define ABS(a)	   (((a) < 0) ? -(a) : (a))	

//!	定義除法（防止分母為零）
static double dividevar1,dividevar2;
#define DIVIDE(a,b) (dividevar1 = (a),(dividevar2 = (b)) == 0.0 ? (dividevar1*10000):((dividevar1)/(dividevar2)))

//!	定義釋放記憶體之巨集
#define RELEASE(a) (((a)!=0) ? (delete[] (a),(a) = 0):((a)=0))

inline int ANSI2UNICODE(char *lpMultiByteStr, wchar_t *lpWideCharStr, int cchWideChar)
{
	int Res = MultiByteToWideChar(CP_ACP,0,lpMultiByteStr, (int)strlen(lpMultiByteStr)+1, lpWideCharStr, cchWideChar);
	return Res;
}

inline int UNICODE2ANSI(wchar_t* lpWideCharStr, char* lpMultiByteStr, int cbMultiByte)
{
	int Res = WideCharToMultiByte(CP_ACP,0,lpWideCharStr, (int)(wcslen(lpWideCharStr)+1), lpMultiByteStr, cbMultiByte, NULL, NULL);
	return Res;
}	

inline int DoubleToStringA(double DoubleValue,char* DoubleString)
{
	return _gcvt_s(DoubleString, MAXSTRLEN, DoubleValue, MAXSTRLEN-40);
}

inline int DoubleToStringW(double DoubleValue,wchar_t* DoubleString)
{
	char _tmpbuf[MAXSTRLEN];
	int Res = DoubleToStringA(DoubleValue,_tmpbuf);
	ANSI2UNICODE(_tmpbuf,DoubleString,MAXSTRLEN);
	return Res;
}

inline void DebugInfoA(char *format,...)
{

	va_list argptr;
	int len;
	char * szMes;

	va_start( argptr, format );
	len = _vscprintf( format, argptr ) + 2; // '\n' + '\0'

	szMes = new char[len];
	vsprintf_s( szMes, len, format, argptr );
	strcat_s(szMes,len,"\n\0");

	OutputDebugStringA(szMes);
	va_end(argptr);

	delete[] szMes;
	szMes = 0;

}