﻿#include <iostream>
#include <stdlib.h>
using namespace  std;

void showMenu()
{
	system("cls");
	cout << "-------------------MENU---------------------" << endl
		<< "Nhom tac vu 5 - Phep bien doi Fourier:" << endl
		<< "\t1. Phep bien doi Fourier thuan FFT" << endl
		<< "\t2. Phep bien doi Fourier nghich FFT" << endl
		<< "\t3. Loc thong tan so thap bang phep bien doi Fourier va DL Convolution" << endl
		<< "\t4. Loc thong tan so cao bang phep bien doi Fourier va DL Convolution" << endl << endl
		<< "Nhom tac vu 6 - Phep bien doi Karhunen Loeve:" << endl
		<< "\t5. Phan tich thanh phan chinh" << endl
		<< "\t6. Rut trich dat trung cho tap mat nguoi" << endl << endl
		<< "Nhom tac vu 7 - Phan doan anh:" << endl
		<< "\t7. Region growing" << endl
		<< "\t8. K-means" << endl << endl
		<< "Nhom tac vu 8 - Toan tu hinh thai hoc:" << endl
		<< "\t9. Toan tu hinh thai hoc tren anh nhi phan" << endl
		<< "\t10. Toan tu hinh thai hoc tren anh xam" << endl << endl
		<< "Vui long cho tac vu - go 0 de thoat" << endl;
}

int showMenuFunc9()
{
	system("cls");
	int f;
	cout << "-----Toan tu hinh thai tren anh nhi phan-----" << endl
		<< "\t1. Dilation" << endl
		<< "\t2. Erosion" << endl
		<< "\t3. Opening" << endl
		<< "\t4. Closing" << endl
		<< "\t5. BoundaryExtraction" << endl
		<< "\t6. RegionFilling" << endl
		<< "\t7. HitOrMiss" << endl
		<< "\t8. Thinning" << endl
		<< "\t9. Thickening" << endl
		<< "\t0. To return" << endl;

	cin >> f;
	return f;
}

int showMenuFunc10()
{
	system("cls");
	int f;
	cout << "-----Toan tu hinh thai tren anh xam-----" << endl
		<< "\t1. Grayscale Dilation" << endl
		<< "\t2. Grayscale Erosion" << endl
		<< "\t3. Grayscale Opening" << endl
		<< "\t4. Grayscale Closing" << endl
		<< "\t5. Grayscale smoothing" << endl
		<< "\t6. Grayscale Morphology Gradient" << endl
		<< "\t7. Top-hat transformation" << endl
		<< "\t8. Textural segmentation" << endl
		<< "\t9. Granulometry" << endl
		<< "\t0. To return" << endl;
	cin >> f;
	return f;
}


int showMenuFunc3()
{
	system("cls");
	int f;
	cout << "-----Loc thong tan thap-----" << endl
		<< "\t1. IdealLowpassFilter" << endl
		<< "\t2. ButterworthLowpassFilter" << endl
		<< "\t3. GaussianLowpassFilter" << endl
		<< "\t0. To return" << endl;
	cin >> f;
	return f;

}

int showMenuFunc4()
{
	system("cls");
	int f;
	cout << "-----Loc thong tan cao-----" << endl
		<< "\t1. IdealHighpassFilter" << endl
		<< "\t2. ButterworthHighpassFilter" << endl
		<< "\t3. GaussianHighpassFilter" << endl
		<< "\t0. To return" << endl;
	cin >> f;
	return f;
}

int** newKernel(int size)
{
	int **kernel = new int*[size];
	for (int i = 0; i < size; i++)
	{
		kernel[i] = new int[size];
		for (int j = 0; j < size; j++)
			kernel[i][j] = 1;
	}
	return kernel;
}

void repairKernel(int** kernel)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			kernel[i][j] = -1;
	kernel[1][1] = 1;
	kernel[1][2] = 0;
}

void deleteKernel(int **kernel)
{
	for (int i = 0; i < 3; i++)
		delete kernel[i];
	delete kernel;
}