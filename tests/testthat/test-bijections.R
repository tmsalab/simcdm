context("test-attribute bijections")

test_that("valid attribute_bijection", {
  bijection_test = matrix( 2^((3-1):0) )
  
  expect_equal(attribute_bijection(3),  bijection_test)
})

test_that("valid attribute_inv_bijection", {
  
  inv_bijection_test = function(K, CL) { 
    alpha = rep(NA, K)
    
    for (k in seq_len(K) - 1) {
      twopow = 2^(K - k - 1)
      alpha[k + 1] = 1 * (twopow <= CL)
      CL = CL - twopow * alpha[k + 1]
    }
    
    matrix(alpha)
  } 
  
  expect_equal(attribute_inv_bijection(3, 0),  inv_bijection_test(3, 0))
  
  expect_equal(attribute_inv_bijection(4, 1),  inv_bijection_test(4, 1))
  
  expect_equal(attribute_inv_bijection(5, 2),  inv_bijection_test(5, 2))
  
})
