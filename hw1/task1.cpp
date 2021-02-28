#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {

    string name;
    int price, temperature;
    bool hasCashback;
    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> boolalpha>>  hasCashback;
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;

    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    std::cout << name << '\n';
    cout<<"Price:..........."<<hex<<uppercase<<setfill('0')<<setw(8)<<price<<endl;
    cout<<"Has cash-back:"<<boolalpha<<setfill('.')<<setw(11)<<hasCashback<<endl;
    cout<<"Max temperature:"<<dec<<showpos<<setfill('.')<<setw(9)<<temperature<<endl;

    return 0;


}
