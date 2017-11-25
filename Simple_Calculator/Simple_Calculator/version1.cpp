#include <iostream>
#include <conio.h>

#include <boost/python.hpp>

using namespace std;


string userName;
void GetUserName()
{
   cout<<"Please enter your name:\n";
   cin>>userName;
}
void SayAboutApplication()
{
   GetUserName();
   //clrscr();
   cout<<"Hello "+userName+"...\n\n";
   cout<<"Here is the details about the application\n";
   cout<<"Application: Simple Calculator\nAuthor: Preeti\nWhat's special here?? - Calculator functions are written in C++ and are exposed to Python\n\n";
}

BOOST_PYTHON_MODULE(Calculator)
{
   using namespace boost::python;

   def("SayAboutApplication", SayAboutApplication);
}






//Settings done in VS
//In Project property
//1. Set c/c++ -> General -> Additional include directory as 'C:\Boost\boost_1_47_0;C:\Python27\include'
//2. Set Linker -> General -> Additional library directory  as 'C:\Boost\boost_1_47_0\lib;C:\Python27\libs'
//3. Set Linker -> General -> Output File as '$(OutDir)\Calculator.pyd' . 
//Here pyd file name(here Calculator) should be same as the name exposed to python from C++ ie. argument of BOOST_PYTHON_MODULE() 
//It builds, but cannot import. Dependency walker can be used to check dependencies
//So added 'boost_python-vc90-mt-1_47.dll' from Boost to Release folder of VS solution. It should enable import in python