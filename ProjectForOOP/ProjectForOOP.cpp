#include <iostream>
#include <time.h>
#include "Administrator.h"
#include "Date.h"
using namespace std;


int main()
{
    Date date(23, 2, 2021);
    cout << date.GetDayCount();
    
}
