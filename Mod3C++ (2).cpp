//Chase Carter
//05/08/23
//CS-210




#include <iostream>
#include<ctime>
// Ctime is a function that returns a string representing the local time based on the timer.

#include<iomanip>
// iomainp is a function used to set fill character it is also for the decimal.

using namespace std;

class time_module3 {
//Name and create a class.

public:
int hour;
int minute;
int seconds;
//List all the variables that will be used, they will all be integers.

};

class hours_12_format:public time_module3 {
//In this block I will set the class and methods, class member are set to public this can later be changed if necessary.

public:
string variable_1;
// This variable will be set for the AM & PM

hours_12_format()
//The format in the instructions were listed to be hours 12 format.

{
time_t now = time(0);
// Time t is a data type in C ++. Set it starting to 0.

tm *ltm = localtime(&now);
// tm or "translate memory" is used in C ++ for time. This is specific to C/C++. This aids in programming time.

//This block will build the first time calculator.
hour=ltm->tm_hour;
// This is  minus greater than, "Arrow operator" all this does is store the information to the variable.

minute=ltm->tm_min;
// Same thing as the previous line, stores the information to the variable.

seconds=ltm->tm_sec;
// Same thing as the previous line, stores the information to the variable.

//This is the beginning of my first loop.
if(hour>=12)
//If the variable hour is greater than or equal to 12.

{
variable_1 = "P M";
//Set the variable1 to PM if..
hour-=12;
//Set the variable hour = hour - 12.

}
else
variable_1 = "A M";
//Set the variable1 to AM if..

}

void add_hour(int h)
// Void is a function in C++ that tells that the function to not return a value.
{
hour+=h;
//Set the variable hour = hour + h.

if(hour>12)
//Beginning of loop, if hour is greater than 12.

{
hour-=12;
//Set the variable hour = hour - 12.

}
else if(hour>=12)
//If the variable hour is greater than or equal to 12.

{
if(variable_1 == "A M")
//Another loop, if variable 1 is equal to AM.

{
variable_1 = "P M";
//If variable 1 is equal to PM.

}
else if(variable_1 == "P M")
{
variable_1 = "A M";
}
}
}




void add_minute(int min)
// Same as the last block, void is a function in C++ that tells that the function to not return a value.

{
minute+=min;
//Set the variable min = min + h.

if(minute>=60)
//Beginning of loop, if min is greater than 60.

{
int h = minute/60;
//Set the variable h to equal to min divided by 60.

minute -= 60*h;
//Min = min - 60 * h.

add_hour(h);
}
}

void add_seconds(int sec)
//This block will be for adding seconds.

{
seconds+=sec;
//Set sec = sec + sec

if(seconds>=60)
//Loop if sec is greater than 60.

{
int m = seconds/60;
// Set the variable m = sec divided by 60.

seconds-=60*m;
//Set sec = sec - 60 * m.

add_minute(m);
}
}
};



class hours_24_format:public time_module3 {
//In this block I will set the class and methods, class member are set to public this can later be changed if necessary.

public:
int hour;
int minute;
int seconds;
// This is a public class set all the variables to integers.

hours_24_format()
//The format in the instructions were listed to be hours 24 format.

{
time_t now = time(0);
// Time t is a data type in C ++. Set it starting to 0.

tm *ltm = localtime(&now);
// Same as other block, tm or "translate memory" is used in C ++ for time. This is specific to C/C++. This aids in programming time.

hour=ltm->tm_hour;
//Set the hour to 1tm to tm_hour.

minute=ltm->tm_min;
//Set the min to 1tm to tm_min.

seconds=ltm->tm_sec;
//Set the sec to 1tm to tm_sec.

}
void add_hour(int h)
// Already stated what void does, just apply it to add hour and h.
{
hour+=h;
// Hour = hour + h.

if(hour>=24)
//If hour is greater than or equal to 24.

{
hour -= 24;
//Set hour = hour - 24.

}
}
void add_minute(int min)
//Void min.

{
minute+=min;
//Set min = min + min.

if(minute>=60)
//Set min is greater than or equal to 60.

{
int h = minute/60;
//Set h = min divided by 60.

minute -= 60*h;
//Set min = min - 60 h.

add_hour(h);
}
}

void add_seconds(int sec)
//Void  add sec and sec.

{
seconds+=sec;
//Set sec = sec+ sec.

if(seconds>=60)
//set set greater than or equal to 60.

{
int m = seconds/60;
//Set m = sec divided by 60.

seconds-=60*m;
//Set sec = sec 60 * m.

add_minute(m);
}
}
};





void display(hours_12_format h1,hours_24_format h2)
//This is the display of the first clock for 12 hrs.
//This will also be for the display for the second clock 24 hours.
//This is how the directions show how it was to be displayed in the output.

{
cout<<"\t\t*************************\t\t";
//In this block these are all display lines.
// \t is tab, so I used this to tab twice.

cout<<"*************************\n";
//In this display line I use \n this is for a new line.

cout<<"\t\t*\t12-Hour Clock\t*\t\t";
//Multiple tabs.

cout<<"*\t24-Hour Clock\t*\n";
//Multiple tabs

cout<<"\t\t*\t"<<setw(2) << setfill('0')<<h1.hour<<":"<<setw(2) << setfill('0')<<h1.minute<<":"<<setw(2) << setfill('0')<<h1.seconds<<" "<<h1.variable_1<<"\t*\t\t";
// This block used the methods that were made in the blocks about to make the clock function.
// It fills and it actually sets the clock.
//This is for the first block.

cout<<"*\t"<<setw(2) << setfill('0')<<h2.hour<<":"<<setw(2) << setfill('0')<<h2.minute<<":"<<setw(2) << setfill('0')<<h2.seconds<<"\t*\n";
//This is for the second clock.

cout<<"\t\t*************************\t\t";
//This is cosmetic, it is for how the clock is going to be displayed.

cout<<"*************************\n";
//This is cosmetic, it is for how the clock is going to be displayed.


}



int main()
// This block is for setting the clock equal to the variables.
// This block is for the 3rd display. This is how it was show in the directions.

{
hours_12_format h1;
hours_24_format h2;
display(h1,h2);
int choice = 0;
while(choice!=4)
{
cout<<"\n\n*************************\n";
//This is cosmetic, it is for how the clock is going to be displayed.

cout<<"* 1 - Add One Hour\t*\n";
//This is for the user, so they can input number and make the clock change.

cout<<"* 2 - Add One Minute\t*\n";
//This is for the user, so they can input number and make the clock change.

cout<<"* 3 - Add One Second\t*\n";
//This is for the user, so they can input number and make the clock change.

cout<<"* 4 - Exit Program\t*\n";
//This is for the user, so they can input number and make the clock change.

cout<<"*************************\n";
// This is how the directions showed how the input options were to be displayed.

cin>>choice;
switch (choice)
// Switch is so that the variable is able to be tested. The variable will be "switched" against the values listed.

{
case 1: h1.add_hour(1);
// This is the conditions for the test case. All of the following block.

h2.add_hour(1);
break;
case 2: h1.add_minute(1);
h2.add_minute(1);
break;
case 3: h1.add_seconds(1);
h2.add_seconds(1);
break;
case 4:
exit(0);
break;
default:
cout<<"Enter your pick.\n";
}
system("cls");
//cls is to clear the screen in c++.
display(h1,h2);
}
}








