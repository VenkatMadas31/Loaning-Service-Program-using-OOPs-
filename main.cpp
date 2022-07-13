
#include <iostream>
#include <string>

using namespace std;

class borrower                                   //Class for declaring borrower. The object of this class will contain all the details from the borrower's side regarding the loan.
{
    public:                                      //Access specifier set to protected so that variables can be accessed only by the inherited class.
    float P_Amount;
    float tenure;
    float pamount()                              //Function declared to take the input for the principle amount.
    {
        cout<<"Please enter the principle amount of the loan"<<endl;
        cin>>P_Amount;
        return P_Amount;
    }
    float gettenure()                            //Function declared to take the input for the Tenure of the loan.
    {
        cout<<"Please enter the tenure of the loan\n";
        cin>>tenure;
        return tenure;
    }
};

class lender: public borrower                    //Class for declaring lender. The object of this class will contain all the details from the lender's side regarding the loan.
{
    public:
    lender()                                     //Constructor being declared (Without parameters)
    {
        pamount();                               //Using inheritance, the functions for taking the inputs for Principle amount
        gettenure();                             //and the tenure of the loan are being called from the parent class (borrower).
    }
    float roi;                                   //Variable for rate of interest.
    float collateralcheck()                      //Function which checks weather the borrower has proper collateral or not.
    {
        int check;
        cout<<"Does the borrower satisfy all the conditions to hold proper collateral? (Reply with 1 if yes or 0 if No)"<<endl;
        cin>>check;
        if(check == 0)
        {
            cout<<"Sorry!! borrower does not hold proper collateral, hence not eligible for the loan."<<endl;
            return 0;
        }
        else
        {
            cout<<"Collateral check complete. Borrower holds proper collateral."<<endl;
        }
    }

    float getroi()                                //Function to input Rate of Interest.
    {
        cout<<"Please enter the rate of interest (only in percentage)\n";
        cin>>roi;
    }
    float emi;
    float pfinal;
    float calculateemi()                          //Calculation of EMI.
    {

        float p=1.000000;
        int i;
        roi=(roi/12)/100;
        for(i=0;i<tenure;i++)
        {
            p = (1+roi)*p;
        }
        emi = P_Amount*roi*p/(p-1);
        pfinal= emi*tenure*12;
    }
    float result()                                //This function displays the result of the obtained inputs and tells the details of the loan.
    {
        cout<<"The final amount of the loan is "<<pfinal<<endl;
        cout<<"The loan is supposed to be paid off in "<<tenure<<" of years"<<endl;
        cout<<"The Equated Monthly Installment for the loan is "<<emi<<endl ;
        cout<<"In case the borrower fails to pay off the loan, the collateral (verified earlier) will be seized by the lender."<<endl;
    }
};

int main()
{
    int a;
    borrower borr;
    lender len;                                   //Default constructor being called by the object of class lender as soon as it is declared.
    a= len.collateralcheck();                     //Storing the return value of len.collateralcheck function in the variable 'a' so that the code can be made to proceed accordingly.
    if(a==0) return 0;                            //If borrower has no proper collateral, then loan can't be sanctioned hence stop the code.
    len.getroi();                                 //Function calling for taking the input of Rate of interest.
    len.calculateemi();                           //Function calling for calculating the emi.
    len.result();
}
