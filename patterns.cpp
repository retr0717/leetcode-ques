#include <iostream>

using namespace std;

void print8(int n) {
  for (int i = 0; i < 5; i++) {

    for (int k = 0; k < i; k++) {
      cout << " ";
    }
    for (int j = 0; j < ((2 * 5) - ((2 * i) + 1)); j++) {
      cout << "*";
    }
    cout << "\n";
  }
}

void print9(int n) {
  for (int i = 0; i < n; i++) {
    // upper trinagle.
    for (int k = 0; k < n - i - 1; k++) {
      cout << " ";
    }
    // start print.
    for (int j = 0; j < 2 * i + 1; j++) {
      cout << "*";
    }
    cout << "\n";
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < i; k++) {
      cout << " ";
    }

    for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
      cout << "*";
    }

    cout << "\n";
  }
}

void print10(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      cout << "*";
    cout << "\n";
  }
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < i; j++)
      cout << "*";
    cout << "\n";
  }
}

void print11(int n) {
  int start = 0;
  for (int i = 0; i < n; i++) {
    if ((i % 2) == 0) {
      start = 1;
    }
    for (int j = 0; j <= i; j++) {
      cout << start;
      start == 1 ? start = 0 : start = 1;
    }
    cout << "\n";
  }
}

void print12(int n) {
  cout << "\n";

  int space = (2 * (n - 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j;
    }
    for (int j = 1; j <= space; j++) {
      cout << " ";
    }
    space -= 2;

    for (int k = i; k >= 1; k--) {
      cout << k;
    }
    cout << "\n";
  }
}

void print13(int n) {
  cout << "\n";

  int k = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << k << " ";
      k++;
    }
    cout << "\n";
  }
}

void print14(int n) {
  cout << "\n";

  for (int i = 65; i < n; i++) {
    for (int j = 65; j <= i; j++) {
      cout << (char)j << " ";
    }
    cout << "\n";
  }
}

void print15(int n) {

  cout << "\n";
  int k = n;
  for (int i = 65; i < n; i++) {
    for (int j = 65; j < k; j++) {
      cout << (char)j << " ";
    }
    k--;
    cout << "\n";
  }
}

void print16(int n) {
  cout << "\n";

  for (int i = 65; i < n; i++) {
    for (int j = 65; j <= i; j++) {
      cout << (char)i << " ";
    }
    cout << "\n";
  }
}

int main() {
  // print8(9);
  print9(9);
  print10(9);
  print11(9);
  print12(5);
  print13(5);
  print14(77);
  print15(77);
  print16(77);
  return 0;
}
