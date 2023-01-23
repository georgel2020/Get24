#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
char op[4]={'+', '-', '*', '/'};    // 4 operators. 
int flag = 0;
double calculate(double num1, double num2, int oper)    // Calculate func. 
{
	double ans = 1048576;
	switch(oper){
	case 0:	
		ans = num1 + num2;
		break;
	case 1:
		ans = num1 - num2;
		break;
	case 2:
		ans = num1 * num2;
		break;
	case 3: 
		if(num2 != 0){    // Do not calculate n / 0. 
			ans = num1 / num2;
		}
		break;
	}
	return ans;
}
/// <summary>
/// Calculate ((num1_num2)_num3)_num4. 
/// </summary>
double cal1(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num1, num2, oper1);
	t2 = calculate(t1, num3, oper2);
	t3 = calculate(t2, num4, oper3);
	return t3;
}
/// <summary>
/// Calculate (num1_(num2_num3))_num4. 
/// </summary>
double cal2(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num2, num3, oper2);
	t2 = calculate(num1, t1, oper1);
	t3 = calculate(t2, num4, oper3);
	return t3;
}
/// <summary>
/// Calculate num1_(num2_(num3_num4)). 
/// </summary>
double cal3(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num3, num4, oper3);
	t2 = calculate(num2, t1, oper2);
	t3 = calculate(num1, t2, oper1);
	return t3;
}
/// <summary>
/// Calculate num1_(num2_num3)_num4). 
/// </summary>
double cal4(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num2, num3, oper2);
	t2 = calculate(t1, num4, oper3);
	t3 = calculate(num1, t2, oper1);
	return t3;
}
/// <summary>
/// Calculate (num1_num2)_(num3_num4). 
/// </summary>
double cal5(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num1, num2, oper1);
	t2 = calculate(num3, num4, oper3);
	t3 = calculate(t1, t2, oper2);
	return t3;
}
/// <summary>
/// Get 24 func. 
/// </summary>
void get24(double num1, double num2, double num3, double num4, double ans){
	int oper1, oper2, oper3;    // 3 operators. 
	for(oper1 = 0;oper1 < 4;oper1++){
		for(oper2 = 0;oper2 < 4;oper2++){
			for(oper3 = 0;oper3 < 4;oper3++){
				if(cal1(num1, num2, num3, num4, oper1, oper2, oper3) == ans){
					printf("((%d%c%d)%c%d)%c%d=24\n", (int)num1, op[oper1], (int)num2, op[oper2], (int)num3, op[oper3], (int)num4);
					flag = true;
				}
				if(cal2(num1, num2, num3, num4, oper1, oper2, oper3) == ans){
					printf("(%d%c(%d%c%d))%c%d=24\n", (int)num1, op[oper1], (int)num2, op[oper2], (int)num3, op[oper3], (int)num4);
					flag = true;
				}
				if(cal3(num1, num2, num3, num4, oper1, oper2, oper3) == ans){
					printf("%d%c(%d%c(%d%c%d))=24\n", (int)num1, op[oper1], (int)num2, op[oper2], (int)num3, op[oper3], (int)num4);
					flag = true;
				}
				if(cal4(num1, num2, num3, num4, oper1, oper2, oper3) == ans){
					printf("%d%c((%d%c%d)%c%d)=24\n", (int)num1, op[oper1], (int)num2, op[oper2], (int)num3, op[oper3], (int)num4);
					flag = true;
				}
				if(cal5(num1, num2, num3, num4, oper1, oper2, oper3) == ans){
					printf("(%d%c%d)%c(%d%c%d)=24\n", (int)num1, op[oper1], (int)num2, op[oper2], (int)num3, op[oper3], (int)num4);
					flag = true;
				}
			}
		}
	}
}
int main(){
	string str;    // Command. 
	double numA, numB, numC, numD, ans;
	while (true) {
		cin >> str;
		if (str == "solve") {
			cin >> numA >> numB >> numC >> numD;
			flag = false;
			get24(numA, numB, numC, numD, 24);
			if(flag == false) {
				printf("No solution\n");
			}
		}
		if (str == "solve-all") {
			cin >> numA >> numB >> numC >> numD;
			flag = false;
			get24(numA, numB, numC, numD, 24);
			get24(numA, numB, numD, numC, 24);
			get24(numA, numC, numB, numD, 24);
			get24(numA, numC, numD, numB, 24);
			get24(numA, numD, numB, numC, 24);
			get24(numA, numD, numC, numB, 24);
			get24(numB, numA, numC, numD, 24);
			get24(numB, numA, numD, numC, 24);
			get24(numB, numC, numA, numD, 24);
			get24(numB, numC, numD, numA, 24);
			get24(numB, numD, numA, numC, 24);
			get24(numB, numD, numC, numA, 24);
			get24(numC, numA, numB, numD, 24);
			get24(numC, numA, numD, numB, 24);
			get24(numC, numB, numA, numD, 24);
			get24(numC, numB, numD, numA, 24);
			get24(numC, numD, numA, numB, 24);
			get24(numC, numD, numB, numA, 24);
			get24(numD, numA, numB, numC, 24);
			get24(numD, numA, numC, numB, 24);
			get24(numD, numB, numA, numC, 24);
			get24(numD, numB, numC, numA, 24);
			get24(numD, numC, numA, numB, 24);
			get24(numD, numC, numB, numA, 24);
			if (flag == false) {
				printf("No solution\n");
			}
		}
		if (str == "solve-ans") {
			cin >> numA >> numB >> numC >> numD >> ans;
			flag = false;
			get24(numA, numB, numC, numD, ans);
			if (flag == false) {
				printf("No solution\n");
			}
		}
		if (str == "solve-ans-all") {
			cin >> numA >> numB >> numC >> numD >> ans;
			flag = false;
			get24(numA, numB, numC, numD, ans);
			get24(numA, numB, numD, numC, ans);
			get24(numA, numC, numB, numD, ans);
			get24(numA, numC, numD, numB, ans);
			get24(numA, numD, numB, numC, ans);
			get24(numA, numD, numC, numB, ans);
			get24(numB, numA, numC, numD, ans);
			get24(numB, numA, numD, numC, ans);
			get24(numB, numC, numA, numD, ans);
			get24(numB, numC, numD, numA, ans);
			get24(numB, numD, numA, numC, ans);
			get24(numB, numD, numC, numA, ans);
			get24(numC, numA, numB, numD, ans);
			get24(numC, numA, numD, numB, ans);
			get24(numC, numB, numA, numD, ans);
			get24(numC, numB, numD, numA, ans);
			get24(numC, numD, numA, numB, ans);
			get24(numC, numD, numB, numA, ans);
			get24(numD, numA, numB, numC, ans);
			get24(numD, numA, numC, numB, ans);
			get24(numD, numB, numA, numC, ans);
			get24(numD, numB, numC, numA, ans);
			get24(numD, numC, numA, numB, ans);
			get24(numD, numC, numB, numA, ans);
			if (flag == false) {
				printf("No solution\n");
			}
		}
		printf("\n");
	}
	return 0;
}
