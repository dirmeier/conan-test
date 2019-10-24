# conan-test

[![Project Status](http://www.repostatus.org/badges/latest/concept.svg)](http://www.repostatus.org/#concept)

> A small header only library to check out `conan.io`

## About

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

* Simon Dirmeier <a href="mailto:simon.dirmeier@web.de">simon.dirmeier @ web.de</a>
