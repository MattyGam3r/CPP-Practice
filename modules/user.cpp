import Vector;
// Modules are compiled only once (rather than in each translation unit in which
// it is used) Two modules can be imported in either order without changing
// their meaning If you import or include something into a module, users of your
// module do not implicitly gain access to that:
//  import is not transitive
#include <cmath>

double sqrt_sum(Vector &v) {
  double sum = 0;
  for (int i = 0; i != v.size(); ++i)
    sum += std::sqrt(v[i]);
  return sum;
}
