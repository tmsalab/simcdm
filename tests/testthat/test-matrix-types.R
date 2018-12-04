context("Simulation Matrix")

test_that("Generate alpha matrix (pi references)", {
  
  # Old, r-specific pi mapping function
  pi_reference = function(K) {
    biject.vector = bijectionvector(K)
    As = as.matrix(expand.grid(rep(list(c(0,1)), K)))
    a = As%*%biject.vector
    As = As[a+1,]
    return(As)
  }
  
  # Check equality
  expect_equal(sim_alpha_matrix(2), pi_reference(2), check.attributes = FALSE,
               info = "Verify latent class mapping is correct.")
  
  # Check equality
  expect_equal(sim_alpha_matrix(5), pi_reference(5), check.attributes = FALSE,
               info = "Verify latent class mapping is correct.")
  
  # Check equality
  expect_equal(sim_alpha_matrix(8), pi_reference(8), check.attributes = FALSE,
               info = "Verify latent class mapping is correct.")
})
