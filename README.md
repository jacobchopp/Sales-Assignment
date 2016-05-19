# Sales-Assignment
A C++ homework assignment about displaying sales data

<p><strong> Assignment 2:</strong> Write a program that calculates information about sales during a year. This program will have an array that will hold the sales totals for 4 divisions (North, South, East and West, stored in an array as strings for the output) and for 4 quarters. This array will also hold the total for each division and for each quarter. These totals will be calculated by the program once the values have been inputted by the user. So this array will be a 2-dimensional array with the quarters as the columns and the divisions as the rows. The last column will hold the totals for the rows (division totals) and the last row will hold the totals for the columns (quarter totals). The program must use/create the following functions:</p>
<ul>
<li>int getTotal(int [][COLS]) // gets the total of the complete array except for the totals in the last column and last row.</li>
<li>int getAverage(int [][COLS]) // return the average of all the values in the array except for the column and row with the totals in them.</li>
<li>int getRowTotal(int [][COLS], int) // returns the total for row that is specified by the second parameter to the function.</li>
<li>int getColumnTotal(int [][COLS], int) // returns the total for a column that is specified by the second parameter to the function.</li>
<li>int getHighest(int [][COLS], int&amp;, int&amp;) //returns the highest value in the array. Last two parameters are the index values of where the highest value is located in the 2D array, these can then be used to display which division and quarter.</li>
<li>int getLowest(int [][COLS], int&amp;, int&amp;) //returns the lowest value in the array. Last two parameters are the index values of where the highest value is located in the 2D array; these can then be used to display which division and quarter.</li>
</ul>
<p>The program should output a table in the same format as below which will then be followed by the division and quarter with the highest value and the division and quarter with the lowest value.</p>
<table>
<tbody>
<tr><th></th><th>Quarter 1</th><th>Quarter 2</th><th>Quarter 3</th><th>Quarter 4</th><th>Division Total</th></tr>
<tr>
<td>North</td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr>
<td>South</td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr>
<td>East</td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr>
<td>West</td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr>
<td>Quarter Total</td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>
