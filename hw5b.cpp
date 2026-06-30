#include <iostream>
#include <string>
#include <vector>

using namespace std;



//call functions
//BEGIN - PROBLEM 1 DAILY SALES LOG - BEGIN
int totalSales(vector<int> sales) { // Recommended to use a while loop, returns the sum of all vectors.
    int total = 0;
    for(int i = 0; i < static_cast<int>(sales.size()); i++ ) { // inlcude static cast to prevent .size issues, did not work without the inclusion.
        total += sales[i]; // total up the values for sales
    }
    return total; //return total
}
//END - PROBLEM 1 - END

//BEGIN - PROBLEM 2 BEST SALES DAY - BEGIN
int bestDayIndex(vector<int> sales) { // returns the INDEX of the largest figure, suggest for loop for problem.
    int day = 0;
    for(int i = 0; i < static_cast<int>(sales.size()); i++) { // scan array
        if(sales[i] > sales[day]) // similar to arrays always an additional variable used as count. if value at i is greater than value stored in day
        day = i; // day is equal to greater value
    }
    return day; //return index named day
}
//END - PROBLEM 2 BEST SALES DAY - END

// BEGIN - PROBLEM 3 REGIONAL SALES - BEGIN
int grandTotal(int totals[], int size) { // returns the sum of all region totals / days per region = 3
    int total = 0;
    for(int i = 0; i < size; i++) {
        total += totals[i];
    }
   return total;

}
// END - PROBLEM 3 REGIONAL SALES - END


// main -- process of arrays to vectors is challenging but they are very similar. Less manual work required.
int main() {

    //Problem 1
    int sale; // individual sale to be placed in vector sales
    vector<int> sales; // declaring vector sales

    // BEGIN PROBLEM 1 DAILY SALES LOG - BEGIN
    cout << "Enter a daily sales figure (-1 to stop): ";
    cin >> sale;

    while(sale != -1) { 
        sales.push_back(sale); // adds input value "sale" to vector

        cout << "Enter a daily sales figure (-1 to stop): ";
        cin >> sale;
    }
   
    // header
    cout << "--- Daily Sales Log ---" << endl;
    //output
    cout << "Days logged: " << sales.size() << endl; // originally tried to call days and store the sale size in another container, convention says to directly call using size.
    cout << "Total sales: " << totalSales(sales) << " gold" << endl; // calling total sales function which only returns the total.
    // END - PROBLEM 1 DAILY SALES LOG - END

    sales.clear(); // since both problems utilize the same vector name, I found that the function gives the wrong output outside of sample input. This clears the previous contents once problem 1 is finished.

    //Problem 2
    int days;

    //BEGIN - PROBLEM 2 BEST SALES DAY - BEGIN
    cout << "Enter the number of days: "; // prompt user for days
    cin >> days;

    for(int i = 0; i < days; i++) { // for length of days entered prompt the user 

        cout << "Enter sales for day " << i + 1 << ": "; // +1 for user visual, indexing starts at 0
        cin >> sale;

        sales.push_back(sale); // push user input into vector
    }

    int day = bestDayIndex(sales);

    cout << "--- Best Sales Day ---" << endl;
    
    cout << "Best day: " << day + 1 << endl; // output best day index value +1
    cout << "Sales: " << sales[day] << " gold" << endl; //input sales vector sales[days] user input values stored in vector and recalled for output.
    //END - PROBLEM 2 BEST SALES DAY - END

    sales.clear(); // clear sales for reuse in problem 3

    //problem 3
    int regions;
    int regionTotalAR[100];
    int regionalSale;
    const int regionDays = 3;

    //BEGIN - PROBLEM 3 REGIONAL SALES - BEGIN
    cout << "Enter the number of regions: ";
    cin >> regions;

    cout << "--- Regional Sales ---" << endl;

    for(int i = 0; i < regions; i++){
        int regionTotal = 0;

        for(int j = 0; j < regionDays; j++) {
            cout << "Enter sales for region " << i + 1 << " " << "day " << j + 1 << ": ";
            cin >> regionalSale;

            regionTotal += regionalSale;   
        }

        regionTotalAR[i] = regionTotal;
    
        cout << "Region " << i + 1 << " total: " << regionTotal << endl;
    }

    cout << "Grand total: " << grandTotal(regionTotalAR, regions) << endl;
    
    //END - PROBLEM 3 REGIONAL SALES - END


    return 0;
}