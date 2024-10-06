#include <iostream>
#include <vector>
using namespace std;

void print(int n) {

  cout << n << endl;
  if (n >= 3)
    return;
  print(n + 1);
}

void print_name(int n, string name) {
  if (n == 0)
    return;

  cout << name << endl;
  print_name(n - 1, name);
}

void print_one_to_n(int i, int n) {
  if (n == 0)
    return;
  cout << i << endl;
  print_one_to_n(i + 1, n - 1);
}

void print_n_to_one(int n) {
  if (n == 0)
    return;
  cout << n << endl;
  print_n_to_one(n - 1);
}

int sum_of_n(int n) {
  if (n == 0)
    return 0;
  return n + sum_of_n(n - 1);
}

int fact(int n) {
  if (n == 1)
    return 1;
  return (n * fact(n - 1));
}

void printArray(int arr[], int n) {
  cout << "The reversed array is:- " << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void reverseArray(int arr[], int start, int end) {
  if (start >= end)
    return;
  swap(arr[start], arr[end]);
  reverseArray(arr, start + 1, end - 1);
}

void checkPalindrome(string arr, int start, int end) {
  if (start >= end) {
    cout << "Palindrome" << endl;
    return;
  }
  if (arr[start] != arr[end]) {
    cout << "Not a Palindrome" << endl;
    return;
  }
  checkPalindrome(arr, start + 1, end - 1);
}

void fibonacci_seq(int first, int second, int n) {
  int third = first + second;
  first = second;
  second = third;
  cout << third << " ";
  if (n == 0) {
    return;
  }
  fibonacci_seq(first, second, n - 1);
}

int main() {
  print(0);
  cout << endl;
  print_name(3, "John");
  cout << endl;
  print_one_to_n(1, 5);
  cout << endl;
  print_n_to_one(5);
  cout << endl;
  int sum = sum_of_n(5);
  cout << sum << endl;
  int ans = fact(5);
  cout << ans << endl;
  int n = 5;
  int arr[] = {5, 4, 3, 2, 1};
  reverseArray(arr, 0, n - 1);
  printArray(arr, n);
  cout << endl;
  // string s = "madam";
  string s = "hello";
  checkPalindrome(s, 0, s.length() - 1);
  cout << endl;
  int first = 0, second = 1;
  cout << first << " " << second << " ";
  fibonacci_seq(first, second, 6 - 2);
  return 0;
}
