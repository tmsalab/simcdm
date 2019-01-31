## Test environments

* local OS X install, R 3.5.2
* ubuntu 14.04 (on travis-ci), R 3.5.2
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 1 note

Days since last update: 1

Possibly mis-spelled words in DESCRIPTION:
  Culpepper (22:5, 23:5)
  Torre (24:11)
  de (24:5)

- We are issuing a patch for the package 1 day after it was listed because 
  of a compilation failure on Solaris, which is caused by an ambiguous overload
  of the `pow()` function.
- Regarding mis-spellings:
  - `Culpepper`, `de`, and `Torre` are either parts of names or lastnames.

## Reverse dependencies

There are no reverse dependencies.
