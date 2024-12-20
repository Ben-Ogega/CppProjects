/*
A program to convert degrees celsius to Farenheight.
*/

#include <cassert> // provides assert function
#include <cstdlib> // provides EXIT_SUCCESS
#include <iomanip> // PROVIDES SETW FUNCTION FOR SETTING OUTPUT WIDTH
#include <iostream> 
#include <string>

using namespace std;

double celsius_to_fahrenheit(double c);

void setup_out_fractions(int fraction_digits);


int main()
{
    /* code */
    const char HEADING1[] = " Celsius";
    const char HEADING2[] = "Fahrenheit";
    const char LABEL1 =  'C';
    const char LABEL2 = 'F';
    const double TABLE_BEGIN = -50;
    const double TABLE_END = 50.0;
    const double TABLE_STEP = 10.0;
    const int WIDTH = 10;
    const int DIGITS = 1;
    const char32_t cels = U'°';  // Prefix with U for Unicode character literals


    double value1; // A value from the table's first column
    double value2; // A value from the table's second column


    // set up the output for fractions and print the table headings

    setup_out_fractions(DIGITS);
    cout << "\n\n";
    cout << std::setw(10) <<"   CONVERSIONS from " << TABLE_BEGIN << " to " << TABLE_END << endl;
    cout <<setw(WIDTH) <<HEADING1 << " ********** "<< HEADING2 << endl;

        // Use a for loop to print the conversions in a formatted table
    for (value1  = TABLE_BEGIN; value1 <= TABLE_END; value1 += TABLE_STEP)
    {
        value2 = celsius_to_fahrenheit(value1);
    
       cout << std::setw(10) << std::fixed << std::setprecision(1) << value1 <<"\u00B0"<<LABEL1
                  << std::setw(15) << value2 <<"\u00B0"<<LABEL2 << std::endl;


    }
    

    return EXIT_SUCCESS;
}


double celsius_to_fahrenheit(double c){
    const double MINIMUM_CELSIUS = -273.16; // Absolute Zero in Celsius degrees
    assert(c >= MINIMUM_CELSIUS);
    return (9.0 / 5.0) * c + 32;

}

void setup_out_fractions(int fraction_digits){

    assert(fraction_digits > 0); // check that fraction_digits is not negative
    cout.precision(fraction_digits);
    cout.setf(ios::fixed, ios::floatfield);

    if (fraction_digits == 0){
        cout.unsetf(ios::showpoint);
    }

    else{
        cout.setf(ios::showpoint);
    }
    
}


