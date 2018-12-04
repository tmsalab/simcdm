
<!-- README.md is generated from README.Rmd. Please edit that file -->

# simcdm

[![Build
Status](https://travis-ci.org/tmsalab/simcdm.svg)](https://travis-ci.org/tmsalab/simcdm)
[![Package-License](http://img.shields.io/badge/license-GPL%20\(%3E=2\)-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](http://www.r-pkg.org/badges/version/simcdm)](https://cran.r-project.org/package=simcdm)
[![Downloads](http://cranlogs.r-pkg.org/badges/simcdm?color=brightgreen)](http://www.r-pkg.org/pkg/simcdm)
[![Coverage
status](https://codecov.io/gh/tmsalab/simcdm/branch/master/graph/badge.svg)](https://codecov.io/github/tmsalab/simcdm?branch=master)

The goal of simcdm is to simulate cognitive diagnostic model data

## Installation

You can install simcdm from github with:

``` r
# install.packages("devtools")
devtools::install_github("tmsalab/simcdm")
```

## Usage

To use `simcdm`, load the package and design the initial Q matrix that
the item response data should be generated from.

Depending on the model being simulated, e.g. rRUM or DINA, additional
parameters will need to be supplied.

Consider the following generation routine for DINA data that follows de
la Torre (2009) simulation.

``` r
library("simcdm")
N = 200
K = 5
J = 30
delta0 = rep(1, 2 ^ K)

# Creating Q matrix
Q = matrix(rep(diag(K), 2), 2 * K, K, byrow = TRUE)
for (mm in 2:K) {
  temp = combn(seq_len(K), m = mm)
  tempmat = matrix(0, ncol(temp), K)
  for (j in seq_len(ncol(temp)))
    tempmat[j, temp[, j]] = 1
  Q = rbind(Q, tempmat)
}
Q = Q[seq_len(J), ]

# Setting item parameters and generating attribute profiles
ss = gs = rep(.2, J)
PIs = rep(1 / (2 ^ K), 2 ^ K)
CLs = c((1:(2 ^ K)) %*% rmultinom(n = N, size = 1, prob = PIs))

# Defining matrix of possible attribute profiles
As = rep(0, K)
for (j in seq_len(K)) {
  temp = combn(1:K, m = j)
  tempmat = matrix(0, ncol(temp), K)
  for (j in seq_len(ncol(temp)))
    tempmat[j, temp[, j]] = 1
  As = rbind(As, tempmat)
}
As = as.matrix(As)

# Sample true attribute profiles
Alphas = As[CLs, ]

# Simulate data under DINA model
gen_data = sim_dina(Alphas, Q, ss, gs)
```

### Package usage

To use `simcdm` in your R package, modify the `DESCRIPTION` file by
adding:

    LinkingTo: Rcpp, RcppArmadillo, simcdm
    Imports:
        Rcpp (>= 0.12.14)

Within the `C++` file, then add:

``` cpp
#include <simcdm.h> // simcdm header
```

Reference the simulation functions using `simcdm` namespace like so:

``` cpp
#include <simcdm.h>

// [[Rcpp::export]]
arma::mat example_dina_sim(const arma::mat &alphas, const arma::mat &Q,
                           const arma::vec &ss, const arma::vec &gs) { 
   arma::mat items_dina = simcdm::sim_dina(alphas, Q, ss, gs);
   return items_dina;
}

// [[Rcpp::export]]
arma::mat example_rrum_sim(const arma::mat &Q, const arma::mat &rstar,
                           const arma::vec &pistar, const arma::mat &alpha) { 
   arma::mat items_rrum = simcdm::sim_rrum(Q, rstar, pistar, alpha);
   return items_rrum;
}
```

## Authors

James Joseph Balamuta and Steven Andrew Culpepper

## License

GPL (\>= 2)
