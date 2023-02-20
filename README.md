# A pybind11 wrapper for fgt a C++ library for fast Gauss transforms.

|      CI              | status |
|----------------------|--------|
| conda.recipe         | [![Conda](https://github.com/hochshi/pyfgt/actions/workflows/conda.yml/badge.svg?branch=master)](https://github.com/hochshi/pyfgt/actions/workflows/conda.yml) |
| pip builds           | [![Pip](https://github.com/hochshi/pyfgt/actions/workflows/pip.yml/badge.svg)](https://github.com/hochshi/pyfgt/actions/workflows/pip.yml) |

[gitter-badge]:            https://badges.gitter.im/pybind/Lobby.svg
[gitter-link]:             https://gitter.im/pybind/Lobby
[actions-badge]:           https://github.com/pybind/cmake_example/workflows/Tests/badge.svg
[actions-conda-link]:      https://github.com/pybind/cmake_example/actions?query=workflow%3A%22Conda
[actions-conda-badge]:     https://github.com/pybind/cmake_example/workflows/Conda/badge.svg
[actions-pip-link]:        https://github.com/pybind/cmake_example/actions?query=workflow%3A%22Pip
[actions-pip-badge]:       https://github.com/pybind/cmake_example/workflows/Pip/badge.svg
[actions-wheels-link]:     https://github.com/pybind/cmake_example/actions?query=workflow%3AWheels
[actions-wheels-badge]:    https://github.com/pybind/cmake_example/workflows/Wheels/badge.svg
[appveyor-link]:           https://ci.appveyor.com/project/dean0x7d/cmake-example/branch/master
[appveyor-badge]:          https://ci.appveyor.com/api/projects/status/57nnxfm4subeug43/branch/master?svg=true

## Prerequisites

* A compiler with C++11 support
* Pip 10+ or CMake >= 3.4 (or 3.14+ on Windows, which was the first version to support VS 2019)
* Ninja or Pip 10+
* Eigen3


## Installation

Just clone this repository and pip install. Note the `--recursive` option which is
needed for the pybind11 and fgt submodules:

```bash
git clone --recursive https://github.com/hochshi/pyfgt.git
pip install ./pyfgt
```

With the `setup.py` file included in this example, the `pip install` command will
invoke CMake and build the pybind11 module as specified in `CMakeLists.txt`.



## Building the documentation

Documentation for the project is generated using Sphinx. Sphinx has the
ability to automatically inspect the signatures and documentation strings in
the extension module to generate beautiful documentation in a variety formats.
The following command generates HTML-based reference documentation; for other
formats please refer to the Sphinx manual:

 - `cd pyfgt/docs`
 - `make html`


## License

pyfgt is provided under a BSD-style license that can be found in the LICENSE
file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.


## Test call

```python
import pyfgt
pyfgt.direct
```
For usage see: [fgt](https://github.com/hochshi/fgt)
