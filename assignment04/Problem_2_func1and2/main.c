void func1(int a, int b, int c, int d, int e);
void func2(void);

int sum = 0;

int main()
{
  func2();
  
  return 0;
}

void func1(int v, int w, int x, int y, int z)
{
    sum = v+w+x+y+z;
}

void func2(void)
{
  func1(2, 4, 6, 8, 10);
}