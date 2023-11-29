
<!-- README.md is generated from README.Rmd. Please edit that file -->

# simcdm

<!-- badges: start -->

[![R-CMD-check](https://github.com/tmsalab/simcdm/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/tmsalab/simcdm/actions/workflows/R-CMD-check.yaml)
[![Package-License](https://img.shields.io/badge/license-GPL%20(%3E=2)-brightgreen.svg?style=flat)](https://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN Version
Badge](https://www.r-pkg.org/badges/version/simcdm)](https://cran.r-project.org/package=simcdm)
[![CRAN
Status](https://badges.cranchecks.info/worst/simcdm.svg)](https://cran.r-project.org/web/checks/check_results_simcdm.html)
[![RStudio CRAN Mirror’s Monthly
Downloads](https://cranlogs.r-pkg.org/badges/simcdm?color=brightgreen)](https://www.r-pkg.org/pkg/simcdm)
[![RStudio CRAN Mirror’s Total
Downloads](https://cranlogs.r-pkg.org/badges/grand-total/simcdm?color=brightgreen)](https://www.r-pkg.org/pkg/simcdm)
<!-- badges: end -->

The goal of `simcdm` is to provide flexible ways to simulate data under
cognitive diagnostic models.

## Installation

You can install `simcdm` from GitHub with:

``` r
# install.packages("remotes")
remotes::install_github("tmsalab/simcdm")
```

## Usage

To use `simcdm`, load the package using:

``` r
library("simcdm")
```

## Overview

There are four distinct sets of functions within the package:

- Attributes: `attribute_classes()`, `attribute_bijection()`,
  `attribute_inv_bijection()`, and `sim_subject_attributes()`.
- Matrix: `sim_q_matrix()` and `sim_eta_matrix()`
- Deterministic Input, Noisy And Gate (DINA): `sim_dina_items()` and
  `sim_dina_attributes()`
- reduced Reparameterized Unified Model (rRUM): `sim_rrum_items()`

Functions that use random numbers to simulate values are named with the
prefix of `sim_*()`. This is done to allow for functions to be quickly
identified and used through autocomplete inside of the [RStudio
IDE](https://posit.co/products/open-source/rstudio/) or [VS
Code](https://code.visualstudio.com/). At a later time, the
`attribute_*()` will likely be moved to a different package.

For more details, please see the [package vignettes](vignettes/):

- [Overview of
  `simcdm`](https://tmsalab.github.io/simcdm/articles/overview-simcdm.html)
- [Using `simcdm` in R
  packages](https://tmsalab.github.io/simcdm/articles/simcdm-in-packages.html)

## Authors

James Joseph Balamuta and Steven Andrew Culpepper with contributions
from Aaron Hudson.

## Citing the simcdm package

To ensure future development of the package, please cite `simcdm`
package if used during the analysis or simulations. Citation information
for the package may be acquired by using in *R*:

``` r
citation("simcdm")
```

## License

GPL (\>= 2)
