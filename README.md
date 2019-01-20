
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

There are three distinct sets of functions within the package:

  - Matrix: `sim_q_matrix()`, `sim_eta_matrix()`,
    `sim_attribute_classes()`, and `sim_subject_attributes()`.
  - Deterministic Input, Noisy And Gate (DINA): `sim_dina_items()` and
    `sim_dina_attributes()`
  - reduced Reparameterized Unified Model (rRUM): `sim_rrum_items()`

Notice that all functions in the package are named with the prefix of
`sim_*()`. This is done to all you to quickly find functions using
autocomplete inside of *RStudio*.

### Matrix Simulation

``` r
# Set a seed for reproducibility
set.seed(888)

# Setup Parameters
N = 500    # Number of Examinees / Subjects
J = 10     # Number of Items
K = 2      # Number of Skills / Attributes

# Simulate a Q matrix  (J items by K skills)
Q = sim_q_matrix(J, K)

# Create the ideal response matrix for each trait (J items by 2^K latent classes)
eta = sim_eta_matrix(K, J, Q)

# Generate latent attribute profile classes (2^K latent classes by K skills)
class_alphas = sim_attribute_classes(K)

# Generate latent attribute profile class for each subject (N subjects by K skills)
subject_alphas = sim_subject_attributes(N, K)

# Equivalent to:
# subject_alphas = class_alphas[sample(2 ^ K, N, replace = TRUE),]
```

### DINA Simulation

``` r
# Assign slipping and guessing values
ss = gs = rep(.2, J)

# Simulate item data under DINA model 
items_dina = sim_dina_items(subject_alphas, Q, ss, gs)

# Simulate attribute data under DINA model 
attributes = sim_dina_attributes(subject_alphas, Q)
```

### rRUM Simulation

``` r
# The probabilities of answering each item correctly for individuals 
# who do not lack any required attribute
pistar = rep(.9, J)

# Penalties for failing to have each of the required attributes
rstar  = .5 * Q

# Latent Class Probabilities
pis = c(.1, .2, .3, .4)

# Generate latent attribute profile with custom probability (N subjects by K skills)
subject_alphas = sim_subject_attributes(N, K, prob = pis)

# Equivalent to:
# class_alphas = sim_attribute_classes(K)
# subject_alphas = class_alphas[sample(2 ^ K, N, replace = TRUE, prob = pis),]

# Simulate rum items
rrum_items = sim_rrum_items(Q, rstar, pistar, subject_alphas)
```

### Package usage

The design of `simcdm` allows the package to be included in other *R*
packages using either the *R* or *C++* functions. The next section
details how to incorporate the *C++* code into the package or standalone
*C++* file.

Note, if you are not familiar with compiled code in *R* please feel free
to use the traditional way to import the *R* functions.

#### C++ Standalone Usage

Within the a *C++* file in `src/`, then add:

``` cpp
#include <RcppArmadillo.h>
#include <simcdm.h>

// [[Rcpp::depends(simcdm, RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat example_dina_sim(const arma::mat &alphas, const arma::mat &Q,
                           const arma::vec &ss, const arma::vec &gs) { 
                           
   arma::mat dina_items = simcdm::sim_dina_items(alphas, Q, ss, gs);
   
   return dina_items;
}
```

#### C++ Package

To use `simcdm` in your R package, modify the `DESCRIPTION` file by
adding:

    LinkingTo: Rcpp, RcppArmadillo (>= 0.9.200), simcdm
    Imports:
        Rcpp (>= 1.0.0)

Reference the simulation functions using `simcdm` namespace like so:

``` cpp
#include <simcdm.h>

// [[Rcpp::export]]
arma::mat example_rrum_sim(const arma::mat &Q, const arma::mat &rstar,
                           const arma::vec &pistar, const arma::mat &alpha) { 
                           
   arma::mat rrum_items = simcdm::sim_rrum_items(Q, rstar, pistar, alpha);
   
   return rrum_items;
}
```

## Authors

James Joseph Balamuta and Steven Andrew Culpepper with contributions
from Aaron Hudson.

## License

GPL (\>= 2)
