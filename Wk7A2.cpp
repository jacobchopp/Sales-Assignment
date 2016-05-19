/***************************************************
Week 7 Assignment 2 - Sales Calculator

This program calculates sales by division and quarter. 
It prints a table of values and overall statistics.

Author: Jacob Hopp
Created: 5/8/2016
Revisions: None
***************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int DIVISIONS = 4;
const int QUARTERS = 4;
const int ROWS = DIVISIONS + 1;
const int COLS = QUARTERS + 1;

const string AREAS[] = { "North", "South", "East", "West" };
const string ORDINALS[] = { "First", "Second", "Third", "Fourth" };

int getTotal(int[][COLS]);	// gets the total of the complete array except for the totals in the last column and last row.
int getAverage(int[][COLS]);	// return the average of all the values in the array except for the column and row with the totals in them.
int getRowTotal(int[][COLS], int);	// returns the total for row that is specified by the second parameter to the function.
int getColumnTotal(int[][COLS], int);	// returns the total for a column that is specified by the second parameter to the function.
int getHighest(int[][COLS], int&, int&);	//returns the highest value in the array. Last two parameters are the index values of where the highest value is located in the 2D array, these can then be used to display which division and quarter.
int getLowest(int[][COLS], int&, int&);		//returns the lowest value in the array. Last two parameters are the index values of where the highest value is located in the 2D array; these can then be used to display which division and quarter.

int main()
{
	int salesTotals[ROWS][COLS];
	int highestQuarter = 0,
		highestDivision = 0,
		lowestQuarter = 0,
		lowestDivision = 0;
	// Introduce Program
	cout << "Year-end Sales Calculator\n\n";
	// Prompt for values
	for (int d = 0; d < DIVISIONS; d++)
	{
		for (int q = 0; q < QUARTERS; q++)
		{
			cout << "What were the sales in " << AREAS[d] << " Division for " << ORDINALS[q] << " Quarter? ";
			cin >> salesTotals[d][q];
		}
	}
	// Calculate Division and Quarter Totals
	for (int d = 0; d < DIVISIONS; d++)
	{
		salesTotals[d][QUARTERS] = getRowTotal(salesTotals, d);
	}
	for (int q = 0; q < QUARTERS; q++)
	{
		salesTotals[DIVISIONS][q] = getColumnTotal(salesTotals, q);
	}
	// Output Table
	cout << endl << endl;
	cout << setw(15) << "" << setw(15) << "Quarter 1" << setw(15) << "Quarter 2" << setw(15) << "Quarter 3" << setw(15) << "Quarter 4" << setw(15) << "Division Total" << endl;
	for (int d = 0; d < DIVISIONS; d++)
	{
		cout << setw(15) << AREAS[d];
		for (int c = 0; c < COLS; c++)
		{
			cout << setw(15) << salesTotals[d][c];
		}
		cout << endl;
	}
	cout << setw(15) << "Quarter Total";
	for (int q = 0; q < QUARTERS; q++)
	{
		cout << setw(15) << salesTotals[DIVISIONS][q];
	}
	cout << setw(15) <<  getTotal(salesTotals) << endl << endl << endl;
	// Output Statistics
	cout << "Total Sales were " << getTotal(salesTotals) << endl;
	cout << "Average quarterly sales for all divisions were " << getAverage(salesTotals) << endl;
	cout << "Highest sales were " << getHighest(salesTotals, highestDivision, highestQuarter);
	cout << " by " << AREAS[highestDivision] << " Divison in their " << ORDINALS[highestQuarter] << " Quarter.\n";
	cout << "Lowest sales were " << getLowest(salesTotals, lowestDivision, lowestQuarter);
	cout << " by " << AREAS[lowestDivision] << " Divison in their " << ORDINALS[lowestQuarter] << " Quarter.\n\n\n";
	return 0;
}

int getTotal(int salesTotals[][COLS])
{
	int total = 0;
	for (int d = 0; d < DIVISIONS; d++)
	{
		for (int q = 0; q < QUARTERS; q++)
		{
			total += salesTotals[d][q];
		}
	}
	return total;
}

int getAverage(int salesTotals[][COLS])
{
	int total = 0;
	for (int d = 0; d < DIVISIONS; d++)
	{
		for (int q = 0; q < QUARTERS; q++)
		{
			total += salesTotals[d][q];
		}
	}
	return total / (DIVISIONS * QUARTERS);
}

int getRowTotal(int salesTotals[][COLS], int div)
{
	int total = 0;
	for (int q = 0; q < QUARTERS; q++)
	{
		total += salesTotals[div][q];
	}
	return total;
}

int getColumnTotal(int salesTotals[][COLS], int qtr)
{
	int total = 0;
	for (int d = 0; d < DIVISIONS; d++)
	{
		total += salesTotals[d][qtr];
	}
	return total;
}

int getHighest(int salesTotals[][COLS], int &div, int &qtr)
{
	int highest = salesTotals[div][qtr];
	for (int d = 0; d < DIVISIONS; d++)
	{
		for (int q = 0; q < QUARTERS; q++)
		{
			if (highest < salesTotals[d][q])
			{
				highest = salesTotals[d][q];
				div = d; qtr = q;
			}
		}
	}
	return highest;
}

int getLowest(int salesTotals[][COLS], int &div, int &qtr)
{
	int lowest = salesTotals[div][qtr];
	for (int d = 0; d < DIVISIONS; d++)
	{
		for (int q = 0; q < QUARTERS; q++)
		{
			if (lowest > salesTotals[d][q])
			{
				lowest = salesTotals[d][q];
				div = d; qtr = q;
			}
		}
	}
	return lowest;
}
