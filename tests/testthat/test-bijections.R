context("test-bijections")

test_that("valid bijectionvector", {
  bijection_test = matrix( 2^((3-1):0) )
  
  expect_equal(bijectionvector(3),  bijection_test)
})

test_that("valid inv_bijectionvector", {
  
  inv_bijection_test = function(K, CL) { 
    alpha = rep(NA, K)
    
    for (k in seq_len(K) - 1) {
      twopow = 2^(K - k - 1)
      alpha[k + 1] = 1 * (twopow <= CL)
      CL = CL - twopow * alpha[k + 1]
    }
    
    matrix(alpha)
  } 
  
  expect_equal(inv_bijectionvector(3, 0),  inv_bijection_test(3, 0))
  
  expect_equal(inv_bijectionvector(4, 1),  inv_bijection_test(4, 1))
  
  expect_equal(inv_bijectionvector(5, 2),  inv_bijection_test(5, 2))
  
})
