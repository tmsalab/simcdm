#include <RcppArmadillo.h>

// [[Rcpp::interfaces(r, cpp)]]

//' Bijection Vector
//'
//' Computes the powers of 2 from \eqn{0} up to \eqn{K - 1}.
//' @param K  Number of Attributes.
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



//' Perform an Inverse Bijection of an Integer to Attribute Pattern 
//' 
//' Convert integer between \eqn{0} and \eqn{2^{K-1}} to
//' \eqn{K}-dimensional attribute pattern.
//'
//' @param CL An `integer` between \eqn{0} and \eqn{2^{K-1}}
//' @inheritParams bijectionvector
//' @return A \eqn{K}-dimensional vector with an attribute pattern corresponding
//' to `CL`. 
//' @export
//' 
//' @examples
//' inv_bijectionvector(5, 1)
//' inv_bijectionvector(5, 2)
// [[Rcpp::export]]
arma::vec inv_bijectionvector(unsigned int K, double CL)
{
  arma::vec alpha(K);
  
  for (unsigned int k = 0; k < K; ++k) {
    double twopow = pow(2, K - k - 1);
    alpha(k) = (twopow <= CL);
    CL = CL - twopow * alpha(k);
  }
  
  return alpha;
}

