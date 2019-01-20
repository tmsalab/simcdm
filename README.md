
<!-- README.md is generated from README.Rmd. Please edit that file -->

# simcdm

[![Build
Status](https://travis-ci.org/tmsalab/simcdm.svg)](https://travis-ci.org/tmsalab/simcdm)
[![Package-License](http://img.shields.io/badge/license-GPL%20\(%3E=2\)-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](http://www.r-pkg.org/badges/version/simcdm)](https://cran.r-project.org/package=simcdm)
[![Downloads](http://cranlogs.r-pkg.org/badges/simcdm?color=brightgreen)](http://www.r-pkg.org/pkg/simcdm)
[![Coverage
status](https://codecov.io/gh/tmsalab/simcdm/branch/master/graph/badge.svg)](https://codecov.io/github/tmsalab/simcdm?branch=master)

The goal of simcdm is to simulate cognitive diagnostic model data.

## Installation

You can install simcdm from GitHub with:

``` r
# install.packages("devtools")
devtools::install_github("tmsalab/simcdm")
```

## Usage

To use `simcdm`, load the package using:

``` r
library("simcdm")
```

## Overview

There are three distinct sets of functions within the package:

  - Matrix: `sim_q_matrix()`, `sim_eta_matrix()`,
    `sim_attribute_classes()`, and `sim_subject_attributes()`.
  - Deterministic Input, Noisy And Gate (DINA): `sim_dina_items()` and
    `sim_dina_attributes()`
  - reduced Reparameterized Unified Model (rRUM): `sim_rrum_items()`

Note that all functions in the package are named with the prefix of
`sim_*()`. This is done to allow for functions to be quickly identified
and used through autocomplete inside of the [RStudio
IDE](https://www.rstudio.com).

For more details, please see the ["Overview of `simcdm`
vignette](vignettes/overview-simcdm.Rmd).

## Authors

James Joseph Balamuta and Steven Andrew Culpepper with contributions
from Aaron Hudson.

## License

GPL (\>= 2)
