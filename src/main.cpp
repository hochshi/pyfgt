#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <fgt.hpp>


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(pyfgt, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: cmake_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("direct", [](const Eigen::MatrixXd& x, const Eigen::MatrixXd& y, double bandwidth) {
            return fgt::direct(x, y, bandwidth);
    });
    m.def("direct3", [](const Eigen::Matrix<double, Eigen::Dynamic, 3>& x, const Eigen::Matrix<double, Eigen::Dynamic, 3>& y, double bandwidth) {
            return fgt::direct(x, y, bandwidth);
    });

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
