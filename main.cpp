#include <iostream>
#include <cstring>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Prototyping general functions
void mainMenu();
void checkIfUserWantsToQuit(string userInput);

// V A R I A B L E S
// Preset Variables
bool arraysAreEmpty = false;
float averageOfEachMonth[12] = {12,13,4,5,56,59,52,54,46,22,46,78}; // Sample average rainfall data
float previousMonthsRainfall[12] = {24,78,9,35,35,33,34,33,42,36,5,12}; // Sample previous month rainfall data
string listOfMonthsLowerCase[12] = {"january", "february", "march", "april", "may", "june", "july","august", "september", "october","november","december"}; // used to check user input in LowerCase letters
string listOfMonths[12] = {"January", "February", "March", "April", "May", "June", "July","August", "September", "October","November","December"};
string systemColor = "0B"; // Default System Color is Aqua
string allMonthsGraphSymbol = "|"; // Default graph symbol
string avgPreMonthsGraphSymbol = "|"; // Default graph symbol
string developersName[6] = {"Betelhem Melkamu", "Betelhem Mesele", "Dagmawi Esayas", "Dawit Getachew", "Dawit Yenew", "Ebenezer Yonas"};
string developersID[6] = {"ETS0139/12", "ETS0138/12", "ETS0204/12", "ETS0213/12", "ETS0216/12", "ETS0226/12"};

// Late assigned variables
string increaseDecreaseOrEqualAnalysis[12];
float previousToAverageDifference[12];
string userMonthChoice;
string TableOrGraph;

// F U N C T I O N S
// Find index of any month
int findIndexOfAnyMonth(string monthName){
    int monthIndexToReturn;
    //Change user input to lowerCase
    transform(monthName.begin(), monthName.end(), monthName.begin(), ::tolower);
    for(int i = 0; i < 12; i++)
    {
        if(listOfMonthsLowerCase[i] == monthName)  //edited list of months to lowercase to compare user input month in lowercase for consistensy
        {
            monthIndexToReturn = i;
            break;
        }
        else
        {
            monthIndexToReturn = -1;
        }
    }
    return monthIndexToReturn;
}

// A function that accepts the average rainfall of each month
void acceptAverageRainfall(){
    cout << " Enter the average for 12 months..." << endl;
    for(int i = 0; i < 12; i++){
        cout << "\t" << listOfMonths[i] << ": ";
        cin >> averageOfEachMonth[i];
    }
}

// A function to accept the current rainfall of each month depending on which month it is
void acceptPreviousRainfall(){
    string currentMonth;
    cout << "\n Enter the previous months rainfall below...";
    monthInput:
    cout << "\n What is the current month?: ";
    cin >> currentMonth;
    checkIfUserWantsToQuit(currentMonth);
    //Change user input to lowerCase
    transform(currentMonth.begin(), currentMonth.end(), currentMonth.begin(), ::tolower);
    // Error Handling
    bool isSearchInputCorrect = false;
    for(int i = 0; i < 12; i++){
        if(listOfMonthsLowerCase[i] == currentMonth){
            isSearchInputCorrect = true;
        }
    }
    if(isSearchInputCorrect == false){
        cout << " \n\t\t\t Invalid Input. Try Again!" << endl << endl;
        system("pause");
        goto monthInput;
    }
    // Search for the current month
    int indexOfCurrentMonth = findIndexOfAnyMonth(currentMonth);
    // Accept the rest of the months
    int endCount = 0;
    int i = indexOfCurrentMonth;
    int monthIndex = indexOfCurrentMonth;
    while(endCount < 12){
        cout << " " << listOfMonths[monthIndex] << ": ";
        cin >> previousMonthsRainfall[monthIndex];
        monthIndex++;
        endCount++;
        if(monthIndex == 11){
            monthIndex = 0;
        }
    }
    cout << " \n\t\t\tDone!" << endl << endl;
    system("pause");
    system("cls");
    mainMenu();
}

// Analyze the previous months data to the average data
void analyzePreviousMonthsToAverage(){
    for(int i = 0; i < 12; i++){
        // Decide if the previous month increased, decreased or equaled the average
        if(previousMonthsRainfall[i] < averageOfEachMonth[i]){
            increaseDecreaseOrEqualAnalysis[i] = "Decreased";
            previousToAverageDifference[i] = averageOfEachMonth[i] - previousMonthsRainfall[i];
        }else if(previousMonthsRainfall[i] > averageOfEachMonth[i]){
            increaseDecreaseOrEqualAnalysis[i] = "Increased";
            previousToAverageDifference[i] = previousMonthsRainfall[i] - averageOfEachMonth[i];
        }else{
            increaseDecreaseOrEqualAnalysis[i] = "Same";
            previousToAverageDifference[i] = 0;
        }
    }
}

// Show tabular analysis of a single month
void showTabularAnalysis(string monthName){
    int monthIndex = findIndexOfAnyMonth(monthName);
    cout << " ______________________________________________" << endl << endl;
    string titles[6] = {"Index            ", "Name             ", "Pre Month RF (mm)", "Average RF (mm)  ", "Difference       ", "Analysis         "};
    // Show Title and Data
    for(int title = 0; title < 6; title++)
    {
        switch (title)
        {
        case 0:
            cout << "\t" << titles[title] << " :\t" << monthIndex;
            break;
        case 1:
            cout << "\t" << titles[title] << " :\t" << listOfMonths[monthIndex];
            break;
        case 2:
            cout << "\t" << titles[title] << " :\t" << previousMonthsRainfall[monthIndex];
            break;
        case 3:
            cout << "\t" << titles[title] << " :\t" << averageOfEachMonth[monthIndex];
            break;
        case 4:
            cout << "\t" << titles[title] << " :\t" << previousToAverageDifference[monthIndex];
            break;
        case 5:
            cout << "\t" << titles[title] << " :\t" << increaseDecreaseOrEqualAnalysis[monthIndex];
            break;
        }
        cout << endl;
    }
    cout << " ______________________________________________" << endl;
    cout << endl;
}

// Show graphical analysis of a single month
void showGraphicalAnalysis(string monthName){
    int monthIndex = findIndexOfAnyMonth(monthName);
    int lengthOfStandardBar = 25;
    int averageRFOfMonthBarLength = lengthOfStandardBar;
    int previousMonthsRFBarLength = ( previousMonthsRainfall[monthIndex] * lengthOfStandardBar ) / averageOfEachMonth[monthIndex];
    cout << " The average-previous month raifall graph of Addis Ababa: " << endl << endl;
    cout << " Avg/Pre" << endl;
    for(int i = 0; i < 7; i++){
        if(i == 2){
            cout << "  |";
            for(int j = 0; j < averageRFOfMonthBarLength; j++)
            {
                cout << avgPreMonthsGraphSymbol;
            }
            cout << "   -> average " << endl;
        }
        else if(i == 4){
            cout << "  |";
            for(int j = 0; j < previousMonthsRFBarLength; j++)
            {
                cout << avgPreMonthsGraphSymbol;
            }
            cout << "   -> previous month " << endl;
        }
        else{
            cout << "  |" << endl;
        }

    }
    cout << "  ";
    for(int i = 0; i < lengthOfStandardBar * 2 + 8; i++){
        cout << "-";
    }
    cout << " Rainfall (mm)";
    cout << endl << endl;
}

// Show graphical analysis of all the months
void showAllAverageGraphicalAnalysis(){
    int maxBarLength = 0;
    int lengthOfStandardBar = 80;
    for(int i = 0; i < 12; i++)
    {
        if(averageOfEachMonth[i] > maxBarLength)
        {
            maxBarLength = averageOfEachMonth[i];
        }
    }
    // Draw the graph
    cout << " The average rainfall of Addis Ababa throughout the year:" << endl << endl;
    cout << "  Months" << endl;
    // Extra graph vertical lines
    for(int i = 0; i < 2; i++)
    {
        cout << "    |" << endl;
    }
    // Graph Bars
    for(int j = 0; j < 12; j++)
    {
        cout << "    |";
        int currentBarLength = ( averageOfEachMonth[j] * lengthOfStandardBar ) / maxBarLength;
        for(int k = 0; k < currentBarLength; k++)
        {
            cout << allMonthsGraphSymbol;
        }
        cout << "   -> " << listOfMonths[j] << endl;
    }
    // Extra graph vertical lines
    for(int i = 0; i < 2; i++)
    {
        cout << "    |" << endl;
    }
    // Graph bottom line
    cout << "    ";
    for(int i = 0; i < lengthOfStandardBar + 5; i++)
    {
        cout << "-";
    }
    cout << " amount (mm)" << endl << endl;
}

// Show tabular analysis of all the months
void showAllTabularAnalysis(){
    for(int i = 0; i < 12; i++)
    {
        cout << " ----------------------------------------------" << endl;
        cout << "   " << i+1 << ". Data for " << listOfMonths[i] << endl;
        showTabularAnalysis(listOfMonths[i]);
        cout << endl;
    }
}

// Check if user wants to quit, goto main menu or clean the screen
void checkIfUserWantsToQuit(string userInput){
    //Change user input to lowerCase
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    if(userInput == "q" || userInput == "quit" || userInput == "e" || userInput == "exit"){
        exit(1);
    }
    else if(userInput == "cls"){
        system("cls");
    }
};

// Analyze or View data
void analyzeOrViewData(){
    string userSearchOrAll;
    analyzePreviousMonthsToAverage();
    // Allow user to search for a specific month or display data for all
    searchOrAllChoice:
    cout << " Would you like to search for a particular month or view all the months? ( Search[S] / All[A] ): ";
    cin >> userSearchOrAll;
    //Change user input to lowerCase
    transform(userSearchOrAll.begin(), userSearchOrAll.end(), userSearchOrAll.begin(), ::tolower);
    checkIfUserWantsToQuit(userSearchOrAll);
    if(userSearchOrAll == "s" || userSearchOrAll == "search" || userSearchOrAll == "a" || userSearchOrAll == "all"){
        if(userSearchOrAll == "s" || userSearchOrAll == "search"){
            searchAMonth:
            cout << " Enter month name: ";
            cin >> userMonthChoice;
            checkIfUserWantsToQuit(userMonthChoice);
            //Change user input to lowerCase
            transform(userMonthChoice.begin(), userMonthChoice.end(), userMonthChoice.begin(), ::tolower);
            // Error handling for the searched month
            bool correctSearchInput = false;
            for(int i = 0; i < 12; i++){
                if(listOfMonthsLowerCase[i] == userMonthChoice){
                    correctSearchInput = true;
                }
            }
            if(correctSearchInput == false){
                cout << " \n\t\t\t Invalid Input. Try Again!" << endl << endl;
                goto searchAMonth;
            }
            cout << endl;
        }
        // Allow user to choose which way they want to view the data
        graphOrTableInput:
        cout << " What format of the data would you like to see? ( Table[T] / Graph[G] ): ";
        cin >> TableOrGraph;
        checkIfUserWantsToQuit(TableOrGraph);
        //Change user input to lowerCase
        transform(TableOrGraph.begin(), TableOrGraph.end(), TableOrGraph.begin(), ::tolower);
        cout << endl;
        if(TableOrGraph == "t" || TableOrGraph == "table" || TableOrGraph == "g" || TableOrGraph == "graph"){
            if(userSearchOrAll == "a" || userSearchOrAll == "all"){
                if(TableOrGraph == "t" || TableOrGraph == "table"){
                    showAllTabularAnalysis();
                    system("pause");
                    system("cls");
                    mainMenu();
                }
                else if (TableOrGraph == "g" || TableOrGraph == "graph"){
                    showAllAverageGraphicalAnalysis();
                    system("pause");
                    system("cls");
                    mainMenu();
                }
            }else{
                if(TableOrGraph == "t" || TableOrGraph == "table"){
                    showTabularAnalysis(userMonthChoice);
                    system("pause");
                    system("cls");
                    mainMenu();
                }else if (TableOrGraph == "g" || TableOrGraph == "graph"){
                    showGraphicalAnalysis(userMonthChoice);
                    system("pause");
                    system("cls");
                    mainMenu();
                }
            }
        }else{
            cout << " \n\t\t Invalid Input. Try Again! " << endl << endl;
            goto graphOrTableInput;
        }
    }else{
        cout << " \n\t\t Invalid Input. Try Again! " << endl << endl;
        goto searchOrAllChoice;
    }
}

// Settings
void settings(){
    string userSettingChoice;
    string userColorChoice;
    // Settings Menu
    cout << " Settings " << endl;
    cout << " 1. Change Colors" << endl;
    cout << " 2. Change Bar Graph Symbol" << endl;
    cout << " 3. Return To Main Menu" << endl << endl;
    colorSettings:
    cout << " Setting Choice: ";
    cin >> userSettingChoice;
    checkIfUserWantsToQuit(userSettingChoice);
    //Change user input to lowerCase
    transform(userSettingChoice.begin(), userSettingChoice.end(), userSettingChoice.begin(), ::tolower);
    // Change Theme Setting
    if(userSettingChoice == "1" ||  userSettingChoice == "c" || userSettingChoice == "color" || userSettingChoice == "colors"){
        cout << endl;
        cout << " Choose two colors from the follow, the first digit being the background and \n the second being the foreground. Press 'D' when finished." << endl;
        cout << "  \n  0 = Black       8 = Gray \n  1 = Blue        9 = Light Blue \n  2 = Green       A = Light Green \n  3 = Aqua        B = Light Aqua \n  4 = Red         C = Light Red \n  5 = Purple      D = Light Purple \n  6 = Yellow      E = Light Yellow \n  7 = White       F = Bright White" << endl;
        cout << endl;
        cout << " Color Choice: ";
        cin >> userColorChoice;
        checkIfUserWantsToQuit(userColorChoice);
        systemColor = userColorChoice;
        string color = "color " + systemColor;
        cout << " \n\t System color changed successfully!" << endl << endl;
        system(color.c_str());
        system("pause");
        system("cls");
        mainMenu();
    // Change the symbol of bar graphs
    } else if(userSettingChoice == "2"){
        string userGraphChangeChoice;
        cout << endl;
        cout << " Which bar graph's icons would u like to change?" << endl;
        cout << " 1. All year rain fall bar-graph's" << endl;
        cout << " 2. Average-Previous rain fall bar-graph's" << endl;
        cout << " 3. Return to main menu" << endl;
        barSettings:
        cout << " \n Bargraph choice: ";
        cin >> userGraphChangeChoice;
        checkIfUserWantsToQuit(userGraphChangeChoice);
        if(userGraphChangeChoice == "1"){
            cout << endl;
            cout << " What symbol would you like to use for the graph? (Current Symbol: '" << allMonthsGraphSymbol << "') " << endl;
            cout << " New Symbol: ";
            cin >> allMonthsGraphSymbol;
            checkIfUserWantsToQuit(allMonthsGraphSymbol);
            cout << " \n\t Bar-graph symbol changed successfully!" << endl << endl;
            system("pause");
            system("cls");
            mainMenu();
        } else if (userGraphChangeChoice == "2"){
            cout << endl;
            cout << " What symbol would you like to use for the graph? (Current Symbol: '" << avgPreMonthsGraphSymbol << "') " << endl;
            cout << " New Symbol: ";
            cin >> avgPreMonthsGraphSymbol;
            checkIfUserWantsToQuit(avgPreMonthsGraphSymbol);
            cout << " \n\t Bar-graph symbol changed successfully!" << endl << endl;
            system("pause");
            system("cls");
            mainMenu();
        } else if (userGraphChangeChoice == "3"){
            system("cls");
            mainMenu();
        } else {
            cout << " \n\t\t Invalid Input. Try Again! " << endl << endl;
            system("pause");
            goto barSettings;
        }
    // Error Handling
    } else {
        cout << " \n\t\t Invalid Input. Try Again! " << endl << endl;
        goto colorSettings;
    }
}

// Welcome Screen
void welcomeScreen(){
    cout << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(45) << "Please Select One of the Following Options" << setfill(' ') << setw(5) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "1. Start Data Input" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << "2. Analyze/View Data" << setfill(' ') << setw(17) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << "3. Introduction/Help" << setfill(' ') << setw(17) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(26) << "4. Developers" << setfill(' ') << setw(24) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(24) << "5. Settings" << setfill(' ') << setw(26) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(25) << "6. Quit/Exit" << setfill(' ') << setw(25) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl;
}

// Goodbye Screen
void goodbyeScreen(){
    cout << endl << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "G O O D  B Y E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl << endl << endl << endl << endl;
}

bool keepMainMenuAlive = true;
// Main Menu or Intro Screen
void mainMenu(){
    correctMenuChoice:
    // Welcoming screen and the main menu list
    welcomeScreen();
    char userChoiceInput;
    while (keepMainMenuAlive){
        cout << " Menu choice (1/2/3/4/5/6): ";
        cin >> userChoiceInput;
        cout << endl;
        switch(userChoiceInput){
            // Start Data Input
            case '1':
                acceptAverageRainfall();
                acceptPreviousRainfall();
                system("pause");
                system("cls");
                welcomeScreen();
                break;
            // Analyze Or View Data
            case '2':
                if(arraysAreEmpty){
                    cout << " \t X - Can't view/analyze empty data. Please enter data first. - X" << endl;
                }else{
                    while(true){
                        analyzeOrViewData();
                        system("pause");
                        system("cls");
                        welcomeScreen();
                    }
                }
                break;
            // Introduction or Help to the program
            case '3':
                cout << "   \t\t\t   Usage \n\t Using this program you can input the average monthly rainfall of Addis Ababa \n and the previous year's monthly rainfall records then this program will \n analyze it and give you statistical results of the data given." << endl << endl;
                cout << "   \t\t\t   Tools \n\t After submitting rainfall data you can search a specific month or all the months \n to look at a tabled analysis or at a bar-graphed analysis of the information. \n" << endl;
                cout << "   \t\t\t Navigation \n You can type in 'q', 'quit', 'e', 'exit' at any input place and quit the program at anytime!  " << endl << endl;
                system("pause");
                system("cls");
                welcomeScreen();
                break;
            // Developers
            case '4':
                // Write developers name and ID
                cout << "   \t\t\t Developers " << endl;
                for(int i = 0; i < 6; i++){
                    cout << " \t\t" << developersName[i] << " -- " << developersID[i] << endl;;
                }
                cout << endl << endl;
                system("pause");
                system("cls");
                welcomeScreen();
                break;
            // Settings
            case '5':
                settings();
                system("pause");
                system("cls");
                welcomeScreen();
                break;
            // Exit
            case '6':
                system("cls");
                goodbyeScreen();
                exit(1);
                break;
            // Error Handling
            default:
                cout << " Invalid choice. Try Again!" << endl;
                system("pause");
                system("cls");
                //mainMenu();
                //keepMainMenuAlive = false;
                break;
        }
        cout << endl;
    }
    cout << endl << endl;
}

// Main
int main(){
    // Set system wide color theme
    string color = "color " + systemColor;
    system(color.c_str());
    // Main Menu
    while(true){
        keepMainMenuAlive = true;
        mainMenu();
        system("pause");
    }
    return 0;
}













