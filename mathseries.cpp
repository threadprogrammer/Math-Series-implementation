#include <string>
#include <iostream>
#include <cmath>
#include <vector>

// Use std for cout,cin,endl
using namespace std;

typedef unsigned long long int ulli;

/// <summary>
/// The Struct that contains application requirements
/// </summary>
struct infoapp
{
	// number of elements of iterations
	int Num = 0;

	// name of that operation
	int OperationID = 0;

	// sum of operation
	long double Sum = 0;

    // the input
    double Inp = 0;

};

// Our application info container instance
infoapp app;

// Our container for calculations and summations
vector<long double> v(160);

/// <summary>
/// A Factorial function implementation
/// </summary>
/// <param name="i">the input integer to calculate it's factorial</param>
/// <returns>returns the factorral of input</returns>
unsigned long long int fac(int i)
{
    // the result of this function
    unsigned long long int res = 1;

    if (i % 2 == 0)
    {
        while (i > 0)
        {
            res *= i * (i - 1);

            i -= 2;
        }
    }

    if (i % 2 != 0)
    {
        while (i > 0)
        {
            if (i == 1)
                break;

            res *= i * (i - 1);

            i -= 2;
        }
    }

    return res;
}


/// <summary>
/// The mathematical calculation for taylor series expansion
/// </summary>
/// <param name="num">The number of iterations for series</param>
/// <param name="inp">The input x in series</param>
void expocalc(int num, double inp)
{
    for (int i = 0; i < num; i++)
    {
        // Calculate elements and set the first element as in series
        v[0] = 1;
        v[i] = pow(inp, i) / fac(i);
    }

    // Add all elements as in series
    for (vector<long double>::iterator it = v.begin(); it!=v.end(); it++)
    {
        app.Sum += *it;
    }

    cout << "The Result is : " << app.Sum << endl;
    app.Sum = 0;
}

/// <summary>
/// The operations for getting inputs from user for taylor series expansion
/// </summary>
void expoOp()
{
    system("cls");
    cout << "Enter number of iterations you want to calculate for taylor series expansion : ";
    cin >> app.Num;
    cout << endl;
    cout << "Now Enter The input: ";
    cin >> app.Inp;
    cout << endl;

    v.resize(app.Num);

    // call expocalc()
    expocalc(app.Num, app.Inp);
}

/// <summary>
/// The mathematical calculation for arctang calculation
/// </summary>
/// <param name="num">The number of iterations for series</param>
/// <param name="inp">The input x in series</param>
void arctancalc(int num, double inp)
{
    for (int i = 0; i < num; i++)
    {
        // Calculate elements
        if(i % 2 == 1)
        {
            v[i] = -(pow(inp, 2 * i + 1) / (2 * i + 1));
        }
        else
        {
            v[i] = (pow(inp, 2 * i + 1) / (2 * i + 1));
        }
    }

    for (vector<long double>::iterator it = v.begin(); it != v.end(); it++)
    {
        app.Sum += *it;
    }

    cout << "The Result is : " << app.Sum << endl;
    app.Sum = 0;
}

/// <summary>
/// The operations for getting inputs from user for arctang calculation
/// </summary>
void arctanOp()
{
    cout << "Enter number of iterations you want to calculate for arctang operation : ";
    cin >> app.Num;
    cout << endl;
    cout << "Now Enter The input: ";
    cin >> app.Inp;
    cout << endl;
    arctancalc(app.Num, app.Inp);
}

/// <summary>
/// The mathematical calculation for summation series calculation
/// </summary>
/// <param name="num">The number of iterations for series</param>
/// <param name="inp">The input x in series</param>
void summcalc(int num, double inp)
{
    for (int i = 0; i < num; i++)
    {
        // Calculate elements
        v[0] = 1;
        v[i] = pow(inp, i);
    }

    for (vector<long double>::iterator it = v.begin(); it != v.end(); it++)
    {
        app.Sum += *it;
    }

    cout << "The Result is : " << app.Sum << endl;
    app.Sum = 0;
    // system("color 0");

}

/// <summary>
/// The operations for getting inputs from user for summation series
/// </summary>
void summationOp()
{
    cout << "Enter number of iterations you want to calculate for summation series : ";
    cin >> app.Num;
    cout << endl;
    cout << "Now Enter The input: ";
    cin >> app.Inp;
    cout << endl;

    summcalc(app.Num, app.Inp);
}


int main()
{
   
    // A boolean for controlling the flow of the program
    bool quit = false;

    while(!quit)
    {
        cout << "............................................................................." << endl;
        cout << endl << "Hello, Welcome ...." << endl;
        cout << "Please enter name of your operation: " << endl << endl;
        cout << "1.Taylor series expansion - maximum allowable iterations = 20" << endl;
        cout << "2.Summation" << endl;
        cout << "3.Arctang Calculator" << endl;

        cout << "4.Exit Application" << endl;
        cout << "5.Clear Console" << endl << endl;


        cout << "Your Choice : ";

        // Enter Operation ID
        cin >> app.OperationID;

        cout << endl;

        switch (app.OperationID)
        {
        case 1:
            system("color 9");

            cout << "Running The Operation (1) ... " << endl;
            expoOp();
            break;
        case 2:
            system("color 2");

            cout << "Running The Operation (2) ... " << endl;
            summationOp();
            break;
        case 3:
            system("color 3");

            cout << "Running The Operation (3) ... " << endl;
            arctanOp();
            break;
        case 4:
            system("color 4");

            // Here the user wants to quit the program
            quit = true;
            cout << "GoodBye. See you soon" << endl;
            break;
        case 5:
            system("cls");
            break;
        default:
            // Here the user send wrong input
            cout << "Wrong Value OR Operation; Please enter one of the items in the menu!" << endl;
            cout << endl << endl;
            break;
        }
        system("color 7");


    }

    return 0;
}
