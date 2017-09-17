// ConsoleApplication3.cpp : Defines the entry point for the console application.
//  Created by Aysar Jezrawi on 2017-09-17.
//  Copyright © 2017 Aysar Jezrawi, Abdul Jamali, Ryker Chapman and James Lopez (AJAR). All rights reserved.
//	The purpose of this program is to have a micro-genetic algorithm evaluate the best parameter settings. 
// Authorship: We, group AJAR, certify that this material is our original work. 
// No other person's work has been used without due acknowledgement and we have not made our work 
// available to anyone else
/////////////////////////////////////////////////////////////////////////////

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

void compareFunc(double [], int);

int main()
{
	cout << "\t AJAR's MICRO-GENETIC ALGORITHM FOR SILVER NANOPARTICLE OPTIMIZATION" << endl;
	cout << endl << endl;
	double old[4] = { 9999,9999,9999,9999 };

	for (int j = 0; j < 5000; j++) {
	compareFunc(old, 4);
}
	cout << "Cost" << "\t\t" << "pH" << "\t\t" << "Glucose" << "\t\t" << "Silver" << "\t\t" << "Temperature" << endl << endl;
	cout << "Optimum pH:" << old[0] << endl;
	cout << "Optimum Glucose:" << old[1] << "g/L"<< endl;
	cout << "Optimum Silver:" << old[2] << "mM"<< endl;
	cout << "Optimum Reaction Temp:" << old[3] << "C" << endl;

	cin.ignore();
	return 0;
}

void compareFunc(double old[], int size) {    //array is in order of ph, glucose, silver, temp

	double phLevel[10];
	double glucoseConc[10];
	double reactionTemp[10];
	double silverConc[10];
	srand(time(NULL));
	double costHolder2 = old[0] + old[1] + old[2] + old[3];
	double costFunc[10];
	double newSet[4];						//array to save the lowest cost's parameter settings when 10 trials are generated
	double costHolder = 99999999999999;		//base value to begin the comparison with the cost function

	for (int i = 0; i < 10; i++) {			//creates 10 randomly generated trials
		
		cout << costHolder2 << "\t\t" << old[0] << "\t\t" << old[1] << "\t\t" << old[2] << "\t\t" << old[3] << endl; 
		phLevel[i] = rand() % 5 + 4;
		glucoseConc[i] = rand() % 9 + 6;
		reactionTemp[i] = rand() % 21 + 25;
		silverConc[i] = rand() % 5 + 2;
		costFunc[i] = glucoseConc[i] + phLevel[i] + reactionTemp[i] + silverConc[i];
		
		if (costFunc[i] < costHolder) {		//new best
			costHolder = costFunc[i];

			newSet[0] = phLevel[i];			//parameter values that result in a lower cost are saved to the newSet array
			newSet[1] = glucoseConc[i];
			newSet[2] = silverConc[i];
			newSet[3] = reactionTemp[i];

			if (costHolder<costHolder2) {	//evalutes the best set of newly generated 10 trials vs. last iteration's best

				old[0] = newSet[0];			//updates old array's elements with the optimized parameters
				old[1] = newSet[1];
				old[2] = newSet[2];
				old[3] = newSet[3];
			}

		}

	} 
}
