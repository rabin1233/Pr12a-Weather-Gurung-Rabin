/*
School  : Contra Costa College 
Term    : 2017 Spring
Course:   Comp-251-2384
          Fundamentals of Computer Science with C++
Chapter : 12
Program : Pr12a-Weather-Gurung-Rabin.cpp
Author  : Gurung, Rabin
Date    : Apr. 25, 2017

Purpose : Obtain government weather data, and edit 
          the data with excel.

          In c++, introduce a data structure.
  
          Pass by reference among c++ functions an
          array based on a structure.
 
          Input data from a file and store the 
          data in an array  based on a structure
    
          Output data to the console from an array
          based on a structure.

Problem : On our course website, see
          Files, 4-Output.
     
          Alternately, in this program, see the 
          "PutHead" function.

Data
Sources : On our course website, see 
          Files, 3-Instructions.

Submit  : Simultaneously submit: 
          -- source (.cpp) program file
          -- input  (.in ) data    file
*/

//**********************************************
//Preprocessor Directives
//**********************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//Strucutre and constant
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

struct Weather         //Weather record
{
  string loc;          //Location
  
  int   year;          //Year
  int   mon;           //MOnth 
  
  float rain;          //Rainafall   (month total)
  float temp;          //Temperature (month mean)
};                     //semicolon

const int SIZE = 84;   //Maximum seven years of
                       //Monthly data

//****************************************************
//Function prototypes
//****************************************************

void   putHead();
string getName();
int    getData(string, Weather []);   //cap W
void   putData(int, Weather []);  
void   putFoot(int, Weather []);

//*****************************************************
//Main Routine
//*****************************************************

int main()
{
  //Declare the variables
  
  string   ifname;    //Name  of input   file
  
  int      count;     //Count of input   records
 
  Weather  w[SIZE];   //Array of weather records

  //Call level one functions
  
  putHead();
   
  ifname  = getName (); 
  
  count   = getData (ifname, w);
  
  putData (count, w);
  
  putFoot(count, w);

  //To the console send back zero to the operating system

  return 0;
}

//********************************************************
//Level 1 Functions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void putHead()
{
  //To the console, output program headings
  //(title and description)

  cout <<                                         endl;
  cout <<"Weather Program"                     << endl; 
  cout <<"----------------------------------"  << endl;
  cout <<                                         endl; 
  cout <<"For one weather reporting location," << endl;
  cout <<"and for each year and month on file,"<< endl; 
  cout <<"this program displays a rainfall "   << endl;
  cout <<"amount and a mean temperature, "     << endl;
  cout <<"followed by totals."                 << endl;
  cout <<                                         endl;
}

string getName()
{
  //Declare the variables
  
  string   ifname;  //Input file name
  ifstream fin;     //Input file object

  //From the console, input a file name
 
  while (true)
  {
    cout << "Input file name? ";
    cin  >>  ifname;

    fin.open (ifname);

    if (fin.good())
    {
      fin.close ();
      break; 
    }
    else 
      cout << "Invalid \a\n";
  }
  
  cout << endl; 
  
  return ifname;
} 

int getData (string ifname, Weather w[])
{
  //Declare and initialize variables
 
  ifstream fin;   //Input file object
  
  int     i;      //Array index
  int count;      //Record count
  
  i = 0;

  //From the input file, get records (rows) of
  //monthly weather data and store them in one
  //array with multiple fields (columns)
  
  fin.open (ifname);
  
  while (fin >> w[i].loc)
  {  
    fin >> w[i].year;
    fin >> w[i].mon;
    fin >> w[i].rain;
    fin >> w[i].temp;

    i++;
  }
  
  fin.close (); 
  
  count = i;
  
  return count;
}

void putData (int count, Weather w[])
{
  //Declare the variable
   
  int   i;   //Array index
  
  //TO the console, output records (lines) of
  //monthly weather data from the weather array
  
  cout <<"Loc  Year   Mon    Rain    Temp" << endl; 
  cout <<"---  ----   ---   -----   -----" << endl;
   
  cout << fixed << showpoint;
  
  for (i = 0; i < count; i++)
  {
    cout << setw(5) << left  << w[i].loc;
    cout << setw(4) << right << w[i].year;
    cout << setw(6) << right << w[i].mon;
 
    cout << setprecision(2);
    cout << setw(8) << right << w[i].rain;
  
    cout << setprecision (1);
    cout << setw(8) << right << w[i].temp << endl;
  } 
}

void putFoot(int count, Weather w[])
{
  //Declare and initialize varaibless
  
  int i;     //Array index
  
  float totrain;  //Total rain
  float tottemp;  //Total temperature
 
  totrain  = 0.00;
  tottemp  = 0.0;
  
  for (i = 0; i < count; i++)
  {
    totrain += w[i].rain;
    tottemp += w[i].temp;
  }
  
  cout << fixed << showpoint;

  cout << endl;
  
  cout << setw(10)            << "Total"   << "  ";
  cout << setprecision (2);
  cout << setw(11)  << right <<  totrain  << "  ";
  cout << setprecision(1);
  cout << setw(6) << right   <<  tottemp  << "  "; 
  cout << endl;
}