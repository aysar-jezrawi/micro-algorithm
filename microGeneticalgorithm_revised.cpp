// microGeneticalgorithm_revised.cpp : Defines the entry point for the console application.
//  Created by Aysar Jezrawi on 2017-09-14.
//  Copyright © 2017 Aysar Jezrawi, Abdul Jamali, Ryker Chapman and James Lopez. All rights reserved.
//	The purpose of this program is to create a micro-genetic algorithm that selects the best parameter settings. 
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <string.h>
#include <conio.h>    
#include <stdio.h>
#include <ctype.h>

using namespace std; 

int main()
{
	double phLevel[10];
	double glucoseConc[10];
	double reactionTemp[10];
	double silverConc[10];
	double costHolder = 999999999999999;	//Compared to the cost to select the smallest one
	double sizeHolder = 999999999999999;	//Compared to the size to select the smallest one
	srand(time(NULL));
	double costFunc[10];
	double sizeFunc[10];

	cout << "pH\t\t" << "Temp\t\t" << "Silver\t\t" << "Glucose" << "\t\t\t" << "Cost" << "\t\t" << "Size" << endl << endl;

	for (int i=0; i<10; i++) {

		phLevel[i] = rand() % 5 + 4;
		glucoseConc[i] = rand() % 9 + 6;
		reactionTemp[i] = rand() % 21 + 25;
		silverConc[i] = rand() % 5 + 2;
		costFunc[i] = glucoseConc[i] + phLevel[i] + reactionTemp[i] + silverConc[i];
		sizeFunc[i] = glucoseConc[i] * phLevel[i] * reactionTemp[i] * silverConc[i];

		if (costFunc[i]<costHolder) {
			costHolder = costFunc[i];}
		if (sizeFunc[i]<sizeHolder) {
			sizeHolder = sizeFunc[i];}

		cout << phLevel[i] << "\t\t" << reactionTemp[i] << "\t\t" << silverConc[i] << "\t\t" << glucoseConc[i] << "\t\t\t" << costFunc[i] << "\t\t" << sizeFunc[i] << endl;
	}
	cout << endl;
	cout << "The lowest cost is " << costHolder << endl;
	cout << "The smallest size is " << sizeHolder << endl;

	cin.ignore(); 
    return 0;
}

