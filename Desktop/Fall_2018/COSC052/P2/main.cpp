/*
 *  main.cpp
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

#include "main.h"

int main(int argc, const char *argv[])
{
	try{
			int two = 2;
				if (argc < two) 
				{
					throw invalid_argument( "Error in main:Not enough command line argument"); 
				}
			string filepath =  argv[1] ;
			
			string textFile = "text.txt";
			
			
			string outputFileName1 = filepath + ".out1";
			VehicleLog vehicle;
			vehicle.read(filepath); 
			vehicle.print(cout); 
			cout<<endl;
			cout << " Total Passenger Capcity: "<< vehicle.getTotalPassengerCapacity()<<endl;
			cout<< " Total Cargo Capacity: " << vehicle.getTotalCargoCapacity()<<endl;	
			/*
			string theID = "i0000000000000001";
			string theID2 = "I0000000000000001";
			string theName = "Chevrolet Camaro";
			int theYear = 1976;
			int theMonth = 5;
			int theDay = 31;
			Date theDate(theYear,theMonth,theDay);
			char theStatus = 'a';

			Individual obj1(theID, theName, theDate, theStatus);

			cout << "output from getter methods:" << endl;
			cout << obj1.getID() << endl;
			cout << obj1.getName() << endl;
			cout << tolower(obj1.getStatus()) << endl;


			cout << obj1.getInspectionDate().getYear() << endl;
			cout << obj1.getInspectionDate().getMonth() << endl;;
			cout << obj1.getInspectionDate().getDay() << endl;

			cout << endl;
			cout << "output from print method:" << endl;
			obj1.print();
			cout << endl;
			*/
		}
		// CATCH BLOCKS FOR ANY EXCEPTION OBJECTS 
		catch (bad_vehicle_code &e)
		{
			cout<<"caught bad_vehicle_code in function main \n"; 
			cout << e.what() <<endl;
		}
		catch (invalid_argument &e)
		{
			cout<< "caught invalid_argument in function main\n"; 
			cout << e.what()<<endl;
		}
		
		catch (logic_error &e) 
		{
			cout<< "caught logic_error in function main\n"; 
			cout <<e.what()<<endl;
		}
		
		catch (...)
		{
			string errMessage; 
			errMessage = "caught unknown exception in function main , ";
			errMessage += "processing terminated.";
		}
	return 0 ;
}