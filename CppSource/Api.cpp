#include "ApiIncludes.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void longLastingFunc();

PYBIND11_MODULE(CppInPyTemplate, m) 
{
    //functions in module
    m.def("mull", &basics::mull, "multiply two numbers");
    m.def("list_mull", &basics::multiplyList, "multiply all list elemnts by a given value");
    m.def("two_by_two_mull", [](int a, int b){
        return py::make_tuple(basics::mull(a,2), basics::mull(b,2));
    });
    m.def("divid", &basics::divid, "divide two numbers");
    m.def("printEven", &basics::printEven);
    m.def("longLastingFunc", &longLastingFunc);

    //classes in module
    py::class_<basics::DoCalcs>(m, "CppCalcs")
        .def(py::init<int>())
        .def("multiply", &basics::DoCalcs::multiplyByArg)
        .def_property("multiplier",  &basics::DoCalcs::getInnerArg, &basics::DoCalcs::setInnerArg)
        .def("make_white_image", [](basics::DoCalcs &self){
            py::array out = py::cast(self.make_white_image());
            return out;
        })
        .def_property_readonly("white_image", [](basics::DoCalcs &self){
            py::array out = py::cast(self.make_white_image());
            return out;
        })
        ;
}

void longLastingFunc()
{
    py::gil_scoped_release release;
    std::cout << "starting " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "task finished" << std::endl;

    py::gil_scoped_acquire acquire; 
    auto list = py::list(); // immutable only one instance, segfault occurs when accesing from different threads
    list.append(1);
    list.append("smt");
}
