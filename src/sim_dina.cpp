#include <RcppArmadillo.h>

// [[Rcpp::interfaces(r, cpp)]]

//' Simulate Binary Responses for DINA Model
//'
//' Simulation the Y Response for a DINA Model
//' 
//' @param N     Number of Observations
//' @param J     Number of Assessment Items
//' @param CLASS Does the individual possess all the necessary attributes?
//' @param ETA   \eqn{\eta} Matrix containing indicators.
//' @param gs    A `vec` describing the probability of guessing or
//'              the probability subject correctly answers item \eqn{j} when at
//'              least one attribute is lacking.
//' @param ss    A `vec` describing the probability of slipping or
//'              the probability of an incorrect response for individuals with
//'              all of the required attributes
//' 
//' @return A `mat`
//' @author Steven A Culpepper
//' @template sim-dina-class-example
//' @export
// [[Rcpp::export]]
arma::mat sim_dina_class(unsigned int N, unsigned int J, const arma::vec &CLASS,
                         const arma::mat &ETA, const arma::vec &gs,
                         const arma::vec &ss)
{
    arma::mat Y(N, J);
    for (unsigned int i = 0; i < N; ++i) {
        double class_i = CLASS(i);
        arma::vec ETA_i = ETA.col(class_i);
        for (unsigned int j = 0; j < J; ++j) {
            double u = R::runif(0, 1);
            Y(i, j) =
                1. * (gs(j) * (1. - ETA_i(j)) + (1. - ss(j)) * ETA_i(j) > u);
        }
    }
    return Y;
}

//' Simulation Responses from the DINA model
//'
//' Sample responses from the DINA model for given attribute profiles, Q matrix,
//' and item parmeters. Returns a `matrix` of dichotomous responses
//' generated under DINA model.
//'
//' @param alphas A \eqn{N} by K `matrix` of latent attributes.
//' @param Q      A \eqn{N} by K `matrix` indicating which skills are required
//'               for which items. 
//' @param ss     A \eqn{J} `vector` of item slipping parameters.
//' @param gs     A \eqn{J} `vector` of item guessing parameters.
//' 
//' @return A \eqn{N} by \eqn{J} `matrix` of responses from the DINA model.
//' @author Steven Andrew Culpepper
//' @examples
//' ############################################
//' # de la Torre (2009) Simulation Replication
//' ############################################
//' N = 200
//' K = 5
//' J = 30
//' delta0 = rep(1, 2 ^ K)
//' 
//' # Creating Q matrix
//' Q = matrix(rep(diag(K), 2), 2 * K, K, byrow = TRUE)
//' for (mm in 2:K) {
//'   temp = combn(seq_len(K), m = mm)
//'   tempmat = matrix(0, ncol(temp), K)
//'   for (j in seq_len(ncol(temp)))
//'     tempmat[j, temp[, j]] = 1
//'   Q = rbind(Q, tempmat)
//' }
//' Q = Q[seq_len(J), ]
//' 
//' # Setting item parameters and generating attribute profiles
//' ss = gs = rep(.2, J)
//' PIs = rep(1 / (2 ^ K), 2 ^ K)
//' CLs = c((1:(2 ^ K)) %*% rmultinom(n = N, size = 1, prob = PIs))
//' 
//' # Defining matrix of possible attribute profiles
//' As = rep(0, K)
//' for (j in seq_len(K)) {
//'   temp = combn(1:K, m = j)
//'   tempmat = matrix(0, ncol(temp), K)
//'   for (j in seq_len(ncol(temp)))
//'     tempmat[j, temp[, j]] = 1
//'   As = rbind(As, tempmat)
//' }
//' As = as.matrix(As)
//' 
//' # Sample true attribute profiles
//' Alphas = As[CLs, ]
//' 
//' # Simulate data under DINA model
//' gen = sim_dina(Alphas, Q, ss, gs)
//' @export
// [[Rcpp::export]]
arma::mat sim_dina(const arma::mat &alphas, const arma::mat &Q,
                   const arma::vec &ss, const arma::vec &gs)
{
    unsigned int N = alphas.n_rows;
    unsigned int J = Q.n_rows;

    arma::mat Y = arma::zeros<arma::mat>(N, J);
    arma::mat ETA(N, J);
    double uij;

    for (unsigned int j = 0; j < J; ++j) {
        for (unsigned int i = 0; i < N; ++i) {
            ETA(i, j) = 1.0;
            uij = R::runif(0., 1.);

            if (arma::dot(alphas.row(i), Q.row(j)) <
                arma::dot(Q.row(j), Q.row(j))) {
                ETA(i, j) = 0.0;
            }

            if (pow(1.0 - ss(j), ETA(i, j)) * pow(gs(j), 1.0 - ETA(i, j)) >
                uij) {
                Y(i, j) = 1;
            } else {
                Y(i, j) = 0;
            }
        }
    }
    return Y;
}