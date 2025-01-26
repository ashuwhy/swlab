#include <iostream>
class List
{
private:
    // Implement this code
public:
    // Implement functionality of the list

    // This function is used to print the list.
    // The signature of this function is kept since 'friend' functions have not been covered yet. You may
    // ignore the 'friend' keyword and implement the function as a normal member function.
    friend std::ostream &operator<<(std::ostream &os, const List &list)
    {
        os << "[";
        // Implement this code
        os << "]";
        return os;
    }
};