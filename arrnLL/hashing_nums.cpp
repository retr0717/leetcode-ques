#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Enter the size : ";
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cout << "\nEnter the item " << i + 1 << " : ";
    cin >> arr[i];
  }

  int hash[13] = {0};
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }

  int num;
  while (true) {
    cout << "\nEnter the number to get the frequency : ";
    cin >> num;
    cout << "\nFrequency of " << num << " is : " << hash[num];

    cout << "\nVacant indexes\n";
    for (int i = 0; i < n; i++) {
      if (hash[i] == 0) {
        cout << i;
      }
    }
  }
  return 0;
}
