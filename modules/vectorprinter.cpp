export module vectorprinter;

import std;

export template <typename T>
void print(std::vector<T> &v) // This is the only function seen by users
{
  cout << "{\n";
  for (const T &val : v)
    std::cout << "  " << val << '\n';
  cout << '}';
}
