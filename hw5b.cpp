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

//END - PROBLEM 2 BEST SALES DAY - END





// main -- process of arrays to vectors is challenging but they are very similar. Less manual work required.
int main() {
    //variables
    //int days; // logs days for later .size() count (Unneeded)
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






    return 0;
}