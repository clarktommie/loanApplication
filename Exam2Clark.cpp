#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
int getNumLoanApplications();
int generateCreditScore();
string generateScoreRating(int);
string generateStatus(int);
void analysis(int, int [], string [], string []);
    
// main function
int main() 
{
	// seed time so every time we run the program, a new set of random numbers is generated
    srand(time(0)); 
    
    int numApplications = getNumLoanApplications();
    int creditScores[numApplications];
    string scoreRatings[numApplications];
    string loanStatuses[numApplications];

	// generate credit score, score rating, and loan status for each loan application
    for (int i = 0; i < numApplications; i++) 
	{
        creditScores[i] = generateCreditScore();
        scoreRatings[i] = generateScoreRating(creditScores[i]);
        loanStatuses[i] = generateStatus(creditScores[i]);
    }
    
    // display simulation result statistics
    analysis(numApplications, creditScores, scoreRatings, loanStatuses);
    
    return 0;
    
}

// ONLY FUNCTION DEFINITIONS BELOW

int getNumLoanApplications()
 {
    int numApplications;
    cout << endl << "Enter the number of loan applications to generate (min 50 - max 2000): ";
    cin >> numApplications;
    
    // Validate choices for number of applications
    while (numApplications < 50 or numApplications > 2000)
    {
    	cout << endl << "ERROR: INVALID NUMBER OF LOAN APPLICATIONS ENTERED. TRY AGAIN" << "\n";
    	cout << endl << "Enter the number of loan applications to generate (min 50 - max 2000): ";
    	cin >> numApplications;
	}
    
    return numApplications;
}

// generate a random number between 300 and 900
int generateCreditScore() 
{
    return rand() % 601 + 300;
}

// generate a score rating based on the credit score
string generateScoreRating(int creditScore) 
{
    if (creditScore >= 800) 
	{
        return "exceptional";
    } 
	else if (creditScore >= 740) 
	{
        return "very good";
    } 
	else if (creditScore >= 670) 
	{
        return "good";
    } 
	else if (creditScore >= 580) 
	{
        return "fair";
    } 
	else 
	{
        return "poor";
    }
}

// generate a status for the loan application based on the credit score
string generateStatus(int creditScore) 
{
    if (creditScore >= 630) 
	{
        return "Approved";
    } 
	else 
	{
        return "Declined";
    }
}

/*
parallel arrays that contain the credit scores, loan statuses, and credit score ratings,
as well as the number of loan applications in the simulation
*/
void analysis(int numApplications, int creditScores[], string scoreRatings[], string loanStatuses[])
{
    int numApproved = 0;
    int numDeclined = 0;
    int numPoor = 0;
    int numFair = 0;
    int numGood = 0;
    int numVeryGood = 0;
    int numExceptional = 0;

    for (int i = 0; i < numApplications; i++) 
	{
        cout << "Application Status: " << loanStatuses[i] << "\t"<< "Credit Score: "<< creditScores[i] << "\t"<< "Score Rating: " << scoreRatings[i] << endl;
        
        if (loanStatuses[i] == "Approved") 
		{
            numApproved++;
        } 
		else 
		{
            numDeclined++;
        }

        if (scoreRatings[i] == "poor") 
		{
            numPoor++;
        } 
		else if (scoreRatings[i] == "fair") 
		{
            numFair++;
        } 
		else if (scoreRatings[i] == "good") 
		{
            numGood++;
        } 
		else if (scoreRatings[i] == "very good") 
		{
            numVeryGood++;
        } 
		else if (scoreRatings[i] == "exceptional") 
		{
            numExceptional++;
        }
    }
    cout << endl << "Stats" << "\n";
    cout << "................................." << "\n";
    cout << "Total Applications " << setw(14) << right << numApplications << endl;
    cout << "\tLoans Approved " << setw(10) << right << numApproved << endl;
    cout << "\tLoans Declined " << setw(10) << right << numDeclined << endl;
    cout << "................................."<< "\n";
    cout << "Total Scores By Ratings:" << "\n";
    cout << "\t# of Poor Scores (300 - 579): " << numPoor << endl;
    cout << "\t# of Fair Scores (580 - 669): " << numFair << endl;
    cout << "\t# of Good Scores (670 - 739): " << numGood << endl;
    cout << "\t# of Very Good Scores (740 - 799): " << numVeryGood << endl;
    cout << "\t# of Exceptional Scores (800 - 900): " << numExceptional << endl;
}
    
