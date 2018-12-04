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

//' Generate random Q matrix
//'
//' Simulates a Q matrix containing three identity matrices after a row
//' permutation.
//'
//' @param J Number of Items
//' @param K Number of Attributes
//'
//' @return A dichotomous \code{matrix} for Q.
//' @examples
//' sim_q_matrix(7, 2)
//' 
//' sim_q_matrix(10, 3)
//' @export
// [[Rcpp::export]]
arma::mat sim_q_matrix(unsigned int J, unsigned int K)
{
    // Impose an error check
    if (J < 3 * K - 1) {
        Rcpp::stop("J must be greater than 3*K.");
    }
    
    // Calculate number of classes
    unsigned int nClass = pow(2, K);

    // Form a Bijection
    arma::vec vv = bijectionvector(K);

    // Fill Q bijection vector
    arma::vec Q_biject(J);
    Q_biject(arma::span(0, K - 1)) = vv;
    Q_biject(arma::span(K, 2 * K - 1)) = vv;
    Q_biject(arma::span(2 * K, 3 * K - 1)) = vv;

    // Randomly sample from a discrete uniform
    arma::vec Jm3K =
        arma::randi<arma::vec>(J - 3 * K, arma::distr_param(1, nClass - 1));
    Q_biject(arma::span(3 * K, J - 1)) = Jm3K;

    // Randomize rows
    Q_biject = arma::shuffle(Q_biject);

    // Create Q Matrix
    arma::mat Q(J, K);
    for (unsigned int j = 0; j < J; ++j) {
        arma::vec qj = inv_bijectionvector(K, Q_biject(j));
        Q.row(j) = qj.t();
    }

    return Q;
}

//' Generate ideal response \eqn{\eta} Matrix
//'
//' Creates the ideal response matrix for each trait
//'
//' @param K      Number of Attribute Levels
//' @param J      Number of Assessment Items
//' @param Q      Q Matrix with dimensions \eqn{K \times J}{K x J}.
//' @return A `mat` with dimensions \eqn{J \times 2^K}{J x 2^K}.
//' @export
//'
//' @examples
//' K       = 3
//'
//' # Fixed Number of Assessment Items for Q
//' J = 18
//'
//' # Specify Q
//' qbj = c(4, 2, 1, 4, 2, 1, 4, 2, 1, 6, 5, 3, 6, 5, 3, 7, 7, 7)
//'
//' # Fill Q Matrix
//' Q = matrix(, J, K)
//' for (j in seq_len(J)) {
//'   Q[j,] = inv_bijectionvector(K, qbj[j])
//' }
//' # Create an eta matrix
//' ETA = eta_matrix(K, J, Q)
// [[Rcpp::export]]
arma::mat eta_matrix(unsigned int K, unsigned int J, const arma::mat &Q)
{
    double nClass = pow(2, K);

    arma::mat ETA(J, nClass);

    for (unsigned int cc = 0; cc < nClass; ++cc) {
        arma::vec alpha_c = inv_bijectionvector(K, cc);

        for (unsigned int j = 0; j < J; ++j) {
            arma::rowvec qj = Q.row(j);
            // Switch to as_scalar
            double compare = arma::as_scalar(qj * alpha_c - qj * qj.t());
            ETA(j, cc) = (compare >= 0);
        }
    }

    return ETA;
}
