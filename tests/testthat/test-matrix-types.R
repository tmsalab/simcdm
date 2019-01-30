context("Simulation Matrix")

test_that("Reproducible Q matrix simulations", {
  
  set.seed(888)
  q1 = sim_q_matrix(20, 3)
  
  set.seed(888)
  q2 = sim_q_matrix(20, 3)
  
  expect_equal(q1,  q2, info = "Verify Q matrix is able to be regenerated")
})


test_that("Incorrect dimensions for an identifiable Q matrix creation", {
  
  # Verify Q matrix throws error if J < 3 * K - 1.
  
  # Todo: tighten this check.
  expect_error(sim_q_matrix(5, 3), info = "")
})
