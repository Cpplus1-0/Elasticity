#include <iostream>
#include <cmath>

using namespace std;

enum relation{Price, RelativePrice, Income};

double calculateEquilibrium(int a, int b, int c, int d, bool var);

double calqty(int a, int b, int p, bool choice);

double elasticity(int pr0, int pr1, int qty0, int qty1);

int main()
{
    double dummy = 0;
    int price, quantity;

    cout << "Welcome to Economeeks calculator. " << endl;
    cout << "You can choose from a variety of options to calculate specific economic variables. " << endl << endl;

    cout << "Choose one: (1) Equilibrium (2) Elasticity by Equation (3) Elasticity by Data" << endl;
    cout << "Enter your option: "; int opt; cin >> opt;
    cout << endl;

    int a, b, c, d, pr, newPr, income, newIncome = 0;
    switch(opt)
    {
        case 1:
            //Input of linear demand and supply curves
            cout << "Enter the values for variables(a,b,c,d) in the supply and demand equations." << endl;
            cout << "Demand curve --> P=a-b*Qd\t\tSupply curve --> P = c+d*Qs" << endl << endl;

            cout << "Enter a: "; cin >> a;
            cout << "Enter b: "; cin >> b;
            cout << "Enter c: "; cin >> c;
            cout << "Enter d: "; cin >> d;
            //End of input

            //Output
            cout << endl << "Choose one of the following to calculate at equilibrium: (1) Price (2) Quantity (3) Point(p,q): ";
            cin >> opt;
            cout << endl;
            switch(opt)
            {
                case 1:
                    cout << "The equilibrium price is: " << calculateEquilibrium(a,b,c,d,true) << endl << endl;
                    break;

                case 2:
                    cout << "Equilibrium quantity is: " << (int)calculateEquilibrium(a,b,c,d,false) << endl << endl;
                    break;

                case 3:
                    cout << "Equilibrium point is: (" << calculateEquilibrium(a,b,c,d,true) << "," << (int) calculateEquilibrium(a,b,c,d,false) << ")" << endl << endl;
                    break;

                default:
                    cout << "Sorry! There is an error in your choice of input. " << endl;
            }
            break;
            //End Output

        case 2:
            cout << "Choose one:";
            cout << "\t1. Price Elasticity of Demand" << endl;
            cout << "\t\t2. Price Elasticity of Supply" << endl;
            cout << "\t\t3. Income Elasticity of Demand" << endl;
            cout << "\t\t4. Cross Elasticity of Demand" << endl;
            cout << endl << "Enter choice:\t"; cin >> opt;
            cout << endl;

            cout << "Enter values for variables a and b in the equation for the ";
            cout << (opt != 2 ? "demand curve.\nDemand: P=a-b*Qd\n" : "supply curve.\nSupply: P=c+d*Qs") << endl;

            if(opt!=2)
            {
                cout << "Enter a: "; cin >> a;
                cout << "Enter b: "; cin >> b;
                cout << endl;
            }
            switch(opt)
            {
                //Tested & Proven
                case 1:
                    cout << "Enter current price: "; cin >> pr;
                    cout << "Enter new price: "; cin >> newPr;
                    cout << "Price elasticity of demand: " << elasticity(pr, newPr, calqty(a,b,pr, true), calqty(a,b,newPr, true));
                    break;

                case 2:
                    cout << endl;
                    cout << "Enter c: "; cin >> c;
                    cout << "Enter d: "; cin >> d;
                    cout << "Enter current price: "; cin >> pr;
                    cout << "Enter new price: "; cin >> newPr;
                    cout << "Price elasticity of supply: " << elasticity(pr, newPr, calqty(c,d,pr,false), calqty(c,d,newPr,false));

                    break;

                case 3:
                    cout << "Income elasticity of demand :( " << endl;

                    //cout << "Enter income: "; cin >> income;
                    //cout << "Enter new income: "; cin >> newIncome;

                    break;

                case 4:
                    cout << "Cross Elasticity of demand :( " << endl;
                    //cout << "Enter current price of related good: "; cin >> pr;
                    //cout << "Enter new price of related good: "; cin >> pr;

                    break;

                default:
                    cout << "Sorry! There is an error in your choice of input. " << endl;
            }
            break;

            case 3:
                cout << "Enter x1: "; cin >> a;
                cout << "Enter x2: "; cin >> b;
                cout << "Enter y1: "; cin >> c;
                cout << "Enter y2: "; cin >> d;
                cout << "Elasticity: " << elasticity(a, b, c, d) << endl << endl;
                break;

        default:
            cout << "Sorry! There is an error in your choice of input. " << endl;
    }
    return 0;
}

double calculateEquilibrium(int a, int b, int c, int d, bool var)
{
    if(var)
        return ((double)(a*d + b*c)) / (b+d);
    else
        return (a-c)/(b+d);
}

double calqty(int a, int b, int p, bool choice) //1 -- True -- Demand, 0 -- False -- Supply
{
    if(choice)
        return (double)(a-p)/b;

    return (double)(p-a)/b;
}

double elasticity(int pr0, int pr1, int qty0, int qty1)
{
    int deltaPr = abs(pr1 - pr0);
    int deltaQty = abs(qty1 - qty0);
    double avgPr = ((double)(pr1 + pr0)) / 2.0;
    double avgQty = ((double)(qty1 + qty0)) / 2.0;

    return ( ((double)deltaQty)/avgQty ) / ( ((double)deltaPr)/avgPr);
}
