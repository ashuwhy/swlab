// author: Ashutosh Sharma

#include <iostream>

using namespace std;

int get_num_after_increment(int k)
{
    return k + 1;
}

int main()
{
    int start, end;
    
    cout << "Enter a start: ";
    cin >> start;

    for (int i = 0; i < 5; ++i) {
        cout << start << endl;
        start = get_num_after_increment(start); // increment the number
    }

    cout << "Printed five numbers." << endl;

    cout << "Enter end: ";
    cin >> end;

    while (start <= end) {
        cout << start << endl;
        start = get_num_after_increment(start); // increment the number
    }

    return 0;
}


