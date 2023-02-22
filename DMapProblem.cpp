#include <iostream>
#include "capd/vectalg/Vector.hpp"
#include "capd/map/Map.hpp"
using namespace capd;
using namespace std;
using DVector = capd::vectalg::Vector<double, 0>;
using DMatrix = capd::vectalg::Matrix<double, 0, 0>;
using DMap = capd::map::Map<DMatrix>;
// ####################################################
int main(){
  int order=5;         // of Taylor method

  auto res1 = DVector::makeArray(order+1,1);

  DVector u1({2});

  string vfFormula1 = "var:y;fun:3-y;";
//  string vfFormula1 = "var:y;fun:-y+3;";

  DMap vf1(vfFormula1);

  vf1.setOrder(order);
  res1[0] = u1;
  vf1.computeODECoefficients(res1, order);

  for(int i=0;i<=order;++i) {
    cout << res1[i]<< endl;
  }
}
