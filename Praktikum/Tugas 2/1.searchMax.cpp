#include <iostream>
using namespace std;

int main()
{
    int n;
    float arr[100];

    cout << "Masukkan banyak angka : ";
    cin >> n;
    cout << endl;

    for(i = 0; i < n; ++i)
    {
       cout << "masukkan angka ke- " << i + 1 << " : ";
       cin >> arr[i];
    }

    for(i = 1;i < n; ++i)
    {
       if(arr[0] < arr[i])
           arr[0] = arr[i];
    }
    cout << "angka terbesar adalah = " << arr[0];

    return 0;
}