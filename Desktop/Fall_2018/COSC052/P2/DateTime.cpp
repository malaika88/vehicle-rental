/*
*  DateTime.cpp                              
*
*  COSC 052 Fall 2018
*  Project #2
*
*  Due on: OCT 11, 2018
*  Author: mmn60
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

#include "DateTime.h"

/****************************************************************************
****************************************************************************
**                                                                        **
**                     class Date implementation                          **
**                                                                        **
**                                    									  **
****************************************************************************
****************************************************************************/

std::istream& operator>>(std::istream &in, Date &d)  throw (invalid_argument)
{
   
    
    char ch;
    int year;
    int month;
    int day; 
    
    // if stream is originally in a failed throw an exception
    // this is thrown outside of the try block so it will not be
    // handled locally, but will immediately pass control back
    // to the calling function
    
    std::string errInStream = "ERROR: in Date class overloaded operator>>\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";
    if (!in)
    {
        throw std::invalid_argument(errInStream);
    }
    
    try
    {
        bool streamFailed = false;
        
        in >> year; //extract the hours and store them in local variable
        if (!in) { streamFailed = true; }
        
        in >> ch; //extract and discard the dilimiting character
        if (!in) { streamFailed = true; }

        in >> month; //extract the hours and store them in local variable
        if (!in) { streamFailed = true; }

        in >> ch; //extract and discard the dilimiting character
        if (!in) { streamFailed = true; }
        
        in >> day; //extract the minutes and store them in local variable
        if (!in) { streamFailed = true; }
        
        // if stream entered a failed state while extracting values
        // throw an exception
        // this is thrown inside of the try block so it will be
        // handled locally
        // in this case, local processing does not rethrow
        // this technique assumes that the point in the program from which
        // the overloaded stream extraction operator was called will test
        // for the stream being in a failed state after the function
        // call and take appropriate action
        
        if(streamFailed)
        {
            std::string errInStream = "WARNING: in Date class overloaded operator>>\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "time object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }
        
        d.setDate(year,month, day); // call setDate method where validation will take place
    }
    catch (std::runtime_error rte1)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Date class overloaded operator>>\n";
        std::cout << rte1.what() << endl;
        // allow processing to continue, do not re-throw
    }
    catch (std::invalid_argument ia1)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in Date class overloaded operator>>\n";
        std::cout << ia1.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Date class overloaded operator>>\n";
        throw;
    }
    
    return in;
    
} //END overloaded stream extraction operator for Time class

std::ostream& operator<<(std::ostream &os, const Date &d)
{
    os << std::setfill('0');
    
    os << std::setw(2) << d.yyyy << "/";
    os << std::setw(2) << d.mm<< "/";
    os << std::setw(2) <<d.dd;
    os << std::setfill(' ');
    
    return os;
    
} //END overloaded stream insertion operator for Time class


Date::Date(int year, int month, int day) throw (invalid_argument)
{
#ifdef DEBUG_DATE
    //std::cout << "Entered constructor Date::Date(int, int,int)" << std::endl;
#endif
    
    // call method setTime where data validation will be accomplished
    
    setDate(year,month, day);
    
#ifdef DEBUG_DATE
    //std::cout << "Exiting constructor Date::Date(int, int,int)" << std::endl;
#endif
    
} //END constructor with parameters for Date class

Date::Date(const Date& otherDate) throw (invalid_argument)
{
	setDate(otherDate.yyyy,otherDate.mm, otherDate.dd);
}// end copy constructor 


void Date::setDate(int year, int month,int day) throw (invalid_argument)
{
	//cout<< "Entered Date::setDate"<<endl;
    // use string stream to generate message with heterogeneous data types
		ostringstream combinedStrm;
		combinedStrm << "Exception thrown from "; 
		combinedStrm << "Date::setDate(" << month << ", " << day << ", " << year << ")\n";
		string combinedMessage = combinedStrm.str();
		
		// use stringstream object to create better error messages
		ostringstream monthRange;
		monthRange << "Exception thrown from ";
		monthRange << "Date::setDate(" << month << ", " << day << ", " << year << ")\n";
		monthRange << "" << ERR_MM_INVALID_P1 << " ";  // constant defined in date.h
		monthRange << "Entered: " << month << ", ";
		monthRange << "Valid: ";
		monthRange << "[" << MIN_MM << ", " << MAX_MM << "]\n";
		
		// the complete error message is a combination of a constant generic message
		// and the variable part that was created above using the stringstream
		string monthErrorMsg = monthRange.str();

		
		ostringstream dayRange;
		dayRange << "Exception thrown from ";
		dayRange << "Date::setDate(" << month << ", " << day << ", " << year << ")\n";
		dayRange << "" << ERR_DD_INVALID_P1  << " ";  // constant defined in date.h
		dayRange << "Entered: " << day << ", ";
		dayRange << "Valid: ";
		dayRange << " February:[" << MIN_DD <<","<< MAX_DD[2]<<"]\n";
		dayRange << "January,March,May,July,August,October,December:[" <<MIN_DD ;
		dayRange << "," << MAX_DD[1]<<"]\n";
		dayRange << "April, June, September, November:[" <<MIN_DD << ","<< MAX_DD[4]<<"]\n";
		
		// the complete error message is a combination of a constant generic message
		// and the variable part that was created above using the stringstream
		string dayErrorMsg = dayRange.str();
		
		
		ostringstream yearRange;
		yearRange << "\tException thrown from ";
		yearRange << "Date::setDate(" << month << ", " << day<< ", " << year << ")\n";
		yearRange << "\t" << ERR_YY_INVALID_P1 << " ";  // constant defined in date.h
		yearRange << "Entered: " << year << ", ";
		yearRange << "Valid: ";
		yearRange << "[" << MIN_YYYY<< ", " << MAX_YYYY << "]\n";
		
		// the complete error message is a combination of a constant generic message
		// and the variable part that was created above using the stringstream
		string yearErrorMsg = yearRange.str();
		
    
    
    // set data members to default values, if values passed
    // in to the parameters pass validation, then the
    // data members will be updated
    yyyy = MIN_YYYY;
    mm = MIN_MM;
    dd = MIN_DD;

    bool badDate = false;
    
    if (year < MIN_YYYY || year > MAX_YYYY)
    {
    	throw invalid_argument(yearErrorMsg); 
    	combinedMessage += yearErrorMsg; 
    	badDate = true;
    }

    if (month < MIN_MM || month > MAX_MM)
    {
    	throw invalid_argument(monthErrorMsg); 
    	combinedMessage+= monthErrorMsg; 
    	badDate = true; 
    }
   
 	if (day < MIN_DD || day > MAX_DD[month])
 	{
 		throw invalid_argument(dayErrorMsg);
 		combinedMessage+= dayErrorMsg; 
 		badDate= true; 
 	}
	if (badDate == true)
	{
		throw invalid_argument (combinedMessage); 
	}
    
    // all parameters are valid, update object's data members
    yyyy= year;
    mm = month;
    dd = day;
} //END member function Date::setDate

	void Date :: setDate(const Date& otherDate) throw (invalid_argument)
	{
		setDate(otherDate.yyyy, otherDate.mm,otherDate.dd); 
		yyyy= otherDate.yyyy; 
		mm = otherDate.mm; 
		dd = otherDate.dd; 

	}//END overloaded member function Date:: setDate

	Date Date:: operator=(const Date& rhsObj ) throw (std::invalid_argument)
	{
		if (this != &rhsObj)
		{
	    // not a self assignment, OK to proceed
	    // call method setDate where validation will be accomplished
	    
			setDate(rhsObj.yyyy, rhsObj.mm,rhsObj.dd);
		}
		//THROW IF PARAMETERS FAIL VALIDATION
		return *this;
	}// END operator=

	bool Date::operator ==(const Date& rhsObj) const
	{
		bool answer = false;
		answer = this->mm == rhsObj.mm && this->dd == rhsObj.dd && this->yyyy == rhsObj.yyyy;
		return answer;
    
	}//END operator ==

    bool Date::operator !=(const Date& rhsObj) const
	{
		bool answer = false; 
		answer = !( *this == rhsObj );
		answer = this->mm != rhsObj.mm || this->dd != rhsObj.dd || this->yyyy != rhsObj.yyyy;
		return answer;
	} // END operator !=

	bool Date::operator <=(const Date& rhsObj) const
	{
		bool answer = false; 
		if (this -> yyyy < rhsObj.yyyy )
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm < rhsObj.mm)
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm == rhsObj.mm && this-> dd < rhsObj.dd)
		{
			answer= true;
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm == rhsObj.mm && this ->dd == rhsObj.dd)
		{
			answer = true; 
		}
		return answer; 
	}
    bool Date:: operator <(const Date& rhsObj) const
    {
    	bool answer = false; 
		if (this -> yyyy < rhsObj.yyyy )
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm < rhsObj.mm)
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm == rhsObj.mm && this-> dd < rhsObj.dd)
		{
			answer= true;
		}
		return answer; 
    }
    bool Date::operator >=(const Date& rhsObj) const
    {
    	bool answer = false; 
		if (this -> yyyy > rhsObj.yyyy )
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm > rhsObj.mm)
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm == rhsObj.mm && this-> dd > rhsObj.dd)
		{
			answer= true;
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm == rhsObj.mm && this ->dd == rhsObj.dd)
		{
			answer = true; 
		}
		return answer; 
    }
    bool Date:: operator >(const Date& rhsObj) const
    {
    	bool answer = false; 
		if (this -> yyyy > rhsObj.yyyy )
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm > rhsObj.mm)
		{
			answer = true; 
		}
		if (this -> yyyy == rhsObj.yyyy && this -> mm == rhsObj.mm && this-> dd > rhsObj.dd)
		{
			answer= true;
		}
		return answer; 
    }

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Time implementation code                         **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2018 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                    Time class default constructor                        *
 ****************************************************************************/

/**
 * <P>Constructor with parameters, also default constructor since all
 * parameters have default values.</P>
 * <P>Sets the hh and mm data members to values passed to parameters.</P>
 * <P>Uses 24-hour format so 24:00 is midnight, 12:00 is noon, 13:00 is 1:00 pm, etc.</P>
 * <P>Should call the setTime method with integer parameters
 * to perform validation testing and actually initialize hh and mm
 * if all values pass validation.</P>
 *
 * @param  hour an int value in [0, 24]
 * @param  minute an int value in [0, 59]
 * @throws invalid_argument if any parameter fails validation
 */

Time::Time(int hour, int minute) throw (invalid_argument)
{
#ifdef DEBUG_DATE
    std::cout << "Entered constructor Time::Time(int, int)" << std::endl;
#endif
    
    // call method setTime where data validation will be accomplished
    
    setTime(hour, minute);
    
#ifdef DEBUG_DATE
    std::cout << "Exiting constructor Time::Time(int, int)" << std::endl;
#endif
    
} //END constructor with parameters for Time class



/****************************************************************************
 *                  Time class member function setTime                      *
 ****************************************************************************/

/**
 * <P>Member function to set the hh and mm data members to
 * to the values passed in to the two integer parameters.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  hour an int value
 * @param  minute an int value
 * @throws invalid_argument if any parameter fails validation
 */

void Time::setTime(int hour, int minute) throw (invalid_argument)
{
    // use string stream to generate message with heterogeneous data types
    // see code in if(badArguments) block
    std::ostringstream errStrm;
    
    // set data members to default values, if values passed
    // in to the parameters pass validation, then the
    // data members will be updated
    hh = MIN_HOUR;
    mm = MIN_MINUTE;
    
    bool badArguments = false;
    
    if ( hour < MIN_HOUR || minute < MIN_MINUTE || hour > MAX_HOUR || minute > MAX_MINUTE )
    {
        // one on more of the values passed in are not valid
        badArguments = true;
    }
    else if ( hour == MAX_HOUR && minute > 0 )
    {
        // if the value passed for hour is 24, then the only valid value for minutes is 0
        badArguments = true;
    }
    
    if (badArguments)
    {
        // one or more parameters are not valid, throw an exception
        // note that we do not need a try block to throw the exception since
        // we do not plan to handle the exception within Time::setTime
        // control will immediately return to the calling function
        
        errStrm << "ERROR: in method Time::setTime( " << hour << ", " << minute << " )\n";
        errStrm << "hour set to MIN_HOUR (" << MIN_HOUR << "), ";
        errStrm << "minute set to MIN_MINUTE (" << MIN_MINUTE << ")\n";
        std::string errTime = errStrm.str();
        
        std::invalid_argument ia1(errTime);
        throw ia1;
    }
    
    // both parameters are valid, update object's data members
    
    hh = hour;
    mm = minute;
    
} //END member function Time::setTime



/****************************************************************************
 *                 Time class stream extraction operator                    *
 ****************************************************************************/

/**
 * <P>friend function, overloaded stream extraction operator</P>
 * <P>Extracts values for a Time object's data members
 * from the input stream.</P>
 * <P>The input format is assumed to hh:mm, be aware that
 * the minute will always be a 2-digit number, right padded with
 * a 0 if necessary, hour values could be either 2-digit or 1-digit numbers.</P>
 * <P>After the values are extracted, the modified input stream is returned.</P>
 * <P>Should call the setTime method with integer parameters
 * to perform validation testing and actually update hh and mm
 * if all values pass validation.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  in  the input stream for extraction
 * @param  t  the Time object for storing the extracted information
 * @return  the modified input stream
 * @throws invalid_argument if an argument's value is invalid
 */

std::istream& operator>>(std::istream &in, Time &t)  throw (invalid_argument)
{
    // input format is expected to be hh:mm
    // examples:
    // 24:00 for midnight
    // 12:00 for noon
    // 2:45 45 minutes past 2 am
    // 14:45 45 minutes past 2 pm
    // etc.
    
    char ch;
    int hour = -1;
    int minute = -1;
    
    // if stream is originally in a failed throw an exception
    // this is thrown outside of the try block so it will not be
    // handled locally, but will immediately pass control back
    // to the calling function
    
    std::string errInStream = "ERROR: in Time class overloaded operator>>\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";
    if (!in)
    {
        throw std::invalid_argument(errInStream);
    }
    
    try
    {
        bool streamFailed = false;
        
        in >> hour; //extract the hours and store them in local variable
        if (!in) { streamFailed = true; }
        
        in >> ch; //extract and discard the dilimiting character
        if (!in) { streamFailed = true; }
        
        in >> minute; //extract the minutes and store them in local variable
        if (!in) { streamFailed = true; }
        
        // if stream entered a failed state while extracting values
        // throw an exception
        // this is thrown inside of the try block so it will be
        // handled locally
        // in this case, local processing does not rethrow
        // this technique assumes that the point in the program from which
        // the overloaded stream extraction operator was called will test
        // for the stream being in a failed state after the function
        // call and take appropriate action
        
        if(streamFailed)
        {
            std::string errInStream = "WARNING: in Time class overloaded operator>>\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "time object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }
        
        t.setTime(hour, minute); // call setTime method where validation will take place
    }
    catch (std::runtime_error rte1)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Time class overloaded operator>>\n";
        std::cout << rte1.what() << endl;
        // allow processing to continue, do not re-throw
    }
    catch (std::invalid_argument ia1)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in Time class overloaded operator>>\n";
        std::cout << ia1.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Time class overloaded operator>>\n";
        throw;
    }
    
    return in;
    
} //END overloaded stream extraction operator for Time class



/****************************************************************************
 *                 Time class stream insertion operator                     *
 ****************************************************************************/

/**
 * <P>overloaded stream insertion operator.</P>
 * <P>Inserts a Time object into the output stream
 * and returns the modified output stream.</P>
 * <P>The output format is the same as the input format expected
 * by the overloaded stream extraction operator: hh:mm, unlike
 * the stream extraction operator, the stream insertion operator
 * shall always output hours and minutes having 2-digits (use right
 * padding with a 0 for hours and minutes less than 10)</P>
 *
 * @param  os  the output stream for insertion
 * @param  t   the Time object for insertion
 * @return  the modified output stream
 */

std::ostream& operator<<(std::ostream &os, const Time &t)
{
    os << std::setfill('0');
    
    os << std::setw(2) << t.hh << ":";
    os << std::setw(2) << t.mm;
    
    os << std::setfill(' ');
    
    return os;
    
} //END overloaded stream insertion operator for Time class



/****************************************************************************
 *                     Time class assignment operator                       *
 ****************************************************************************/

/**
 * <P>Overloaded assignment operator.</P>
 * <P>Sets the hh amd mm data members to values of the corresponding
 * data members of the Time object passed in as a parameter.</P>
 * <P>Should test for self assignment (not an issue with this class, but
 * good habit nevertheless).</P>
 * <P>Should call the setTime method with integer parameters
 * to perform validation testing and actually update hh and mm
 * if all values pass validation.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  rhsObj a Time object
 * @throws invalid_argument if any parameter fails validation
 */

Time Time::operator=(const Time &rhsObj)
{
    if (this != &rhsObj)
    {
        // not a self assignment, OK to proceed
        // call method setTime where validation will be accomplished
        
        setTime(rhsObj.hh, rhsObj.mm);
    }
    
    return *this;
    
} //END overloaded assignment operator for Time class


