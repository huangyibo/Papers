#include <newton/newton.hpp>

int main()
{
  float a[4] = {1.0, 1.0, 1.0, 1.0};
  float b[4] = {2.0, 2.0, 2.0, 2.0};
  float c[4] = {};

  newton::numeric_vector<float> A = a;
  newton::numeric_vector<float> B = b;
  newton::numeric_vector<float> C = c;

  C = A * B;
  thrust::copy(C.begin(), C.end(), std::ostream_iterator<float>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}
