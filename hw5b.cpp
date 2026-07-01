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

//BEGIN - PROBLEM 4 STORE ANNOUNCEMENT - BEGIN
string toUpperCase(string text) { // returns a copy of text with every lowercase lettercase letter converted to uppercase.
    for(size_t i = 0; i < text.length(); i++) { // reads array the length of the string text, to prevent warning flags from comparing int to string must use size_t instead of int
        if( text[i] >= 'a' && text[i] <= 'z'){ // if text at position i is greater than or equal to the value of a and less than or equal to the value of z
            text[i] = text[i] - 32; // text at i - 32 = uppercase ascii. Lower case and uppercase are seperated by the value 32
        }
    }    
    return text; // returns modified text.
}   
//END - PROBLEM 4 STORE ANNOUNCEMENT - END

//BEGIN - PROBLEM 5 JOJA TERMINAL - BEGIN
void printMenu() {
    cout << "1. Spend on advertising (-100 gold)" << endl; // simple print out void function with all apropriate dialogue.
    cout << "2. Restock shelves (-50 gold)" << endl;
    cout << "3. Collect membership fees (+75 gold)" << endl;
    cout << "4. Check budget" << endl;
    cout << "5. Close terminal" << endl;
}
//END - PROBLEM 5 JOJA TERMINAL - END

//BEGIN - PROBLEM 6 HIGH PERFORMERS - BEGIN
vector<int> aboveThreshold(vector<int> sales, int threshold) { //similar to part 1 and 2 vector function
    vector<int> result; // need to initialize additional vector to hold results
    for(size_t i = 0; i < sales.size(); i++) { // scan through sales vector, size_t added because .size() does not return an integer but a value of size_t similar to problem 4
        if(sales[i] > threshold){ // if sales at i is greater than threshold
            result.push_back(sales[i]); // pushback sales[i] to result, 
        }
    }
    return result;
}
//END - PROBLEM 6 HIGH PERFORMERS - END


//BEGIN - PROBLEM 7 DEBUGGING MORRIS'S STOCK TALLY - BEGIN
// int sumVector(vector<int> v) {
//     int total = 0
//     for (int i = 0; i <= v.size(); i++) {
//         total += v[i];
//     }
//     return total
// }

int sumVector(vector<int> v) {
    int total = 0; // FIXED : added semicolon
    for (size_t i = 0; i < v.size(); i++) { // FIXED chaned <= to <  for index reading, set i < size variable for vectors add .size() FIXED: added size_t to avoid int to size_t comparison
        total += v[i]; // add value v at i to total
    }
    return total; // return new total
}
//END - PROBLEM 7 DEBUGGING MORRIS'S STOCK TALLY - END


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

    //BEGIN - PROBLEM 4 STORE ANNOUNCEMENT - BEGIN
    //variables
    string announcement;
    string modAnnouncements;

    cin.ignore(1000, '\n'); // given command to clear input before getline.

    cout << "Enter the store announcement: "; // user input prompt
    getline(cin, announcement); // getline for announcement

    modAnnouncements = toUpperCase(announcement); //modifed announcements is equal to the contents of announcement after being placed into the call function

    //header
    cout << "--- Store Announcement ---" << endl;

    //out put formatted, all out put comes from the call function logic.
    cout << "Original: " << announcement << endl; // original user input
    cout << "Announcement: " << modAnnouncements << endl; //modified announcement
    cout << "Length: " << announcement.length() << endl; // length of user input announcement
    //END - PROBLEM 4 STORE ANNOUNCEMENT - END

    //BEGIN - PROBLEM 5 JOJA TERMINAL - BEGIN
    // problem 3 variables
    int budget;
    int choice;

    cout << "Enter the starting daily budget: "; // user prompt
    cin >> budget; //stored in budget

    cout << "--- Joja Terminal ---" << endl; // print header

    do {
    printMenu(); //prints menu options

    cout << "Choose an option: "; // prompt user for selection
    cin >> choice;

    if(choice == 1) { // choice 1 advertising
        if(budget >= 100) { // budget must be at least 100 gold to use.
            budget -= 100; // subtract 100 gold from budget 
            cout << "Spent 100 gold on advertising. Budget: " << budget << endl; 
        }
        else {
            cout << "Not enough budget for advertising." << endl;
        }
    }
    else if(choice == 2){ // choice 2 restocking
        if(budget >= 50) { // budget must be greater than 50 to use
            budget -= 50; // subtract 50 from the budget
            cout << "Spent 50 gold restocking. Budget: " << budget << endl;
        }
        else {
            cout << "Not enough budget for restocking." << endl;
        }
    }
    else if(choice == 3) { //choice 3 membership
        budget += 75; // add 75 to budget for collections
        cout << "Collected 75 gold in membership fees. Budget: " << budget << " gold" << endl;
    }
    else if(choice == 4) { // current budget
        cout << "Current budget: " << budget << endl;
    }
    else if(choice == 5) {
        cout << "Closing the Joja terminal." << endl;
    }
    else{
        cout << "Invalid option." << endl;
    }
    } while(choice != 5);

    cout << "Final budget: " << budget << " gold" << endl;
    //END - PROBLEM 5 JOJA TERMINAL - END

    //BEGIN - PROBLEM 6 HIGH PERFORMERS - BEGIN
    //problem 5 variables
    int saleCount;
    int threshold = 100;
    int productSales;

    //vectors needed to filter vector
    sales.clear(); // vector sales already exists, clear before using.
    vector<int> highPerformers; //vector to store the high performers

    cout << "Enter the number of products: "; // prompt for user input
    cin >> saleCount; //store number of unique products sold 

    for(int i = 1; i <= saleCount; i++) { // for loop to prompt user for input on each item's sale data stored in sale.
        cout << "Enter sales for product " << i << ": ";
        cin >> productSales;
        sales.push_back(productSales); // add sale to sales vector (value amount per product)
    }

    highPerformers = aboveThreshold(sales, threshold); // set highPerformers vector equal to call function with parameters sales and threshold

    cout << "--- High Performers ---" << endl; // header

    for(size_t i = 0; i < highPerformers.size(); i++) { // for loop scan the contents of highPerformers
        cout << highPerformers[i] << " gold" << endl; // cout highperformers at i, the value for a particular product. We are only tracking product sales that pass a threshold
    }

    cout << "Products above 100 gold: " << highPerformers.size() << endl; // cout the count of products that are above the threshold.
    //END - PROBLEM 6 HIGH PERFORMERS - END

    //BEGIN - PROBLEM 7 DEBUGGING MORRIS'S STOCK TALLY - BEGIN

    // vector<int> nums;
    // nums.push_back(10);
    // nums.push_back(20)
    // nums.push_back(30);
    // cout << "Sum: " << sumVector(nums) << endl;

    vector<int> nums;

    nums.push_back(10);
    nums.push_back(20); // FIXED: added semi colon to line
    nums.push_back(30);

    //header
    cout << "--- Debug Report ---" << endl;
    cout << "Sum: " << sumVector(nums) << endl;




    //END - PROBLEM 7 DEBUGGING MORRIS'S STOCK TALLY - END


    return 0;
}