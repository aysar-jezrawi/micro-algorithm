//
//  main.cpp
//
//  Created by Aysar Jezrawi on 2017-09-14.
//  Copyright © 2017 Aysar Jezrawi. All rights reserved.
//

//#include "stdafx.h"   Doesn't work on mac
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <string.h>
//#include <conio.h>    Doesn't work on mac
#include <stdio.h>
#include <ctype.h>

    using namespace std;

int main(int argc, const char * argv[]) {

        double phLevel[10];
        double glucoseConc[10];
        double reactionTemp[10];
        double silverConc[10];
    
    double optimPH;
    double optimGlucose;

    
        double costHolder=999999999999999;
        double sizeHolder=999999999999999;
    
        
       // double costFunc = glucoseConc+phLevel+reactionTemp+silverConc; //Function to Evaluate Cost
       // double sizeFunc = glucoseConc*phLevel*reactionTemp*silverConc; //Function to Evaluate Size
        
    srand(time(NULL));

    cout << "pH\t\t\t\t" << "Temp\t\t\t" << "Silver\t\t" << "Glucose "<< endl;
    
    for(int i=0; i<10;i++) {
        phLevel[i]=rand()%5+4;
        glucoseConc[i]=rand()%9+6;
        reactionTemp[i]=rand()%21+25;
        silverConc[i]=rand()%5+2;
        
        cout << phLevel[i] << "\t\t\t\t" << reactionTemp[i] << "\t\t\t\t" << silverConc[i] << "\t\t\t\t" << glucoseConc[i] << endl;
        
        double costFunc[10];
        double sizeFunc[10];
        costFunc[i]= glucoseConc[i]+phLevel[i]+reactionTemp[i]+silverConc[i];
        sizeFunc[i]= glucoseConc[i]*phLevel[i]*reactionTemp[i]*silverConc[i];
                                     
        if (costFunc[i]<costHolder) {
            costHolder=costFunc[i];}
        
        if (sizeFunc[i]<sizeHolder){
            sizeHolder=sizeFunc[i];}
                                     
        
    }
    cout << endl;
    cout << "The lowest cost is " << costHolder << endl;
    cout << "The smallest size is " << sizeHolder << endl;
    
    
    cin.ignore();
    return 0;
    
    
    }


