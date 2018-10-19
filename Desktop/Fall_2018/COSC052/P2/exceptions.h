/*
 *  exceptions.h
 *
 *  COSC 052 Fall 2018
 *  Project #2
 *
 *  Due on: OCT 11, 2018
 *  Author: mmn60
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */



#ifndef _COSC052_FALL2018_P2_EXCEPTIONS_H_
#define _COSC052_FALL2018_P2_EXCEPTIONS_H_



#include <iostream>
#include <stdexcept>
#include <exception>


using std::invalid_argument;
using std::string;



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class bad_vehicle_code declaration                     **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2018 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

/**
 * <P>The <code>bad_vehicle_code</code> class.</P>
 *
 * <P>This is a user-defined exception class derived from the system 
 * exception class <code>invalid_argument</code>.  As with any derived class, 
 * <code>bad_vehicle_code</code> inherits all of the members of its base class 
 * <code>invalid_argument</code>.  Also, as with any derived class <code>bad_vehicle_code</code>
 * has the option to add any members it may need.  However, in this case, the 
 * derived class really does not need any additional members.  We simply want
 * a new class to provide additional specificity when throwing exceptions.</P>
 *
 * <P>Class <code>bad_vehicle_code</code> does provide its own constructor having a 
 * single string parameter.  We shall use this string parameter as the argument to
 * a call to the base class constructor via a member initialization list 
 * in the heading of the implementation code for <code>bad_vehicle_code's</code>
 * constructor.
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1, 2018/09/23
 * @version 1.2, 2018/09/24
 * @version 1.3, 2018/09/26
 *
 */

class bad_vehicle_code : public std::invalid_argument
{
public:
    bad_vehicle_code(string msg = "");
    
}; // END class bad_vehicle_code





#endif /*  _COSC052_FALL2018_P2_EXCEPTIONS_H_  */
