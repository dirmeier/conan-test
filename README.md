<h1 align="center"> cstat </h1>

![Build Status](https://travis-ci.org/rafstraumur/cstat.svg?branch=master)](https://travis-ci.org/rafstraumur/cstat.svg?branch=master)
[![codecov](https://codecov.io/gh/rafstraumur/cstat/branch/master/graph/badge.svg)](https://codecov.io/gh/rafstraumur/cstat)

Statistics header-only template library in C++.

## Introduction

`cstat` is just another header-only template library for sampling from density and mass functions. Mainly for demonstration purposes...

## Installation
 
In order to use `cstat` you need to make sure to have Eigen installed. If you have it, run:

```{shell}
autoreconf -vif
./configure CPPFLAGS="-I/path/to/eigen"
```

from the terminal. Then compile and check if everything works using:

```shell
make
make check
```

## Author

* Simon Dirmeier <a href="mailto:simon.dirmeier@gmx.de">simon.dirmeier@gmx.de</a>
