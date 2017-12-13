#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector<int> giftsPrice;
enum Name{Andrew, Belle, Chris, Desiree, Edward, Fabienne, Exit};

vector<string> read_file(string file, vector<string> giftList, bool wishes){

    int size = 0;
    ifstream infile;
    infile.open(file.c_str());
    char a;
    a = infile.get();
    int price = 0;
    while(infile && a != '\n'){
        string price_string;
        string name;
        if(!wishes){
        while(a != ' '){
             price_string += a;
             a = infile.get();
        }
        std::istringstream (price_string) >> price;
        giftsPrice.push_back(price);
        }
        cout << "price: " << price;
        while(a != '\n'){
            name += a;
            a = infile.get();
        }
        a = infile.get();
        giftList.push_back(name);
        cout << " Name : " << name << endl;
    }
    cout << "muh" << endl;
    infile.close();
    return giftList;


}

void gifts(vector<string> store, vector<int> prices, vector<string> wishes){

    int budget;
    std::istringstream (wishes[0]) >> budget;

}

int main()
{
    cout << "making store list..." << endl;
    vector<string> StoreGifts;
    StoreGifts = read_file("giftstore.txt", StoreGifts, false);
    bool go = false;
    while(go){
    cout << "Please select a name or exit Andrew = 1, Belle = 2, Chris = 3, Desiree = 4, Edward = 5, Fabienne = 6, Exit = 7" << endl;
    int select;
    cin >> select;
    switch (select){
        case 1:
            vector<string> andrew;
            andrew = read_file("Andrew.txt", andrew, true);
            break;
        case 2:
            vector<string> belle;
            belle = read_file("Belle.txt", belle, true);
            break;
        case 3:
            vector<string> chris;
            chris = read_file("Chris.txt", chris, true);
            break;
        case 4:
            vector<string> desiree;
            desiree = read_file("Desiree.txt", desiree, true);
            break;
        case 5:
            vector<string> edward;
            edward = read_file("Edward.txt", edward, true);
            break;
        case 6:
            vector<string> fabienne;
            fabienne = read_file("Fabienne.txt", fabienne, true);
            break;
        case 7:
            go = false;
            break;
        case default:
            cout << "Choose valid number" << endl;
    }
    cout << "Terminating" << endl;
    }
}
