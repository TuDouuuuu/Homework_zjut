/*#ifndef _IOSTEAM_
#define _IOSTEAM_
#ifndef _COMPANY_H_
#define _COMPANY_H_*/
#include"Product.h"
#include<string>
#include<iostream>
//构造函数
Product::Product(string n,int p){
	name=n;prize=p;
}
//操作系列
void Product::RePrize(int p){
	prize=p;
}
void Product::Re(string n,int p){
	name=n;prize=p;
}
//读取系列
int Product::ReturnPrize(){
	return prize;
}
/*
#endif
#endif*/