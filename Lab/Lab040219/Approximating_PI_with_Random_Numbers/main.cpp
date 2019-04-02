/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 2nd, 2019, 10:06 AM
 * Purpose:  Approximate Pi
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cmath>     //Math Library
#include <cstdlib>   //Random number Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float PI=4*atan(1);             //Trig Identity
const unsigned int MAXRND=pow(2,31)-1;//Max Random Number

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float approxPI;
    int nmDarts,nmInCrc;
    
    //Declare Values
    nmDarts=100000;//Number of Darts thrown
    nmInCrc=0;
    
    //Find the min and max random number
    for(int dart=1;dart<nmDarts;dart++){
        float x=1.0f*rand()/MAXRND;//[0-1] X Coordinate where dart thrown
        float y=1.0f*rand()/MAXRND;//[0-1] Y Coordinate where dart thrown
        if(x*x+y*y<=1)nmInCrc++;
    }
    approxPI=4.0f*nmInCrc/nmDarts;
    
    //Display the outputs
    cout<<"Total Number of Darts Thrown = "<<nmDarts<<endl;
    cout<<"PI exact  = "<<PI<<endl;
    cout<<"PI approx = "<<approxPI<<endl;

    //Exit stage right or left!
    return 0;
}