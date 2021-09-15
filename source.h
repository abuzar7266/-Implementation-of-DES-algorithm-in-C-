#pragma once
/*
   Name  		: Abuzar
   Roll ID 		: 19I-0531
   Assignment   : DataStructures-1
*/

#include<iostream>
using namespace std;
template<typename T>
T* InversePermuteText(T Text[])//Final_Permutation_For Generating Cipher Text in binary representation
{
	int IP_Table[] = { 40  ,   8 ,  48  ,  16  ,  56  , 24  ,  64 ,  32
			,39   ,  7  , 47 ,   15,    55   ,23 ,   63   ,31
			,38  ,   6 ,  46,    14 ,   54   ,22  ,  62   ,30
			,37 ,    5  , 45    ,13  ,  53   ,21   , 61   ,29
			,36    , 4   ,44   , 12   , 52   ,20    ,60   ,28
			,35   ,  3 ,  43  ,  11    ,51  , 19    ,59  , 27
			,34  ,   2  , 42 ,   10    ,50 ,  18    ,58 ,  26
			,33 ,    1   ,41,     9    ,49,   17    ,57,   25 };
	T* Cipher_Text = new T[65];
	Cipher_Text[64] = '\0';
	for (int i = 0; i < 64; i++)
	{
		Cipher_Text[i] = Text[IP_Table[i] - 1];
	}
	return Cipher_Text;
}
template<typename T>
T* GetLeftHalf(T key[])//For Getting Left Half String as seperate
{
	int Length = 0;
	while (key[Length] != '\0')
		Length++;
	Length /= 2;
	T* NewStr = new T[Length + 1];
	NewStr[Length] = '\0';
	for (int i = 0; i < Length; i++)
	{
		NewStr[i] = key[i];
	}
	return NewStr;
}
template<typename T>
T* GetRightHalf(T key[])//For Getting Right Half String as seperate
{
	int Length = 0;
	while (key[Length] != '\0')
		Length++;
	Length /= 2;
	T* NewStr = new T[Length + 1];
	NewStr[Length] = '\0';
	for (int i = 0; i < Length; i++)
	{
		NewStr[i] = key[Length + i];
	}
	return NewStr;
}
template<typename T>
T* CombineHalves(T First[], T Sec[])//For combining Halves of Newly Generated Plain Text
{
	int x = 0;
	int y = 0;
	while (First[x] != '\0')
		x++;
	while (Sec[y] != '\0')
		y++;
	T* CombinedHalves = new T[x+y+1];
	CombinedHalves[x + y] = '\0';
	for (int i = 0; i < x + y; i++)
	{
		if(i<x)
		CombinedHalves[i] = First[i];
		else
			CombinedHalves[i] = Sec[i];
	}
	return CombinedHalves;
}
template<typename T>
T* HexaToBin(T key[])
{
	const T* Arr2 = key;
	T** Arr = new T * [16];
	for (int i = 0; i < 16; i++)
	{
		Arr[i] = new T[5];
		Arr[i][4] = '\0';
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Arr[i][j] = '0';
		}
	}
	for (int i = 0; i < 16; i++)
	{
		int Number = -1;
		if (Arr2[15 - i] >= '0' && Arr2[15 - i] <= '9')
		{
			Number = static_cast<int>(Arr2[15 - i]);
		}
		else if (Arr2[15 - i] == 'A')
		{
			Number = 10;
		}
		else if (Arr2[15 - i] == 'B')
		{
			Number = 11;
		}
		else if (Arr2[15 - i] == 'C')
		{
			Number = 12;
		}
		else if (Arr2[15 - i] == 'D')
		{
			Number = 13;
		}
		else if (Arr2[15 - i] == 'E')
		{
			Number = 14;
		}
		else if (Arr2[15 - i] == 'F')
		{
			Number = 15;
		}
		int idx = 0;
		while (Number > 0)
		{
			int Bin = Number % 2;
			if (Bin == 1)
				Arr[15 - i][3 - idx] = '1';
			else if (Bin == 0)
				Arr[15 - i][3 - idx] = '0';

			Number /= 2;
			idx++;
		}
	}
	T* ResultKey = new T[65];
	ResultKey[64] = '\0';
	int ridx = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ResultKey[ridx] = Arr[i][j];
			ridx++;
		}
	}
	/*for (int i = 0; i < 16; i++)
	{
		delete []Arr[i];
	}*/
	delete[]Arr;
	return ResultKey;
}
template<typename T1>
T1* PermutedChoice_1(T1 key[])
{
	T1* Arr2 = key;
	T1* PermutedKey = new T1[57];
	PermutedKey[56] = '\0';
	int PermutChoice[56];
	PermutChoice[7] = 1;
	PermutChoice[15] = 2;


	for (int i = 0; i < 7; i++)
		PermutChoice[i] = 57 - (i * 8);
	for (int i = 8; i < 15; i++)
		PermutChoice[i] = 58 - ((i - 8) * 8);
	for (int i = 16; i < 24; i++)
		PermutChoice[i] = 59 - ((i - 16) * 8);
	for (int i = 24; i < 28; i++)
		PermutChoice[i] = 60 - ((i - 24) * 8);
	for (int i = 28; i < 36; i++)
		PermutChoice[i] = 63 - ((i - 28) * 8);
	for (int i = 36; i < 44; i++)
		PermutChoice[i] = 62 - ((i - 36) * 8);
	for (int i = 44; i < 52; i++)
		PermutChoice[i] = 61 - ((i - 44) * 8);
	for (int i = 52; i < 56; i++)
		PermutChoice[i] = 28 - ((i - 52) * 8);
	for (int i = 0; i < 56; i++)
	{
		PermutedKey[i] = Arr2[PermutChoice[i] - 1];
		//cout <<i<<")"<< PermutChoice[i] << ") PermutedKey : " << PermutedKey[i] << endl;
	}
	return PermutedKey;
}
template<typename T>
T* initKeyPermutation(T key[])
{
	/*This function accepts Hex-Key and Returns binary permuted key*/
	T* Y = HexaToBin(key); //For HexToBinary
	Y = PermutedChoice_1(Y);//For initialPermutation of Key
	return Y;
}
template<typename T>
T* halfCircularShift(T KeyChunk[], int iter)
{
	/*This functions shifts Binary to left for 'n'
	times,where 'n' depends on round number*/
	int shiftNo = -1;
	if (iter == 1 || iter == 2 || iter == 9 || iter == 16)
		shiftNo = 1;
	else
		shiftNo = 2;
	T ShiftBox[29];
	ShiftBox[28] = '\0';
	for (int i = 0; i < shiftNo; i++)
	{
		ShiftBox[27] = KeyChunk[0];
		for (int i = 0; i < 27; i++)
		{
			ShiftBox[i] = KeyChunk[i + 1];
		}
		for (int i = 0; i < 28; i++)
		{
			KeyChunk[i] = ShiftBox[i];
		}
	}
	return KeyChunk;
}
template<typename T>
T* roundPermutation(T key[])
{
	/*This function performs 2nd permutation and compression of key
	We just pass it 56-bits key then it'll be compressed to 48-bits,which
	 will be further passed to round functions*/
	int PC2[] = { 14  ,  17  , 11  ,  24  ,   1 ,   5,
				  3 ,   28  , 15     ,6  ,  21   ,10,
				 23  ,  19 ,  12 ,    4 ,   26    ,8,
				 16   ,  7  , 27  ,  20    ,13    ,2,
				 41   , 52   ,31   , 37   , 47   ,55,
				 30 ,   40   ,51    ,45  ,  33   ,48,
				 44  ,  49  , 39 ,   56 ,   34  , 53,
				 46   , 42 ,  50  ,  36,    29 ,  32 };
	T* PermutedKey = new T[49];
	PermutedKey[48] = '\0';
	for (int i = 0; i < 48; i++)
	{
		PermutedKey[i] = key[PC2[i] - 1];
	}
	return PermutedKey;
}
template<typename T>
T* initTextPermutation(T Text[])
{
	/*This Functions accepts Hex value as plain text and return permuted binary of plain text*/
	T* HexText = HexaToBin(Text);
	int initPermutTable[] = { 58 , 50 , 42 , 34 , 26 , 18 , 10 , 2,
								60 , 52 , 44 , 36 , 28 , 20 , 12 , 4,
								62 , 54 , 46 , 38 , 30 , 22 , 14 , 6,
								64 , 56 , 48 , 40 , 32 , 24 , 16 , 8,
								57 , 49 , 41 , 33 , 25 , 17 , 9  , 1,
								59 , 51 , 43 , 35 , 27 , 19 , 11 , 3,
								61 , 53 , 45 , 37 , 29 , 21 , 13 , 5,
								63 , 55 , 47 , 39 , 31 , 23 , 15 , 7 };
	T* PermutedText = new T[65];
	PermutedText[64] = '\0';
	for (int i = 0; i < 64; i++)
	{
		PermutedText[i] = HexText[initPermutTable[i] - 1];
	}
	delete[]HexText;
	return PermutedText;

}
template<typename T>
T* expandHalfText(T Text[])
{
	/*This Function will expand 32-bits Plain Text to 48-bits for performing Further DES operations*/
	int EXPANSION_TABLE[] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
	T* ExpandedText = new T[49];
	ExpandedText[48] = '\0';
	for (int i = 0; i < 48; i++)
	{
		ExpandedText[i] = Text[EXPANSION_TABLE[i] - 1];
	}
	return ExpandedText;
}
template<typename T>
T* XOR(T Text[], T key[])
{
	/*This function will perform XOR operation between two given binary strings and will return the output in T ptr*/
	T* Result = new T[49];
	Result[48] = '\0';
	for (int i = 0; i < 48; i++)
	{
		if (Text[i] == key[i])
		{
			Result[i] = '0';
		}
		else
		{
			Result[i] = '1';
		}
	}
	return Result;
}
template<typename T>
T* calcSBox(T ExpandKey[])//In this Function,48 bit will be compressed to 32 bits using 8 Substitutions Boxes
{
	T* Arr = new T[33];//Array to store Resultant 32 bits of Compressed 48-bits
	Arr[32] = '\0';
	T Pair_Of_Key[8][6];//2D template based array,For making 8 pairs of ExpandKey parameter;in which each pair contains 6 bits
	int x = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Pair_Of_Key[i][j] = ExpandKey[x];
			x++;
		}
	}
	/*Now Next 8 -->2D Arrays are being initialized using initializer lists*/
	int S_BOX_1[4][16] =
	{
		{14,  4 , 13 , 1 ,  2 ,15,  11,  8 ,  3 ,10  , 6 ,12 ,  5 , 9 ,  0 , 7},
		{0 ,15   ,7  ,4  ,14  ,2  ,13  ,1  ,10  ,6  ,12 ,11  , 9 , 5  , 3 , 8},
		{4  ,1 , 14 , 8 , 13 , 6 ,  2 ,11 , 15 ,12  , 9 , 7 ,  3 ,10  , 5 , 0},
		{ 15, 12  , 8 , 2  , 4 , 9 ,  1 , 7  , 5 ,11 ,  3, 14 , 10 , 0  , 6 ,13 }
	};
	int S_BOX_2[4][16] = {
		{15,  1,   8, 14,   6 ,11 ,  3 , 4 ,  9 , 7 ,  2 ,13 , 12 , 0 ,  5 ,10},
		{ 3 ,13  , 4 , 7 , 15 , 2  , 8 ,14  ,12  ,0   ,1 ,10   ,6  ,9  ,11  ,5 },
		{0 ,14 ,  7 ,11 , 10 , 4  ,13 , 1  , 5 , 8  ,12 , 6,   9 , 3 ,  2, 15},
		{13  ,8  ,10 , 1   ,3 ,15   ,4  ,2  ,11 , 6  , 7 ,12  , 0  ,5  ,14  ,9} };

	int S_BOX_3[4][16] = {
		{10 , 0 ,  9, 14 ,  6 , 3  ,15 , 5 ,  1, 13 , 12 , 7 , 11,  4,   2,  8},
{ 13  ,7   ,0  ,9   ,3  ,4   ,6 ,10   ,2  ,8   ,5 ,14  ,12 ,11  ,15  ,1 },
{ 13 , 6 ,  4 , 9 ,  8, 15 ,  3 , 0 , 11 , 1 ,  2 ,12 ,  5 ,10 , 14 , 7},
{ 1 ,10 , 13  ,0  , 6 , 9   ,8  ,7  , 4 ,15  ,14  ,3  ,11  ,5   ,2 ,12 } };

	int S_BOX_4[4][16] = {
		{	7 ,13 , 14,  3 ,  0 , 6  , 9 ,10  , 1 , 2  , 8 , 5  ,11 ,12  , 4 ,15},
		{13 , 8 , 11 , 5  , 6 ,15 ,  0 , 3 ,  4 , 7  , 2 ,12 ,  1 ,10 , 14 , 9 },
	{10 , 6 ,  9,  0 , 12, 11 ,  7, 13 , 15 , 1  , 3 ,14  , 5  ,2   ,8 , 4 },
	{ 3 ,15  , 0 , 6  ,10  ,1  ,13  ,8  , 9 , 4  , 5, 11  ,12  ,7   ,2 ,14 } };

	int S_BOX_5[4][16] = {
		{ 2 ,12  , 4  ,1   ,7 ,10 , 11 , 6  , 8  ,5 ,  3 ,15 , 13 , 0 , 14 , 9},
	{14 ,11  , 2, 12 ,  4 , 7 , 13 , 1 ,  5 , 0  ,15 ,10  , 3 , 9  , 8 , 6},
	{ 4  ,2 ,  1 ,11,  10 ,13 ,  7  ,8,  15  ,9 , 12  ,5 ,  6 , 3 ,  0 ,14},
	{11 , 8 , 12 , 7  , 1 ,14   ,2 ,13  , 6 ,15  , 0 , 9 , 10 , 4  , 5 , 3}
	};

	int S_BOX_6[4][16] = { {12 , 1 , 10 ,15 ,  9 , 2   ,6  ,8 ,  0, 13 ,  3 , 4 , 14 , 7  , 5 ,11 },
	{10 ,15  , 4,  2 ,  7 ,12 ,  9 , 5  , 6  ,1  ,13 ,14   ,0, 11  , 3  ,8 },
	{ 9 ,14  ,15 , 5 ,  2 , 8 , 12 , 3  , 7 , 0  , 4 ,10   ,1 ,13 , 11 , 6 },
	{ 4  ,3  , 2, 12 ,  9 , 5 , 15 ,10 , 11 ,14  , 1 , 7   ,6 , 0   ,8 ,13} };

	int S_BOX_7[4][16] = {
		{4 ,11 ,  2 ,14 , 15 , 0  , 8 ,13 ,  3 ,12 ,  9 , 7 ,  5 ,10 ,  6 , 1},
	{13  ,0 , 11 , 7 ,  4  ,9 ,  1 ,10 , 14 , 3  , 5 ,12 ,  2 ,15  , 8 , 6 },
	{ 1  ,4  ,11, 13 , 12 , 3  , 7 ,14  ,10, 15  , 6 , 8  , 0 , 5 ,  9 , 2},
	{ 6 ,11 , 13 , 8 ,  1,  4 , 10 , 7  , 9 , 5  , 0, 15 , 14 , 2  , 3 ,12} };

	int S_BOX_8[4][16] = {
		{13,  2  , 8,  4  , 6 ,15  ,11,  1 , 10 , 9  , 3 ,14  , 5 , 0  ,12 , 7},
		{1, 15  ,13  ,8  ,10 , 3  , 7  ,4 , 12 , 5   ,6 ,11  , 0, 14  , 9 , 2},
		{ 7, 11,   4  ,1 ,  9 ,12  ,14  ,2  , 0 , 6 , 10 ,13  ,15 , 3  , 5 , 8},
		{2  ,1,  14 , 7 ,  4 ,10  , 8 ,13,  15, 12 ,  9 , 0  , 3 , 5 ,  6 ,11} };

	int RowNum[8];//For storing Specific S-Box Row Number 
	int ColNum[8];//For storing Specific S-Box Col Number 
	for (int j = 0; j < 8; j++)//Loop Created for Converting Logically related Bits for Row and Col to their Decimal Value
	{
		RowNum[j] = (static_cast<int>(Pair_Of_Key[j][0]) - 48) * 2 + (static_cast<int>(Pair_Of_Key[j][5]) - 48);
		ColNum[j] = ((static_cast<int>(Pair_Of_Key[j][1]) - 48) * (2 * 2 * 2)) + ((static_cast<int>(Pair_Of_Key[j][2]) - 48) * (2 * 2)) + ((-48 + static_cast<int>(Pair_Of_Key[j][3])) * 2) + (-48 + static_cast<int>(Pair_Of_Key[j][4]));
	}
	int Digits[8];//For Storing Value of nth S-BOX at mxn indexes 
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			Digits[i] = S_BOX_1[RowNum[i]][ColNum[i]];
		else if (i == 1)
			Digits[i] = S_BOX_2[RowNum[i]][ColNum[i]];
		else if (i == 2)
			Digits[i] = S_BOX_3[RowNum[i]][ColNum[i]];
		else if (i == 3)
			Digits[i] = S_BOX_4[RowNum[i]][ColNum[i]];
		else if (i == 4)
			Digits[i] = S_BOX_5[RowNum[i]][ColNum[i]];
		else if (i == 5)
			Digits[i] = S_BOX_6[RowNum[i]][ColNum[i]];
		else if (i == 6)
			Digits[i] = S_BOX_7[RowNum[i]][ColNum[i]];
		else if (i == 7)
			Digits[i] = S_BOX_8[RowNum[i]][ColNum[i]];
	}
	T FiestelKey[8][4];//For Storing Binary of Digits;We just got in previous loop
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			FiestelKey[i][j] = '0';
		}
	}
	for (int i = 0; i < 8; i++)
	{
		int idx = 3;
		int Temp = Digits[i];
		while (Temp > 0)
		{
			if (Temp % 2 == 1)
			{
				FiestelKey[i][idx] = '1';
			}
			else
			{
				FiestelKey[i][idx] = '0';
			}
			Temp = Temp / 2;
			idx--;
		}
	}
	int itr = 0;
	/*Now Finally,Converting S-box calculated Binary to 2d array to Single dimensionals*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Arr[itr] = FiestelKey[i][j];
			itr++;
		}
	}
	return Arr;//Returning S-Box Calculated Binary
}
/*template<typename T>
T* DES(T text[], T key[])
{
	T* PermutedText = initTextPermutation(text);
	T* PermutedKey  = initKeyPermutation(key);
	
	T* C = GetLeftHalf(PermutedKey);
	T* D = GetRightHalf(PermutedKey);
	T* Cipher_Bin = NULL;
	cout << "PermutedText : " << PermutedText << endl;
	for (int i = 0; i < 16; i++)
	{
		T* LeftText = GetLeftHalf(PermutedText);
		T* RightText = GetRightHalf(PermutedText);
		T* Ci = halfCircularShift(C, i + 1);
		T* Di = halfCircularShift(D, i + 1);
		delete[]C;
		delete[]D;
		C = Ci;
		D = Di;
		
		T* CombKey = CombineHalves(C, D);
		T* roundKey = roundPermutation(CombKey);
		delete[]CombKey;

		T* RightExpan = expandHalfText(RightText);
		delete[]RightExpan;
		T* Xor_Out = XOR(roundKey, RightExpan);
		T* SBOX_Out = calcSBox(Xor_Out);
		delete[]roundKey;
		delete[]RightExpan;
		T* NewRightText = XOR(SBOX_Out, LeftText);

		delete[]LeftText;
		LeftText = RightText;
		RightText = NewRightText;

		delete[]PermutedText;
		cout << "-----------------------------" << endl;
		cout << "PermutedText : " << PermutedText << endl;
		PermutedText = CombineHalves(LeftText, RightText);
		cout << "PermutedText : " << PermutedText << endl;
	}
	cout << "PermutedText : " << PermutedText << endl;
	
	Cipher_Bin = InversePermuteText(PermutedText);

	return Cipher_Bin;
}
*/


