# Probability Distributions
A C library for generating Random Variables according to a few common probability distributions.

### Usage Notes

- Make sure to call the **seed()** function before calling any of the generator functions.
- To avoid memory leaks, don't forget to free the pointers returned by the respective distribution generator functions (does not apply to the "single" functions).

### Supported Distributions
- Uniform
- Normal/Gaussian
- Exponential

### Distributions to be added
- Poisson
- Binomial
- Bernoulli
