//Application: Calculator
//Author: Preeti
//Calculator functions are written in C++ and are exposed to Python

#include <iostream>
#include <conio.h>
#include <boost/python.hpp>

using namespace std;
using namespace boost::python;


string userName;
void GetUserName()
{
   cout<<"Please enter your name:\n";
   cin>>userName;
}

void Greet(string name)
{
   GetUserName();
   cin.clear();
   cin.ignore(100000, '\n');
   system("cls");
   cout<<"\nHello "<<userName<<"...\n\n";
}

void SayAboutApplication()  //Expose it to Python
{
   Greet(userName);
   cout<<"Here is the details about the application\n";
   cout<<"--------------------------------------------\n";
   cout<<"Application  : Simple Calculator\n";
   cout<<"Author       : Preeti\n";
   cout<<"Details      : Calculator functions are written in C++ and are exposed to Python\n";
   cout<<"               You are using C++ through python !!! \n\n";
//    cout<<"\n\nPress any key to continue ...";
//    getch();
}



class MyCalculator
{
private:
   double num1,num2;
public:
   MyCalculator(double n1, double n2)
   {
      num1 = n1;
      num2 = n2;
   }
   void Add()
   {
      cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
   }
   void Subtract()
   {
      cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl;
   }
   void Multiply()
   {
      cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
   }
   void Divide()
   {
      if( (int)num2==0)
      {
         cout<<"Cannot divide by zero";
      }
      else
         cout<<num1<<"/"<<num2<<"="<<num1/num2<<endl;
   }

};
BOOST_PYTHON_MODULE(Calculator)
{

   def("SayAboutApplication", SayAboutApplication);

   class_<MyCalculator>("MyCalculator", init<double,double>())
      .def("Add", &MyCalculator::Add)
      .def("Subtract", &MyCalculator::Subtract)
      .def("Multiply", &MyCalculator::Multiply)
      .def("Divide", &MyCalculator::Divide)
      ;
}


//Settings done in Visual Studio 
//In Project property
   //1. Set c/c++ -> General -> Additional include directory as 'C:\Boost\boost_1_47_0;C:\Python27\include'
   //2. Set Linker -> General -> Additional library directory  as 'C:\Boost\boost_1_47_0\lib;C:\Python27\libs'
   //3. Set Linker -> General -> Output File as '$(OutDir)\Calculator.pyd' . 
         //Here pyd file name(here Calculator) should be same as the name exposed to python from C++ ie. argument of BOOST_PYTHON_MODULE() 
   //It builds, but cannot import. Dependency walker can be used to check dependencies
   //So added 'boost_python-vc90-mt-1_47.dll' from Boost to Release folder of VS solution. It should enable import in python