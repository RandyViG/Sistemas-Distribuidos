#ifndef __REGISTRO__
#define __REGISTRO__

#include<iostream>

using namespace std;

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
	string toString(){
		return string(celular)+string(CURP)+string(partido);
	}
};

#endif