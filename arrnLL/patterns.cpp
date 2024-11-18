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

  for (int i = 0; i < n; i++) {
    for (int j = 'A'; j <= 'A' + i; j++) {
      cout << (char)j << " ";
    }
    cout << "\n";
  }
}

void print15(int n) {

  cout << "\n";
  int k = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << (char)('A' + j) << " ";
    }
    cout << "\n";
  }
}

void print16(int n) {
  cout << "\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << (char)('A' + i) << " ";
    }
    cout << "\n";
  }
}

void print17(int n) {
  cout << "\n";
  for (int i = 0; i < n; i++) {
    // upper trinagle.
    for (int k = 0; k < n - i - 1; k++) {
      cout << " ";
    }
    // start print.
    char ch = 'A';
    int bPoint = ((2 * i) + 1) / 2;
    for (int j = 0; j < 2 * i + 1; j++) {
      cout << ch;
      if (j < bPoint)
        ch++;
      else
        ch--;
    }
    cout << "\n";
  }
}

void print18(int n) {
  cout << "\n";

  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--)
      cout << (char)('E' - j) << " ";
    cout << "\n";
  }
}

void print19(int n) {
  int k = 0;

  // upper symmetry.
  for (int i = 0; i < n; i++) {
    cout << "\n";
    for (int j = 1; j <= n - i; j++) {
      cout << "*";
    }

    // print space.
    for (int j = 0; j < k; j++) {
      cout << " ";
    }
    k = k + 2;

    // print star.
    for (int j = 1; j <= n - i; j++) {
      cout << "*";
    }
  }

  // lower symmetry.
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }

    // print space.
    for (int j = 0; j < k; j++) {
      cout << " ";
    }
    k = k - 2;

    // print star.
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
}

void print20(int n) {
  int k = (2 * n) - 2;
  int stars = 0;
  for (int i = 1; i <= (2 * n) - 1; i++) {

    // cout << "\nk = " << k << " i = " << i;
    cout << "\n";

    if (i > n)
      stars = (2 * n) - i;
    else
      stars = i;

    for (int j = 1; j <= stars; j++) {
      cout << "*";
    }

    // print space.
    for (int j = 0; j < k; j++) {
      cout << " ";
    }

    // print star.
    for (int j = 1; j <= stars; j++) {
      cout << "*";
    }

    if (i < n)
      k -= 2;
    else
      k += 2;
  }

  cout << "\n";
}

void print21(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void print22(int n) {
  cout << "\n";
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int left = j;
      int right = 2 * n - 2 - j;
      int down = 2 * n - 3 - i;

      cout << n - min(min(top, down), min(left, right));
    }
    cout << endl;
  }
}

int main() {
  // print8(9);
  print9(9);
  print10(9);
  print11(9);
  print12(5);
  print13(5);
  print14(5);
  print15(5);
  print16(5);
  print17(5);
  print18(5);
  print19(5);
  print20(5);
  print21(5);
  print22(5);
  return 0;
}
