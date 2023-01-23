#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
char op[4]={'+', '-', '*', '/'};
int flag = 0;
double calculate(double num1, double num2, int oper)
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
		if(num2 != 0){
			ans = num1 / num2;
		}
		break;
	}
	return ans;
}
double cal1(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num1, num2, oper1);
	t2 = calculate(t1, num3, oper2);
	t3 = calculate(t2, num4, oper3);
	return t3;
}
double cal2(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num2, num3, oper2);
	t2 = calculate(num1, t1, oper1);
	t3 = calculate(t2, num4, oper3);
	return t3;
}
double cal3(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num3, num4, oper3);
	t2 = calculate(num2, t1, oper2);
	t3 = calculate(num1, t2, oper1);
	return t3;
}
double cal4(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num2, num3, oper2);
	t2 = calculate(t1, num4, oper3);
	t3 = calculate(num1, t2, oper1);
	return t3;
}	
double cal5(double num1, double num2, double num3, double num4, int oper1, int oper2, int oper3){
	double t1, t2, t3;
	t1 = calculate(num1, num2, oper1);
	t2 = calculate(num3, num4, oper3);
	t3 = calculate(t1, t2, oper2);
	return t3;
}
void get24(double num1, double num2, double num3, double num4, double ans){
	int oper1, oper2, oper3;
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
	string str;
	double a, b, c, d, n;
	while (true) {
		cin >> str;
		if (str == "solve") {
			cin >> a >> b >> c >> d;
			flag = false;
			get24(a, b, c, d, 24);
			if(flag == false) {
				printf("No solution\n");
			}
		}
		if (str == "solve-all") {
			cin >> a >> b >> c >> d;
			flag = false;
			get24(a, b, c, d, 24);
			get24(a, b, d, c, 24);
			get24(a, c, b, d, 24);
			get24(a, c, d, b, 24);
			get24(a, d, b, c, 24);
			get24(a, d, c, b, 24);
			get24(b, a, c, d, 24);
			get24(b, a, d, c, 24);
			get24(b, c, a, d, 24);
			get24(b, c, d, a, 24);
			get24(b, d, a, c, 24);
			get24(b, d, c, a, 24);
			get24(c, a, b, d, 24);
			get24(c, a, d, b, 24);
			get24(c, b, a, d, 24);
			get24(c, b, d, a, 24);
			get24(c, d, a, b, 24);
			get24(c, d, b, a, 24);
			get24(d, a, b, c, 24);
			get24(d, a, c, b, 24);
			get24(d, b, a, c, 24);
			get24(d, b, c, a, 24);
			get24(d, c, a, b, 24);
			get24(d, c, b, a, 24);
			if (flag == false) {
				printf("No solution\n");
			}
		}
		if (str == "solve-ans") {
			cin >> a >> b >> c >> d >> n;
			flag = false;
			get24(a, b, c, d, n);
			if (flag == false) {
				printf("No solution\n");
			}
		}
		if (str == "solve-ans-all") {
			cin >> a >> b >> c >> d >> n;
			flag = false;
			get24(a, b, c, d, n);
			get24(a, b, d, c, n);
			get24(a, c, b, d, n);
			get24(a, c, d, b, n);
			get24(a, d, b, c, n);
			get24(a, d, c, b, n);
			get24(b, a, c, d, n);
			get24(b, a, d, c, n);
			get24(b, c, a, d, n);
			get24(b, c, d, a, n);
			get24(b, d, a, c, n);
			get24(b, d, c, a, n);
			get24(c, a, b, d, n);
			get24(c, a, d, b, n);
			get24(c, b, a, d, n);
			get24(c, b, d, a, n);
			get24(c, d, a, b, n);
			get24(c, d, b, a, n);
			get24(d, a, b, c, n);
			get24(d, a, c, b, n);
			get24(d, b, a, c, n);
			get24(d, b, c, a, n);
			get24(d, c, a, b, n);
			get24(d, c, b, a, n);
			if (flag == false) {
				printf("No solution\n");
			}
		}
		printf("\n");
	}
	return 0;
}
