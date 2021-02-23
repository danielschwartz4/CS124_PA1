# Fitting Polynomial Regression to the dataset 
from sklearn.preprocessing import PolynomialFeatures 
import numpy as np


y = "128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 261244"
y = y.split(" ")
y = np.array(y)


# D1 data
x = "7.65462 10.898884 15.067772 21.152227 29.633859 41.769656 58.829882 83.052014 117.561844 165.919409 234.687828 331.625912"
x = x.split(" ")
x = np.array(x)



