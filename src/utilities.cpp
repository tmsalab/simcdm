#include <RcppArmadillo.h>

// [[Rcpp::interfaces(r, cpp)]]

//' Bijection Vector
//'
//' Computes the powers of 2 from 0 up to K - 1.
//' @param K  Number of Attributes
//' @return A \code{vec} with length \eqn{K} detailing the power's of 2.
//' @examples
//' 
//' bijectionvector(3)
//' 
//' @export
// [[Rcpp::export]]
arma::vec bijectionvector(unsigned int K)
{
  arma::vec vv(K);
  for (unsigned int i = 0; i < K; ++i) {
    vv(i) = pow(2, K - i - 1);
  }
  return vv;
}
