from functools import reduce
from pyspark import SparkContext
import functools
import numpy as np

x = 2
degrees = [0, 1, 2, 3]
coeffs = [-1, 3, 0, 10]

map_out = list(map(lambda k: x**k, degrees))

# we define a list of integers
numbers = [1, 4, 6, 2, 9, 10]

# Use reduce to combine numbers
print(numbers)
reduce(lambda x, y: "(" + str(x) + ", " + str(y) + ")", numbers)

# # squaring the values in an RDD
# nums = sc.parallelize([1, 2, 3, 4])
# squared = nums.map(lamda x: x*x).collect()

# for num in squared:
#     print "%i " % (num)


# OUTPUT: evaluate(x)
