#include <vector>
#include <R_ext/Rdynload.h>

#include "cpp11.hpp"
#include "cpp11/integers.hpp"
#include "cpp11/doubles.hpp"
using namespace cpp11;
namespace writable = cpp11::writable;




#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Point_2<K> Point;
typedef CGAL::Polygon_2<K> Polygon_2;

//https://doc.cgal.org/4.14.3/Polygon/Polygon_2Example_8cpp-example.html
[[cpp11::register]]
integers point_in_polygon_cgal(doubles px, doubles py, doubles polyx, doubles polyy)
{

  Polygon_2 polys;
  for (int ip = 0; ip < polyx.size(); ip++){
    polys.push_back( Point(polyx[ip], polyy[ip]));
  }
  // bool IsSimple    = polys.is_simple();
  // std::cout << "polygon p is";
  // if (!IsSimple) std::cout << " not";
  // std::cout << " simple." << std::endl;
  writable::integers pip(px.size());
  for (int i = 0; i < px.size(); i++) {
    Point q(px[i], py[i]);
    if (polys.bounded_side(q) == CGAL::ON_BOUNDED_SIDE) {
      pip[i] = 1;
    } else {
      pip[i] = 0;
    }
  }
  return pip;
}



// list of matrix polygons matches POLYGON (or unlist(MULTIPOLYGON, recursive = F))
[[cpp11::register]]
list insidecgal_loop_mat(doubles xx, doubles yy, list lpxy) {
  writable::list out;
  for (int i = 0; i < lpxy.size(); i++)  {


    writable::doubles polyx;
    writable::doubles polyy;

    cpp11::doubles_matrix<cpp11::by_column> mat = lpxy[i];
    for (int j = 0; j < mat.nrow(); j++){
     polyx.push_back(mat(j, 0));
     polyy.push_back(mat(j, 1));
    }


    out.push_back(point_in_polygon_cgal(xx, yy, polyx, polyy));

  }
  return out;
}
