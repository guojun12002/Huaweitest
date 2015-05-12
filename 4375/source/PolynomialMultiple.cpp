/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2010/9
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2010/9
Author      :
Modification: Created file

******************************************************************************/


/******************************************************************************************************
Description     : �����������һԪ����ʽ�����ж���ʽ�˷����㣬������һԪ����ʽ
Prototype       : void PolynomialMultiple (char* InputString1, char* InputString2, char* OutputString)
Input Param     : char* InputString1 ����1����ʽ�ַ���
                  char* InputString2 ����2����ʽ�ַ���
Output Param    : char* OutputString �˻�����ʽ�ַ���
Return Value    : void

********************************************************************************************************/
#include "polynomial.cpp"
void PolynomialMultiple (char* InputString1, char* InputString2, char* OutputString)
{
    /*������ʵ�ֹ���*/
	if(InputString1 == NULL || InputString1[0] == '\0' || InputString2 == NULL || InputString2[0] == '\0' || OutputString == NULL) return;
	char* s1 = InputString1;
	string str;
	while(s1 != NULL)
	{
		int a1, b1;
		sscanf(s1, "%dX^%d", &a1, &b1);
		char* s2 = InputString2;
		while(s2 != NULL)
		{
			int a2, b2;
			sscanf(s2, "%dX^%d", &a2, &b2);
			int a = a1 * a2, b = b1 + b2;
			if(a < 0) str.push_back('-');
			else str.push_back('+');
			string A, B;
			inttostring(A, abs(a));
			inttostring(B, abs(b));
			str += A;
			str.append("X^");
			str += B;
			char* sp = strchr(s2+1, '+');
			char* sm = strchr(s2+1, '-');
			s2 = cmp(sp, sm);
		}
		char* sp = strchr(s1+1, '+');
		char* sm = strchr(s1+1, '-');
		s1 = cmp(sp, sm);
	}
	// cout<<str<<endl;
	OrderPolynomial((char*)str.c_str(), OutputString);
}
