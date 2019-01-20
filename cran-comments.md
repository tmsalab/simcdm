## Test environments
* local OS X install, R 3.5.2
* ubuntu 14.04 (on travis-ci), R 3.5.2
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 1 note

New submission

Possibly mis-spelled words in DESCRIPTION:
  CDM (3:45)
  Culpepper (22:5, 23:5)
  Torre (24:11)
  de (24:5)
  rRUM (21:44)

Found the following (possibly) invalid URLs:
  URL: http://www.r-pkg.org/pkg/simcdm (moved to https://www.r-pkg.org:443/pkg/simcdm)
    From: README.md
    Status: 404
    Message: Not Found
    
- This is a new release. As a result, the package has yet to be listed on 
  r-pkg, which is why the URL is failing.
- Regarding mis-spellings:
  - CDM and rRUM are the appropriate acronyms for 
    Deterministic Input, Noisy "And" Gate (DINA) and
    reduced Reparameterized Unified Model (rRUM).
  - `Culpepper`, `de`, and `Torre` are either parts of names or lastnames.

## Reverse dependencies

This is a new release, so there are no reverse dependencies.
