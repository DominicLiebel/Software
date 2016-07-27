//
//  wechselstucke.h
//  test
//
//  Created by Dominic Liebel on 24.07.16.
//  Copyright © 2016 Dominic Liebel. All rights reserved.
//

#define wechselstucke_h

void wechselgeld(void)
{
    /*
     Declare variables cent per euro(100).
     Declare which coins are avaiable for change (kleingeld).
     Declare the entered amount of money (geld).
     Declare an int wechselstuck, and set it to 0 (for counting the amount of change needed).
     */
    int cent_pro_euro = 100;
    float kleingeld[8] = {1,2,5,10,20,50,100,200};
    float geld;
    int wechselstucke = 0;
    
    //Asks for users input for the amount of money to change.
    printf("Wie viel Geld muss ich wechseln?: ");
    scanf("%f", &geld);
    
    //Checks if the input is over 100.000€ and gives you an error message if so, if not program continues normally.
    if(geld > 1000000){
        printf("Input too high. Please restart the program.!\n");
    }else {
    
    //Turns the input from user from Euro to cent (multiplies input times 100).
    float geld_in_cent = geld * cent_pro_euro;
    for(int x = 7; x != -1; x--)
    {
        //Go through our array kleingeld from 7 to 0.
        while(kleingeld[x] <= geld_in_cent)
        {
            //Checks if the current coin is larger than the money to change.
            if(kleingeld[x] <= geld_in_cent)
                {
                    //subtracts the value of the coin from the value of the money left to be changed.
                    geld_in_cent -= kleingeld[x];
                    //If the amount to change is bigger than the current coin, wechselstuck is increased by 1.
                    wechselstucke++;
                }
        }
    }
    //Prints the number of coins that are needed change the user input to the console.
            printf("%i\n", wechselstucke);
    }
}
