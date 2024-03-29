// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// check_inside.cpp
integers point_in_polygon_cgal(doubles px, doubles py, doubles polyx, doubles polyy);
extern "C" SEXP _insidecgal_point_in_polygon_cgal(SEXP px, SEXP py, SEXP polyx, SEXP polyy) {
  BEGIN_CPP11
    return cpp11::as_sexp(point_in_polygon_cgal(cpp11::as_cpp<cpp11::decay_t<doubles>>(px), cpp11::as_cpp<cpp11::decay_t<doubles>>(py), cpp11::as_cpp<cpp11::decay_t<doubles>>(polyx), cpp11::as_cpp<cpp11::decay_t<doubles>>(polyy)));
  END_CPP11
}
// check_inside.cpp
list insidecgal_loop_mat(doubles xx, doubles yy, list lpxy);
extern "C" SEXP _insidecgal_insidecgal_loop_mat(SEXP xx, SEXP yy, SEXP lpxy) {
  BEGIN_CPP11
    return cpp11::as_sexp(insidecgal_loop_mat(cpp11::as_cpp<cpp11::decay_t<doubles>>(xx), cpp11::as_cpp<cpp11::decay_t<doubles>>(yy), cpp11::as_cpp<cpp11::decay_t<list>>(lpxy)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_insidecgal_insidecgal_loop_mat",   (DL_FUNC) &_insidecgal_insidecgal_loop_mat,   3},
    {"_insidecgal_point_in_polygon_cgal", (DL_FUNC) &_insidecgal_point_in_polygon_cgal, 4},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_insidecgal(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
