int a () {
  return 0;
}

void b () {
  a();
}

void c () {
  for (int i = 0; i < 10; i ++) {
    b();
    b();
    b();
  }
}


int main () {
  c();
  return 0;
}


