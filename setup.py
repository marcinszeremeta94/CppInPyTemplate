from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

__version__ = "0.0.1"

#source files directories 
file_paths = glob("CppSource/*.cpp")
file_paths.extend(glob("CppSource/Basics/*.cpp"))

#module definition
ext_modules = [
    Pybind11Extension(
        "CppInPyTemplate",
        sorted(file_paths),
        define_macros = [('VERSION_INFO', __version__)],
        ),
]

#info data
setup(
    name="CppInPyTemplate",
    version=__version__,
    author="",
    author_email="",
    url="",
    description="",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
