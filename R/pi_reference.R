
#' Mapping of Entries of Pi to Latent Attribute Classes
#'
#' Obtains mapping of entries of pi to latent attribute classes.
#' @param K A `numeric`, denoting the number of attributes.
#' @return A `matrix`, where row \eqn{c} represents the latent class
#' corresponding to entry \eqn{c} of \eqn{pi}
#' @author Steven Andrew Culpepper, Aaron Hudson
#' @export
pi_reference = function(K) {
  biject.vector = bijectionvector(K)
  As = as.matrix(expand.grid(rep(list(c(0,1)), K)))
  a = As%*%biject.vector
  As = As[a+1,]
  return(As)
}
