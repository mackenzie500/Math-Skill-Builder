//Sample Functional Decomposition Phase 1 (Math Skill Builder)
#include <iostream>
#include <cstdlib>       //for srand
#include <ctime>         //to seed the random number
#include <cmath>         //for geometric expressions
#include <iomanip>       //formatted display
using namespace std;

//program user interface in main
void programInfo();//function prototype with no refernce parameters
void mathSkillBuilderMenu (/*out*/ int& choice);
/*
function prototype shows position of one datatype as refernce parameters and the direction of dataflow
pre: none
post: choice = user input meaning that the user must choose the choice
*/

void processProbSets (/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect);
/*
function prototype shows position of three datatypes as refernce parameters and the direction of dataflow
pre: choice is assigned
post: number of problem sets depends on user input and the number that is correct all get outputted
*/
void printReportEmbellishments ();
//function prototype with no refernce parameters, pre: none, post: none
void generateOperands (/*out*/ double& num1,/*out*/ double& num2);
/*
function prototype shows position of two datatypes as refernce parameters and the direction of dataflow
pre: none
post: operands are num1 and num2, they are the random numbers that are generated
*/

void generategeoOperands (/*out*/ double& num1, /*out*/double& num2, /*out*/double& num3);
/*
function prototype shows position of three datatypes as refernce parameters and the direction of dataflow
pre: none
post: operands are num1, num2, and num3, they are the random numbers that are generated
*/

//function prototypes - note formal parameter list and direction of data flow 
void arithmeticProbSet (/*in*/ int numProbSets,/*out*/ int& correctCount);
/*
function prototype shows position of two datatypes as refernce parameters and the direction of dataflow
pre: the number of problem sets will detremine how many are correct
post: the correct count will go up if the user gets the problem right
*/
void geometryProbSet (/*in*/ int numProbSets, /*out*/ int& correctCount);
/*
function prototype shows position of two datatypes as refernce parameters and the direction of dataflow
pre: the number of problem sets will detremine how many are correct
post: the correct count will go up if the user gets the problem right
*/
void statisticsProbSet (/*in*/ int numProbSets,/*out*/ int& correctCount);
/*
function prototype shows position of two datatypes as refernce parameters and the direction of dataflow
pre: the number of problem sets will detremine how many are correct
post: the correct count will go up if the user gets the problem right
*/
int getNumSets ();
//gets the number of sets the user will do
double getUserInput ();
//stores the number the user writes as a decimal

//global constants
const int PROBSPERSET = 4;           //Number of Problems in each set
const int MIN_NUM = 1, MAX_NUM = 10; //preset range for random numbers
const double PI = 3.141593;          // use for geometry problems

int main()
{
 cout << showpoint << fixed << setprecision(2);//all numbers will appear to two decimal places
 srand(time(0));     //seed the random number generator

 int problem; int choice = 0, numProbSets = 0, numCorrect = 0; //all of these integers will begin at zero
  
programInfo();//the program information
mathSkillBuilderMenu (choice);//takes into consideration the users choice of problems

  while (choice!=4)
    //while the choice isn't 4 the program will generate the problems and results
  {
    processProbSets (choice,numProbSets,numCorrect);
    printReportEmbellishments ();
    mathSkillBuilderMenu (choice);
  }

    cout << "\n\nNow exiting MATH SKILL BUILDER program ...." << endl;
//if the user chooses 4, the program will end
 return 0;
  
}

/*
   The programInfo function provides a few details about the math skill builder program,
   the menu driven user interface, the type of skill sets and the problems in each set are
   generated and user response is assessed.
   pre: none
   post: Formatted display of program information displayed in console output
*/

void programInfo()
{
    cout << "                       MATH IS FUN                                            " << endl;
    cout << "The Math Skill Builder program will assess basic mathematics skills.          " << endl;
    cout << "Each Math skill builder set generates four problems using randomly            " << endl;
    cout << "generated numbers in the range of 1 to 10, stored as double values.\n         " << endl;
    cout << "The randomly generated numbers are to be used as operands or arguments        " << endl;
    cout << "for the various arithmetic, geometry or other problem types to be generated   " << endl;
    cout << "in each Math skill builder set. User response to a problem is compared to the " << endl;
    cout << "correct answer and an appropriate message is displayed.\n                     " << endl;

    cout << "A menu driven interface provides the user an opportunity to select a specific " << endl;
    cout << "Math Builder Skill set to try and the program interface design algorithms are " << endl;
    cout << "built with expandability in mind to allow for (1) additional problem sets or  " << endl;
    cout << "modules to be added or (2) additional different problem types in each set or  " << endl;
    cout << "(3) a larger random number range.\n                                           " << endl;

    cout << "Program Assertions: When comparing two double values with precision (for eg., " << endl;
    cout << "in comparing user response to the correct answer for a double quotient result " << endl;
    cout << "or mixed type calculation the user is reminded to provide a response rounded  " << endl;
    cout << "to two decimal places, as a precision criteria of less than .01 will be used  " << endl;
    cout << "to determine equality. Expect a few floating point representational errors.   " << endl; 
  
}

/*
  The mathSkillBuilderMenu function includes a formatted display of 4 menu choices and a
  leading prompt for user input is provided.

  Input validation is included for out of range choice or non alpha character input. With
  an appropriate message and a re-input is allowed. The validated input is passed
  through a reference parameter variable choice to the calling code.
  pre: none
  post: Formatted display of program information displayed. A value for reference parameter choice has been entered by the user and validated. Range validation (1-4) and a cin fail state will allow user to reenter a new value.
*/

void mathSkillBuilderMenu (/*out*/ int& choice)
//post, user has been prompted to input a value from 1-4 for a choice
{
     cout << setw(50) << "++++++++++++++++++++++++++++++++++++++++++ " << endl;
     cout << setw(50) << "- MATH SKILL BUILDER SETS - Select one -   " << endl;
     cout << setw(50) << "* 1. BASIC ARITHMETIC *                    " << endl;
     cout << setw(9) << char(227) << " 2. BASIC GEOMETRY "<< char(227) <<endl;
     cout << setw(50) << "% 3. BASIC STATISTICS %                    " << endl;
     cout << setw(50) << "\\ 4. EXIT MATH IS FUN \\                  " << endl;
     cout << setw(50) << "++++++++++++++++++++++++++++++++++++++++++ " << endl;
     
     cout << "\nSELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: ";
     cin >> choice;
//all of the different choices the user has
     while(choice < 1 || choice > 4 || !cin)
     {
        cin.clear();
        cin.ignore(200,'\n');
        cout << "OOPS, Invalid choice? " << endl;
        cout << "\nSELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: ";
        cin >> choice;
     }
}//if the choice is greater than 4 or less than 1, the program will output this

int getNumSets ()//will get the ammount of sets the user wants to attempt
{
int numProbSets  = 1; //default setting
  
  cout << "How many times you wish to attempt this current set (enter 1-5) : ";
  cin >> numProbSets;
  

if (numProbSets <=5 && numProbSets >=1)
{
    //input validation for number of problem sets
  cout << "Problem Set\n" << "---------------"<< endl;
}
  
  else
  {
    cout << "OOPS, Invalid input?\n" << 
"How many times you wish to attempt this current set (enter 1-5) : ";
    cin >> numProbSets;
  }

  return numProbSets;//will produce the ammount of sets the user inputted
}

void arithmeticProbSet (/*in*/ int numProbSets, /*out*/int& correctCount)
{//pre:numProbSets has been assigned, post: correctCount begins at 0 & is refernce parameter
   double num1 = 0, num2 = 0, userAnswer = 0, correctAnswer = 0;
   correctCount = 0;
  // all of the values will begin at zero
  for (int j = 1; j <= numProbSets; j++)
    //pretest loop evaluates the expression before each iteration
  {
    for (int problem = 1; problem <= PROBSPERSET; problem++)
    {//pretest loop evaluates the expression before each iteration
      generateOperands(num1, num2);//will generate the random numbers for each problem
      
        switch(problem)//user input is required for a selection 
        {
        case 1: cout << num1 << " + " << num2 << " = ";
          correctAnswer = num1 + num2;
        break;
          
        case 2: cout << num1 << " - " << num2 << " = ";
          correctAnswer = num1 - num2;
        break;
          
        case 3: cout << num1 << " * " << num2 << " = ";
          correctAnswer = num1 * num2;
        break;
          
        case 4: cout << num1 << " / " << num2 << " = ";
          correctAnswer = num1 / num2;
        break;
        }
      //all of the different poosible arithmetic problems
      
    cin >> userAnswer;//user input
      
    if (fabs(correctAnswer - userAnswer) < .01)//needed for comparing doubles
{
  cout << "Correct\n" << "---------------" << endl;
  
  correctCount++;
  // if the user inputs a correct answer, the correctCount will go up until there are no more problems
}
else
{
cout << "Incorrect. Correct answer displayed with precision of .01 = " << correctAnswer << endl;//if the user is wrong, the program will output the correct answer
    }
    }
  cout << "=======\n";
  }
  cout << "=======\n";
  }


void  geometryProbSet (/*in*/ int numProbSets, /*out*/ int& correctCount)
{/*
pre: numProbSets has been assigned post: correctCount is generated with referernce to parameter
*/
   double num1 = 0, num2 = 0, num3 = 0, userAnswer = 0, correctAnswer = 0;
   correctCount = 0;
//all of the values begin at 0 
  for (int j = 1; j <= numProbSets; j++)
    //pretest loop evaluates each expression before each iteration 
  {
    
  for (int problem = 1; problem <= PROBSPERSET; problem++)
  {//pretest loop evaluates each expression before each iteration
    
    generategeoOperands(num1, num2, num3);
    //will generate the random numbers for each problem
    
      switch(problem)//user input is required for a selection 
      {
        case 1: cout << "Calculate the area of a Triangle given base and height: "  
          << "Base = " << num1 << " Height = " << num2 << "\nArea of Triangle is: ";
          correctAnswer = (.5 * num1) * num2;
        break;
        
        case 2: cout << "Calculate the perimeter of a Triangle with three sides: " 
          << "side1 = " << num1 << " side2 = " << num2 << " side3 = " << num3 
          << "\nPerimeter of Triangle is: ";
          correctAnswer = num1 + num2 + num3;
        break;
        
        case 3: cout << "Calculate the perimeter of a Rectangle : " << "Length = " 
          << num1<< " and Width = " << num2 << "\nPerimeter of Rectangle is: ";
          correctAnswer = 2*(num1 + num2);
        break;
        
        case 4: cout << "Calculate the area of a Circle given radius: " << " Radius = " 
          << num1 <<  " and Pi(Ï) is " << 3.141593 
          << "\nType a response rounded to two decimal places below... "
          << "\nArea of Circle is: ";
          correctAnswer = PI*(num1*num1);
        break;
      }//the different geometric problems
    cin >> userAnswer;
    //user inputs the answers
    if (fabs(correctAnswer - userAnswer) < .01)//needed for comparing doubles
{
  cout << "Correct\n" << "---------------" << endl;
  correctCount++;
  //if the answer is correct the correctCounter goes up by one, marking the problem correct
}
else
    {cout << "Incorrect. Correct answer displayed with precision of .01 = " << correctAnswer << "\n----------------" << endl;
    }
    }
  cout << "=======\n";
    }//seprartors
  cout << "=======\n";
  }
   //get userResponse-compare answers and display appropriate message
   //increment correctCount if correct user 
void statisticsProbSet (/*in*/ int numProbSets,/*out*/ int& correctCount)
{
  /*
pre: numProbSets has been assigned post: the correctCount is generated using the refernce parameter correctCount
*/
   double num1 = 0, num2 = 0, userAnswer = 0, correctAnswer = 0;
   correctCount = 0;
//all of the values begin at 0
  
   cout << "\nStatistics Problem Set#" << numProbSets << "(EXTRA CREDIT ONLY)" << endl;
  cout << "-------------------------" <<endl;

  cout << PROBSPERSET <<" Statistics formulas to be coded...." <<endl;
  cout << "---------------------" << endl;
}//stats problems
void generateOperands(/*out*/ double& num1, /*out*/ double& num2)
{
//post: num1, num2 are randomly generated using refernce parameter of num1 and num2
  num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  num2 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
}
void generategeoOperands (/*out*/ double& num1, /*out*/double& num2, /*out*/double& num3)
{
  /*
post: num1, num2, and num3 are randomly generated using refernce parameter of num1 and num2
   */
  num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  num2 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  num3 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
  
}
void processProbSets (/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect)
{
  /*
pre: prompts the user for a choice post: uses that choice to generate the ammount of problems and what is correct to output the Problem set
*/
  switch(choice)//switch expression for the type of problems user wants to do
  {
    case 1:cout << "\nArithmetic Skill Sets" << endl;
    numProbSets = getNumSets();
      //Number of attempts on a Math Skill Builder set
     arithmeticProbSet(numProbSets, numCorrect); 
      //Math Skill Builder set function call with two arguments
    
 cout << "Basic Arithmetic Skill Set: You got " 
   << numCorrect << " correct out of "
 << PROBSPERSET * numProbSets << " for " 
   << (100 * numCorrect) / (PROBSPERSET * numProbSets) 
   << "%" << endl;;
    break;//how many the user got correct
    
    case 2:cout << "\nGeometry skill sets" << endl;
    numProbSets = getNumSets();    //Number of attempts on a Math Skill Builder set
    geometryProbSet (numProbSets, numCorrect); 
      //Math Skill Builder set function call with two arguments
    
 cout << "Basic Geometry Skill Set: You got " 
   << numCorrect 
   << " correct out of "
   << PROBSPERSET * numProbSets << " for " 
   << (100 * numCorrect) / (PROBSPERSET * numProbSets) 
   << "%" << endl;;
    break;//how many the user got correct
    
    case 3:cout << "\nBusiness statistics skill sets" << endl;
    numProbSets = getNumSets();    //Number of attempts on a Math Skill Builder set
    statisticsProbSet (numProbSets, numCorrect); 
    //Math Skill Builder set function call with 2 arguments;
    break;
    
    case 4:cout << "\n\nNow exiting MATH SKILL BUILDER program ...." << endl;;
    break;//leaving the program
  }
}

void printReportEmbellishments ()//no arguments or references, outputs a bar as a separator
{
  cout << "=============\n" << endl;
}
/*
  MATH IS FUN                                            
The Math Skill Builder program will assess basic mathematics skills.          
Each Math skill builder set generates four problems using randomly            
generated numbers in the range of 1 to 10, stored as double values.
         
The randomly generated numbers are to be used as operands or arguments        
for the various arithmetic, geometry or other problem types to be generated   
in each Math skill builder set. User response to a problem is compared to the 
correct answer and an appropriate message is displayed.
                     
A menu driven interface provides the user an opportunity to select a specific 
Math Builder Skill set to try and the program interface design algorithms are 
built with expandability in mind to allow for (1) additional problem sets or  
modules to be added or (2) additional different problem types in each set or  
(3) a larger random number range.
                                           
Program Assertions: When comparing two double values with precision (for eg., 
in comparing user response to the correct answer for a double quotient result 
or mixed type calculation the user is reminded to provide a response rounded  
to two decimal places, as a precision criteria of less than .01 will be used  
to determine equality. Expect a few floating point representational errors.   
       ++++++++++++++++++++++++++++++++++++++++++ 
       - MATH SKILL BUILDER SETS - Select one -   
       * 1. BASIC ARITHMETIC *                    
        � 2. BASIC GEOMETRY �
       % 3. BASIC STATISTICS %                    
         \ 4. EXIT MATH IS FUN \                  
       ++++++++++++++++++++++++++++++++++++++++++ 

SELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: 1

Arithmetic Skill Sets
How many times you wish to attempt this current set (enter 1-5) : 2
Problem Set
---------------
3.00 + 7.00 = 10
Correct
---------------
1.00 - 10.00 = -9
Correct
---------------
7.00 * 3.00 = 21
Correct
---------------
6.00 / 7.00 = .3
Incorrect. Correct answer displayed with precision of .01 = 0.86
=======
6.00 + 6.00 = 12
Correct
---------------
1.00 - 7.00 = -6
Correct
---------------
10.00 * 8.00 = 80
Correct
---------------
4.00 / 2.00 = 2
Correct
---------------
=======
=======
Basic Arithmetic Skill Set: You got 7 correct out of 8 for 87%
=============

       ++++++++++++++++++++++++++++++++++++++++++ 
       - MATH SKILL BUILDER SETS - Select one -   
       * 1. BASIC ARITHMETIC *                    
        � 2. BASIC GEOMETRY �
       % 3. BASIC STATISTICS %                    
         \ 4. EXIT MATH IS FUN \                  
       ++++++++++++++++++++++++++++++++++++++++++ 

SELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: 2

Geometry skill sets
How many times you wish to attempt this current set (enter 1-5) : 1
Problem Set
---------------
Calculate the area of a Triangle given base and height: Base = 10.00 Height = 7.00
Area of Triangle is: 35
Correct
---------------
Calculate the perimeter of a Triangle with three sides: side1 = 8.00 side2 = 4.00 side3 = 3.00
Perimeter of Triangle is: 15
Correct
---------------
Calculate the perimeter of a Rectangle : Length = 9.00 and Width = 4.00
Perimeter of Rectangle is: 26
Correct
---------------
Calculate the area of a Circle given radius:  Radius = 7.00 and Pi(Ï) is 3.14
Type a response rounded to two decimal places below... 
Area of Circle is: 147
Incorrect. Correct answer displayed with precision of .01 = 153.94
----------------
=======
=======
Basic Geometry Skill Set: You got 3 correct out of 4 for 75%
=============

       ++++++++++++++++++++++++++++++++++++++++++ 
       - MATH SKILL BUILDER SETS - Select one -   
       * 1. BASIC ARITHMETIC *                    
        � 2. BASIC GEOMETRY �
       % 3. BASIC STATISTICS %                    
         \ 4. EXIT MATH IS FUN \                  
       ++++++++++++++++++++++++++++++++++++++++++ 

SELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: 3

Business statistics skill sets
How many times you wish to attempt this current set (enter 1-5) : 1
Problem Set
---------------

Statistics Problem Set#1(EXTRA CREDIT ONLY)
-------------------------
4 Statistics formulas to be coded....
---------------------
=============

       ++++++++++++++++++++++++++++++++++++++++++ 
       - MATH SKILL BUILDER SETS - Select one -   
       * 1. BASIC ARITHMETIC *                    
        � 2. BASIC GEOMETRY �
       % 3. BASIC STATISTICS %                    
         \ 4. EXIT MATH IS FUN \                  
       ++++++++++++++++++++++++++++++++++++++++++ 

SELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: 4


Now exiting MATH SKILL BUILDER program ....
*/