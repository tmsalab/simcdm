## Test environments

* local OS X install, R 4.3.2
* ubuntu 20.04 (on github-actios), R 4.3.2
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 1 note

Possibly mis-spelled words in DESCRIPTION:
  Culpepper (22:5, 23:5)
  Torre (24:11)
  de (24:5)

- We are issuing a patch for the package to address an issue with the compilation
  attributes detected in Rcpp's glue layer.
- Regarding mis-spellings:
  - `Culpepper`, `de`, and `Torre` are either parts of names or lastnames.

## Reverse dependencies

There are no reverse dependencies.
