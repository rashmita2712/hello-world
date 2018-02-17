#include<stdio.h>
int main()
{
    int loads,i,j,input;
    printf("Enter number of loads:");
    scanf("%d",&loads);
    double current[loads],current_between_loads[loads];
    for(i=0;i<loads;i++)
    {
        scanf("%lf",&current[i]);
    }
    for(i=loads-1;i>=0;i--)
    {
        j=loads-1;
        while(j>=i)
        {
            current_between_loads[i]=current_between_loads[i]+current[j];
            j--;
        }
    }
    double voltage_drop,resistance,power_loss,total_current=0,current_square=0;
    for(i=0;i<loads;i++)
    {
        total_current=total_current+current_between_loads[i];
    }
    printf("\nChoose any one of the known value");
    printf("\n1.Maximum Voltage Drop\n2.Value of resistance");
    printf("\nYour Selection:");
    scanf("%d",&input);
    switch(input)
    {
        case 1:
            {
                printf("\nEnter the maximum volatage drop:");
                scanf("%lf",&voltage_drop);
                resistance=voltage_drop/total_current;
                break;
            }
        case 2:
            {
                printf("\nEnter the value of resistance:");
                scanf("%lf",&resistance);
                voltage_drop=total_current*resistance;
                break;
            }
        default:
            printf("\nEnter valid number");
            break;
    }
    for(i=0;i<loads;i++)
    {
        current_square=current_square+(current_between_loads[i]*current_between_loads[i]);
    }
    power_loss=resistance*current_square;
    printf("\n------RESULT-----");
    printf("\nResistance at each section is %.3le ohm",resistance);
    printf("\nMaximum voltage drop is %.3lf volts",voltage_drop);
    printf("\nPower loss is %.3lf watts",power_loss);
    return 0;
}
