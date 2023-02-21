#include <fgt.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

using Matrix3 = Eigen::Matrix<double, Eigen::Dynamic, 3, Eigen::RowMajor>;
using Matrix3Ref = Eigen::Ref<const Matrix3>;

template<class T>
Eigen::VectorXd direct(const T &x, const T &y,
                       double bandwidth) {
  return fgt::direct(x, y, bandwidth);
}

template<class T>
Eigen::VectorXd wdirect(const T &x, const T &y,
                        double bandwidth, const fgt::VectorRef weights) {
  return fgt::direct(x, y, bandwidth, weights);
}

template<class T>
Eigen::VectorXd direct_tree(const T &x, const T &y,
                       double bandwidth) {
  return fgt::direct_tree(x, y, bandwidth, 1e-8);
}

template<class T>
Eigen::VectorXd wdirect_tree(const T &x, const T &y,
                        double bandwidth, const fgt::VectorRef weights) {
  return fgt::direct_tree(x, y, bandwidth, 1e-8, weights);
}

template<class T>
Eigen::MatrixXd mat_direct(const T&x, const T& y, double bandwidth) {
  return fgt::mat_direct(x, y, bandwidth);
}

template<class T>
Eigen::MatrixXd mat_direct_tree(const T&x, const T& y, double bandwidth) {
  return fgt::mat_direct_tree(x, y, bandwidth, 1e-8);
}

PYBIND11_MODULE(pyfgt, m) {
  m.doc() = R"pbdoc(
        Pybind11 pyfgt 
        -----------------------

        .. currentmodule:: pyfgt

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

  m.def("direct", &direct<fgt::MatrixRef>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);
  m.def("wdirect", &wdirect<fgt::MatrixRef>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::arg("weights").noconvert(), py::return_value_policy::take_ownership);

  m.def("direct3", &direct<Matrix3Ref>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);
  m.def("wdirect3", &wdirect<Matrix3Ref>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::arg("weights").noconvert(), py::return_value_policy::take_ownership);
    
  m.def("mat_direct", &mat_direct<fgt::MatrixRef>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);

  m.def("mat_direct3", &mat_direct<Matrix3Ref>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);

  m.def("direct_tree", &direct_tree<fgt::MatrixRef>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);
  m.def("wdirect_tree", &wdirect_tree<fgt::MatrixRef>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::arg("weights").noconvert(), py::return_value_policy::take_ownership);

  m.def("direct_tree3", &direct_tree<Matrix3Ref>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);
  m.def("wdirect_tree3", &wdirect_tree<Matrix3Ref>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::arg("weights").noconvert(), py::return_value_policy::take_ownership);
    
  m.def("mat_direct_tree", &mat_direct_tree<fgt::MatrixRef>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);
    
  m.def("mat_direct_tree3", &mat_direct_tree<Matrix3Ref>, py::arg("x").noconvert(), py::arg("y").noconvert(),
        py::arg("bandwidth"), py::return_value_policy::take_ownership);
    
#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
