/*
*  DateTime.h                                
*
*  COSC 052 Fall 2018
*  Project #2
*
*  Due on: OCT 11, 2018
*  Author: waw23
*
*
*In accordance with the class policies and Georgetown's
*  Honor Code, I certify that, with the exception of the
*  class resources and those items noted below, I have neither
*  given nor received any assistance on this project.
*
*  References not otherwise commented within the program source code.
*  Note that you should not mention any help from the TAs, the professor,
*  or any code taken from the class textbooks.
*/

#ifndef _COSC052_FALL2018_P2_DATE_TIME_H_
#define _COSC052_FALL2018_P2_DATE_TIME_H_

//#define DEBUG_DATE

#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>


using std::invalid_argument;
using std::cout;
using std::endl;
using std::string; 
using std:: ostream; 
using std:: istream; 
using std::ostringstream; 
 
enum MONTH_LIST {DUMMY, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

 // use minimum values as defaults when necessary

const int MAX_DD[] =  { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MIN_DD = 1;
const int MIN_YYYY = 1492;
const int MAX_YYYY = 2192;
const int MIN_MM = 1;
const int MAX_MM = 12;

const int MIN_HOUR = 0;
const int MAX_HOUR = 24;    // assumes that 24:00 is valid for midnight, 00:00 would also be valid
const int MIN_MINUTE = 0;
const int MAX_MINUTE = 59;

const string ERR_DD_INVALID_P1 = "The day value is outside of acceptable range ";
const string ERR_MM_INVALID_P1 = "The month value is outside of acceptable range ";
const string ERR_MM_INVALID_P2 = "( 1 <= month <= 12 )\n";
const string ERR_YY_INVALID_P1 = "The year value is outside of acceptable range ";
const string ERR_YY_INVALID_P2 = "( 1492 <= year <= 2192 )\n";

/****************************************************************************
****************************************************************************
**                                                                        **
**                     class Date declaration                             **
**                                                                        **
**                 This code is provided to students                      **
**                 in COSC 052 Fall 2018 to use in                        **
**                 part or in total for class projects.                   **
**                 Students may use this code as their                    **
**                 own, without any attribution.                          **
**                                                                        **
****************************************************************************
****************************************************************************/

 

class Date
{
    friend std::istream& operator>>(std::istream&, Date&) throw (invalid_argument);
    friend std::ostream& operator<<(std::ostream&, const Date&);
    
    public:
    Date(int=MIN_YYYY, int=MIN_MM, int=MIN_DD) throw (invalid_argument); //yyyy, mm, dd default constructor
    Date(const Date&) throw (invalid_argument); // copy constructor 
    void setDate(int, int, int) throw (invalid_argument);  //yyyy, mm, dd
    void setDate(const Date&) throw (invalid_argument);
    Date operator=(const Date&) throw (std::invalid_argument);
    int getYear() const{return yyyy;}
    int getMonth() const{return mm;}
    int getDay() const{return dd;}
    bool operator ==(const Date&) const;
    bool operator !=(const Date&) const;
    bool operator <=(const Date&) const;
    bool operator <(const Date&) const;
    bool operator >=(const Date&) const;
    bool operator >(const Date&) const;

    private:

    int yyyy; 
    int mm;   
    int dd;   
}; //end class Date
 
 /****************************************************************************
 ****************************************************************************
 **                                                                        **
**                 class Time declaration                                 **
**                                                                        **
**                 This code is provided to students                      **
**                 in COSC 052 Fall 2018 to use in                        **
*                 part or in total for class projects.                   **
**                 Students may use this code as their                    **
**                 own, without any attribution.                          **
**                                                                        **
****************************************************************************
****************************************************************************/

class Time
{
    friend std::istream& operator>>(std::istream &in, Time &t) throw (invalid_argument);
    //Overloaded stream extraction operator
    //Postcondition: Extracts values for each data member from 
    //the input stream.  Format of the data in the stream 
    //is assumed to be:  hh:mm
    //The delimiting character is read and discarded.
    
    friend std::ostream& operator<<(std::ostream &os, const Time &t);
    //Overloaded stream insertion operator.
    //Postcondition: The time is output to the steam.  Delimiting 
    //character is replaced.  The result is a time value
    //output in the same format as was read in (except values less than
    //10 shall be right padded with a 0 which may not have been
    //what was read in).
   
    private:

    int hh; 
    int mm; 
    public:
    Time(int = MIN_HOUR, int = MIN_MINUTE) throw (invalid_argument);
    //constructor with parameters, with default values
    //This constructor calls the member function setTime()
    //and passes the same arguments as were passed in to
    //the constructor, function setTime() updates the data members.
    //Postcondition: Sets the values of hh and mm
    //according to the values of the arguments passed in.
    //If no values are passed, this acts as the default constructor
    //all integer data members are set to zero  
    
    void setTime(int, int) throw (invalid_argument);
    //Function to set the values of the object data members,
    //can be called directly or by a constructor.
    //Postcondition: Data members are set to the values
    //of the respective arguments passed in.
     
    int getHour() const {return hh;}  
    //In-line function to return the hour value.
    //Postcondtion: The value of data member hh is retured. 
    
     int getMinute() const {return mm;}  
    //In-line function to return the minute value.
     //Postcondtion: The value of data member mm is retured.
     
     Time operator=(const Time&);
     //Overloaded assignment operator.
     //Postcondtion: The values of right hand side object's
     //data members are copied to the respective data
     //members of the left hand side object.
    
    }; //END class Time declaration

#endif  /*  _COSC052_FALL2018_P1_DATE_TIME_H_  */